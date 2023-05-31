vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int>ans;
    for (int i=0;i<n;i++)
    {
        if(i==n-1)
        {
            ans.push_back(-1);
        }
        int num=arr[i];
        int count=0;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<num)
            {
                count++;
                ans.push_back(arr[j]);
                break;
            }
        }
        if(count==0)
        {
            ans.push_back(-1);
        }
    }
    return ans;
}
