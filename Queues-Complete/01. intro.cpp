#include<iostream>
using namespace std;
class Queue{
    int *arr;
    int f,r,cs,ms; //front , rear, curr_size, max_size

public:
    Queue(int ds = 5){
        arr = new int[ds];
        cs = 0; // current size of Q is 0
        ms = ds; // max size = default size passed by user
        f = 0; // in begining, front points to 0th index
        r = ms-1; // in begining, rear points to n-1 index
    }
    bool isFull(){
        return cs == ms; // will return true if curr size is equal to max size
    }
    bool isEmpty(){
        return cs==0;
    }
    void push(int data){   
        if(!isFull()){
            r = (r+1)%ms;
            arr[r] = data;
            cs++;
        }
    }
    void pop(){
        if(!isEmpty())    {
            f = (f+1)%ms;
            cs--;
        }
    }
    int front(){
        if(!isEmpty()){
            return arr[f];
        }
        return -1; // return -1 if the stack is empty       
    }
    ~Queue(){
        if(arr != NULL){
            delete [] arr; // this will delete the heap memory not the arr variable
            arr = NULL;
        }
    }

};
int main()
{
    Queue q;
    for(int i = 1;i<=6; i++){
        q.push(i);
    }
    q.pop();
    q.pop();

    q.push(7);
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}