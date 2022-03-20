/*
-> 	we can not apply binary search in linked lists even if they are sorted, because??
->	Finding the middle element in the LL will only take O(n) time.
->	In arrays we have a property that arrays can be directly access (Direct Access) i.e. Arr[i] can be found
->	therefore in case of LL, the search operation we willl use is Linear Search
*/
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};
void insertAtHead(node*&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}
void printLL(node*head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
bool searchInLL(node*head,int key){
    //linear search
    while(head != NULL){
        if(head->data == key)   return true;
        head = head->next;
    }
    return false;
}
bool recursivelySearchInLL(node*head,int key){
    //base case
    if(head == NULL)    return false;

    //rec case
    if(head->data == key)   return true;
    else return recursivelySearchInLL(head->next,key);
}
int main(){
    node* head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    printLL(head);// output = 1->2->3->4->5->

    int key = 10;
    if(recursivelySearchInLL(head,key)){
        cout<<"Key found"<<endl;
    }
    else{
        cout<<"Key not found"<<endl;
    }
    //output = "Key not found"
    key = 5;
    if(searchInLL(head,key)){
        cout<<"Key found"<<endl;
    }
    else{
        cout<<"Key not found"<<endl;
    }
    //output = "Key found"
    
    return 0;
}
