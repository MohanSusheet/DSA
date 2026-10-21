#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int findKRotationBrute(vector<int>&nums)
{
    //Brute Force Approach: using liner search
    //T.C --> O(N), S.C --> O(1)

    int n = nums.size(), mini = INT_MAX, rotation = 0;

    for(int i = 0; i < n; i++)
    {
        if(nums[i] < mini)
        {
            mini = nums[i];
            rotation = i;
        }
    }

    return rotation;
}

int findKRotationOptimal(vector<int> &nums) {
    //Approach: find the index where the minimum element is present
    //and that is essentially the no. of time the array is rotated.
    //To find the min we apply binary search 
    //concept to find minimum in rotated sorted array
    //T.C --> O(N), S.C --> O(1)
    
    int n = nums.size();
    
    int low = 0, high = n - 1, ans = INT_MAX, rotation = 0;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(nums[low] <= nums[mid])
        {
            if(nums[low] < ans)
            {
                ans = nums[low];
                rotation = low;
            }
            low = mid + 1;
        }
        else
        {
            if(nums[mid] < ans)
            {
                ans = nums[mid];
                rotation = mid;
            }
            high = mid - 1;
        }
    }
    
    return rotation;
}


int main()
{
    vector<int> nums = {6, 7, 8, 9, 1, 2, 3, 4, 5};

    cout<<"The given array rotated: "<<findKRotationBrute(nums)<<" number of times."<<"\n";

    cout<<"The given array rotated: "<<findKRotationOptimal(nums)<<" number of times."<<"\n";

    return 0;
}