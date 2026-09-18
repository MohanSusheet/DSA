#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void printArr(vector<int>&a)
{
    for(int i : a)cout<<i<<" ";
}

vector<int> asteroidCollision(vector<int>& a) {
    //Approach: Core intuition of using stack/list comes from the idea that whenever we encounter an asteroid
    //with -ve value we need the previous encountered element and we need to keep comparing the previous elements
    //we find an asteroid with value greater than the -ve one or until we have no more elements left
    //Hence, the idea for LIFO strikes.
    //T.C --> O(2N), S.C --> O(N)[stack] + O(N)[ans]
    int n = a.size();
    stack<int> st;

    for(int i = 0; i < n; i++)
    {
        if(a[i] > 0)
        {
            st.push(a[i]);
        }
        else
        {
            while(!st.empty() && st.top() > 0 && st.top() < abs(a[i]))
            {
                st.pop();
            }
            if(!st.empty() && st.top() == abs(a[i]))
            {
                st.pop();
            }
            else if(st.empty() || st.top() < 0)
            {
                st.push(a[i]);
            }
        }
    }

    int size = st.size();
    vector<int> ans(size);  //This step can be skipped if vector is used to play the role of stack

    for(int i = size - 1; i >= 0; i--)
    {
        ans[i] = st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    vector<int> asteroids = {3,5,-6,2,-1,4};

    vector<int>remains = asteroidCollision(asteroids);

    printArr(remains);

    return 0;
}