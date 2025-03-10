#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is freed for the value:"<<value<<endl;
    }

};

void Insertion(Node* &tail,int elem,int d){
    //empty case
    if(tail == NULL){
     Node* newNode = new Node(d);
     tail = newNode;
     tail -> next = newNode;
    }

    else{
        Node* curr = tail;
        
        while(curr -> data != elem){
            curr = curr -> next;
        }

        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void deleteNode(Node* &tail,int elem){
 
    if(tail == NULL){
        cout<<"list is empty";
    }

    else{
        Node* prev = tail;
        Node* curr = prev -> next;
        int count = 1;
        while(curr -> data != elem){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //only 1 node
        if(curr == prev)
            tail = NULL;
        
        else if(tail == curr)
            tail = prev;
        

        curr -> next = NULL;
        delete curr;

    }
}

void Print(Node* &tail){
    Node* temp = tail;

    if(tail == NULL)
      cout<<"list is empty";
    
    do {
        cout<< tail ->data<<" ";
        tail = tail->next;
    } while (tail != temp);
    cout<<endl;    
    
}

int main(){
      Node* tail =  NULL;
      
      Insertion(tail,5,3);
      Print(tail);

      Insertion(tail,3,5);
      Print(tail);

    //   Insertion(tail,5,7);
    //   Print(tail);
    
    //   Insertion(tail,5,6);
    //   Print(tail);

    //   Insertion(tail,3,4);
    //   Print(tail);

      deleteNode(tail,5);
      Print(tail);
  
      
      


}