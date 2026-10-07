#include<iostream>
#include<vector>
#include<climits>
#include<math.h>
#include<algorithm>

using namespace std;


long long calculateTimeTaken(vector<int>&p, double speed)
{
    long long time = 0;
    for(int i = 0; i < p.size(); i++)
    {
        //without explicit type conversion integer division takes place
        //returning integer value to ceil function instead of floating value
        time += (ceil((float)p[i] / speed));
    }
    return time;
}
int minEatingSpeedBrute(vector<int>& p, int h) {
    //Brute Force Approach: calculating time taken to eat banana 
    //with speed ranging from 1 to 1e9(max value of p[i] as per input contraints(which is not ideal))
    //T.C --> O(1e9 * N), S.C --> O(1)
    long long maxSpeed = 1e9;
    int ans = INT_MAX;

    for(int i = 1; i < maxSpeed; i++)
    {
        long long time = calculateTimeTaken(p, i);
        //cout<<"time: "<<time<<" @ speed: "<<i<<"\n";
        if(time <= h){
            ans = i;
            break;
        }
    }

    return ans;
}

int minEatingSpeedBetter(vector<int>& p, int h) {
    //Better Approach: calculating time taken to eat banana 
    //with speed ranging from 1 to max value of p[i]
    //T.C --> O(MaxVal(p) * N), S.C --> O(1)
    int maxSpeed = *max_element(p.begin(), p.end());
    int ans = INT_MAX;

    for(int i = 1; i <= maxSpeed; i++)
    {
        long long time = calculateTimeTaken(p, i);
        //cout<<"time: "<<time<<" @ speed: "<<i<<"\n";
        if(time <= h){
            ans = i;
            break;
        }
    }

    return ans;
}

int minEatingSpeedOptimal(vector<int>& p, int h) {
    //Optimal Approach: calculating time taken to eat banana 
    //with speed ranging from 1 to max value of p[i] but Applying the concept of Binary Search on Answer
    //T.C --> O(log(MaxVal(p)) * N), S.C --> O(1)
    int maxSpeed = *max_element(p.begin(), p.end()), minSpeed = 1;
    int ans = INT_MAX;

    while(minSpeed <= maxSpeed)
    {
        int mid = minSpeed + (maxSpeed -minSpeed) / 2;
        long long time = calculateTimeTaken(p, mid);
        //cout<<"time: "<<time<<" @ speed: "<<i<<"\n";
        if(time <= h)
        {
            ans = mid;
            maxSpeed = mid - 1;
        }
        else
        {
            minSpeed = mid + 1;
        }
    }

    return ans;
}


int main()
{
    vector<int> piles = {30,11,23,4,20};
    int h = 5;

    cout<<minEatingSpeedBrute(piles, h)<<"\n";
    cout<<minEatingSpeedBetter(piles, h)<<"\n";
    cout<<minEatingSpeedOptimal(piles, h)<<"\n";

    return 0;
}