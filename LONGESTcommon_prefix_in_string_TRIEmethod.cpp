class trienode
{
	public:
		char data;
		trienode* children[26];
		bool isterminal;
		int childcount;
		trienode(char ch)
		{
			data=ch;
			for(int i=0;i<26;i++)
			{
				children[i]=NULL;
			}
            childcount=0;
			isterminal=false;
		}
};
class trie {

public:
    trienode*root;
    /** Initialize your data structure here. */
    trie(char ch) {
        root=new trienode(ch);
    }
    void insertutil(trienode*root, string word)
		{
			//base case
			if(word.length()==0)
			{
				root->isterminal=true;
				return;
			}
			
			int index=word[0]-'a';
			trienode*child;
			
			//if char is present
			
			if(root->children[index]!=NULL)
			{
				child=root->children[index];
			}
			//if not present
			
			else
			{
				child= new trienode(word[0]);
                root->childcount++;
				root->children[index]=child;
			}
			// recursion
			
			insertutil(child, word.substr(1));
		}
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertutil(root,word);
    }

    void lcp(string s, string &ans)
    {
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];

            if(root->childcount==1)
            {
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }
            else{
                break;
            }
            if(root->isterminal)
            {
                break;
            }
        }
    }
    
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    trie*t=new trie('\0');

    for(int i=0;i<n;i++)
    {
        t->insert(arr[i]);
    }

    string s=arr[0];
    string ans="";

    t->lcp(s,ans);
    return ans;


}
