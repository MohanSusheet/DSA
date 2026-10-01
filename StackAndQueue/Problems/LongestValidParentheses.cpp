#include<iostream>
#include<vector>
#include<stack>

using namespace std;


bool isValid(string& s, int i, int j)
{
    int count = 0;

    while(i <= j)
    {
        if(s[i] == '(')count++;
        else count--;
        i++;
        //if at any point count turns -ve, means closing bracket appeared before opening.
        if(count < 0)return false;
    }

    return count == 0;
}
int longestValidParenthesesBrute(string s) {
    //Brute Force Approach: using 2 pointers(nested), defining the start and end
    //and checking whether that portion of the given string forms a valid paranthesis sequence
    //T.C --> O(N^3), S.C --> O(1)
    int n = s.size();
    int maxLen = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j+=2)
        {
            if(isValid(s, i, j))
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}

int longestValidParenthesesBetter(string s) {
    //Better Approach: using stack
    //T.C --> O(N), S.C --> O(N)
    int n = s.size();
    stack<int> st;
    st.push(-1);
    int maxLen = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }

    return maxLen;
}

int longestValidParenthesesOptimal(string s) {
    //Optimal Approach: Space Optimized approach.
    ///Traversing the string and identifying the portion valid portions using 2 Pointers
    //Left and Right. 
    //T.C --> O(2*N), S.C --> O(1)
    int n = s.size();
    int maxLen = 0;
    int left = 0, right = 0;

    for(int i = 0; i < n; i++) //iterating from left to right  
    {
        if(s[i] == '(')left++;
        else right++;

        if(left == right)
        {
            maxLen = max(maxLen, 2 * right);
        }
        else if(right > left)//invalid case, moving forward towards n, the substring till now is for sure invalid as ) is found befor (.
        {
            left = right = 0;
        }
    }
    
    left = right = 0;

    //iterating from left to right as the left to right iteration does not cover cases like
    //"(()" as the condition "left == right" never satisfies while iterating from left to right
    for(int i = n-1; i >= 0 ; i--)
    {
        if(s[i] == '(')left++;
        else right++;

        if(left == right)
        {
            maxLen = max(maxLen, 2 * right);
        }
        else if(left > right)//invalid case, moving towards 0, the substring till now is for sure invalid as "(" is found befor "("
        {
            left = right = 0;
        }
    }

    return maxLen;
}

int main()
{
    string s = ")()())";

    cout<<longestValidParenthesesBrute(s)<<"\n";

    cout<<longestValidParenthesesBetter(s)<<"\n";

    cout<<longestValidParenthesesOptimal(s)<<"\n";


    return 0;
}