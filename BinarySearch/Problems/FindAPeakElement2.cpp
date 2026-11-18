#include<iostream>
#include<vector>

using namespace std;

vector<int> findPeakGridBrute(vector<vector<int>>& mat) {
    //Brute Force Approach: simple iterating the matrix and return any element that
    //stisfies the "peak element" definition.
    //T.C --> O(n*m), S.C --> O(1)

    int n = mat.size(), m = mat[0].size();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int left = j - 1 >= 0 ? mat[i][j-1] : -1;
            int right = j + 1 < m ? mat[i][j+1] : -1;
            int bottom = i + 1 < n ? mat[i+1][j] : -1;
            int top = i - 1 >= 0 ? mat[i-1][j] : -1;

            if(mat[i][j] > left && mat[i][j] > right && mat[i][j] > top && mat[i][j] > bottom)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int findRowMax(vector<vector<int>>&mat, int n, int col)
{
    int maxEle = -1, maxEleInd = -1;

    for(int i = 0; i < n; i++)
    {
        if(mat[i][col] > maxEle)
        {
            maxEle = mat[i][col];
            maxEleInd = i;
        }
    }
    return maxEleInd;
}
vector<int> findPeakGridOptimal(vector<vector<int>>& mat) {
    //Optimal Approach: Applying binary search on matrix Columns, determining the peak
    //element candidate among "mid" column element (max ele among them)
    //Then, eliminating left or right portion of the matrix based on "peak element conditions"
    //utilizing the concept of PEAK ELEMENT 1. (graphical representation)
    //T.C --> O(log(m * n)), S.C --> O(1)

    int n = mat.size(), m = mat[0].size();
    int low = 0, high = m - 1, maxEle = -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int rowMaxInd = findRowMax(mat, n, mid);

        int left = mid - 1 >= 0 ? mat[rowMaxInd][mid-1] : -1;
        int right = mid + 1 < m ? mat[rowMaxInd][mid+1] : -1;

        //only compared to left and right element
        //"findRowMax" make the comparison to top and bottom elements Obviated
        if(mat[rowMaxInd][mid] > left && mat[rowMaxInd][mid] > right)
        {
            return {rowMaxInd, mid};
        }
        else if(mat[rowMaxInd][mid] < left)
        {
            high = mid -1;
        }
        else low = mid + 1;
    }

    return {-1, -1};
}

int main()
{
    vector<vector<int>> nums = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};

    vector<int> ans;

    ans = findPeakGridBrute(nums);
    cout<<"Peak element present at row: "<<ans[0]<<" & col: "<<ans[1]<<"\n";

    ans = findPeakGridOptimal(nums);
    cout<<"Peak element present at row: "<<ans[0]<<" & col: "<<ans[1];

    return 0;
}