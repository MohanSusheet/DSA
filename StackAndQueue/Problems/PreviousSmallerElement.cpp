#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void printArray(vector<int>&a)
{
    for(auto i: a)
    {
        cout<<i<<" ";
    }
}

vector<int> prevSmallerBrute(vector<int>& arr) {
    //Naive Approach: using nested loop
    //T.C --> O(N^2), S.C --> O(N)[ans]
    int n = arr.size();
    vector<int> ans(n, -1);

    for(int i = 0; i < n; i++)
    {
        for(int j = i-1; j >= 0; j--) //since nearest (prev) smallest is required we move fro i-1 to 0 rather than 0 to i-1
        {
            if(arr[j] < arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

vector<int> prevSmallerOptimal(vector<int>& arr) {
    //Optimized Approach: using stack in a monotonic fashion
    //T.C --> O(N), S.C --> O(N)[ans] + O(N)[ans]
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> s;
    
    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && s.top() >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    
    return ans;
}


int main()
{
    vector<int> arr = {1, 5, 0, 3, 4, 5};

    vector<int> ans1 = prevSmallerBrute(arr);
    printArray(ans1);
    cout<<endl;
    vector<int> ans2 = prevSmallerOptimal(arr);
    printArray(ans2);

    return 0;
}