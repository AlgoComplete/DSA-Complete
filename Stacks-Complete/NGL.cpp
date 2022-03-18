//nearest greater element to right 
/*
Traverse from left to right
push -1 if stack.empty()

push top() if arr[i] < s.top()

pop() untill arr[i] < s.top()

*/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> solve(vector<int> v){
    stack<int> s;
    vector<int> ans;
    for(int i = 0; i<v.size(); i++){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(!s.empty() and s.top()>v[i]){
            ans.push_back(s.top());
        }
        else if(!s.empty() and s.top()<=v[i]){
            while(s.size()>0 and s.top()<=v[i]){
                s.pop();
            }
            if(s.size()==0){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
        }
        s.push(v[i]);

    }
    return ans;
}
int main()
{
    vector<int> v = {1,3,2,4};
    vector<int> ans;
    ans = solve(v);
    for(int x: ans){
        cout<<x<<", ";
    }
    cout<<endl;    
    return 0;
}