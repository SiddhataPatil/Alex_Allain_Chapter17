/*
 ==============================================================================================================================
 Name        : remove.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright ©  Siddhata Pati and GeeksforGeeks(void inorder(struct node *root), struct node * minValueNode(struct node* node),
               struct node* remove1(struct node* root, int key)). Sourcecode rights reserved.
 Copyright   : Copyright ©  Alex_Allain_Jumping_into_Cpp_Book. Question rights reserved.
 Question    : Remove an element from a binary tree Case 1: It has no children. Case 2: Has one Child Case 3: Has two children
 ==============================================================================================================================
 */

#include <iostream>
using namespace std;

struct node
{
    node* left;
    node* right;
    int data;
};


node* insert1 (node *tree, int new_data)
{
    if(tree == NULL)
    {
        node *new_tree = new node;
        new_tree->left=NULL;
        new_tree->right=NULL;
        new_tree->data=new_data;
        return new_tree;
    }
    if (new_data < tree->data)
    {
        tree->left = insert1(tree->left, new_data);
    }
    else
        tree->right = insert1(tree->right, new_data);
}

node* maximum(node* tree)
{
    if(tree==NULL) return NULL;
    if(tree->right==NULL) return tree;
    else return maximum(tree->right);
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
/* Given a non-empty binary search tree, return the node with minimum
key value found in that tree. Note that the entire tree does not
need to be searched. */
struct node * minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

/* Given a binary search tree and a key, this function deletes the key
and returns the new root */
struct node* remove1(struct node* root, int key)
{
	// base case
	if (root == NULL) return root;

	// If the key to be deleted is smaller than the root's key,
	// then it lies in left subtree
	if (key < root->data)
		root->left = remove1(root->left, key);

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (key > root->data)
		root->right = remove1(root->right, key);

	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		struct node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->data = temp->data;

		// Delete the inorder successor
		root->right = remove1(root->right, temp->data);
	}
	return root;
}


void print1(node* p1)
{
    cout<<"                          "<<p1->data<<endl;
    cout<<"      "<<p1->left->data;
    cout<<"                                      "<<p1->right->data<<endl;
    cout<<p1->left->left->data;
    cout<<"              "<<p1->left->right->data;
    cout<<"                 "<<p1->right->left->data;
    cout<<"                          "<<p1->right->right->data;
}



int main()
{
node* p = NULL;
node* p1;
p = insert1 (p, 10);
p = insert1 (p, 6);
p = insert1 (p, 5);
p = insert1 (p, 7);
p = insert1 (p, 14);
p = insert1 (p, 18);
p = insert1 (p, 11);
print1(p);

p1 = remove1(p,6);
cout<<endl;
inorder(p);
p1 = remove1(p,7);
cout<<endl;
inorder(p);
p1 = remove1(p,10);
cout<<endl;
inorder(p);
cout<<endl;

system ("pause");
return 0;
}


/*
node* remove1(node* tree, int value)
{
    if(tree==NULL)
    {
        return NULL;
    }
    if(tree->data==value)
    {

        if ( tree->left == NULL )
        {
        node* right_subtree = tree->right;
        tree->data=0;
        delete tree;
        return right_subtree;
        }
        if ( tree->right == NULL )
        {
        node* left_subtree = tree->left;
        tree->data=0;
        delete tree;
        return left_subtree;
        }
        node* max_node = maximum( tree->left );
        max_node->left = tree->left;
        max_node->right = tree->right;
        tree->data=0;
        delete tree;
        return max_node;
    }
    else if (tree->data > value)
    {
         return remove1(tree->left,value);
    }
    else if (tree->data < value)
    {
         return remove1(tree->right,value);
    }
}
*/

/*
node* remove_max_node (node* tree, node* max_node)
{
if ( tree == NULL )
{
return NULL;
}
// we found or node, now we can replace it
if ( tree == max_node )
{
// the only reason we can do this is because we know
// p_max_node->p_right is NULL so we aren’t losing
// any information. If p_max_node has no left sub-tree,
// then we will just return NULL from this branch, which
// will result in p_max_node being replaced with an empty tree,
// which is what we want.
return max_node->left;
}
// each recursive call replaces the right sub-tree tree with a
// new sub-tree that does not contain p_max_node.
tree->right = remove_max_node( tree->right, max_node );
return tree;
}
node* remove1 (node* p_tree, int key)
{
if ( p_tree == NULL )
{
return NULL;
}
if ( p_tree->data == key )
{
// the first two cases handle having zero or one child node
if ( p_tree->left == NULL )
{
node* p_right_subtree = p_tree->right;
delete p_tree;
// this might return NULL if there are zero child nodes,
// but that is what we want anyway
return p_right_subtree;
}
if ( p_tree->right == NULL )
{
node* p_left_subtree = p_tree->left;
delete p_tree;
// this will always return a valid node, since we know
// is not NULL from the previous if statement
return p_left_subtree;
}
node* p_max_node = maximum( p_tree->left );
// since p_max_node came from the left sub-tree, we need to
// remove it from that sub-tree before re-linking that sub-tree
// back into the rest of the tree
p_max_node->left =
remove_max_node( p_tree->left, p_max_node );
p_max_node->right = p_tree->right;
delete p_tree;
return p_max_node;
}
else if ( key < p_tree->data )
{
p_tree->left = remove1( p_tree->left, key );
}
else
{
p_tree->right = remove1( p_tree->right, key );
}
return p_tree;
}
*/
