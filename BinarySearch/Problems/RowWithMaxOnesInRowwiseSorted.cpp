#include<iostream>
#include<vector>

using namespace std;


vector<int> rowWithMax1sBrute(vector<vector<int>>& mat) {
    //Brute Force Approach: iterating to each row and counting the number of 1s.
    //T.C --> O(N*M) [N -> Rows, M -> Cols], S.C --> O(1)
    int n = mat.size(), m = mat[0].size();

    int rowInd = 0, maxCount = 0;

    for(int i = 0; i < n; i++)
    {
        int count = 0;
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] == 1)count++;
        }
        if(count > maxCount)
        {
            rowInd = i;
            maxCount = count;
        }
    }

    return {rowInd, maxCount};
}

int lowerBound(vector<int>&arr, int m, int target)
{
    int low = 0, high = m - 1;
    int lb = m;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
    
        if(arr[mid] >= target)
        {
            lb = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    
    return lb;
}

vector<int> rowWithMax1sOptimal(vector<vector<int>> &mat) {
    //Optimal Approach: iterating to each row and counting the number of 1s using the concept of 
    //Lower Bound (to find the first index where 1 occurs).
    //The appraoch works as each row of the given matrix is sorted.
    //T.C --> O(N*logM) [N -> Rows, M -> Cols], S.C --> O(1)
    int n = mat.size(), m = mat[0].size();

    int rowInd = -1, maxCount = 0;

    for(int i = 0; i < n; i++)
    {
        int count = m - lowerBound(mat[i], m, 1); //or upperBound(0) or firstOccurance(1);
        // cout<<"Count for "<<i<<"th row is: "<<count<<"\n";
        if(count > maxCount)
        {
            rowInd = i;
            maxCount = count;
        }
    }

    return {rowInd, maxCount};
}

int main()
{
    vector<vector<int>> nums = {{0,1,1,1},{0,0,1,1},{1,1,1,1}};

    vector<int>ans = rowWithMax1sBrute(nums);
    cout<<"The row index with max 1s is: "<<ans[0]<<" and the count is: "<<ans[1]<<"\n";

    nums = {{0}};
    ans = rowWithMax1sOptimal(nums);
    cout<<"The row index with max 1s is: "<<ans[0]<<" and the count is: "<<ans[1]<<"\n";

    return 0;
}