//BRUTE FORCE

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    int n=nums.size();
    int maxi=-1000001;
    int i;
    vector<int>ans;
    for(i=0;i<k;i++)
    {
        maxi=max(maxi,nums[i]);
        
    }
    if(i==n)
    {
        ans.push_back(maxi);
        return ans;
    }
    ans.push_back(maxi);
    
    maxi=0;
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<i+k;j++)
        {
            maxi=max(maxi,nums[j]);
        }
        ans.push_back(maxi);
        if(i+k==n)
        {
            break;
        }
        maxi=0;
    }
    return ans;
}

//OPTIMAL APPROACH USING DQUEUE

ector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < n; i++)
    {
        // Remove elements from the front of the deque that are outside the window
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // Remove elements from the back of the deque that are smaller than the current element
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }

        // Add the current element to the deque
        dq.push_back(i);

        // If the window size is reached, add the maximum element to the result
        if (i >= k - 1)
        {
            
            
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}
