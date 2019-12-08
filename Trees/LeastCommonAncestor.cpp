#include<bits/stdc++.h>
using namespace std;

struct node{
	node* left;
	node* right;
	int data;
};
node* newNode(int val)
{
 node *temp = new node;
 temp->data = val;
 temp->left = NULL;
 temp->right = NULL;
 return temp;
}
node* insert1(node* root, int val)
{
    if(!root) return newNode(val);
    if(root->data > val)
        root->left = insert1(root->left, val);
    else
        root->right = insert1(root->right, val);
    return root;

}
void inorder(node* root)
{
    if(root){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int find1(node *root, int val)
{
    if(!root) return 0;
    if(root->data == val) return 1;
    if(((root->left) && find1(root->left, val)) || ((root->right) && find1(root->right, val)))
        return 1;
    return 0;
}
node* lca(node* root, int val1, int val2)
{
    if(!root || root->data == val1 || root->data == val2) return root;
    node* L = lca(root->left, val1, val2);
    node* R = lca(root->right, val1, val2);
    if(L && R) return root;
    return L ? L : R;
}
int main()
{
	int n;
	int x ;
	int i;
	int val1;
	int val2;
	vector<int> v1;
	vector<int> v2;
	node* root = NULL;
	cin >> n;
	cin >> x;
	root = insert1(root, x);
	for (i = 0; i < n-1; i++) {
        int r;
        cin >> r;
        insert1(root, r);
	}
	inorder(root);
    cin >> val1 >> val2;
    if (!find1(root, val1) || !find1(root, val2))
        return -1;
    node* ancestor = lca(root, val1, val2);
    if(ancestor){
        cout << ancestor->data << endl;
        return ancestor->data;
    }
    return -2;
}
