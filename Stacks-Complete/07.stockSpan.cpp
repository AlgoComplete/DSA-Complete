//better thinking approach for stock span problem 
// this question is a little extension of Nearest Greater to Left Question

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> solve(vector<int> vec){
    vector<int> v;
    stack<pair<int,int>> s;

    for(int i = 0; i < vec.size(); i++){
        if(s.empty()){
            v.push_back(-1);
        }
        else if(vec[i] < s.top().first){
            v.push_back(s.top().second);
        }
        else if(vec[i] >= s.top().first){
            while(!s.empty() and vec[i] >= s.top().first){
                s.pop();
            }
            if(s.empty()){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top().second);
            }
        }
        //pair<int,int> p;
        //p.first = vec[i];
        //p.second = i;
        s.push({vec[i],i});
    }
    for(int i = 0; i<v.size(); i++){
        v[i] = i - v[i];
    }
    return v;
}
using namespace std;
int main()
{
    vector<int> v = {100,80,60,70,60,75,85};
	vector<int> ans = solve(v);
	for(int x : ans) cout<<x<<" ";
	cout<<endl;
	return 0;
}