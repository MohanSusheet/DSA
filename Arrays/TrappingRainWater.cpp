#include<iostream>
#include<vector>

using namespace std;

int trapBrute(vector<int> &h)
{
    //Brute Force Approch: Traversing through the vector and determining the leftMax and rightMax wall 
    //using nested loop "j" and "k" for each index "i"
    //T.C -->O(N^2), S.C --> O(1)

    int n = h.size();
    int totalVol = 0;

    for(int i = 0; i < n; i++)
    {
        int curVol = 0;

        int leftMax = h[0], rightMax = h[n-1];
        for(int j = 1; j <= i; j++)
        {
            leftMax = max(leftMax, h[j]);
        }
        for(int k = n-2; k >= i; k--)
        {
            rightMax = max(rightMax, h[k]);
        }

        curVol = min(leftMax, rightMax) - h[i];
        totalVol += curVol;
    }

    return totalVol;
}

int trapBetter(vector<int> &height)
{
    //Optimal Approach: using 2 vectors to keep track of leftMax wall and rightMax wall for each index "i"
    //T.C --> O(N), S.C --> O(2N)
    int n = height.size(), water = 0;
    vector<int> lmax(n, 0);
    vector<int> rmax(n, 0);

    lmax[0] = height[0];
    rmax[n-1] = height[n-1];

    for(int i = 1; i < n; i++)
    {
        lmax[i] = max(lmax[i-1], height[i]);
    }

    for(int j = n-2; j >= 0; j--)
    {
        rmax[j] = max(rmax[j+1], height[j]);
    }

    for(int i = 0; i < n; i++)
    {
        water = water + (min(lmax[i], rmax[i]) - height[i]);
    }

    return water; // Return the total trapped water
}

int trapOptimal(vector<int>& arr) {
    //Most Optimal Approach: Using 2 pointers left and right and lMax and rMax to 
    //keep track of left and right maximums respectively
    //T.C --> O(N), S.C --> O(1)

    int n = arr.size();
    int lmax = 0, rmax = 0, l = 0, r = n-1, total = 0;

    while(l < r)
    {
        if(arr[l] <= arr[r])
        {
            if(lmax > arr[l])
            {
                total += (lmax - arr[l]);
            }
            else
            {
                lmax = arr[l];
            }
            l++;
        }
        else
        {
            if(rmax > arr[r])
            {
                total += (rmax - arr[r]);
            }
            else
            {
                rmax = arr[r];
            }
            r--;
        }
    }
    return total;
}

int main()
{
    vector<int> height = {4,2,0,3,2,5};

    cout<<"Water Trapperd: "<<trapBrute(height)<<" units.\n";

    cout<<"Water Trapperd: "<<trapBetter(height)<<" units.\n";

    cout<<"Water Trapperd: "<<trapOptimal(height)<<" units.\n";\

    return 0;
}