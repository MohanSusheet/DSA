#include<iostream>
#include<vector>
#include<queue>


using namespace std;

double minMaxDistBrute(vector<int> &stations, int k) {
    //Brute Force Approach:
    //T.C --> O(K * N) + O(N), S.C --> O(N-1)
    int n = stations.size();
    
    vector<int>howMany(n-1, 0); //keeps the track of how many gas stations have been placed
    //between the sections. sections = n - 1 [i.e. the gaps btween the gasStations]
    
    for(int gasStations = 0; gasStations < k; gasStations++)
    {
        long double maxValue = -1; //refers to max distance between 2 gas stations.
        int maxInd = -1; //refers to the section/gap index between those two gas in "howMany" vector
        
        for(int i = 0; i < n - 1; i++)
        {
            long double difference = stations[i+1] - stations[i];
            long double sectionLength = difference / (long double)(howMany[i] + 1);
            
            if(sectionLength > maxValue)
            {
                maxValue = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++; //means at "maxInd" index () there was maximum distance betwwen
        //given gas stations, so we will place current gasStation in btween those 2.
    }
    
    long double ans = -1;
    
    for(int i = 0; i < n-1; i++)
    {
        long double sectionLen = (stations[i+1] - stations[i]) / (long double)(howMany[i]+1);
        ans = max(ans, sectionLen);
    }
    
    return ans;
    
}

double minMaxDistBetter(vector<int>  &stations, int k)
{
    //Better Approach:
    //T.C --> O(K * LogN), S.C --> O(N-1)
    int n = stations.size();
    vector<int> howMany(n-1, 0);
    priority_queue<pair<long double, int>> pq;

    for(int i = 0; i < n - 1; i++)
    {
        long double difference = stations[i+1] - stations[i];
        pq.push({difference, i});
    }

    for(int i = 0; i < k; i++)
    {
        int sectionIndex = pq.top().second;
        pq.pop();
        
        howMany[sectionIndex]++; //placing the gas station first in the current section
        
        //then update the track of max Distance between stations.
        
        //original distance betweent the gas station is calculated. "largestDiff = pq.top().first" gives the already reduced distance
        long double largestDiff = stations[sectionIndex + 1] - stations[sectionIndex];
        pq.push({largestDiff / (long double)(howMany[sectionIndex] + 1), sectionIndex});
    }

    return pq.top().first;
}

int gasStationsRequired(vector<int>&stations, long double dist)
{
    int n = stations.size();
    
    int gasStationsReq = 0;
    
    for(int i = 0; i < n-1; i++)
    {
        int numberInBetween = (stations[i+1] - stations[i]) / dist;
        if(((stations[i+1] - stations[i]) / dist) == (numberInBetween * dist))
        {
            numberInBetween--;
        }
        gasStationsReq += numberInBetween;
    }
    return gasStationsReq;
}

double minMaxDistOptimal(vector<int> &stations, int k) {
    //Optimal Approach:
    //T.C --> O(N * logN) + (N), S.C --> O(1)
    int n = stations.size();
    
    long double low = 0, high = 0;
    
    for(int i = 0; i < n- 1; i++)
    {
        high = max(high, (long double)(stations[i+1] - stations[i]));
    }
    
    long double diff = 1e-6;
    
    while(high - low > diff)
    {
        long double mid = (low + high) / 2.0;
        
        if(gasStationsRequired(stations, mid) > k)
        {
            low = mid;
        }
        else
        {
            // ans = high;
            high = mid;
        }
    }
    
    return high;
}

int main()
{
    vector<int> nums = {3, 6, 12, 19, 33};
    int k = 3;

    cout<<"Minimum max possible distance between adjacent gas stations is: "<<minMaxDistBrute(nums, k)<<"\n";
    cout<<"Minimum max possible distance between adjacent gas stations is: "<<minMaxDistBetter(nums, k)<<"\n";
    cout<<"Minimum max possible distance between adjacent gas stations is: "<<minMaxDistOptimal(nums, k)<<"\n";

    return 0;
}