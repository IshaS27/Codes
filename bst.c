#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct Node
{
	int key;
	struct Node* right;
	struct Node* left;
};

struct Node* newn(int k)
{
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->key=k;
	newnode->left=newnode->right=NULL;

	return newnode;
}


struct Node* addval(struct Node *root,int k) // struct Node *root =NULL;  root = addval(root,12);
{
	if(root == NULL)
		return newn(k);

	if(k < root->key) //less than = left
		root->left = addval(root->left,k);

	else if(k >= root->key) //greater than = right
		root->right = addval(root->right,k);

	return root;

}

struct Node* minmax(struct Node* root)
{
	struct Node *curr=root;
	while(curr && curr->left != NULL) //min
	{
		curr = curr->left;
	}
	return curr;
	//printf("\n Min: %d \n",curr->key);

	// curr=root;
	// while(curr && curr->right != NULL) //max
	// {
	// 	curr = curr->right;
	// }
	// printf("\n Max: %d \n",curr->key);
}

struct Node* deleteval(struct Node* root,int k) //root = deleteval(root,2);
{
    if (root == NULL) 
    	return root; 

    if (k < root->key) //left leaf
        root->left = deleteval(root->left, k); 

    else if (k > root->key) //right leaf
        root->right = deleteval(root->right, k); 
		
    else //1 child/no children
    { 
        if (root->left == NULL) 
        { 
            struct Node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct Node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        //2 children
        struct Node* temp = minmax(root->right); //min
        root->key = temp->key;          
        // Delete the inorder successor 
        root->right = deleteval(root->right, temp->key); 
    } 
    return root;
}

void printbst(struct Node* root)
{
	if(root!=NULL)
	{
		printbst(root->left);
		printf("%d  ",root->key);
		printbst(root->right);
	}
}

struct Node* search(struct Node *root,int k) //assuming no duplicates/will be found though
{	
	if(root == NULL || root->key==k)
		return root;

	if(root->key > k)
		return search(root->left,k);
	else if(root->key < k)
		return search(root->right,k);
	
	/*	struct Node* f = search(root,13);
	if(f!=NULL)
		printf("Key found -- %d \n",f->key);
	else
		printf("Key not found\n");
	printbst(root);*/
}

int maxDepth(struct TreeNode* root){
    
   if (root==NULL)  
       return 0; 
   else 
   { 
       /* compute the depth of each subtree */
       int lDepth = maxDepth(root->left); 
       int rDepth = maxDepth(root->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}