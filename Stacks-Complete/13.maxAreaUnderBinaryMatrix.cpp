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

int maxAreaMatrix(int arr[][100], int m, int n){
    vector<int> v;
    int ans;
    //first row
    for(int j = 0; j<n; j++){
        v.push_back(arr[0][j]);
    }
    ans = maxAreaHist(v);

    //loop for second row to last
    for(int i = 1; i<m; i++){
        for(int j = 0; j<n; j++){
            if(arr[i][j] == 0){
                v[j] = 0;
            }
            else{
                v[j] = v[j] + arr[i][j];
            }
        }
        ans = max(ans,maxAreaHist(v));
    }
    return ans;
}
int main()
{   
    int arr[100][100];
    int m,n;

    cin>>m>>n;

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<maxAreaMatrix(arr,m,n)<<endl;

    return 0;
}