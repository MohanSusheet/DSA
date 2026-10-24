#include<iostream>
#include<vector>

using namespace std;


int findPeakElementBrute(vector<int>& nums) 
{
    //Brute Approach: using linear search
    //T.C --> O(N), T.C --> O(1)

    int n = nums.size();

    if(n == 1)return 0;
    if(nums[0] > nums[1])return 0;
    if(nums[n-1] > nums[n - 2])return n - 1;

    for(int i = 1; i < n - 1; i++)
    {
        if(nums[i-1] < nums[i] && nums[i] > nums[i+1])
        {
            return i; //we can end execution as we have to return any one peak element
        }
    }

    return -1;
}

int findPeakElementOptimal(vector<int>& nums) {
    //Optimal Approach: using binary search. For this particular problem
    //Graphical representation of array assists in analysing the conditions in a way easier manner.
    //T.C --> O(logN), T.C --> O(1)

    int n = nums.size();

    if(n == 1)return 0;
    if(nums[0] > nums[1])return 0;
    if(nums[n-1] > nums[n - 2])return n - 1;

    int low = 1, high = n - 2;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])return mid;
        else if(nums[mid] > nums[mid - 1])low = mid + 1;
        else if(nums[mid] > nums[mid + 1])high = mid - 1;
        else low = low + 1; //with this condition the logic works for cases with multiple peaks.
        //this last condiition deals with scenario where nums[mid - 1] > nums[mid] < nums[mid + 1], which is
        //possible in arrays having multiple peaks.
    }

    return -1;
}

int main()
{
    vector<int> nums = {1,2,1,3,5,6,4};

    /*
    NOTE: For arrays with multiple peak, the brute approach and optimal approach may give different result
    Brute --> First Peak it finds & Optimal --> Any peak founnd by the BinarySearch algo.
    */
    cout<<"Peak element in the given array is present at index : "<<findPeakElementBrute(nums)<<"\n";
    cout<<"Peak element in the given array is present at index : "<<findPeakElementOptimal(nums);

    return 0;
}