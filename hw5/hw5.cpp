#include <iostream>
#include <stack>
using namespace std;`

class node{
public:
int val;
node* left;
node* right;
bool istraversed=false;
};


void printdfs(node* root){
stack<node*> s;
s.push(root);

while(!s.empty()){

    node *temp = s.top();
    if(temp->istraversed==false){
        cout<<temp->val<<" ";
        temp->istraversed=true;
    }
    if(temp->left!=NULL){
        if(temp->left->istraversed==false){
            s.push(temp->left);
            continue;
        }
    }
    if(temp->right!=NULL){
        if(temp->right->istraversed==false){
            s.push(temp->right);
            continue;
        }
    }
    s.pop();
}
}
int main()
{
  node* root;
root->val=2;
cout<<root->val<<",";

root->left->val = 7;
cout<<root->left->val<<",";
root->right->val = 5;
cout<<root->right->val<<",";

root->left->left->val=2;
cout<<root->left->left->val<<",";
root->left->right->val=6;
cout<<root->left->right->val<<",";
root->right->left->val=NULL;
cout<<root->left->right->val<<",";
root->right->right->val=9;
cout<<root->left->right->val<<",";

root->left->left->left->val=NULL;
cout<<root->left->right->val<<",";
root->left->left->right->val=NULL;
cout<<root->left->right->val<<",";
root->left->right->left->val=5;
cout<<root->left->right->val<<",";
root->left->right->right->val=11;
cout<<root->left->right->val<<",";
root->right->right->left->val=4;
cout<<root->left->right->val<<",";
root->right->right->right->val=NULL;
cout<<root->left->right->val<<",";

printdfs(root);

return 0;
}
