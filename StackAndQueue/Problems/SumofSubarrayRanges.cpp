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
        for(int j = i; j < n; j++)
        {
            mini = min(mini, nums[j]);
            maxi = max(maxi, nums[j]);
            sum += (maxi - mini);
        }
    }

    return sum;
}


int main()
{
    vector<int> nums = {4,-2,-3,4,1};

    cout<<subArrayRangesBrute(nums);

    return 0;
}