//earlier we made a class which can create stack of only integers
//but we should be able to make stack for all datatypes, therefore we will generalize it for all types
//this generalization in cpp is done using templates

#include<iostream>
#include<vector>
using namespace std;

template<typename T> // T is the general type

class Stack{
private:
    //v declared in private such that entire stack elements could not be accessed. 
    //only access point will be top
    vector<T> v;
public:
    void push(T d){
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
    T top(){
        return v[v.size()-1];
    }
};
//by this method we can also create stack of user defined dataypes i.e. stack of books, stack of breads,
//stack of plats, etc
int main()
{
    //Stack<T> s;
    Stack<int> s;
    for(int i = 1; i<=5; i++){
        s.push(i);
    }
    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    Stack<char> x;

    for(int i = 65; i<=70; i++){
        x.push(i);
    }
    while(!x.isEmpty()){
        cout<<x.top()<<endl;
        x.pop();
    }

    return 0;
}