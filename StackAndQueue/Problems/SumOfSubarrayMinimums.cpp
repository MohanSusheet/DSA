#include<iostream>
#include<vector>
#include<climits>
#include<stack>

using namespace std;

int sumSubarrayMinsBrute(vector<int>&arr)
{
    int n = arr.size(), ans = 0;

    for(int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        for(int j = i; j < n; j++)
        {
            mini = min(mini, arr[j]);
            ans += mini;
        }
    }

    return ans;
}

int mod = 1e9+7;

vector<int> findNextSmallerElemet(vector<int>&arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int>ans(n, n);  //initializing with 'n' when there is no NSE for the given element, so 'n' instead of -1 helps calculate the indices in the main code.
    //as we are storing the index at which the next smaller element is found for each element.

    for(int i = n-1; i>= 0; i--)
    {
        while(!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    
    return ans;
}

vector<int> findPrevSmallerOrEqualElemet(vector<int>&arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int>ans(n, 0);  //initializing with 'n' when there is no NSE for the given element, so 'n' instead of -1 helps calculate the indices in the main code.
    //as we are storing the index at which the next smaller element is found for each element.

    for(int i = 0; i < n; i++)
    {
        //arr[st.top()] ">" arr[i] and not arr[st.top()] ">=" arr[i] beacuse of edge cases like arr = [1, 1]
        while(!st.empty() && arr[st.top()] > arr[i]) //hence looking for smller or equal
        {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    return ans;
}

int sumSubarrayMinsOptimal(vector<int>& arr) {
    //Optimal Approach: Core idea is to calculate the number of subarrays in which the "ith"(cuurent) element will be the minimum element. 
    //Hence, the total contribution of that element in the answer will be (no. of subarrays in which it is minimum) * (its value)
    int n = arr.size(), ans = 0;
    vector<int> nse = findNextSmallerElemet(arr);//T.C-->O(2N), S.C-->O(2N)
    vector<int> psee = findPrevSmallerOrEqualElemet(arr);//T.C-->O(2N), S.C-->O(2N)

    for(int i = 0; i < n; i++)  //T.C-->O(N) 
    {
        int left = i - psee[i];
        int right = nse[i] - i;

        ans = (ans + ((left * right * 1LL * arr[i]) % mod)) % mod;
    }
    
    //Overall T.C --> O(5N), S.C --> O(4N)
    return ans;
}

int main()
{
    vector<int> arr = {3,1,2,4};

    cout<<sumSubarrayMinsBrute(arr)<<"\n";
    cout<<sumSubarrayMinsOptimal(arr);

    return 0;
}