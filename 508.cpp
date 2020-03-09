//508. most frequent subtree sum

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
    int calSubtreeSum(TreeNode* root,unordered_map<int,int>& map)
    {
        int cur=root->val,sumL=0,sumR=0;
        if(root->left!=NULL) sumL=calSubtreeSum(root->left,map);
        if(root->right!=NULL) sumR=calSubtreeSum(root->right,map);
        int res=cur+sumL+sumR;
        ++map[res];
        return res;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        vector<int> res;
        priority_queue<pair<int,int>> que;
        unordered_map<int,int> map;
        
        calSubtreeSum(root,map);

        for(auto it=map.begin();it!=map.end();++it)
            que.push(make_pair(it->second,it->first));
        int frequent=que.top().first;
        while(que.top().first()==frequent)
        {
            res.push_back(que.top().second);
            que.pop();
        }

        return res;
    }
};