#include<iostream>
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
//to find the middle element of the array
void findMiddle(Node *root){
    Node *fast=root;
    Node *slow=root;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<slow->data;
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
    findMiddle(root);
    return 0;
}