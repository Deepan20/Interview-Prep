/*
Array consist of only 0's, 1's and 2's. Write an algorithm to sort  this array in O(n) time complexity and O(1) Space complexity with only one traversal
Input : 0 1 2 0 1 2
Output : 0 0 1 1 2 2
*/
#include<iostream>
using namespace std;
void swap(int *a,int start,int end){
    int temp=a[start];
    a[start]=a[end];
    a[end]=temp;
}
void segregation(int *a,int n){
    int mid=0,start=0;
    int end=n-1;
    while(mid<=end){
        if(a[mid]==0){                  //moving 0's to the front of the array
            swap(a,start,mid);
            start++;
            mid++;
        }
        else if(a[mid]==2){             //moving 2's to the end of the array
            swap(a,mid,end);
            end--;
        }
        else                            //moving 1's to the mid of the array
            mid++;
    }
}
int main(){
    int n;      //size of an array
    cin >> n; 
    int a[n];    
    for(int i=0;i<n;i++) cin >> a[i];    // read the array values
    segregation(a,n);
    for(int i=0;i<n;i++) cout<< a[i] << " ";
}