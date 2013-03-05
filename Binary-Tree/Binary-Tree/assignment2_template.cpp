#include <iostream>
using namespace std;

// Declare the data structure
struct CP {
	int id;			// id of the node
	int data;		// data of the node
	CP * left;		// pointer to the left subtree 
	CP * right;		// pointer to the right subtree
};

typedef CP * CPPtr;	


// Function prototypes 
int countNode(CPPtr root);
int countOnlyChilds(CPPtr root);
int countHeight(CPPtr root);
CPPtr minNode(CPPtr root);
void minNodeCore(CPPtr root, CPPtr &CurrentMin);
bool ChildrenSmaller(CPPtr root);
// Generate an instance of the structure
void constructStructure(CPPtr &hdTree);

//SOLUTION 1
int countNode(CPPtr root) { 
  if (root == NULL) return 0;
  return 1 + countNode(root->left) + countNode(root->right);
  }
//SOLUTION 2
int countOnlyChilds(CPPtr root)
  {
     if(root == NULL)
         return 0;
     if ( (root->left!=NULL && root->right==NULL)||(root->left==NULL && root->right!=NULL) )
         return countOnlyChilds(root->left)+ countOnlyChilds(root->right) + 1;

     return countOnlyChilds(root->left)+ countOnlyChilds(root->right);

  }
//SOLUTION 3
CPPtr minNode(CPPtr root) { 
	if (root == NULL) return 0;
	CPPtr CurrentMin = root;
	minNodeCore(root->left, CurrentMin);
	minNodeCore(root->right, CurrentMin);
	return CurrentMin;
  }

void minNodeCore(CPPtr root, CPPtr &CurrentMin) { 
  
	if (root == NULL){return;}
	if (CurrentMin->data > root->data){CurrentMin = root;}
	minNodeCore(root->left, CurrentMin);
	minNodeCore(root->right, CurrentMin);
  }

//SOLUTION 4
int countHeight(CPPtr root)
{
     if (root==NULL) { 
        return 0;
     } else {
        return max(countHeight(root->left),
                   countHeight(root->right)) + 1;
     }
}
//SOLUTION 5
bool ChildrenSmaller(CPPtr root)
{
     if (root==NULL) { 
        return true;
	 } 
	
	 bool temp = ((ChildrenSmaller(root->left))&(ChildrenSmaller(root->right)));
	 if(root->left != NULL){temp = (root->data > root->left->data) & temp;}
	 if(root->right != NULL){temp = (root->data > root->right->data) & temp;}
	 return temp;
}
//SOLUTION 6

int main(int argc, char ** argv)
{

	// Declare a pointer to the head of the tree
	CPPtr hdTree  = NULL;
	
	// Construct a tree structure. Comment out one of them. The version 2 has been given to the studnets
    //constructStructure(hdTree);
	constructStructure(hdTree);

	// =================================
	// Your functions should go here
 

 
  cout <<"Number of Nodes ="<< countNode(hdTree) << endl;
  cout <<"Number of Nodes with single child ="<< countOnlyChilds(hdTree) << endl; 
  cout <<"Node with smalles value="<< " id =" << minNode(hdTree)->id << " data =" << minNode(hdTree)->data << endl; 
  cout << "Height of tree =" << countHeight(hdTree) << endl;  
  cout <<"All children smaller than parents= "<< std::boolalpha << ChildrenSmaller(hdTree) << endl;
    // =================================
    
    // Just to freeze the console window (not always necessary)
    getchar();
     
    return 0;
}



// The function generates an instance of the structure. The SP pointer
// points to the head of the tree
void constructStructure(CPPtr &SP){
    // Declare a structure with 5 nodes
    
    
    CPPtr SP0 = NULL;
    CPPtr SP1 = NULL;
    CPPtr SP2 = NULL;
    CPPtr SP3 = NULL;
    CPPtr SP4 = NULL;
	/*/##################
	CPPtr SP5 = NULL;
	CPPtr SP6 = NULL;
	CPPtr SP7 = NULL;
	//################## */

    // build the structure tree
    // State 0
    SP0 = new CP;
    SP0->id = 1;
    SP0->data = 10;
    SP0->left = NULL;
    SP0->right = NULL;
    // State 1
    SP1 = new CP;
    SP1->id = 4;
    SP1->data = 5;
    SP1->left = NULL;
    SP1->right = NULL;
    // State 2
    SP2 = new CP;
    SP2->id = 8;
    SP2->data = 9;
    SP2->left = NULL;
    SP2->right = NULL;
    // State 3
    SP3 = new CP;
    SP3->id = 6;
    SP3->data = 3;
    SP3->left = NULL;
    SP3->right = NULL;
    // State 4
    SP4 = new CP;
    SP4->id = 5;
    SP4->data = 5;
    SP4->left = NULL;
    SP4->right = NULL;

	/*/##################
	SP5 = new CP;
    SP5->id = 12;
    SP5->data = 2;
    SP5->left = NULL;
    SP5->right = NULL;
	
	SP6 = new CP;
    SP6->id = 13;
    SP6->data = 12;
    SP6->left = NULL;
    SP6->right = NULL;
	
	SP7 = new CP;
    SP7->id = 14;
    SP7->data = 10;
    SP7->left = NULL;
    SP7->right = NULL;
	//################## */
    
    // Make the connections
    SP0->left = SP1;
    SP0->right = SP4;
    
    SP1->left = SP2;
    SP1->right = SP3;
   /* 
	SP3->right = SP5;
	SP5->left = SP6;
	SP2->left = SP7; */
    // Make the head pointer to point to the head of the tree
    SP = SP0;
}