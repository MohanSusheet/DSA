#include<iostream>
#include<vector>

using namespace std;

int mySqrtBrute(int x) {
    //Brute Force using linear seach
    //T.C --> O(sqrt(N)), S.C --> O(1)

    int ans = 0;

    for(int i = 1; i <= x; i++)
    {
        if(1LL*i * i <= x)
        {
            ans = i;
        }
        else break;
    }

    return ans;
}

int mySqrtOptimal(int x) {
    //Optimal Appraoch: using Binary search on answer
    //For Scenarios where my desired output is limited to a certain extent and i am sure that
    //it won't be found beyond that certain point, "BINARY SEARCH ON ANSWER" concept is always applicable in those scenarios    
    //T.C --> O(logN), S.C --> O(1)

    int ans = 0;

    int low = 0, high = x;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(1LL * mid * mid <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }

    return ans;
}

int main()
{
    int x = 98;

    cout<<"Square Root of "<<x<<" is: "<<mySqrtBrute(x)<<"\n";
    cout<<"Square Root of "<<x<<" is: "<<mySqrtOptimal(x);

    return 0;
}