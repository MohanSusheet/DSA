#include<iostream>
#include<vector>

using namespace std;

int searchInsertBrute(vector<int>& nums, int target) {
    //Brute Force Approach: using linear search
    //T.C --> O(N), S.C --> O(1)
    int n = nums.size(), ans = n;

    for(int i = 0; i < n; i++)
    {
        if(nums[i] >= target)return i;
    }

    return ans;
}

int searchInsertOptimal(vector<int>& nums, int target) {
    //Optimal Approach : Using binary search
    //T.C --> O(log n), S.C --> O(1)
    int n = nums.size();
    if(target < nums[0])return 0;
    if(target > nums[n-1])return n;
    
    //Optimal Approach: using Binary search
    //T.C --> O(logN), S.C --> O(1)
    int low = 0, high = n-1, ans = n;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans; //or "LOW" as low always points at the index where target should be inserted 
    //as at last it points at the element just greater than the target.
}

int main()
{
    /*
    Return the index if the target is found. If not, return the index where it would be if it were inserted in order.
    */
    vector<int> nums = {1,3,5,6};
    int target = 5;

    int foundAt = searchInsertBrute(nums, target);
    cout<<"Target : "<<target<<" found at index: "<<foundAt<<"\n";

    target = 4;
    int insertAt = searchInsertOptimal(nums, target);
    cout<<"Target : "<<target<<" to be inserted at index: "<<insertAt<<"\n";

    target = 10;
    int insertAt1 = searchInsertOptimal(nums, target);
    cout<<"Target : "<<target<<" to be inserted at index: "<<insertAt1<<"\n";


    return 0;
}