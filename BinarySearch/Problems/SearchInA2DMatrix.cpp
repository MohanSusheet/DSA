#include<iostream>
#include<vector>

using namespace std;

bool searchMatrixBrute(vector<vector<int>>& nums, int target) {
    //Brute Force Approach: simple liner traversal visiting each and every cell.
    //T.C --> O(N*M), S.C --> O(1)

    int n = nums.size(), m = nums[0].size();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(nums[i][j] == target)return true;
        }
    }

    return false;
}


bool bs(vector<int>& nums, int size, int target)
{
    int low = 0, high = size - 1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(nums[mid] == target)return true;
        else if(nums[mid] < target)low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
bool searchMatrixBetter(vector<vector<int>>& nums, int target) {
    //Better Approach: iterating over the rows and applying Binary Search on row in which tha target may be present.
    //T.C --> O(N + logM), S.C --> O(1)

    int n = nums.size(), m = nums[0].size();

    for(int i = 0; i < n; i++)
    {
        if(nums[i][0] <= target && target <= nums[i][m-1])
        {
            return bs(nums[i], m, target); //executes only once
        }
    }

    return false;
}

bool searchMatrixOptimal(vector<vector<int>>& nums, int target) {
    //Optimal Approach: Applying binary search on hypothetically flattened matrix
    //Since the entire matrix is sorted in non-decreasing fashion binary search can be applied
    //be devising a method/formula to convert the linear index of an ele in hypothetically flattened to
    //2D index to map the element in the actual matrix
    //T.C --> O(log(n*m)), S.C --> O(1)

    int n = nums.size(), m = nums[0].size();

    int low = 0, high = (n * m) - 1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;  //mid index in the hypothetically flattened matrix array

        int row = mid / m;
        int col = mid %  m;

        if(nums[row][col] == target)return true;
        else if(nums[row][col] < target)low = mid + 1;
        else high = mid - 1;
    }

    return false;
}

int main()
{
    vector<vector<int>> nums = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    cout<<(searchMatrixBrute(nums, 30) ? "Target found." : "Target not found in the given matrix")<<"\n";
    
    cout<<(searchMatrixBetter(nums, 3) ? "Target found." : "Target not found in the given matrix")<<"\n";

    cout<<(searchMatrixOptimal(nums, 30) ? "Target found." : "Target not found in the given matrix");

    return 0;
}