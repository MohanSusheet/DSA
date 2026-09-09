#include<iostream>

using namespace std;

/* 
Date : 08-09-2026
PROBLEM STATEMENT

You are given an integer n.
Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.
In standard formatting:
- A comma is inserted after every three digits from the right.
- Numbers with fewer than 4 digits contain no commas.

Constraints:  1 <= n <= 105
*/

int countCommas(int n)
{
    int ans = 0;

    return max(0, n - 999);
}

int main()
{
    int n = 1000;

    cout<<"Commas used to represent all number 1 to n : "<<countCommas(n);

    return 0;
}