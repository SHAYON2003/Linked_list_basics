#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

 //constructor
   Node(int data){
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
   }
  ~Node(){
     cout<<"Node with value: "<<this->data<<" "<<"deleted"<<endl;
  
}
};
void printlinkedlist( Node* &head){
     
     Node*temp = head;
     while(temp!=NULL){
         cout<<temp->data<<" ";
         temp = temp->next;
     }
     cout<<endl;
}

int getLength(Node* &head){
     int len = 0;
     Node* temp = head;
     while(temp!=NULL){
         temp =  temp->next;
       len++;         
     }
    return len;
}
 void insertAtHead(Node* &head, Node* &tail,int data){
      Node *newnode = new Node(data);
      newnode->next  = head;
      head->prev  = newnode;
      head = newnode;
 }

 void insertAtTail(Node* &head,Node* &tail, int data){
    Node* newnode = new Node(data);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
 }

 void insertAtPosition(Node* &head,Node* &tail, int data, int position){

   //if at start
    if(position ==1){
      insertAtHead(head, tail, data);
      return;
    
    }
     int len = getLength(head);
    if(position > len){
       insertAtTail(head,tail,  data);
       return;
    }
    Node* prev1 = head;
    int i = 1;
    while(i<position-1){
      //cout<<"getting the previous node"<<endl;
        prev1 = prev1->next;
        //cout<<"got the previous node as"<<" "<<prev1->data<<endl;
         i++;
    } 
    // cout<<"getting the current node"<<endl;
     Node*curr  = prev1->next;
    //cout<<"got the current node as"<<" "<<curr->data<<endl;

    Node* newnode = new Node(data);
    newnode->next = curr;
    curr->prev = newnode;
     prev1->next = newnode;
     newnode->prev = prev1;
     // if you dont have or know current node pointer
   
    //  Node* newnode = new Node(data);
    // prev->next->prev = newnode;
    // newnode->next = prev->next;
    //  newnode->prev = prev;
    // prev->next = newnode;
 }
 void deleteNodes(Node* head,Node* &tail,int position){
      //if no node exists
     if(head == NULL){
       cout<<"the linked list is empty"<<endl;
     }
     // if 1  node exists
      if(head->next == NULL){
         Node* temp = head;
         head = NULL;
         tail = NULL;
          delete temp;

        return;
 }
     int len  = getLength(head);
   // if the value exceds the length of the linked list
     if(position > len){
       cout<<"please enter valid value"<<endl;
       return;
     }
      //deletion of last node which is tail
      if(position == len){
         Node* temp = tail;
        tail = tail->prev;
          temp->prev = NULL;
          tail->next = NULL;
          delete temp;
          return ;
      }
     // deleting of first node
   if(position == 1){
     Node*temp = head;
       head = head->next;
       temp->next = NULL;
       head->prev = NULL;
       delete temp;
 }
  // deleting at the middle of the linked list
     Node*left = head;
     int i = 1;
     while(i < position - 1 ){
       left = left->next;
       i++;
     }
   Node*right = left->next;
   
   Node* curr = left -> next;
    left->next = right;
    right->prev = left;
    curr->next = NULL;
    curr->prev = NULL;  
    delete curr;
 }
int main(){
  
  Node* node1 = new Node(10);
   Node* head = node1;
   Node* tail = node1;

  
 
  //cout<<getLength(head)<<endl;
  insertAtHead(head,tail,11);
  insertAtHead(head,tail,13);
 insertAtHead(head,tail,15);
  insertAtHead(head,tail,17);
  //insertAtPosition(head,tail,19,3);
  
  deleteNodes(head,tail, 2);
   cout<<endl;
   printlinkedlist(head);
   cout<<endl;
  
}