/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements in O(n) Time complexity and O(1) Space complexity with single traversal allowed
Input: 0,1,0,3,12
Output: 1,3,12,0,0
*/
#include<iostream>
using namespace std;
void move(int *a,int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]!=0) a[count++]=a[i];        //keeping the number other than 0 in the front of the array
    }
    while(count<n) a[count++]=0;            //place 0 until it reach end 
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    move(a,n);
    for(int i=0;i<n;i++) cout << a[i] << " ";
}