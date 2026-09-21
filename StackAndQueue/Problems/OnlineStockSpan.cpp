#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class StockSpannerBrute {
    vector<int>prices;
public:
    StockSpannerBrute() {
        prices = {};
    }
    
    int next(int price) {
        //Brute Force Approach: calculating the number of days using nested loop for given price
        //T.C --> O(N^2), S.C --> O(1)
        prices.push_back(price);
        int n = prices.size();
        
        int days = 1;

        for(int i = n - 2; i >= 0; i--)
        {
            if(prices[i] <= price)days++;
            else break;
        }

        return days;
    }
};


class StockSpannerBetter {
    vector<int> prices;
    stack<int> st;
    int index;
public:
    StockSpannerBetter() {
        prices = {};
        st = stack<int>();
        index = -1;
    }
    
    int next(int price) {
        //Better Approach: using monotonic stack and pge(prev greater element concept)
        //***In optimal approach, get rid of the vector, in the stack itself store <price, ind>
        //T.C --> O(2N), S.C --> O(N[vector] +N[stack]) 
        // int n = prices.size(); //use a class variable index, instead of calculating the size every time
        index = index + 1;
        prices.push_back(price);

        while(!st.empty() && prices[st.top()] <= price)
        {
            st.pop();
        }
        int pge = st.empty() ? -1 : st.top();
        st.push(index); //pushing the index[acc. to prices vector] current price in the stack. 
        int ans = index - pge;

        return ans;
    }
};

class StockSpannerOptimal {
    //vector<int> prices;
    stack<pair<int,int>> st;
    int index;
public:
    StockSpannerOptimal() {
        st = stack<pair<int,int>>();
        index = -1;
    }
    
    int next(int price) {
        //Better Approach: using monotonic stack and pge(prev greater element concept)
        //***In optimal approach, get rid of the vector, in the stack itself store <price, ind>
        //T.C --> O(2N), S.C --> O(N[stack]) 
        // int n = prices.size(); //use a class variable index, instead of calculating the size every time
        index = index + 1;

        while(!st.empty() && st.top().first <= price)
        {
            st.pop();
        }
        int pge = st.empty() ? -1 : st.top().second;
        st.push({price,index}); //pushing the index[acc. to prices vector] current price in the stack. 
        int ans = index - pge;

        return ans;
    }
};


int main()
{
    StockSpannerBrute s1;
    StockSpannerBetter s2;
    StockSpannerOptimal s3;

    cout<<s1.next(100); // return 1
    cout<<s1.next(80);  // return 1
    cout<<s1.next(60);  // return 1
    cout<<s1.next(70);  // return 2
    cout<<s1.next(60);  // return 1
    cout<<s1.next(75)<<"\n"; //return 4

    
    cout<<s2.next(100);
    cout<<s2.next(80);
    cout<<s2.next(60);
    cout<<s2.next(70);
    cout<<s2.next(60);
    cout<<s2.next(75)<<"\n";

    cout<<s3.next(100);
    cout<<s3.next(80);
    cout<<s3.next(60);
    cout<<s3.next(70);
    cout<<s3.next(60);
    cout<<s3.next(75);

    return 0;
}