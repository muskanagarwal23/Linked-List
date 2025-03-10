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

  //Destructor
  ~Node(){
    int value = this -> data;
    if(this->next != NULL){
     delete next;
     this->next = NULL;
    }

    cout<<"memory is freed for the value:"<<value<<endl;
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
  
  //Deletion
  void deleteNode(Node* &head, Node* &tail,int position){
    if(position == 1){
      Node* temp = head;
      head = head -> next;
      temp -> next = NULL;
      delete temp;
    }
    
    //mid or last position
    else{
     Node* current = head;
     Node* previos = NULL;
     
     int count = 1;
     while(count<position){
      previos = current;
      current = current->next;
      count++;
     }
     
    //updating the tail if last node is deleted 
     if(current->next == NULL){
      tail = previos;
      tail->next = NULL;
     } 

     
     
     previos->next = current->next;
     current->next=NULL;
     delete current;
    }
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
   cout<<"tail:"<<tail->data<<endl;

  //deleteNode(head,tail,1);
  //deleteNode(head,tail,3);
  deleteNode(head, tail,6);
   
   cout<<"After deletion:";
    print(head);

  cout<<"head:"<<head->data<<endl;
  cout<<"tail:"<<tail->data<<endl;


    return 0;
}