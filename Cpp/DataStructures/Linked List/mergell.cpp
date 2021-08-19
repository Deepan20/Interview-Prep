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
//merge two linked list
Node *merge(Node *l1,Node *l2){
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    if(l1->data>l2->data){
        Node *temp=l1;
        l1=l2;
        l2=temp;
    }
    Node *res=l1;
    while(l1!=NULL && l2!=NULL){
        Node *ptr=NULL;
        while(l1!=NULL && l1->data<=l2->data){
            ptr=l1;
            l1=l1->next;
        }
        ptr->next=l2;
        Node *temp=l1;
        l1=l2;
        l2=temp;
    }
    return res;
}
//display nodes in linked list
void display(Node *root){
    while(root!=NULL){
        cout << root->data << " ";
        root=root->next;
    }
}
int main(){
    Node *root1=NULL;
    Node *root2=NULL;
    Node *res=NULL;
    int n,m;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        root1=insert(&root1,a[i]);
    }
    cin >> m;
    int b[m];
    for(int i=0;i<m;i++){
        cin >> b[i];
        root2=insert(&root2,b[i]);
    }
    //display(root1);
    //display(root2);
    res=merge(root1,root2);
    display(res);
    return 0;
}