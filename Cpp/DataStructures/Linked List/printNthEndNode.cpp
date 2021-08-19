#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
//creating the new Node
Node *newNode(int ele){
    Node *nn=new Node();
    nn->data=ele;
    nn->next=NULL;
    return nn;
}
//insert the node at the end of the list
Node *insert(Node **root,int ele){
    Node *nn=newNode(ele);
    if(*root==NULL) *root=nn;
    else{
        Node *temp=*root;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=nn;
    }
    return *root;
}
//print the end node in linked list
void nthnode(Node *root){
    Node *temp=root;
    while(temp->next!=NULL) temp=temp->next;
    cout << temp->data;
}
int main(){
    Node *root=NULL;
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        root=insert(&root,a[i]);
    }
    nthnode(root);
    return 0;
}
