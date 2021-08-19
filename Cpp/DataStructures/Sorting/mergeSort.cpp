/*
Like QuickSort, Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.
Input:
7
64 34 25 12 22 11 90

Output:
11 22 12 25 34 64 90
*/
#include<iostream>
using namespace std;
void mergesort(int *a,int *b,int start,int mid,int end){
    int i=start,k=start;
    int j=mid+1;
    while(i<=mid && j<=end){
        if(a[i]<a[j])
            b[k++]=a[i++];
        else 
            b[k++]=a[j++];
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=end)
        b[k++]=a[j++];
    for(int i=start;i<end;i++) cout << a[i] <" ";
}
void merge(int *a,int *b,int start,int end){
    if(start==end)
        return;
    int mid=(start+end)/2;
    merge(a,b,start,mid);
    merge(a,b,mid+1,end);
    mergesort(a,b,start,mid,end);
}
int main(){
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++) cin >> a[i];
    merge(a,b,0,n);
}