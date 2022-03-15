//implementation of stack class using vectors
/*
Functionalities in stack class:
    1. Insertion(push)
    2. pop
    3. Top - will give the top most element of stack
    4. isEmpty() - will check if the stack is empty or not
*/
#include<iostream>
#include<vector>
using namespace std;

class Stack{
private:
    //v declared in private such that entire stack elements could not be accessed. 
    //only access point will be top
    vector<int> v;
public:
    void push(int d){
        v.push_back(d);
    }
    bool isEmpty(){
        return v.size()==0;
    }
    void pop(){
        if(!isEmpty()){
            v.pop_back();
        }
    }
    int top(){
        return v[v.size()-1];
    }
};
int main()
{
    Stack s;
    for(int i = 1; i<=5; i++){
        s.push(i);
    }
    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}