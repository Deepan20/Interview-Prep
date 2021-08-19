/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
Input:
7
64 34 25 12 22 11 90
Output:
11 22 12 25 34 64 90
*/
#include<iostream>
using namespace std;

void bubblesort(int *a,int n){
    bool swap;
    for(int i=0;i<n;i++){
        swap=false;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){ 
            a[j]=(a[j]+a[j+1])-(a[j+1]=a[j]); //swap two elements without extra space (temp)
            swap=true;
            }
        }
        if(swap==false) break;
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    bubblesort(a,n);
    for(int i=0;i<n;i++) cout <<a[i]<<" ";
}