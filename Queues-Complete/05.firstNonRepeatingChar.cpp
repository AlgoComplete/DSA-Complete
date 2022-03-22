/*
i/p = a  a b c c  b  c  d
o/p = a -1 b b b -1 -1  d
For every char, output the first non repeating char
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{   
    queue<char> q;
    int freq[27] = {0};//a's freq will get stored in 0th index and z in 25th index
    //take running stream as input untill a '.'
    char ch;
    cin>>ch;

    while(ch!='.'){
        //insert char in the queue and freq table
        q.push(ch);
        freq[ch-'a']++; // increase the freq by one at req index
        
        //now check the front
        while(!q.empty()){
            int idx = q.front() - 'a';
            if(freq[idx] > 1){
                q.pop();
            }
            else{
                cout<<q.front()<<" ";
                break;
            }

        }
        //q is empty
        if(q.empty()) cout<<-1<<" ";
        cin>>ch;
    }
    cout<<endl;
    return 0;
}