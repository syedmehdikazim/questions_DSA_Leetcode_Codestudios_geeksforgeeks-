#include <bits/stdc++.h> 
#include<algorithm>
vector<int> Klargest(vector<int> &a, int k, int n) {
    sort(a.begin(),a.end());
    vector<int>ans;
    for(int i=n-1;i>n-k-1;i--)
    {
        ans.push_back(a[i]);
    }
    int e=ans.size()-1;
    int s=0;
    while(e>s)
    {
        swap(ans[e],ans[s]);
        s++;
        e--;
    }
    return ans;
}
