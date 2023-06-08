vector<int> topView(Node* root) {
        vector<int> ans;
        if(root == NULL) 
        {
            return ans;
        }
        
        map<int,int> topnode;
        queue<pair<Node*, int> > q;
        q.push(make_pair(root, 0));
        
        while(!q.empty())
        {
            pair<Node*,int> temp=q.front();
            q.pop();
            Node* firstnode=temp.first;
            int horizontaldistance= temp.second;
            if(topnode.find(horizontaldistance)==topnode.end())
            {
                topnode[horizontaldistance]=firstnode->data;
            }
            
            if(firstnode->left)
            {
                q.push(make_pair(firstnode->left, horizontaldistance-1));
            }
            if(firstnode->right)
            {
                q.push(make_pair(firstnode->right, horizontaldistance+1));
            }
        }
        for(auto i:topnode)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
