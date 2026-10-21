#include<iostream>
#include<vector>
#include<map>

using namespace std;

int singleNonDuplicateBrute(vector<int>& nums) {
    //Extreme Brute Force: using map
    //T.C --> O(N logN), S.C --> O(N)

    int n = nums.size();
    map<int,int> mp;

    for(int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    for(int i = 0; i < n; i++)
    {
        if(mp[nums[i]] == 1)return nums[i];
    }

    return -1;
}

int singleNonDuplicateBetter(vector<int>& nums) {
    //Better Mathematical Approach: using XOR
    //T.C --> O(N), S.C --> O(1)

    int n = nums.size(), XOR = 0;

    for(int i = 0; i < n; i++)
    {
        XOR ^= nums[i];
    }

    return XOR;
}

int singleNonDuplicateBetter2(vector<int>& nums) {
    //Better Approach: using liner traversal and comparing current with prev and next elements.
    //T.C --> O(N), S.C --> O(1)

    int n = nums.size();
    if(n == 1)return nums[0];

    for(int i = 0; i < n; i++)
    {
        //works only because the array is sorted.
        //hence, all the occurances of each number are together
        if(i == 0)
        {
            if(nums[i] != nums[i+1])return nums[i];
        }
        else if(i == n-1)
        {
            if(nums[i] != nums[i-1])return nums[i];
        }
        else
        {
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1])return nums[i];
        }
    }

    return -1;
}

int singleNonDuplicateOptimal(vector<int>& nums) {
    //Optimal Approach: using liner traversal and comparing current with prev and next elements.
    //T.C --> O(logN), S.C --> O(1)

    int n = nums.size();
    if(n == 1)return nums[0];
    if(nums[0] != nums[1])return nums[0];
    if(nums[n-1] != nums[n-2])return nums[n-1];

    int low = 1, high = n - 2;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])return nums[mid];
        else if((mid % 2 == 1 && nums[mid - 1] == nums[mid]) || (mid % 2 == 0 && nums[mid + 1] == nums[mid]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    cout<<"The element present only once in the given array is: "<<singleNonDuplicateBrute(nums)<<"\n";
    cout<<"The element present only once in the given array is: "<<singleNonDuplicateBetter(nums)<<"\n";
    cout<<"The element present only once in the given array is: "<<singleNonDuplicateBetter2(nums)<<"\n";
    cout<<"The element present only once in the given array is: "<<singleNonDuplicateOptimal(nums)<<"\n";
    
    return 0;
}