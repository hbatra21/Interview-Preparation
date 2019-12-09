#include<bits/stdc++.h>
using namespace std;
struct node{
	node *left;
	node *right;
	int data;
};
node* newNode(int val){
	node* temp = new node;
	temp->left = temp->right = NULL;
	temp->data = val;
	return temp;
}
node* insert(node* root, int val)
{
	if(!root) return newNode(val);
	if(root->data < val)
		root->right = insert(root->right, val);
	else if(root->data > val)
		root->left = insert(root->left, val);	
	return root;
}
void inorder(node *temp , vector<int> &ans){
     if(temp == NULL)return ;
     inorder(temp->left,ans);
     if(temp->left == NULL && temp->right == NULL)
     	ans.push_back(temp->data);
     inorder(temp->right, ans);
 }
 int height( node* temp) 
{  
   	if(temp == NULL) 
       return 0; 
  	return 1 + max(height(temp->left), height(temp->right)); 
}  
int diameter(node* tree) 
{ 
   if (tree == NULL) 
     return 0; 
  int lheight = height(tree->left); 
  int rheight = height(tree->right); 
  
  int ldiameter = diameter(tree->left); 
  int rdiameter = diameter(tree->right); 
  
  return max(lheight + rheight + 1, max(ldiameter, rdiameter)); 
}  
int main()
{
	int n, i, j;
	vector<int >ans;
	cin >> n;
	node* root = NULL;
	int x;
	cin >> x;
	root = insert(root, x);
	for(i = 1; i < n; i++)
	{
		int y;
		cin>>y;
		insert(root, y);
	}
	int a = diameter(root);
	cout<<a<<endl;
	return 0;
	
}
