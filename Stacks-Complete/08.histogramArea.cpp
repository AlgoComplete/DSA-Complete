/*
Algo: Given arr that is heights of histograms
1.Find NSR index array
2.Find NSL index aray
3.Find width array, width[i] = NSR[i]-NSL[i]-1
4.Find area array, area[i] = width[i]*arr[i];
5.Return max element in the area array.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
vector<int> findNSR(vector<int> v){
    int psuedoIdx = v.size();
    stack<pair<int,int>> s;
    vector<int> left;
    for(int i = v.size()-1; i>=0; i--){
        if(s.empty()){
            left.push_back(psuedoIdx);
        }
        else if(!s.empty() and s.top().first<v[i]){
            left.push_back(s.top().second);
        }
        else if(!s.empty() and s.top().first>=v[i]){
            while(s.size()>0 and s.top().first>=v[i]){
                s.pop();
            }
            if(s.size()==0){
                left.push_back(psuedoIdx);
            }
            else{
                left.push_back(s.top().second);
            }
        }
        s.push({v[i],i});

    }
    reverse(left.begin(), left.end());
    return left;
}
vector<int> findNSL(vector<int> v){
    int psuedoIdx = -1;
    stack<pair<int,int>> s;
    vector<int> right;
    for(int i = 0; i<v.size(); i++){
        if(s.empty()){
            right.push_back(psuedoIdx);
        }
        else if(!s.empty() and s.top().first<v[i]){
            right.push_back(s.top().second);
        }
        else if(!s.empty() and s.top().first>=v[i]){
            while(s.size()>0 and s.top().first>=v[i]){
                s.pop();
            }
            if(s.size()==0){
                right.push_back(psuedoIdx);
            }
            else{
                right.push_back(s.top().second);
            }
        }
        s.push({v[i],i});

    }
    return right;
}
int maxAreaHist(vector<int> v){
    vector<int> left = findNSL(v);
    vector<int> right = findNSR(v);
    vector<int> width;
    vector<int> area;
    for(int i = 0; i<v.size(); i++){
        width.push_back(right[i]-left[i]-1);
        area.push_back(width[i]*v[i]);
    }
    return *max_element(area.begin(), area.end());
}
int main()
{
    //vector<int> v = {10,8,6,7,6,8,9}; ans = 42
    vector<int> v = {6,2,5,4,5,1,6};
    
	cout<<maxAreaHist(v)<<endl;
	return 0;
}