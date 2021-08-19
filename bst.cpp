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
void preorder(Node *root){
    if(root!=NULL){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout <<  root->data << " ";
    }
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
    inorder(root);
    cout << "\n";
    preorder(root);
    cout << "\n";
    postorder(root);
}