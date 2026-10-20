#include<iostream>
#include<vector>

using namespace std;

int countFreqBrute(vector<int>& nums, int target) {
    //Brute Approach: using linera search and counting the target occurances
    //T.C --> O(N), O(1)
    
    int n = nums.size(), count = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == target)count++;
        if(nums[i] > target)break; //just an optimization.
        //stopping as soon as we get a number greater than the target
        //since the array is sorted in non-dec order, we will not find the target moving further right
    }
    
    return count;
}

int findFirstUsingLowerBound(vector<int>& nums, int target)
{
    int n = nums.size(), firstOccurance = n;
    
    int low = 0, high = n - 1;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(nums[mid] >= target)
        {
            firstOccurance = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    return firstOccurance;
}

int findLastUsingUpperBound(vector<int>& nums, int target)
{
    int n = nums.size(), lastOccurance = n;
    
    int low = 0, high = n - 1;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(nums[mid] > target)
        {
            lastOccurance = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    return lastOccurance;
}
    
int countFreqOptimal(vector<int>& nums, int target) {
    //Optimal Approach: using BINARY search to find the first and last occurances of target
    //T.C --> O(2*logN), O(1)
    
    int n = nums.size();
    
    int firstOccurance = findFirstUsingLowerBound(nums, target);
    
    if(firstOccurance == n)return 0; //target not present in the array
    
    //as upper bound return the first element which is strictly greater than target
    //to get the last occurance, we need to subtract 1 from the upper bound returned value
    int lastOccurance = findLastUsingUpperBound(nums, target) - 1;
    
    // cout<<firstOccurance<<" & "<<lastOccurance<<"\n";
    
    return lastOccurance - firstOccurance + 1;
}

int main()
{
    vector<int> nums = {8, 9, 10, 12, 12, 12};
    int target = 12;

    cout<<"Count of Target : "<<target <<" is: "<< countFreqBrute(nums, target)<<"\n";

    cout<<"Count of Target : "<<target <<" is: "<< countFreqOptimal(nums, target);
    return 0;
}