//Given a Linked List, our task is to check if it contains a cycle or not
//1. Detect cycle
//2. Break the cycle if it exists.
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
bool detectCycle(node* head){
    //use fast and slow pointers
    //move fast 2 steps and slow 1 step
    // slow == fast will happen if there exists a cycle 
    // or else fast will reach NULL and loop will end

    node*fast = head;
    node*slow = head;
    while(fast != NULL and fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}
int main(){
    node* head = NULL;
    insertAtHead(head,7);
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    printLL(head);

    if(detectCycle(head)){
       cout<<"This ll contains a cycle."<<endl;
    }
    else{
       cout<<"Does not contain a cycle"<<endl;
    }

    //lets make a cycle so that we can detect it and break it 
    /*
    1 -> 2 -> 3 -> 4 -> 5
              ^         |
              |  <-7<-6<|
                        
    */
    //making 7 -> next point to 3

    int cnt=1;
    node* temp = head;
    node* cycleNode;

    while(temp->next != NULL){
        temp = temp -> next;
       cnt++;
       if(cnt == 3){
           cycleNode = temp;
       }
    }
    temp->next = cycleNode;
    
    cout<<"Cycle created!"<<endl;

    // now that we have creaed the cycle, lets detect it
    if(detectCycle(head)){
        cout<<"This ll contains a cycle."<<endl;
    }
    else{
       cout<<"Does not contain a cycle"<<endl;
    }

    return 0;
}