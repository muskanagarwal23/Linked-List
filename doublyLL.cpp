#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        if(this->next != NULL){
         delete next;
         this->next = NULL;
        }
    
        cout<<"memory is freed for the value:"<<value<<endl;
      }
};

void insertAtHead(Node* &head,Node* &tail,int d){
  Node* temp = new Node(d);
  if(head == NULL){
     head = temp;
     tail = temp;
  }  
  
  else{
    temp -> next = head;
   head -> prev = temp;
   head = temp;
  }
}

void insertAtTail(Node* &head,Node* &tail,int d){
    Node* temp = new Node(d);
    if(tail == NULL){
        tail = temp;
        head = temp;
    }
    
    else{
        tail -> next = temp;
        temp-> prev = tail;
        tail = temp;
    }

}

void insertAtPosition(Node* &head,Node* &tail,int pos,int d){
    if(pos == 1){
        insertAtHead(head,tail,d);
        return;
    }

    Node* temp = head;
    int count = 1;
    
    while(temp -> next!=NULL && count<pos-1){
        temp = temp -> next;
        count++;
    }

    //insert at last
    if(temp -> next == NULL){
        insertAtTail(head,tail,d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev= nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;

}

void deleteNode(Node* &head,Node* &tail,int pos){
    if(pos == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }

    else{
        Node* curr = head;
        Node* prev = NULL;

        int count =1;
        while(count <pos  ){
         prev = curr;
         curr = curr -> next;
         count++;
        }

        if(curr -> next == NULL){
            tail = prev;
            tail -> next = NULL;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }


}

void Print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp -> data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLen(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}


int main()
{
    
    Node* head = NULL;
    Node* tail = NULL;
    Print(head);
    //cout<<getLen(head);

     insertAtHead(head,tail,11);
     Print(head);

    insertAtHead(head,tail,12);
    Print(head);

    insertAtHead(head,tail,13);
    Print(head);

    insertAtHead(head,tail,14);
    Print(head);

    insertAtTail(head,tail,15);
    Print(head);

    insertAtPosition(head,tail,2,8);
    Print(head);

    insertAtPosition(head,tail,1,7);
    Print(head);
    cout<<"Head:"<<head -> data <<endl;
    cout<<"Tail:"<<tail -> data <<endl;

    deleteNode(head,tail,7);
    Print(head);
     
    cout<<"After Deletion:"<<endl;
    cout<<"Head:"<<head -> data <<endl;
    cout<<"Tail:"<<tail -> data <<endl;

   
}