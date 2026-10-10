#include<iostream>
#include<vector>

using namespace std;

int findKthPositiveBrute(vector<int>& nums, int k) {
    //Brute Force Approach: simply calculating the missing number using 
    //what actaully should have been in the place in case no number was missing.
    //T.C -- O(N), S.C --> O(1)
    int n = nums.size();

    for(int i = 0; i < n; i++)
    {
        if(nums[i] <= k)k++; //simply k can not be returned as the number present
        //take up the place and hence we need to move "k" forward in order \
        //for it to point at the correct Kth "missing" number.
        else break;
    }

    return k;
}

int findKthPositiveOptimal(vector<int>& nums, int k) {
    //Optimal Approach: Using Binary Search as the given array is sorted in strictly increasing order
    //But BS cannot be applied straight away here as the ansolute number required is missing.
    //Hence we apply BS to find the range in which our kth missing number lies.
    //Also, we apply the BS not on the number present at any index 'i', but the count of numbers missing uptil that particular index.
    //T.C -- O(logN), S.C --> O(1)

    int n = nums.size(), low = 0, high = n-1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        //nums[mid] - (mid + 1) gives the count of missing numbers till index "mid".
        //(mid + 1) --> number that should have been present
        
        int missing = nums[mid] - (mid + 1);
        if(missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    //Once the loop ends, low and high point to the range in which the required ans lies.
    //high now points to the lower bound and low points to the upper bound

    //"eqn 1" --> ans = nums[high] + more. 
    //And more = k - missing (where missing is nums[high] - (high + 1)) 
    //but, high can be pointing to a -ve index(for cases where k < nums[0])
    //hence, we simply substitute the values in "eqn 1".
    //ans = nums[high] + k - (nums[high] - high - 1)
    //ans = nums[high] - nums[high] + k + high  + 1
    //ans = high + 1 + k; also, low = high + 1, ans = low + k;

    return low + k;
}

int main()
{

    vector<int>nums = {2,3,4,7,11};
    int k = 5;
    cout<<findKthPositiveBrute(nums, k)<<"\n";
    cout<<findKthPositiveOptimal(nums, k);

    return 0;
}