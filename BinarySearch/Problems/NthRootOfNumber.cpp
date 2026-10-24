#include<iostream>
#include<math.h>
using namespace std;


int calculateNthPower1(int i, int n)
{
    int ans = 1;
    
    while(n--)
    {
        ans *= i;
    }
    
    return ans;
}

int nthRootBrute(int n, int m) {
    //Brute Force Approach: linearly iterating in the search space to look for the ans
    //search space --> [1 to m(number itself)]
    //T.C --> O(NthRoot(M) * N) or O(NthRoot(M) * logN) [if pow() if used to calculate the power]
    //S.C --> O(1)
    
    
    for(int i = 0; i <= m; i++) //T.C of loop --> NthRoot(M)
    {
        int power = calculateNthPower1(i, n); //T.C --> O(N) or O(logN)
        
        if(power == m)return i;
        else if(power > m)break;
    }
    
    return -1;
}

int calculateNthPower2(int i, int n)
{
    return pow(i, n);
}
int nthRootOptimal(int n, int m) {
    //Optimal Approach: Binary Search on ans
    //search space --> [1 to m(number itself)]
    //T.C --> O(log(M) * N) or O(log(M) * logN) [if pow() if used to calculate the power]
    //S.C --> O(1)
    
    if(m == 0)return 0;
    
    int low = 1, high = m;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        int power = calculateNthPower2(mid, n);
        
        if(power == m)return mid;
        else if(power < m)low = mid + 1;
        else high = mid - 1;
    }
    
    return -1;
}


int main()
{
    int n = 3, m = 216;

    cout<<"Nth root of "<<m<<" is: "<<nthRootBrute(n, m)<<"\n";
    cout<<"Nth root of "<<m<<" is: "<<nthRootOptimal(n, m);

    return 0;
}