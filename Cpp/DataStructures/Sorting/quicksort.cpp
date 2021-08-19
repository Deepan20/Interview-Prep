/*
like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot
Input:
7
64 34 25 12 22 11 90

Output:
11 22 12 25 34 64 90
*/
#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int Partition(int *a,int start,int end){
    int pivot=a[end];
    int i=(start-1);
    for(int j=start;j<end;j++){
        if(a[j]>pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
        swap(&a[i+1],&a[end]);
    return (i+1);
}
void quicksort(int *a,int start,int end){
    if(start<end) {
    int par=Partition(a,start,end);
    quicksort(a,start,par-1);
    quicksort(a,par+1,end);
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    quicksort(a,0,n-1);
    for(int i=n-1;i>=0;i--) cout << a[i]<<" ";
}