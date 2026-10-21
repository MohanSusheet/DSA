#include<iostream>
#include<vector>

using namespace std;


bool searchOptimal(vector<int>& nums, int target) 
{
    //Brute Force: using linear search,  T.C --> O(N), S.C --> O(1)
    //Optimal Appraoch: using binary search with conditional elimination or array portion
    //T.C --> O(logN), S.C --> O(1)

    int n = nums.size(), low = 0, high = n -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(nums[mid] == target)return true;
        else if(nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low += 1;
            high -= 1;
        }
        else if(nums[low] <= nums[mid])
        {
            if(nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if(nums[mid] <= target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return false;
}


int main()
{
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;

    cout<<searchOptimal(nums, target);


    return 0;
}