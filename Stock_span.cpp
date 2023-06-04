//BRUTE FORCE

vector<int> findSpans(vector<int> &price) {
    
    int n=price.size();
    vector <int>ans;
    int cnt=0;
    // Write your code here.
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>=0;j--)
        {
            if(price[i]>=price[j])
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        ans.push_back(cnt);
        cnt=0;
    }
    return ans;
}
// OPTIMAL APPROACH USING QUEUE

vector<int> findSpans(vector<int>& price) {
    int n = price.size();
    vector<int> ans;
    deque<int> dq;
    dq.push_front(0);
    ans.push_back(1);

    for (int i = 1; i < n; i++) {
        while (!dq.empty() && price[i] >= price[dq.back()]) {
            dq.pop_back();
        }

        if (dq.empty()) {
            ans.push_back(i + 1);
        } else {
            int num = i - dq.back();
            ans.push_back(num);
        }

        dq.push_back(i);
    }

    return ans;
}

