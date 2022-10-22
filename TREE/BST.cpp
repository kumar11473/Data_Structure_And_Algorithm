#include<iostream>
using namespace std;

#define SPACE 10

class TreeNode{
    public:
    int value;
    TreeNode * right;
    TreeNode * left;

    TreeNode(){
        value=0;
        right=NULL;
        left=NULL;
    }

    TreeNode(int v){
        value=v;
        left=NULL;
        right=NULL;
    }
};

class BST{
    public:
    TreeNode* root;
    BST(){
        root=NULL;
    }

    bool isEmpty()
    {
        if(root==NULL)
        return true;
        else
        return false;
    } 
   



//  void insertNode(TreeNode * new_node)
//   {
//     if (root == NULL)
//      {
//       root = new_node;
//       cout << "Value Inserted as root node!" << endl;
//     } 
//     else
//      {
//       TreeNode * temp = root;
//       while (temp != NULL) {
//         if (new_node -> value == temp -> value) {
//           cout << "Value Already exist," <<
//             "Insert another value!" << endl;
//           return;
//         } 
//         else if ((new_node -> value < temp -> value) && (temp -> left == NULL))
//          {
//           temp -> left = new_node;
//           cout << "Value Inserted to the left!" << endl;
//           break;
//         }
//          else if (new_node -> value < temp -> value)
//           {
//           temp = temp -> left;
//         }
//          else if ((new_node -> value > temp -> value) && (temp -> right == NULL)) 
//          {
//           temp -> right = new_node;
//           cout << "Value Inserted to the right!" << endl;
//           break;
//         }
//          else
//           {
//           temp = temp -> right;
//         }
//       }
//     }
//   }

                               /* FUNCTION OF PREORDER TRAVERSAL */
  void printPreorder(TreeNode * r)
  {
    if(r==NULL)
      return;
      // first print the value of the node
    cout<<r->value<<" ";
    // then recursively go on left subtree
    printPreorder(r->left);
    // then recursively go on right subtree
    printPreorder(r->right);
  }

                           /* FUNCTION OF INORDER TRAVERSAL */
  void printInorder(TreeNode* r)
  {
    if(r==NULL)
      return;
    printInorder(r->left);
    cout<<r->value<<" ";
    printInorder(r->right);  
  }       

                        /* FUNCTION OF POSTORDER TRAVERSAL */                  
  void printPostorder(TreeNode*r)
  {
    if(r==NULL)
      return;
    printPostorder(r->left);
    printPostorder(r->right);
    cout<<r->value<<" ";  
  }
  
                        /*FUNCTION FOR PRINTING DATA IN TREE FASHION */
  void print2D(TreeNode * r, int space)
   {
    if (r == NULL) 
      return;
    space += SPACE;   
    print2D(r -> right, space); 
    cout << endl;
    for (int i = SPACE; i < space; i++) 
      cout << " "; // 5.1  
    cout << r -> value << "\n"; 
    print2D(r -> left, space); 
  }

TreeNode * iterativeSearch(int val)
{
  if(root==NULL)
  {
    return root;
  }
  else
  {
    TreeNode*temp=root;
    while(temp!=NULL)
    {
      if(val==temp->value)
      {
        return temp;
      }
      else if(val>temp->value)
      {
        temp=temp->right;
      }
      else
      {
        temp=temp->left;
      }

    }
    
  }

}

int height(TreeNode* r)
{
  if(r==NULL)
  {
    return -1;
  }
  else
  {
    int lheight = height(r->left);
    int rheight = height(r->right);
    if(lheight>rheight)
    {
      return (lheight+1);
    }
    else
      return (rheight+1);
  }
}

                       // BREATH LEVEL TRAVERSING (BFS)
void printGivenLevel(TreeNode * r, int level)
{ 
  if(r==NULL)
     return;
  else if(level ==0)
    cout<<r->value<<" ";
  else
  {
    printGivenLevel(r->left,level-1);
    printGivenLevel(r->right,level-1);
  }      

}

void printLevelOrder(TreeNode * r)
{
  int h=height(r);
  for(int i=0;i<=h;i++)
  {
    printGivenLevel(r,i);
  }
}

