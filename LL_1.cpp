#include<iostream>
using namespace std;

class Node{
     public:
     int data;
     Node* next; // basic declaration of node
  
  Node(){
     this->data = 0;
     this->next = NULL;

  }
  Node(int data){
     this->data = data;
     this->next = NULL;
  }
 // write a destructor to delete node
   ~Node(){
      cout<<"Node with"<<this->data<<": is deleted"<<endl;
   }

}; // CLASS ENDS


int length(Node* &head){
  int len = 0;
    Node* temp  = head;
    while(temp != NULL){
       temp = temp->next;
       len++;
    }
     return len;
}
//Insertion of linked list at head
void insertatHead(Node* &Tail,Node* &Head, int data){
     
     if(Head  == NULL){
       Node* newNode = new Node(data);
       Head = newNode;
       Tail = newNode;}
   else{  
    Node* newNode = new Node(data);

      //step 2: attach (Newnode next) to hed
        newNode->next = Head;

      //step 3: point the head on new node 
       Head= newNode;
   }
}

// i want to insert a node right at the end of the linked list{at tail }
void insertatTail(Node* &Head,Node* &Tail, int data){
       
     if(Head  == NULL){
       Node* newNode = new Node(data);
       Head = newNode;
       Tail = newNode;}
   
  else{   // create a node
     Node* newNode = new Node(data);

     // point the newnode next to tail;
        Tail->next = newNode;
      // put the tail pointer onto the head node
      Tail = newNode;
  }
}

// Inserting a node in a specific position
void positionofll(Node* &head,Node* &tail,int data,int position){
     
      if(head  == NULL){
       Node* newNode = new Node(data);
       head = newNode;
       tail = newNode;}
   
  
   //if i have to insert the node at first specific position
   if(position == 0){
      insertatHead(tail,head,data);  
      return;
   }
   // finding the position of previous and current node
     int i = 1;
     Node* prev = head;
    while(i < position){
         cout<<prev->data<<endl;
        cout<<"getting the previous node"<<endl;

         prev = prev->next;
         cout<<prev->data<<endl;
         i++;
         cout<<"breaked the loop comes out"<<endl;
    }
     cout<<"getting the current node"<<endl;
     Node* curr =  prev->next;
     cout<<curr->data<<endl;

    Node* newNode = new Node(data);

    newNode->next = curr;

    prev->next = newNode;

}
 //deletion of linked list
 // 1. start
  // 2. middle
  //3 . end
 void deleteNode(Node* &head, Node* &tail,int position){
        if(head  == NULL){
       cout<<"Cannot delete ll is empty"<<endl;
        }
    //deleting first node
    if(position == 1){
     Node* temp = head; 
      // step 1: head ko update kro
     head = head->next;
      temp->next = NULL;
     delete temp;
    }

  int ans =  length(head);
   
      if(position >= ans){
          //find prev
         Node* prev = head;
         int i = 1;
        
        while(i< position-1 ){
               prev = prev->next;
               i++;
        }
         //step-2;
       
          prev->next = NULL;
         //step 3;
         Node* temp = tail;
       //  delete temp
        delete temp;
    }
 }
 // deleting a node at middle

  void deleteatMiddle(Node* &head, Node* &tail,int position){
      int i = 1;
       Node* prev = head;
      if( i < position){
          prev = prev->next;
          i++;
      }
     Node* curr = prev->next;

     // step 1: 
     prev->next = curr->next;
     //step2:
      curr->next = NULL;
    
    // delete
     delete curr;
  }
void print(Node* &head){
      Node* temp = head;
    
    while(temp != NULL){ 
         cout<<temp->data<<" "; // accessing the data
         
         temp = temp->next; 
       // incrementing the temp onto the next node to access the data.
}}
  

int main(){

//     // creation of  nodes in ll using dynamic allocation
//     Node * first = new Node(10);
//      Node * second = new Node(20);
//     Node * third = new Node(30);
//     Node * fourth = new Node(40);
//      Node * fifth = new Node(50);

//     // linking the next node to the other nodes 
//      first->next = second;
//      second->next = third;
//      third->next = fourth;
//      fourth->next = fifth;
   
   //Node* head = new Node(10);
    Node* head = NULL; // Head node null ho sakta hai,
     // zaruri nai ki head node me data rhe
     Node *tail = NULL;
    insertatHead(tail,head,20);
   insertatHead(tail,head,30);
   insertatHead(tail,head,40);
   insertatHead(tail,head,60);
  

 
     print(head);

//  positionofll(head,tail,12,2);
 


     
     return 0;
}