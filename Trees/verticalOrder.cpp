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
void verticalOrder(node* root)
{
	int i, j;
	vector<vector<int>> v;
	if(root == NULL) return ;
	queue<pair<node*, int>> q;
	q.push({root, 0});
	map<int, vector<int>> mp;
	while(!q.empty()) {
		pair<node*, int> temp = q.front();
        q.pop();
         if(temp.first->left){
            q.push({temp.first->left, temp.second-1});
        }
        if(temp.first->right){
            q.push({temp.first->right, temp.second+1});
        }
        mp[temp.second].push_back(temp.first->data);
	}
	map<int, vector<int> >::iterator it;
	for(it = mp.begin(); it != mp.end(); it++) {
		v.push_back(it->second);
	}
	for(i = 0; i < v.size(); i++) {
		for(j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return ;	
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
	verticalOrder(root);
	cout<<endl;
	return 0;
	
}
