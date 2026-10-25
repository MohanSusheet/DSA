#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int count(vector<int>&nums, int limit, int n)
{
    //this function returns the number of painters that will be required if
    //each painter is allowed to take "limit" units of time to complete his task
    int subarrays = 1, subarraySum = nums[0];

    for(int i = 1; i < n; i++)
    {
        if(subarraySum + nums[i] <= limit)
        {
            subarraySum += nums[i];
        }
        else
        {
            subarraySum = nums[i];
            subarrays++;
        }
    }
    return subarrays;
}

int splitArrayBrute(vector<int>& nums, int k) {
    //Brute Force Approach:
    //T.C --> O((high - low + 1) * N), S.C --> O(1)

    int n = nums.size();

    if(n < k)return -1; //if the number of elements is less than the no. of partitions/subarrays asked,
    //it is not possible to split the original array

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    for(int i = low; i <= high; i++)
    {
        int partitions = count(nums, i, n);
        if(partitions <= k)return i;
    }

    return -1;
}


int splitArrayOptimal(vector<int>& nums, int k) {
    //Optimal Approach: 
    /*using Binary Search on answer. Rather than calculating how much time each painter should take to complete the entire task of painting all the boards, we calculate the number of painters required to complete the task in some "limit" time. This limit time is calculated using the binary search concept on on search space.*/
    //T.C --> O(logN * N), S.C --> O(1)

    int n = nums.size();

    if(n < k)return -1; //if the number of boards is less than the no. of painters,
    //it is not possible to a board to each painter

    /*since nums[i] is length of board and painter takes 1 unit time to paint 1 unit length,
    the mini time any painter will take to paint any single board should be max ele of array*/
    int low = *max_element(nums.begin(), nums.end());

    int high = accumulate(nums.begin(), nums.end(), 0);

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        int partitions = count(nums, mid, n);

        if(partitions <= k)
        {
            high = mid - 1;
        }
        else low = mid + 1;
    }

    return low;
}

int main()
{
    //Task: split the array into "k" subarrays such that the maximum sum of a subarray is minimum.
    //HINT: Similar to Allocate Pages to Students and Painter's partition problems
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    

    cout<<"Maximum subarrya sum is: "<<splitArrayBrute(nums, k)<<" after splitting into "<<k<<" subarrays.\n";
    cout<<"Maximum subarrya sum is: "<<splitArrayOptimal(nums, k)<<" after splitting into "<<k<<" subarrays.";

    return 0;
}