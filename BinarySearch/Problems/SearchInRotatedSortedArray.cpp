#include<iostream>
#include<vector>

using namespace std;

int searchBrute(vector<int>& nums, int target)
{
    int n = nums.size();

    for(int i = 0; i < n; i++)
    {
        if(nums[i] == target)return i;
    }

    return -1;
}

int searchOptimal(vector<int>& nums, int target) {
    //Brute Force Approach: linera search
    //Optimal Approach: Using binary search, but eliminations of one portion of array will be subject to a condition here.
    //T.C --> O(logN), S.C --> O(1)

    int n = nums.size();

    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(nums[mid] == target)return mid;
        else if(nums[low] <= nums[mid]) //if true, means left half is sorted
        {
            //finding the sorted half does not guarantee that target lies in the sorted half, hence the follow up checking condition
            if(nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else  //means the right half is sorted
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


    return -1;
}

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    cout<<"Target: "<<target<<" found at index(0 based): "<<searchBrute(nums, target)<<"\n";
    cout<<"Target: "<<target<<" found at index(0 based): "<<searchOptimal(nums, target);

    return 0;
}