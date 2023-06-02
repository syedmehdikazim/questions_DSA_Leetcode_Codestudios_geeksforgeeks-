queue<int> modifyQueue(queue<int> q, int k) {
    vector<int>arr;
    int num;
    int i=0;
    while(!q.empty())
    {
        num=q.front();
        arr.push_back(num);  // Add elements to the vector using push_back()
        q.pop();
    }
    int m=0;
    int n=k-1;
    while(m<n)
    {
        swap(arr[m],arr[n]);
        m++;
        n--;
    }
    while (!q.empty()) {
        q.pop();
    }
    
    for(int j=0;j<arr.size();j++)
    {
        q.push(arr[j]);
    }
    return q;
}