                       //Deleting node from the tree
TreeNode* minValueNode(TreeNode* node)
{
  TreeNode* current =node;
  while(current->left!=NULL)
  {
    current=current->left;
  }
  return current;
}

TreeNode* deleteNode(TreeNode*r,int v)
{
  if(r== NULL)
    return NULL;

  else if(v < r->value)
     r->left=deleteNode(r->left,v);
  else if(v > r->value)
     r->right=deleteNode(r->right,v);
  else
  {
      //to delete node with only one child
    if(r->left==NULL)
    {
      TreeNode*temp=r->right;
      delete r;
      return temp;
    }
    else if(r->right == NULL)
    {
      TreeNode* temp=r->right;
      delete r;
      return r;
    }
    else
    {
      TreeNode* temp=minValueNode(r->right);
      r->value=temp->value;
      r->right=deleteNode(r->right,temp->value);
    }
  }    
  return r;
}

                       //lect 85 Recursive insertion of elements in the tree

TreeNode* insertRecursive(TreeNode* r, TreeNode *new_node)
{
  if(r==NULL)
  {
    r=new_node;
    return r;
  }
  if(new_node->value< r->value)
  {
    r->left=insertRecursive(r->left,new_node);
  }
  else if(new_node->value > r->value)
  {
    r->right=insertRecursive(r->right,new_node);
  }
  else
  {
    cout<<"No duplicate value are allowed"<<endl;
    return r;
  }
  return r;
}                       

};


  
int main()
{
    BST obj;
    int option,val;

    do
    {
        cout<<endl<<"Select the option to perform  action"<<
        " Or Press 0 to exit"<<endl; 
        cout<<"1. Insert Node"<<endl;
        cout<<"2. Search Node"<<endl;
        cout<<"3. Delete Node"<<endl;
        cout<<"4. print BST value"<<endl;
        cout<<"5. Height "<<endl;
        cout<<"6. Clear Screen"<<endl;
        cout<<"0. Exit Program"<<endl;
        
        cin>>option;
    TreeNode * new_node= new TreeNode(); //lec 70 (45min 40se) creating object in heap memory and pointer in stack memory
 /* this above node creating line should 
 be inside do while loop so that every time loop execute a new node is created in which we put our value */

        switch (option)
        {
         case 0:
           cout<<"Exit From Program "<<endl;
           break;
         case 1:
          // cout <<"INSERT"<<endl;
	         cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
	         cin >> val;
	         new_node->value = val;

	        // obj.insertNode(new_node);  

           obj.root=obj.insertRecursive(obj.root,new_node);
	         cout<<endl;
    		   break;
         case 2:
           cout<<"Search "<<endl;
           cout<<"Enter the value to search : ";
           cin>>val;
           TreeNode* res;
           res= obj.iterativeSearch(val);
           if(res!=NULL)
           {
             cout<<"Value found at address "<<res<<endl;
           }
           else
            {
                cout<<"Value not found  "<<endl;  
            }
           break;
         case 3:
           cout<<"Delete "<<endl;
           cout<<"Enter value of three node to delete in bst: ";
           cin>>val;
           new_node= obj.iterativeSearch(val);
           if(new_node!=NULL)
           {
             obj.deleteNode(obj.root,val);
             cout<<"Value Deleted"<<endl;
           }
           else
           {
             cout<<"Value Not Found"<<endl;
           }
           break;
         case 4:
          //  cout<<"Print BST "<<endl;
          //  obj.print2D(obj.root,5);
          //  cout<<endl;
          //  cout<<"PRE-ORDER : ";
          //  obj.printPreorder(obj.root);
          //  cout<<endl;
          //  cout<<"IN-ORDER : ";
          //  obj.printInorder(obj.root);
          //  cout<<endl;
          //  cout<<"POST-ORDER : ";
          //  obj.printPostorder(obj.root);
          //  cout<<endl;
          
          cout<<"Print level order BFS : \n ";
          obj.printLevelOrder(obj.root);

          cout<<endl;

           break;
         case 5:
           cout<<"Height of tree : "<<obj.height(obj.root)<<endl;
           break;
         case 6:
           system("cls");
           break;  

         default:
           cout<<"Enter correct option"<<endl;
           break;
        }
        
    }while(option!=0);

return 0;
}