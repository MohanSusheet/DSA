#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


string removeKdigits(string& num, int k)
{
    //Optimal Approach:
    //T.C --> O(3N) + O(K), S.C --> O(N)
    int n = num.size();
    if(n == k)return "0";

    stack<char> st;
    string res = "";

    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && k > 0 && st.top() - '0' > num[i] - '0')
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    while(k > 0)
    {
        st.pop();
        k--;
    }

    if(st.empty())return "0";

    //stack is now left with the desired output but in reverse order (may contain trailing zeroes)
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }

    //removing leading zeros from res if any. Since the res is being derived from the stack it is in reverse order
    //hence leading zeroes are current
    while(res.size() != 0 && res.back() == '0')
    {
        if(res.size() == 1)return "0"; //for cases such as "10", K=1 OR "100", K=2
        res.pop_back();
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    string num = "1432219";
    int k = 3;

    string ans = removeKdigits(num, k);
    for(int i = 0; i < ans.size(); i++)cout<<ans[i]<<" ";

    return 0;
}