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
int parent(Node *root,Node *par,int ele){
    if(root->data==ele) return par->data;
    if(root->data>ele) return parent(root->left,root,ele);
    else if(root->data<ele) return parent(root->right,root,ele);
}
bool ancester(Node *root,int ele){
    if(root==NULL) return false;
    if(root->data==ele) return true;
    if(ancester(root->left,ele)||ancester(root->right,ele)){
        cout << root->data << " ";
        return true;
    }
    return false;
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
    cout << "Parent = " << parent(root,root,2);
    cout << "\nAncester :";
    ancester(root,20);
}