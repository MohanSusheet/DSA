#include<iostream>
#include<vector>
#include<stack>

using namespace std;


int largestRectangleAreaBrute(vector<int>& h) {
    //Brute Force Approach: finding  the prev smaller and next smaller indices
    //for every element using nested loop and calcluating the current area
    //T.C --> O(N^2), S.C --> O(1)

    int n = h.size(), area = 0;

    for(int i = 0; i < n; i++)
    {
        int left = 0, right = n-1;
        for(int j = i - 1; j >= 0; j--)
        {
            if(h[j] < h[i])
            {
                left = j+1;
                break;
            }
        }
        for(int j = i + 1; j < n; j++)
        {
            if(h[j] < h[i])
            {
                right = j-1;
                break;
            }
        }
        area = max(area, (h[i] * (right - left + 1)));
    }

    return area;
}


vector<int> prevSmallerElements(vector<int>&h)
{
    int n = h.size();
    stack<int> st;
    vector<int> pse(n, -1);

    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && h[st.top()] >= h[i])st.pop();

        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return pse;
}

vector<int> nextSmallerElements(vector<int>&h)
{
    int n = h.size();
    stack<int> st;
    vector<int> nse(n, -1);

    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && h[st.top()] >= h[i])st.pop();

        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return nse;
}

int largestRectangleAreaBetter(vector<int>& h) {
    //Better Approach: precalculate pse and nse using stack and calculate the area.
    //T.C --> O(2N), S.C --> O(1)

    int n = h.size(), area = 0;

    vector<int> pse = prevSmallerElements(h);
    vector<int> nse = nextSmallerElements(h);

    for(int i = 0; i < n; i++)
    {
        area = max(area, (h[i] * (nse[i] - pse[i] - 1)));
    }

    return area;
}

int largestRectangleAreaOptimal(vector<int>& h) {
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

int main()
{
    vector<int>heights = {3, 2, 10, 11, 5, 10, 6, 3};

    cout<<"MAx Area: "<<largestRectangleAreaBrute(heights)<<"\n";
    cout<<"MAx Area: "<<largestRectangleAreaBetter(heights)<<"\n";
    cout<<"MAx Area: "<<largestRectangleAreaOptimal(heights);

    return 0;
}