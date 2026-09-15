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


vector<int> nextGreaterElements2Brute(vector<int>& nums) {
    //Naive Approach: Using nested loop
    //T.C --> O(N * (2N)) ~~ O(N^2), S.C --> O(N)[for ans array]

    int n = nums.size();
    vector<int> ans(n, -1);

    for(int i = 0; i < n; i++)
    {
        bool found = false;
        for(int j = i + 1; j < n; j++)
        {
            if(nums[j] > nums[i])
            {
                ans[i] = nums[j];
                found = true;
                break;
            }
        }
        for(int j = 0; j < i; j++) //(hypothetically)rotated portion i.e. 0 to i-1
        {
            if(nums[j] > nums[i] && !found)
            {
                ans[i] = nums[j];
                break;
            }
        }
    }
    return ans;
}

vector<int> nextGreaterElement2Better(vector<int>& nums) {
    //Naive Approach: Using nested loop. A little optimised by running the inner loop 2*N times and using % operator to fetch the index 
    //T.C --> O(N^2), S.C --> O(N)[for ans array]

    int n = nums.size();
    vector<int> ans(n, -1);

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < i + n; j++)
        {
            if(nums[j % n] > nums[i])
            {
                ans[i] = nums[j % n];
                break;
            }
        }
    }

    return ans;
}

vector<int> nextGreaterElement2Optimal(vector<int>& nums) {
    //Optimal Approach: Using stack 
    //T.C --> O(4N), S.C --> O(N)[stack] + O(N)[for ans array]

    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = (2*n) - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }
        if(i < n){ans[i] = st.empty() ? -1 : st.top();}
        st.push(nums[i % n]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {6, 8, 0, 1, 3};

    vector<int>ans1 = nextGreaterElements2Brute(arr);
    printArray(ans1);
    cout<<endl;
    vector<int>ans2 = nextGreaterElement2Better(arr);
    printArray(ans2);
    cout<<endl;
    vector<int>ans3 = nextGreaterElement2Optimal(arr);

    return 0;
}