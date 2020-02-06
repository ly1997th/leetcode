//124. Binary Tree Maximum Path Sum

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
private:
    int dfs(TreeNode* root,int &maxsum)
    {
        if(root==NULL)
            return 0;
        int l=max(0,dfs(root->left,maxsum));
        int r=max(0,dfs(root->right,maxsum));
        
        maxsum=max(maxsum,l+r+root->val);
        
        return root->val+max(r,l); 
    }
    
public:
    int maxPathSum(TreeNode* root) 
    {
        int maxsum=INT_MIN;
        dfs(root,maxsum);
        
        return maxsum;
    }
};