#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

bool isPossible(vector<int>&bloomDay, int days, int m, int k)
{
    int count = 0, total = 0, n = bloomDay.size();

    for(int i = 0; i < n; i++)
    {
        if(bloomDay[i] <= days)count++;
        else
        {
            total += (count / k);
            count = 0;
        }
    }
    total += (count / k);
    return total >= m ? true : false;
}

int minDaysBrute(vector<int>& bloomDay, int m, int k) {
    //Brute Force: determining the day by linearly iterating throught the range in which ans lies
    //T.C --> O((max-min + 1) * N), S.C --> O(1);  
    int n = bloomDay.size();

    //in case the number of flowers is less than the required 
    //number of flowers (i.e. m bouquets of K flowers each)
    if(n < 1LL * m * k)return -1;

    //determining the range in which ans lies
    int minDays = *min_element(bloomDay.begin(), bloomDay.end()); //to make atleast 1 flower bloom 
    int maxDays = *max_element(bloomDay.begin(), bloomDay.end());

    for(int i = minDays; i <= maxDays; i++)
    {
        if(isPossible(bloomDay, i, m, k))return i;
    }

    return -1;
}

int minDaysOptimal(vector<int>& bloomDay, int m, int k) {
    //Optimal Approach: since we can identify the range in which the ans lies
    //and the pattern of days is linerly increasing, we can apply the concept of
    //BINARY SEARCH On Answer
    //T.C --> O(log(max-min + 1) * N), S.C --> O(1);  
    int n = bloomDay.size();

    //in case the number of flowers is less than the required 
    //number of flowers (i.e. m bouquets of K flowers each)
    if(n < 1LL * m * k)return -1;

    //determining the range in which ans lies
    int minDays = *min_element(bloomDay.begin(), bloomDay.end()); //to make atleast 1 flower bloom 
    int maxDays = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;

    while(minDays <= maxDays)
    {
        int mid = minDays + (maxDays - minDays) / 2;

        if(isPossible(bloomDay, mid, m, k))
        {
            ans = mid;
            maxDays = mid - 1;
        }
        else
        {
            minDays = mid + 1;
        }
    }

    return ans;
}



int main()
{
    vector<int> bloomDays = {1,10,3,10,2};
    int m = 3, k = 1;

    cout<<minDaysBrute(bloomDays, m, k)<<"\n";
    cout<<minDaysOptimal(bloomDays, m, k);
    
    return 0;
}