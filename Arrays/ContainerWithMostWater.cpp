#include<iostream>
#include<vector>

using namespace std;

int maxAreaBrute(vector<int>&h)
{
    //Brute Forcer Approach: Using nested loop to calculate the maximum area between aur possible 2 points
    //T.C --> O(N^2), S.C --> O(1)

    int ans = 0, n = h.size();

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            ans = max(ans, min(h[i], h[j]) * (j - i));
        }
    }

    return ans;
}

int maxAreaOptimal(vector<int>& h) {
    //Optimal Approach: Using 2 pointers left and right the maximum area between aur possible 2 points.
    //A = W * H. while moving the 2 pointers towards each other
    //the "W" is decreasing and in order to get the "A" max, "H"should increase. Hence we move the 2 pointers conditionally.
    //T.C --> O(N), S.C --> O(1)

    int ans = 0, n = h.size(), i = 0, j = n - 1;

    while(i < j)
    {
        ans = max(ans, min(h[i], h[j]) * (j - i));
        
        if(h[i] < h[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return ans;
}

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout<<"Maximum water contained: "<<maxAreaBrute(height)<<" units.\n";
    cout<<"Maximum water contained: "<<maxAreaOptimal(height)<<" units.";

    return 0;
}