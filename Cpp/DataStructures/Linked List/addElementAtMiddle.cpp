#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
//create the new Node
Node *newNode(int ele){
    Node *nn=new Node();
    nn->data=ele;
    nn->next=NULL;
    return nn;
}
//insert the node at the end
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
//add the element at the middle of the linked list
void addElementAtMiddle(Node *root,int ele){
    Node *nn=new Node();
    nn->data=ele;
    Node *fast=root;
    Node *slow=root;
    Node *middle;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        middle=slow;
        slow=slow->next;
    }
    middle->next=nn;
    nn->next=slow;
}
//display the list
void display(Node *root){
    while(root!=NULL){
        cout << root->data<<" ";
        root=root->next;
    }
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
    addElementAtMiddle(root,30);
    display(root);
}