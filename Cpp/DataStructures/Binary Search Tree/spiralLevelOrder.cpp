#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
};
void printLevelOrder(Node *root,int level,bool spiral);
Node *newNode(int ele){
    Node *nn=new Node();
    nn->data=ele;
    nn->left=NULL;
    nn->right=NULL;
}
Node *insert(Node *root,int ele){
    Node *nn=newNode(ele);
    if(root==NULL) root=nn;
    else{
        if(root->data>ele) root->left=insert(root->left,ele);
        else if(root->data<ele) root->right=insert(root->right,ele);
    }
}
int height(Node *root){
    if(root==NULL) return 0;
    int left=height(root->left);
    int right=height(root->right);
    if(left>right) return left+1;
    else return right+1;
}
void spiralLevelOrder(Node *root){
    int h=height(root);
    bool spiral=false;
    for(int i=1;i<=h;i++){
        printLevelOrder(root,i,spiral);
        spiral=!spiral;
    }
}
void printLevelOrder(Node *root,int level,bool spiral){
    if(root==NULL) return;
    if(level==1){
        cout << root->data << " ";
    }
    if(level>1){
        if(spiral){
            printLevelOrder(root->left,level-1,spiral);
            printLevelOrder(root->right,level-1,spiral);
        }
        else{
            printLevelOrder(root->right,level-1,spiral);
            printLevelOrder(root->left,level-1,spiral);
        }
    }
}

int main(){
    Node *root=NULL;
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >>a[i];
        root=insert(root,a[i]);
    }
    spiralLevelOrder(root);
}