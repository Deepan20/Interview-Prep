/*
Write an algorithm to find out next greater number to given number with the same set of digits
input= 218765
Ouput= 251678
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
void swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}
void nextLargestNumber(char *digit,int n){
    int i;
    for(i=n-1;i>0;i--){         //Start from the right most digit and find the first digit that is smaller than the digit next to it.
        if(digit[i]>digit[i-1]) break;
    }
    if(i==0){                  // If no such digit is found, then all digits are in descending order means there cannot be a greater number with same set of digits 
        cout << "No Next Largest Number is present";
        return;
    }
    //Find the smallest digit on right side of (i-1)'th digit that is greater than array1[i-1] 
    int element=digit[i-1],smallest=i;
    for(int j=i+1;j<n;j++){
        if(digit[j]>element && digit[j]<digit[smallest])
              smallest=j;
    }
    swap(&digit[smallest],&digit[i-1]);   // Swap the above found smallest digit with array1[i-1] 
    sort(digit+i,digit+n);                //Sort the digits after (i-1) in ascending order 
    cout << "The next Largest Number is " << digit;
}
int main(){
    char *digit;             //initialing size dynamically      
    digit=(char*)malloc(sizeof(char));  //allocating the memory for digit
    cout << "Enter the Number : ";
    cin >> digit;
    int n=strlen(digit);
    nextLargestNumber(digit,n);
}