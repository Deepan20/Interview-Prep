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
    nn->left=NULL;
    nn->right=NULL;
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
int minimum(Node *root){
    while(root->left!=NULL) 
        root=root->left;
    return root->data;
}
int maximum(Node *root){
    while(root->right!=NULL) 
        root=root->right;
    return root->data;
}
int main(){
    Node *root=NULL;
    int n;
    cin >>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >>a[i];
        root=insert(root,a[i]);
    }
    cout << "the minimum element is " << minimum(root);
    cout << "\nthe maximum element is " << maximum(root);
}