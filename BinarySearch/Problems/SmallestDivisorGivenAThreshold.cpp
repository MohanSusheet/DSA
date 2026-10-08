#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h> 

using namespace std;

bool isPossible(vector<int>& nums, int divisor, int threshold)
{
    int n = nums.size();
    int result = 0;

    for(int i = 0; i < n; i++)
    {
        result += ceil((float)nums[i] / divisor);
        //cout<<"i = "<<i<<". result: "<<result<<"\n";
    }

    return result <= threshold;
}

int smallestDivisorBrute(vector<int>& nums, int threshold) {
    //T.C --> O((max)*N), S.C --> O(1)
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = -1;

    for(int i = low; i <= high; i++)
    {
        if(isPossible(nums, i, threshold)){
            ans = i;
            break;
        }
    }

    return ans;
}

int smallestDivisorOptimal(vector<int>& nums, int threshold) {
    //T.C --> O(log(max)*N), S.C --> O(1)
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(isPossible(nums, mid, threshold))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {44,22,33,11,1};
    int threshold = 5;

    cout<<smallestDivisorBrute(nums, threshold)<<"\n";
    cout<<smallestDivisorOptimal(nums, threshold);
    return 0;
}