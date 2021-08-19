#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
};
void printlevelOrder(Node *root,int level);
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
int height(Node *root){
    if(root==NULL) return 0;
    int left=height(root->left);
    int right=height(root->right);
    if(left>right) return left+1;
    else return right+1;
}
void levelOrder(Node *root){
    int h=height(root);
    for(int i=1;i<=h;i++)
    printlevelOrder(root,i);
}
void printlevelOrder(Node *root,int level){
    if(root==NULL) return ;
    if(level==1){
        cout << root->data << " ";
    }
    if(level > 1){
        printlevelOrder(root->left,level-1);
        printlevelOrder(root->right,level-1);
    }
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
    levelOrder(root);
}