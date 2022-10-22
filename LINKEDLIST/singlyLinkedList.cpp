#include<iostream>
using namespace std;

class Node{     //Node class is for creating Nodes
    public:
    int key;
    int data;
    Node* next;
    public:
     Node(){
         key=0;
         data=0;
         next=NULL;
     }
      Node(int k, int d){
         key=k;
         data=d;
     }
};

class SinglyLinkedList{     // SinglyLinkedList class is for creating links
    public:
    Node * head;
    SinglyLinkedList(){
        head=NULL;
    }
    SinglyLinkedList(Node *n){
        head=n;
    }

// 1. check if node exists using key value
    Node* nodeExist(int k){
         Node* temp=NULL;
         Node* ptr=head  ;        //use this ptr to traverse in the entire LL
     while(ptr!=NULL){
          if(ptr->key==k){
              temp=ptr; 
          }
          ptr=ptr->next;   //ek node se dure node pe jane k liye
     }
     return temp;  //if temp == NULL means key doesn't exist
    }

// 2. Append a node to the list 
   void appendNode(Node* n){     //Node* n ---> pass by address
       if(nodeExist(n->key)!=NULL){  //nodeExits() will return NULL only when the entered key doesn't exist
        cout<<"Node already exists with key value :"<<n->key<<". Append another node with different key value"<<endl; 
       }
       else{
           if(head==NULL){
               head=n;
               cout<<"Node appended"<<endl;
           }
           else{
                Node* ptr=head;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                ptr->next=n;
                cout<<"Node Appended"<<endl;
           }
       }
   }
                                                      //"n->next"  means 'next' of Node n
   //3. Prepend Node-Attach a note at the start
   void prependNode(Node* n){
if(nodeExist(n->key)!=NULL){ 
        cout<<"Node already exists with key value :"<<n->key<<". Append another node with different key value"<<endl; 
       }
       else{
           n->next=head; //we are storing the data of head in next of new node n
           head=n;
                cout<<"Node Appended"<<endl; 
       }
   }

   // 4. Insert a Node after a particular node in the list
   void inserNodeAfter(int k,Node* n)
   {
    Node* ptr=nodeExist(k); // this line take us to the Node with key k and if no Node exist with that key value then ptr become NULL
     if(ptr==NULL){
         cout<<"No Node exist with key value :"<<k<<endl;
     }
     else{
         if(nodeExist(n->key)!=NULL){ 
        cout<<"Node already exists with key value :"<<n->key<<". Append another node with different key value"<<endl; 
       }
       else{
               n->next=ptr->next;
               ptr->next=n;
               cout<<"Node Inserted"<<endl;
      }
     }
   }

   //5. Delete Node by unique key
   void deleteNodeByKey(int k){
       if(head==NULL){
           cout<<"Singly Linked List already empty. Can't delete anything"<<endl;
       }
       else if(head!=NULL)  
       {     
        if(head->key==k)        //for deleting first node
        {
          head=head->next;
          cout<<"Node unlinked with key value :"<<k<<endl;
        }
        else        //for deleting any inbetween Node
        {
          Node* temp=NULL;
          Node* prevptr=head;
          Node* currentptr=head->next;
          while(currentptr!=NULL)
          {
              if(currentptr->key==k)
              {
                  temp= currentptr;
                  currentptr=NULL;  //this line take us out of while loop
              }
              else
              {
                  prevptr=prevptr->next;  //for incrementing prevptr
                  currentptr=currentptr->next;
              }
          }
          if(temp!=NULL)   //
          {
            prevptr->next=temp->next;
            cout<<"Node Unlinked with key value :"<<k<<endl;
          }
        }
       }
   }
   //6. Updating Node
   void updateNodeByKey(int k,int d)
   {   
       Node* ptr=nodeExist(k);  //this line take us to the Node with key k and if no Node exist with that key value then ptr become NULL
       if(ptr!=NULL)
       {
           ptr->data=d;
           cout<<"Node Data updated successfully"<<endl;
       }
       else
       {
           cout<<"Node doesn't exist with key value :"<<k<<endl;
       }
   }

   //7. printing Nodes
   void printList(){
       if(head==NULL)
       {
           cout<<"No Nodes present in singly Linked List"<<endl;
       }
       else{
           cout<<endl<<"Singly Linked List Values :";
           Node* temp=head;
           while(temp!=NULL)
           {
               cout<<"("<<temp->key<<","<<temp->data<<") --> ";
               temp=temp->next;
           }
       }
   }
};

int main(){
    SinglyLinkedList s;
    int option;
    int key1,k1,data1;
    do{
   cout<<"\nWhat operation do you want to perform? Select option number. Enter 0 to exit."<<endl;
   cout<<"1. appendNode()"<<endl;
   cout<<"2. prependNode()"<<endl;
   cout<<"3. insertNodeAfter()"<<endl;
   cout<<"4. deleteNodeByKey()"<<endl;
   cout<<"5. updateNodeByKey()"<<endl;
   cout<<"6. print()"<<endl;
   cout<<"7. clear screen()"<<endl;
  
   cin>>option;
   Node* n1=new Node();

  switch(option)
   {
   case 0:
    break;
   
   case 1:
    cout<<"Append Node operation \nEnter key and data of the Node to be Appended"<<endl;
    cin>>key1;
    cin>>data1;
    n1->key=key1;
    n1->data=data1;  
    s.appendNode(n1);
     break;

   case 2:
    cout<<"Prepend Node operation \nEnter key and data of the Node to be Prepended"<<endl;  
    cin>>key1;
    cin>>data1;
    n1->key=key1;
    n1->data=data1;  
    s.appendNode(n1);
     break;

   case 3:
    cout<<"Insert Node after operation \nEnter key of existing Node after which you want to insert this Node"<<endl;
    cin>>k1;
    cout<<"Enter key and data of the new Node first :"<<endl;
    cin>>key1;
    cin>>data1;
    n1->key=key1;
    n1->data=data1;
    s.inserNodeAfter(k1,n1);
    break;

   case 4:
    cout<<"Delete Node by key operation -\nEnter key of the Node to be deleted: "<<endl;
    cin>>k1;
    s.deleteNodeByKey(k1);
    break;

   case 5:
    cout<<"update Node by key operation -\nEnter key and new data to be updated"<<endl;
    cin>>key1;
    cin>>data1;
    s.updateNodeByKey(key1,data1);
    break;

   case 6:
    s.printList();
    break;

   case 7:
    system("cls");
    break;

   default:
   cout<<"Enter proper option number"<<endl; 

   }  
    }while(option!=0);

    return 0;
} 