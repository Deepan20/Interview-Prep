/*
Pairwise swap elements of a given linked list

*/
#include<iostream>
#include<algorithm>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
//create the new node
Node *newNode(int ele){
    Node *nn=new Node();
    nn->data=ele;
    nn->next=NULL;
    return nn;
}
//insert the node at the end of the linked list
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
// swap the the node pairwise
Node *pairwiseSwap(Node *root){
    Node *temp=root;
    while(temp!=NULL && temp->next!=NULL){
        swap(temp->data,temp->next->data);
        temp=temp->next->next;
    }
    return root;
}
//display the Node in the list
void display(Node *root){
    while(root!=NULL){
        cout << root->data<<" ";
        root=root->next;
    }
}
int main(){
    Node *root=NULL;
    int n;
    cin >>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        root=insert(&root,a[i]);
    }
    pairwiseSwap(root);
    display(root);
    return 0;
}