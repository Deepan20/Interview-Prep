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
//add two linked list
Node *addTwoll(Node *l1,Node *l2){
    Node *ptr=newNode(-1);
    Node *temp=ptr;
    int sum=0,carry=0;
    while(l1!=NULL||l2!=NULL||carry){
        sum=0;
        if(l1!=NULL){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node *nn=newNode(sum%10);
        temp->next=nn;
        temp=temp->next;
    }
    return ptr->next;
}
//display node in the linked list
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
    res=addTwoll(root1,root2);
    display(res);
    return 0;
}