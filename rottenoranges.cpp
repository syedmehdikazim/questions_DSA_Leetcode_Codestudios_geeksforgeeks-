int minTimeToRot(vector<vector<int>>& a, int n, int m)
{
    int totaltwos=0;
    queue <int>rowq;
    queue <int>colq;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==2)
            {
                rowq.push(i);
                colq.push(j);
                totaltwos++;
            }
        }
    }
    int count=0;
    int cnt=0;
    while(!rowq.empty()&&!colq.empty())
    {
        int rowind=rowq.front();
        int colind=colq.front();

        //for cheacking on down
        if(rowind+1<n && a[rowind+1][colind]==1)
        {
            a[rowind+1][colind]=2;
            rowq.push(rowind+1);
            colq.push(colind);
            cnt++;
        }
        //up
        if(rowind-1>=0 && a[rowind-1][colind]==1)
        {
            a[rowind-1][colind]=2;
            rowq.push(rowind-1);
            colq.push(colind);
            cnt++;
        }
        //right
        if(colind+1<m && a[rowind][colind+1]==1 )
        {
            a[rowind][colind+1]=2;
            rowq.push(rowind);
            colq.push(colind+1);
            cnt++;
        }
        //left
        if(colind-1>=0 && a[rowind][colind-1]==1 )
        {
            a[rowind][colind-1]=2;
            rowq.push(rowind);
            colq.push(colind-1);
            cnt++;
        }
        rowq.pop();
        colq.pop();
        totaltwos--;
        
        if(totaltwos==0)
        {
            totaltwos=cnt;
            if(cnt==0)
            {
                break;
            }
            count++;
            cnt=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==1)
            {
                return -1;
            }
        }
    }
    return count;
}
