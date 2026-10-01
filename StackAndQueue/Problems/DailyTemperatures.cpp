#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void printArray(vector<int>&arr)
{
    for(int i: arr)
    {
        cout<<i<<" ";
    }
}

vector<int> dailyTemperaturesBrute(vector<int>& t) {
    //Brute Approach: using nested loop to determine the next greater temp for each day.
    //T.C --> O(N^2), S.C --> O(1)

    int n = t.size();
    vector<int> ans(n, 0);

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(t[j] > t[i])
            {
                ans[i] = j - i;
                break;
            }
        }
    }

    return ans;
}

vector<int> dailyTemperaturesOptimal(vector<int>& t) {
    //Optimal Approach: Using the concept of NGE(next greater element)
    //and stack to determine the NGE.
    //T.C --> O(2*N), S.C --> O(N)

    int n = t.size();
    stack<int> st;
    vector<int> ans(n, 0);

    for(int i = n-1; i >= 0; i--)
    {
        while(!st.empty() && t[st.top()] <= t[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? 0 : st.top() - i;
        st.push(i);
    }

    return ans;
}

int main()
{
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ans1 = dailyTemperaturesBrute(temperatures);
    printArray(ans1);
    cout<<endl;
    vector<int> ans2 = dailyTemperaturesOptimal(temperatures);
    printArray(ans2);

    return 0;
}