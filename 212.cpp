//212. Word Search II

class Solution 
{

private:
    
    struct TrieNode
    {
        unordered_map<char,unique_ptr<TrieNode>> leave;
        bool is_string=false;
    };
    
    class Trie
    {
    private:
        
        unique_ptr<TrieNode> root_=make_unique<TrieNode>(TrieNode());
        
    public:
        bool insert(const string& word)
        {
            TrieNode* root=root_.get();
            
            for(char c:word)
            {
                if(root->leave.find(c)==root->leave.end())
                    root->leave[c]=make_unique<TrieNode>(TrieNode());
                root=root->leave[c].get();
            }
            
            if(!root->is_string)
                return root->is_string=true;
            
            return false;
        }
        
        TrieNode* getRoot()
        {
            return root_.get();
        }
    };
    
    bool validCheck(int i,int j,int M,int N)
    {
        return i>=0&&j>=0&&i<M&&j<N;
    }
    
    void DFS(int i,int j,string partial,TrieNode* root,vector<string>& result,vector<vector<char>> board)
    {
        if(board[i][j]=='$')
            return;
        
        partial +=board[i][j];
        
        if(root->is_string)
        {
            result.emplace_back(partial);
            root->is_string=false; 
        }
        
        char curr=board[i][j];
        board[i][j]='$';
        
        int row=i+1;int col=j;
        if(validCheck(row,col,board.size(),board[0].size())&&root->leave.find(board[row][col])!=root->leave.end())
            DFS(row,col,partial,root->leave[board[row][col]].get(),result,board);
        
        row=i;col=j+1;
        if(validCheck(row,col,board.size(),board[0].size())&&root->leave.find(board[row][col])!=root->leave.end())
            DFS(row,col,partial,root->leave[board[row][col]].get(),result,board);
        
        row=i-1;col=j;
        if(validCheck(row,col,board.size(),board[0].size())&&root->leave.find(board[row][col])!=root->leave.end())
            DFS(row,col,partial,root->leave[board[row][col]].get(),result,board);
        
        row=i;col=j-1;
        if(validCheck(row,col,board.size(),board[0].size())&&root->leave.find(board[row][col])!=root->leave.end())
            DFS(row,col,partial,root->leave[board[row][col]].get(),result,board);
        
        board[i][j]=curr;
        return;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        Trie wordTree=Trie();
        
        for(string s:words)
            wordTree.insert(s);
 
        string partial;
        vector<string> result;
        int M=board.size();int N=board[0].size();
        TrieNode* root=wordTree.getRoot();
            
        for(int i=0;i<M;++i)
            for(int j=0;j<N;++j)
            {
                if(root->leave.find(board[i][j])!=root->leave.end())
                    DFS(i,j,partial,root->leave[board[i][j]].get(),result,board);
            }
        return result;
    }
};