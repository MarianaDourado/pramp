#include <iostream>

using namespace std;

struct Node
{
   int key;
   Node *left;
   Node *right;
   Node *parent;
};

// Helper function that allocates a new Node 
Node* newNode( int key )
{
   Node* n = new Node;
   n->key = key;
   n->left = nullptr;
   n->right = nullptr;
   n->parent = nullptr;

   return n;
}

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use 
Node *insert( Node *root, int key )
{
   // 1) If the tree is empty, return a new single Node
   if( root == nullptr )
      return newNode( key );

   Node *temp;

   // 2) Otherwise, recur down the tree
   if( key < root->key )
   {
      temp = insert( root->left, key );
      root->left = temp;
      temp->parent = root;
   } else
   {
      temp = insert( root->right, key );
      root->right = temp;
      temp->parent = root;
   }

   // Return the (unchanged) Node pointer
   return root;
}

// Return a pointer to a Node in the BST by its key.
// Use this fuction when you need a Node to test your 
// findInOrderSuccessor function on
Node *getNodeByKey( Node *root, int key )
{
   Node *currentNode = root;

   while( currentNode )
   {
      if( key == currentNode->key )
         return currentNode;

      if( key < currentNode->key )
         currentNode = currentNode->left;
      else
         currentNode = currentNode->right;
   }

   return nullptr;
}

Node* findInOrderSuccessor( Node *inputNode )
{
  // return null if there is no node
  if(!inputNode) return NULL;
 
   // if there is someone on the right (its already a possible ans)
  if(inputNode->right){
    Node *actual = inputNode->right;
    while(actual->left) actual = actual->left; // lgn
    // return the most left
    return actual;
  }
  // there is no right
  else{
    //, then go up
    Node *father;
    Node *actual = inputNode;
    while(actual->parent){
      father = actual->parent;
      // if i am left child, return my parent
      if(father->left == actual) return father;
      actual = father;
    }
    
    // did not found someone that i am left child? return nullptr
    return NULL;
  }
  

  
}

int main() {
  return 0;
}
