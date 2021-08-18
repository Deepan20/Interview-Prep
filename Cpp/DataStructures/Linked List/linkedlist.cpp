#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
Node *newNode(int ele){
    Node *nn=new Node();
    nn->data=ele;
    nn->next=NULL;
    return nn;
}
//insert the element at the begining of the list
void push(Node **root,int ele){
    Node *nn=new Node();
    nn->data=ele;
    nn->next=*root;
    *root=nn;
}
//insert the element at the end of the array
Node *append(Node **root,int ele){
    Node *nn=newNode(ele);
    if(*root==NULL) *root=nn;
    else{
        Node *temp=*root;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=nn;
    }
    return *root;
}
//display the linked list
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
        //push(&root,a[i]);
        root=append(&root,a[i]);
    }
    display(root);
    return 0;
}