//cout<<head.. will give the address stored at head that is address of first node of LL
//we want to overload << and >> operator
//s.t. cout<<head will give print entire ll
//and cin>>head will take LL elements as input
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
node* take_input(){
    //will take input from cin unless -1 is encountered
    node* head = NULL;
    int d;
    cin>>d;
    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}
//implementation of operator overloading along with cascading 
//cout<<head1<<head2 will also work because of cascading

//passing ostream object - 'os' by reference and node*head
//returning os with return type ostream&
ostream& operator<<(ostream &os, node* head){
	printLL(head);
	return os; //cout object returned
}
istream& operator>>(istream &is, node*&head){
	head = take_input();
	return is;
}
int main(){
    node*head;
	node*head2;
	cin>>head>>head2;//input = 5 4 3 2 1 -1 10 9 8 7 6 5 -1
	cout<<head<<head2;
    //output
    /*
    1->2->3->4->5->
    5->6->7->8->9->10->
    */
    return 0;
}