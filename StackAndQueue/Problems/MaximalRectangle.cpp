#include<iostream>
#include<vector>
#include<stack>

using namespace std;


int largestRectangleArea(vector<int>& h) {
    //Optimal Approach: Determining pse and nse for all the elements on the fly.
    //using a stack that maintains an increasing order (basically a monotonic stack)
    //T.C --> O(N[traversal] + N[stack pops]) ~~ O(2N), S.C --> O(N)

    int n = h.size(), maxArea = 0;
    stack<int> st; // will store indices

    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && h[st.top()] > h[i])
        {
            int ele = st.top();  //element for which area will be calculated
            //as nse for ele is "i" and pse is the next top element in the stack
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top(); //pse is the next top element in the stack
            maxArea = max(maxArea, (h[ele] * (nse - pse - 1)));
        }
        st.push(i);
    }

    //at last we need to calculate the area for elements that either don't have nse or pse.
    //As our above logic did not consider -1 as pse and n as nse for elements
    while(!st.empty())
    {
        int nse = n;
        int ele = st.top();
        st.pop();
        int pse = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, (h[ele] * (nse - pse - 1)));
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>>& m) {
    int rows = m.size(), cols = m[0].size(), maxArea = 0;

    vector<vector<int>> preSum(rows, vector<int>(cols, 0));

    for(int j = 0; j < cols; j++) //we are calculatig the pre sum column wise. converting into height
    {
        int sum = 0;
        for(int i = 0; i < rows; i++)
        {
            sum += 1;
            if(m[i][j] == '0')sum = 0; //as the height breaks at this point
            // cout<<"i = "<<i<<" & j = "<<j<<" & sum = "<<sum<<"\n";
            preSum[i][j] = sum;
        }
    }

    for(int i = 0; i < rows; i++)
    {
        maxArea = max(maxArea, largestRectangleArea(preSum[i]));
        // cout<<maxArea<<"\n";
    }

    return maxArea;
    //Overall T.C --> O(R * C)[prefixSum] + O(R * 2C[largestRectangleArea])
    //Overall S.C --> O(R * C)[prefixSum] + O(C)[largestRectangleArea]
}


int main()
{
    vector<vector<char>> matrix = 
    {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    int maxArea = maximalRectangle(matrix);
    cout<<"Max Area : "<<maxArea;

    return 0;
}