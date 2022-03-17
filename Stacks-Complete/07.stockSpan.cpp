#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
Q- Given a list of a stock prices for n days.
Find the span of stock for each day.

Span - Span of a stock means the number of days for which 
        the current price is highest.

Efficient approach - using stack.

1. Push each stock price along with day number that starts with 0 inside the stack
2. If ith price is higher than the top(), remove top() elements until 
    ith price is lower than top.
3. Calculate: i(day number) of current stock - i of top, which will be the required span
4. If stack is empty and there still needs a price to be pushed
    this means it is the highest price that is at the last day
    , so for this span will be i+1
*/

vector<int> findStockSpans(vector<int> prices){
    stack<pair<int,int>> s; // we will store i that is day number, price of stock in each section of stack
    vector<int> spans;// for storing answers
    pair<int,int> p;
    p.first = 0;
    p.second = prices[0];
    s.push(p);
    spans.push_back(1);

    for(int i = 1; i<prices.size(); i++){
        if(s.empty()){
            spans.push_back(i+1);
            return spans;
        }
        
        p.first = i;
        p.second = prices[i];

        if(prices[i] < s.top().second){
            spans.push_back(i-s.top().first);
            s.push(p);
        }
        else{
            while(prices[i] >= s.top().second){
                s.pop();
            }
            i--;
        }
    }
    return spans;
}

int main(){

    //vector<int> prices{100,80,60,70,60,75,85};
    vector<int> prices{31, 27, 14, 21, 30, 22};
    vector<int> span = findStockSpans(prices);
    for(int x : span){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}