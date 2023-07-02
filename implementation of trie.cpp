/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class trienode
{
	public:
		char data;
		trienode* children[26];
		bool isterminal;
		
		trienode(char ch)
		{
			data=ch;
			for(int i=0;i<26;i++)
			{
				children[i]=NULL;
			}
			isterminal=false;
		}
};

class Trie {

public:
    trienode*root;
    /** Initialize your data structure here. */
    Trie() {
        root=new trienode('\0');
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
				root->children[index]=child;
			}
			// recursion
			
			insertutil(child, word.substr(1));
		}
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertutil(root,word);
    }
    bool searchutil(trienode* root, string word)
		{
			//base case
			if(word.length()==0)
			{
				return root->isterminal;
			}
			int index=word[0]-'a';
			trienode* child;
			// char is present
			
			if(root->children[index]!=NULL)
			{
				child=root->children[index];
			}
			
			//absent
			else
			{
				return false;
			}
			
			return searchutil(child,word.substr(1));
		}
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchutil(root,word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool prefixutil(trienode* root, string word)
		{
			//base case
			if(word.length()==0)
			{
				return true;
			}
			int index=word[0]-'a';
			trienode* child;
			// char is present
			
			if(root->children[index]!=NULL)
			{
				child=root->children[index];
			}
			
			//absent
			else
			{
				return false;
			}
			
			return prefixutil(child,word.substr(1));
		}
    bool startsWith(string prefix) {
        return prefixutil(root,prefix);
    }
};
