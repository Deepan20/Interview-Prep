#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
//creating the new node
Node *newNode(int ele){
    Node *nn=new Node();
    nn->data=ele;
    nn->next=NULL;
    return nn;
}
//insert at end
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
//to find the length of the loop
int length(Node *slow){
    int count=1;
    Node *temp=slow;
    while(temp->next!=slow){
		count+=1;
		temp=temp->next;
	}
    return count;
}
//to detect the loop
int detectLoop(Node *root){
    Node *fast=root;
    Node *slow=root;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return length(slow); 
        }
    }
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
    root->next->next->next->next->next=root->next->next;     //creating the loop
    cout << detectLoop(root);
}