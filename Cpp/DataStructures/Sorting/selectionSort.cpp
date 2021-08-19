/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element from unsorted part and putting it at the beginning1
Input:
7
64 34 25 12 22 11 90
Output:
11 22 12 25 34 64 90
*/
#include<iostream>
using namespace std;
void selectionsort(int *a,int n){
    int min;
    for(int i=0;i<n;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) min=j;
        }
        a[i]=(a[i]+a[min])-(a[min]=a[i]);
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    selectionsort(a,n);
    for(int i=0;i<n;i++) cout << a[i] <<" ";
}