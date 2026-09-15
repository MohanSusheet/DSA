#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void printArray(vector<int>&a)
{
    for(auto it: a)
    {
        cout<<it<<" ";
    }
}

vector<int> nextGreaterElementBrute(vector<int>& arr) {
    //Brute Force Approach: Using nested loop to iterate towards the right and
    //find the next greater element for each element.
    //T.C --> O(N^2), S.C --> O(N)[for ans]

    int n = arr.size();
    vector<int> ans(n, -1);

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }

    return ans;
}

vector<int> nextGreaterElementOptimal(vector<int>& arr) {
    //Optimal Approach: Using stack in a monotonic fashion and iterating from the back side in order to keep 
    //the greatest element seen yet (from n-1 to i[current] index)
    //T.C --> O(2N), S.C --> O(N)[for ans] + O(N)[stack]

    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {6, 8, 0, 1, 3};

    vector<int>ans1 = nextGreaterElementBrute(arr);
    printArray(ans1);
    cout<<endl;
    vector<int>ans2 = nextGreaterElementOptimal(arr);
    printArray(ans2);

    return 0;
}