/*
You have an array of non-negative integers,you are initially positioned at the first index of the array.Each element in the array represents your maximum jump length at that position.Determine if you are able to reach the last index in O(n) Time complexity and O(1) Space Complexity
Input 1:
A = 2,3,1,1,4
Input 2:
A = 3,2,1,0,4
Output 1: 2
Explanation 1: Index 0 -> Index 2 -> Index 4 
Output 2: 0
Explanation 2: Explanation 1: Index 0 -> Index 3 There is no possible path to reach the last index return -1
*/
#include<iostream>
#include<algorithm>
using namespace std;
int JumpGame(int *a,int n){ 
    if(n<=1) return 0;              // The number of jumps needed to reach the starting index is 0 
    if(a[0]==0) return -1;          // Return -1 if not possible to jump 
    int step=a[0];                  // stores the number of steps we can still take 
    int maxStepReach=a[0];          // initially stores all time the maximum reachable index in the array. 
    int jump=1;                     // stores the number of jumps necessary to reach that maximal reachable position. 
    for(int i=1;i<n;i++){
        if(i==n-1) return jump;     // Check if we have reached the end of the array
        maxStepReach=max(maxStepReach,i+a[i]);  // updating maxStepReach
        step--;                     // we use a step to get to the current index
        if(step==0){                // If no further steps left
            jump++;                 // we must have used a jump 
            if(i>=maxStepReach) return -1; // Check if the current index/position or lesser index is the maximum reach point from the previous indexes
            step=maxStepReach-i;    // re-initialize the steps to the amount of steps to reach maxStepReach from position i.
        }      
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    cout<<JumpGame(a,n); 
}