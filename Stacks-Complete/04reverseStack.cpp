#include<iostream>
#include<stack>
using namespace std;
//time O(N^2), space O(N)
void transfer(stack<int> &s1, stack<int> &s2, int n){
    for(int i = 0; i<n; i++){
        s2.push(s1.top());
        s1.pop();
    }
}
void reverseStack(stack<int>&s1){
    //helper stack 
    stack<int> s2;
    int n = s1.size();
    for(int i = 0; i<n; i++){
        //pick the element at the top and insert it into the bottom
        int x = s1.top();
        s1.pop();

        //transfer n-i-1 element(s from s1 to s2
        transfer(s1,s2,n-i-1);
        //insert element x into s1
        s1.push(x);
        //again transfer back elements from s2 to s1
        transfer(s2,s1,n-i-1);
    }
}
int main()
{   
    stack<int> s;
    for(int i = 1; i<=5; i++){
        s.push(i);
    }
    reverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}