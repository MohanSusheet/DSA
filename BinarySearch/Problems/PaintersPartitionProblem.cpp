#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;


int count(vector<int>&nums, int limit, int n)
{
    //this function returns the number of painters that will be required if
    //each painter is allowed to take "limit" units of time to complete his task
    int painters = 1, timeTaken = nums[0];

    for(int i = 1; i < n; i++)
    {
        if(timeTaken + nums[i] <= limit)
        {
            timeTaken += nums[i];
        }
        else
        {
            timeTaken = nums[i];
            painters++;
        }
    }
    return painters;
}

int minTimeBrute(vector<int>& nums, int k) {
    //Brute Force Approach: 
    /*using linear Search on answer. Rather than calculating how much time each painter should take to 
    complete the entire task of painting all the boards, we calculate the number of painters required to complete the task in some "i" time.
    This limit time is calculated using the linear search on on search space.*/
    //T.C --> O((high - low + 1) * N), S.C --> O(1)

    int n = nums.size();

    if(n < k)return -1; //if the number of boards is less than the no. of painters,
    //it is not possible to a board to each painter

    /*since nums[i] is length of board and painter takes 1 unit time to paint 1 unit length,
    the mini time any painter will take to paint any single board should be max ele of array*/
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    for(int i = low; i <= high; i++)
    {
        int painters = count(nums, i, n);
        if(painters <= k)return i;
    }

    return -1;
}


int minTimeOptimal(vector<int>& nums, int k) {
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

        int painters = count(nums, mid, n);

        if(painters <= k)
        {
            high = mid - 1;
        }
        else low = mid + 1;
    }

    return low;
}




int main()
{
    vector<int> nums = {5, 10, 30, 20, 15};
    int k = 3;

    cout<<"Minimum time required by "<<k<<" painters to paint all the boards is: "<<minTimeBrute(nums, k)<<"\n";
    cout<<"Minimum time required by "<<k<<" painters to paint all the boards is: "<<minTimeOptimal(nums, k); 

    return 0;
}