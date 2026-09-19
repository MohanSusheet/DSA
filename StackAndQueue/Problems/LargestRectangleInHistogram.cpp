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

int main()
{
    vector<int>heights = {2,1,5,6,2,3};

    cout<<"MAx Area: "<<largestRectangleAreaBrute(heights);
    cout<<"MAx Area: "<<largestRectangleAreaBetter(heights);
    // cout<<"MAx Area: "<<largestRectangleInHistogramOptimal(heights);

    return 0;
}