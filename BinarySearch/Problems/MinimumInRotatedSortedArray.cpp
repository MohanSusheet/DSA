#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int findMinBrute(vector<int>& nums)
{
    int n = nums.size(), ans = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        ans = min(ans, nums[i]);
    }

    return ans;
}

int findMinOptimal(vector<int>& nums) {
    //BruteForce Approach: linear search to find the element.
    //Optimal Approach: using binary search to find the min ele, but with conditional
    //elimination of array portion as the array is rotated and only one half of the array is sorted
    //T.C --> O(logN), S.C --> O(1)

    int n = nums.size(), ans = INT_MAX;

    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(nums[low] <= nums[mid]) //left halft is sorted, doesn;t guarantee minimum lies in this half
        {
            //considering the min of this half for ans
            //and nums[low] is the min of this half
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else
        {
            //considering the min of this half for ans
            //and nums[mid] is the min of this half
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }

    return ans;
}


int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};

    cout<<"Minimum is: "<<findMinBrute(nums)<<"\n";
    cout<<"Minimum is: "<<findMinOptimal(nums);

    return 0;
}