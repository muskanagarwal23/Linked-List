#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  //constructor
  Node(int data){
    this -> data = data;
    this -> next = NULL;
  }
};

void insertAtHead (Node* &head,int data) {
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;

  }

  void insertAtTail(Node* &tail,int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
  }

  void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    //insert at first
    if(position == 1){
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int count = 1;
    
    while(temp -> next!=NULL && count<position-1){
        temp = temp -> next;
        count++;
    }

    //insert at last
    if(temp -> next == NULL){
        insertAtTail(tail,d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

  }

  

  void print(Node* &head){
    Node *temp = head;
    while(temp != NULL) {
    cout<<temp -> data<<" ";
    temp = temp -> next;
    }
    cout<<endl;
    
  }

int main(){
    Node* node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next;

    Node* head = node1;
    Node* tail = node1;
    print (head);
    insertAtTail(tail,12);
    //insertAtHead(head,12);
    print(head);
    insertAtTail(tail,15);
    //insertAtHead(head,15);
    print(head);

    insertAtPosition(head,tail,1,9);
    print(head);

    insertAtPosition(head,tail,4,13);
    print(head);
    
    insertAtPosition(head,tail,100,17);
    print(head);

   cout<<"head:"<<head->data<<endl;
   cout<<"tail:"<<tail->data;


    return 0;
}