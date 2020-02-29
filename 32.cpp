//32. Longest Valid Parentheses

class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
        stack<int> stk;
        int maxL=0,cur=-1;
        stk.push(-1);
        for(int i=0;i<s.size();++i)
        {
            cur=stk.top();
            if(cur!=-1 && s[cur]=='(' && s[i]==')')
            {
                stk.pop();
                maxL=max(maxL,i-stk.top());
            }
            else
                stk.push(i);
        }

        return maxL;
    }
};