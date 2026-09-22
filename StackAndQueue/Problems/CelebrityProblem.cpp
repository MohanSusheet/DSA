#include<iostream>
#include<vector>

using namespace std;

int celebrityBrute(vector<vector<int>>& mat) {
    //Brute Force: iterating throught the matrix to determine who knows whom
    //keeping track of who knows whom using 2 vectors: knowsMe, iKnow
    //T.C --> O(N^2) + O(N)[iterating through the 2 vectors to find the final ans]
    //S.C --> O(2*N)

    int n = mat.size();
    if(n == 0)return 0;

    vector<int> knowsMe(n, 0), iKnow(n, 0);


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <n; j++)
        {
            if(i == j)continue;//diagonal entries to be neglected as every candidate know itself
            if(mat[i][j] == 1)
            {
                knowsMe[j]++;
                iKnow[i]++;
            }
        }
    }


    for(int i = 0; i < n; i++)
    {
        if(iKnow[i] == 0 && knowsMe[i] == n-1)return i;
    }

    return -1;
}

int celebrityOptimal(vector<vector<int>>& mat) {
    //Optimal Approach: using 2 pointers "top" and "bottom" and eliminating based on condition.
    //then at last, if top == bottom, making sure the row mat[top][j] is all "0" and col mat[i][top] is all "1"
    //T.C --> O(N) + O(2*N)[iterating through row and col for top == bottom]
    //S.C --> O(1)
    
    int n = mat.size();
    if(n == 0)return 0;
    
    int top = 0, bottom = n-1;
    
    while(top < bottom)
    {
        if(mat[top][bottom] == 1) //top fails to satisfy the celebrity condition
        {
            top = top + 1;
        }
        else if(mat[bottom][top] == 1) //bottom fails to satisfy the celebrity condition
        {
            bottom = bottom - 1;
        }
        else
        {
            top++; bottom--; //both fail to satisfy the celebrity condition
        }
    }
    
    if(top > bottom)return -1;
    
    for(int i = 0; i < n; i++)
    {
        if(top == i)continue;
        if(mat[top][i] == 1)return -1; //celebrity should not know anybody
        if(mat[i][top] == 0)return -1; //top should be known to everybody
    }
    
    return top;
}


int main()
{
    vector<vector<int>> mat = {{1, 1, 0},{0, 1, 0},{0, 1, 1}};

    cout<<celebrityBrute(mat)<<"\n";
    cout<<celebrityOptimal(mat);
    return 0;
}