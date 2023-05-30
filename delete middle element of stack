#include <bits/stdc++.h> 
#include<math.h>
void solve(stack<int>&inputStack,int cnt, int size)
{
   //base case
    if(cnt == size/2) {
        inputStack.pop();
        return ;
    }
   int num =inputStack.top();
   inputStack.pop();
   
// recursive call
   solve(inputStack,cnt+1,size);
   inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
	int cnt=0;
   // Write your code here
   solve(inputStack,cnt,N);
}
