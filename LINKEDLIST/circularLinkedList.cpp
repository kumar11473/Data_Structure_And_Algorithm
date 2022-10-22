

#include<iostream>
using namespace std;
class Node{
    public:
    int key;
    int data;
    Node* next;

    Node(){
        key=0;
        data=0;
        next=NULL;
    }
    Node(int k,int d){
        key=k;
        data=d;
    }
};
class CircularLinkedList{
    public:
    Node* head;
    
    CircularLinkedList(){
        head=NULL;
    }

//1. Check if Node exists using key value
 Node* nodeExist(int k){
     Node* ptr=head;
     Node* temp=NULL;
     if(ptr==NULL){
         return temp;
     }
     else
     {
      do
         {
     if(ptr->key==k)
     {
      temp=ptr;
     }
     
     ptr=ptr->next;

     }while(ptr!=head);
     return temp;               //temp==NULL means no node found with given key
     }
 }   

 // 2. Append a Node in the list
 void appendNode(Node* new_node){
     if(nodeExist(new_node->key)!=NULL)
     {
      cout<<"Node already exist with key value :"<<new_node->key<<". Append anothe node with different key value"<<endl;
     }
     else
     {
         if(head==NULL)
         {
             head=new_node;
             new_node->next=head;
             cout<<"Node Appended at head position"<<endl;
         }else{
             Node*ptr=head;
             while(ptr->next!=head){
                 ptr=ptr->next;
             }
             ptr->next=new_node;
             new_node->next=head;
             cout<<"Node appended"<<endl;
         }
     }
 }  
 //3. Prepending a Node
 void prependNode(Node* new_node){
   
     if(nodeExist(new_node->key)!=NULL){
         cout<<"No Node exist with key value "<<new_node->key<<". Append another node with different key value"<<endl;        
     }else
     {
         if(head==NULL){          //if Linked List is empty
             head=new_node;
             new_node->next=head;
             cout<<"Node appended as head Node"<<endl;
         }
         else
         {
          Node* ptr=head;
          while(ptr->next!=head){
              ptr=ptr->next=head;
          }
          ptr->next=new_node;
          new_node->next=head;
          head=new_node;
          cout<<"Node prepended"<<endl;
         }
     }
 }

 //4. Insert a Node after  a particular Node in the list
 void insertNodeAfter(int k, Node* new_node){
     Node* ptr=nodeExist(k);
     if(ptr==NULL){
         cout<<"No Node exist with key value "<<k<<endl;
     }
     else
     {
       if(nodeExist(new_node->key)!=NULL){
           cout<<"Node already exist with key value "<<k<<". Insert another Node with different key value"<<endl;
       }else
       {
           if(ptr->next==head){    
           new_node->next=head;
           ptr->next=new_node;
           cout<<"Node Inserted at the end"<<endl;
           }else{
               new_node->next=ptr->next;
               ptr->next=new_node;
               cout<<"Node Inserted in between"<<endl;
           }
       }
     }
 }

//5. Delete Node by unique key
void deleteNodeByKey(int k){
    Node* ptr=nodeExist(k);
    if(ptr==NULL){
        cout<<"No Node exist with key value :"<<k<<endl;
    }
    else{
        if(ptr==head)        // case of deleting head Node  
        {       
        if(head->next==head){      
        head=NULL;
        cout<<"Head Node unlinked.... List empty "<<endl;
        }else{       
            Node* ptr=head;
            while(ptr->next!=head){
                ptr=ptr->next;
            }
            ptr->next=head->next;
            head=head->next;
            cout<<"Node unlinked with key value :"<<k<<endl;
           }              
        }
        else        //case of deleting a end Node and between Node
        {         
         Node* temp=NULL;
         Node* prevptr=head;
         Node* currentptr=head->next;
         while(currentptr!=NULL)
         {
             if(currentptr->key==k){
                 temp=currentptr;
                 currentptr=NULL;
             }
             else{
                 prevptr=prevptr->next;
                 currentptr=currentptr->next;
             }
         }
         prevptr->next=temp->next;
         cout<<"Node unlinked with key value :"<<k<<endl;       
        }
    }
}

//6. Updating a Node
void updateNodeByKey(int k,int new_data){
    Node* ptr=nodeExist(k);
    if(ptr!=NULL){
    ptr->data=new_data;
    cout<<"Node updated successfully"<<endl;
    }
    else{
        cout<<"Node doesn't exist with key value :"<<k<<endl;
    }
}

//7. printing Nodes
void printList(){
    if(head==NULL){
        cout<<"No Node exists in Linked List"<<endl;
    }
    else{
       cout<<endl<<"head address :"<<head<<endl;
       cout<<"Circular Linked List value :"<<endl;
       Node * temp=head;
       do{
           cout<<"("<<temp->key<<","<<temp->data<<","<<temp->next<<")-->";
           temp=temp->next;
       }while(temp!=head);
        
    }
}
};

int main(){
    
 CircularLinkedList obj;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1->key = key1;
      n1->data = data1;
      obj.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1->key = key1;
      n1->data = data1;
      obj.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1->key = key1;
      n1->data = data1;

      obj.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      obj.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      obj.updateNodeByKey(key1, data1);

      break;
    case 6:
      obj.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
    return 0;
}