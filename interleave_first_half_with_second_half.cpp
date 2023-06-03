#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    int e=q.size();
    int s=0;
    int mid=(s+e)/2;
    vector<int>first;
    vector<int>second;
    int num;
  
    for(int i=0;i<mid;i++)
    {
        num=q.front();
        q.pop();
        first.push_back(num);
        
    }
    for(int i=mid;i<e;i++)
    {
        num=q.front();
        q.pop();
        second.push_back(num);
        
    }
    
    for(int i=0;i<mid;i++)
    {
        q.push(first[i]);
        q.push(second[i]);
    }
}
