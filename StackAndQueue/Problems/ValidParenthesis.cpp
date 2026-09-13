#include<iostream>
#include<stack>

using namespace std;

bool isValid(string s) {
    //T.C --> O(N), S.C --> O(N)[worst case]
    stack<char> st;
    int n = s.size();

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty())return false; //means we have encountered a closing bracket without any closing bracket in the stack.
            else if(st.top() == '{' && s[i] != '}')return false;
            else if(st.top() == '(' && s[i] != ')')return false;
            else if(st.top() == '[' && s[i] != ']')return false;
            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    /*
    An input string is valid if:

    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.
    3. Every close bracket has a corresponding open bracket of the same type.
    
    eg.  ()[{}()] --> valid, ()[{}(]) --> invalid, (() --> invalid
    */
    string s = "()[{}()";
    for(auto i: s)cout<<i;
    cout<<endl;
    cout<<isValid(s);

    return 0;
}