#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool canBePlaced(vector<int>&nums, int k, int dist)
{
    int n = nums.size();
    
    int cowsCount = 1;//first cow placed
    int last = nums[0]; //at the very first index, as placing early helps the cause
    
    for(int i = 0; i < n; i++)
    {
        if(nums[i] - last >= dist)
        {
            cowsCount++;
            last = nums[i];
        }
    }
    
    if(cowsCount >= k)return true;
    else return false;
}

int aggressiveCowsBrute(vector<int> &nums, int k) {
    /*Brute Force Approach: Trying to place the at a distance. We try with distances
    ranging from 1 to 1e9 
    (or a better choice is maxDist = max - min element of array) as that can be the max
    dist between any 2 consecutive cows.
    Then we try to place the cows with each distance and as "min" dist will always be between any 2 "consecutive" cows.
    */
    //T.C --> O((max - min) * N), S.C --> O(1)
    sort(nums.begin(), nums.end());
    int ans = 0;
    
    int start = 1, end = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
    
    for(int i = start; i <= end; i++)
    {
        if(canBePlaced(nums, k, i))
        {
            ans = i;
            continue;
        }
        else break;
    }
    
    return ans;
}

int aggressiveCowsOptimal(vector<int> &nums, int k) {
    /*Optimal Approach: Using the BINARY SEARCH concept on the RANGE of distance (1 - (max - min))
    as after maximum min dist possible there is not point of checking whether cows can be placed or not
    as we won't be able to place all the cows
    Trying to place the at a distance. We try with distances
    ranging from 1 to 1e9 
    (or a better choice is maxDist = max - min element of array) as that can be the max
    dist between any 2 consecutive cows.
    Then we try to place the cows with each distance and as "min" dist will always be between any 2 "consecutive" cows.
    */
    //T.C --> O(log(max - min) * N), S.C --> O(1)
    sort(nums.begin(), nums.end());
    int ans = 0;
    
    int start = 1, end = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
    
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        
        if(canBePlaced(nums, k, mid))
        {
            start = mid + 1; //to search for a greater possible distance
        }
        else end = mid - 1;
    }
    
    //no need to use ans variable as high will allways be pointing at the ans
    //as the polarity of the variables (start & low) OR (low & high) reverses once the loop ends
    return end;
}

int main()
{

    vector<int>nums = {1, 2, 4, 8, 9};
    int k = 3;
    cout<<aggressiveCowsBrute(nums, k)<<"\n";
    cout<<aggressiveCowsOptimal(nums, k);

    return 0;
}