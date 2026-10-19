#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int lowerBound(vector<int>& nums, int target)
{
    /*
    LOWER BOUND algorithm (commonly used in binary search) finds the first position 
    where the target could be inserted without violating the sorted order of the array.
    Here is a quick breakdown of how it handles the three scenarios you mentioned:

    Here is a quick breakdown of how it handles the three scenarios :
    • First occurrence: If the target exists multiple times (e.g., [1, 2, 2, 2, 3] with target 2), it returns the index of the first 2 (index 1).
    • Greater than or equal to: If the target does not exist but there are larger numbers (e.g., [1, 3, 5, 7] with target 4), it returns the index of the first element greater than 4, which is 5 (index 2).
    • Last hypothetical index: If all numbers in the array are strictly smaller than the target (e.g., [1, 2, 3] with target 5), it returns the index just past the end of the array (index 3, which equals the total length of the array).
    */
    
    //T.C --> O(logN), S.C --> O(1)
    int n = nums.size(), low = 0, high = n - 1;
    int lb = n;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(nums[mid] >= target)
        {
            lb = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    return lb;
}

int upperBound(vector<int>& nums, int target)
{
    //UpperBound return the index if First element that is strictly greater than the target
    //T.C --> O(logN), S.C --> O(1)
    int n = nums.size(), low = 0, high = n - 1;
    int ub = n;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(nums[mid] > target)
        {
            ub = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    return ub;
}

int main()
{
    vector<int> nums = {5,7,7,8,8,10};

    int lb1 = lowerBound(nums, 8); //expected ans = 3
    int lb2 = lowerBound(nums, 11); //expected ans = 6
    int lb3 = lowerBound(nums, 9); //expected ans = 5

    //alternate STL method
    int lb = lower_bound(nums.begin(), nums.end(), 8) - nums.begin(); //starting iterator is subtracted
    cout<<lb1<<" "<<lb2<<" "<<lb3<<"\n"<<lb<<"\n";

    int ub = upperBound(nums, 9);
    cout<<ub<<"\n";

    ub = upper_bound(nums.begin(), nums.end(), 8) - nums.begin();
    cout<<ub;
    return 0;
}