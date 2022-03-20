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
int length(node*head){
	int cnt = 0;
	while(head!=NULL){
		cnt++;
		head = (*head).next;
		//or head = head->next;
	}
	return cnt;
}
void deleteAtHead(node*&head){
    // 1 -> 2 -> 3 , head stores address of 1
	//after deltion: 2->3, head stores address of 2
    if(head == NULL){
        //nothing to delete
        return;
    }
    
    node* temp = head->next;
    //following will not delete the head bucket, but will delete the node at the address stored inside head
    delete head;
    head = temp;    
}
void deleteAtTail(node*&head){
    // 1 -> 2 -> 3 , head stores address of 1
	//after deltion: 1->2->, head will remain unchanged
    if(head == NULL){
        //nothing to delte
        return;
    }
    node*temp = head;
    node*prev = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    //1->2->3, prev will store address of 2 and temp will store address of 3
    delete temp;
    prev->next = NULL;
}
void deleteAtPosition(node*&head,int p){
    if(head == NULL){
        return;
    }
    if(p == 0){
        deleteAtHead(head);
        return;
    }
    if(p >= length(head)){
        deleteAtTail(head);
        return;
    }
    //delete at middle
    node*prev = head;
    node*curr = head;
    int jump = 1;
    while(jump <= p-1){
        prev = curr;
        curr = curr->next;
        jump++;
    }
    prev->next = curr->next;
    delete curr;

}
void printLL(node*head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

int main(){

    node* head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    printLL(head);// output = 1->2->3->4->5->

    deleteAtPosition(head,0); //at head
    printLL(head);//output = 2->3->4->5->

    deleteAtPosition(head,100); //at tail
    printLL(head);//output = 2->3->4->

    deleteAtPosition(head,2);
    printLL(head);//output = 2->4->;
    
    return 0;
}