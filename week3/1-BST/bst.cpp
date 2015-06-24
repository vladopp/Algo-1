#include <iostream>

class Node {
public:
  int value;
  Node* left;
  Node* rigth;
};

class BST {
public:

  // Checks if a binary tree is a binary search tree.
  bool isBST(Node* root) {
  	if(root->value > (root->left)->value && root->value < (root->rigth)->value  && root->rigth != 0 && root->left != 0)
	{
	    	return(isBST(root->left) && isBST(root->rigth));
	}
	else if(root->left == 0 && root->value < (root->rigth)->value)
	{
		return isBST(root->rigth);
	}
	else if(root->rigth == 0 && root->value > (root->left)->value)
	{
		return isBST(root->left);
	}
	else if(root->left == 0 && root->rigth == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
  }
};


int main()
{
	return 0;
}