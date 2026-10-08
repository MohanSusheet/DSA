#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric> 

using namespace std;


int getDaysRequired(vector<int>&w, int cap, int days)
{
    int n = w.size(), daysRequired = 1, total = 0;

    for(int i = 0; i < n; i++)
    {
        if(total + w[i] > cap)
        {
            daysRequired += 1;
            total = w[i];
        }
        else
        {
            total += w[i];
        }
    }

    return daysRequired;
}

int shipWithinDaysBrute(vector<int>& w, int days) {
    //Brute Approach: first identfying the range in which the answer lies.
    //iterating through the range and check whether shipping is possible or not.
    //T.C --> O((sum-max+1)*N), S.C --> O(1)

    //as we won't be able to ship the last(heaviest) weight
    int start = *max_element(w.begin(), w.end());

    //the max capacity can be equal to the sum of all the weights in order to ship in 1 day
    int end = accumulate(w.begin(), w.end(), 0);

    int ans = 0;

    for(int i = start; i <= end; i++)
    {
        int daysRequired = getDaysRequired(w, i, days);
        if(daysRequired <= days)
        {
            ans = i;
            break;
        }
    }

    return ans;
}

int shipWithinDaysOptimal(vector<int>& w, int days) {
    //Optimal Approach: Using the BINARY SEARCH ON ANS concept
    //first identfying the range in which the answer lies.
    //iterating through the range and check whether shipping is possible or not.
    //T.C --> O(log(sum-max+1)*N), S.C --> O(1)

    //as we won't be able to ship the last(heaviest) weight
    int start = *max_element(w.begin(), w.end());

    //the max capacity can be equal to the sum of all the weights in order to ship in 1 day
    int end = accumulate(w.begin(), w.end(), 0);

    int ans = 0;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;

        int daysRequired = getDaysRequired(w, mid, days);

        if(daysRequired <= days)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    cout<<shipWithinDaysBrute(weights, days)<<"\n";
    cout<<shipWithinDaysOptimal(weights, days);
    return 0;
}