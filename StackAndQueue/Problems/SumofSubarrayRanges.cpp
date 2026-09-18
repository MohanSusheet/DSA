#include<iostream>
#include<vector>
#include<climits>
#include<stack>

using namespace std;

long long subArrayRangesBrute(vector<int>& nums) {
    //Brute Force Approach: Generating all subarrays and calculating the difference between
    //that subarray's largest and smallest element.
    //T.C --> O(N^2), S.C --> O(1)

    int n = nums.size();
    long long sum = 0;

    for(int i = 0; i < n; i++)
    {
        int mini = INT_MAX, maxi = INT_MIN;
        //or start "j" from "i+1" as single element subarray is not really contributing to the ans as
        //arr[j] - arr[j] = 0 (as the max and min elements are the element intself.
        for(int j = i; j < n; j++)
        {
            mini = min(mini, nums[j]);
            maxi = max(maxi, nums[j]);
            sum += (maxi - mini);
        }
    }

    return sum;
}


vector<int> nextSmallerElements(vector<int>& nums)
{
    int n = nums.size();
    vector<int> nse(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
            st.pop();
        }

        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return nse;
}

vector<int> prevSmallerOrEqualElements(vector<int>& nums)
{
    int n = nums.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }

        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return pse;
}

long long SumOfSubarrayMinimums(vector<int>& nums)
{
    int n = nums.size();
    long long totalSum = 0;

    vector<int> nse = nextSmallerElements(nums);
    vector<int> psee = prevSmallerOrEqualElements(nums);

    for (int i = 0; i < n; i++)
    {
        long long left = i - psee[i];
        long long right = nse[i] - i;

        totalSum += left * right * nums[i];
    }

    return totalSum;
}

vector<int> nextGreaterElements(vector<int>& nums)
{
    int n = nums.size();
    vector<int> nge(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }

        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return nge;
}

vector<int> prevGreaterOrEqualElements(vector<int>& nums)
{
    int n = nums.size();
    vector<int> pge(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] < nums[i])
        {
            st.pop();
        }

        pge[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return pge;
}

long long SumOfSubarrayMaximums(vector<int>& nums)
{
    int n = nums.size();
    long long totalSum = 0;

    vector<int> nge = nextGreaterElements(nums);
    vector<int> pgee = prevGreaterOrEqualElements(nums);

    for (int i = 0; i < n; i++)
    {
        long long left = i - pgee[i];
        long long right = nge[i] - i;

        totalSum += left * right * nums[i];
    }

    return totalSum;
}

long long subArrayRangesOptimal(vector<int>& nums)
{
    //Brute Approach: Generating all subarrays and determinig the max and min elements for each.
    //Optimal apporach: Since, we have solved "Sum of Subarray minimums", we can similarly calculate "Sum of subarray maximums".
    //The core intuition is to determine the in how many subarrays each element contributes as a minimum and in how many as maximum.
    //Hence, "Sum of subArrayRanges" can then be simple calculated by "Sum of subarray maximums" - "Sum of Subarray minimums"
    long long sumOfSubarrayMins = SumOfSubarrayMinimums(nums);
    long long sumOfSubarrayMaxs = SumOfSubarrayMaximums(nums);

    return sumOfSubarrayMaxs - sumOfSubarrayMins;
}

int main()
{
    vector<int> nums = {4,-2,-3,4,1};

    cout<<subArrayRangesBrute(nums)<<"\n";
    cout<<subArrayRangesOptimal(nums);

    return 0;
}