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
//insert a node at the end of the linked list
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
//reverse a linked list 
void reverse(Node **root){
    Node *next=NULL;
    Node *curr=*root;
    Node *prev=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *root=prev;
}
//display the node in the linked list
void display(Node *root){
    while(root!=NULL){
        cout << root->data <<" ";
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
    //display(root);
    reverse(&root);
    //cout << "\n";
    display(root);
    return 0;
}