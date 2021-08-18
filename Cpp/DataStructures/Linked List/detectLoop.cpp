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
//to detect the loop
int detectLoop(Node *root){
    Node *fast=root;
    Node *slow=root;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return 1;
            break;
        }
    }
    return 0;
}
//display the list
void display(Node *temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next; 
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
    root->next->next->next=root->next;     //creating the loop
    if(detectLoop(root)==1) cout << "Loop is detected";
    else cout << "Loop not detected";
}