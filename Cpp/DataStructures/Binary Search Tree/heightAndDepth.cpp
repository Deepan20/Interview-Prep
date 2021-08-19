#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
};
Node *newNode(int ele){
    Node *nn=new Node();
    nn->data=ele;
    nn->left=nn->right=NULL;
    return nn;
}
Node *insert(Node *root,int ele){
    Node *nn=newNode(ele);
    if(root==NULL) root=nn;
    else{
        if(root->data>ele) root->left=insert(root->left,ele);
        else if(root->data<ele) root->right=insert(root->right,ele);
    }
    return root;
}
int height(Node *root){
    if(root==NULL) return 0;
    int left=height(root->left);
    int right=height(root->right);
    if(left>right) return left+1;
    else return right+1;
}
int depth(Node *root){
    if(root==NULL) return 0;
    int left=1+depth(root->left);
    int right=1+depth(root->right);
    if(left>right) return left;
    else return right;
}
int main(){
    Node *root=NULL;
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        root=insert(root,a[i]);
    }
    cout << "heoght : " << height(root);
    cout << "\ndepth : "  << depth(root);
}