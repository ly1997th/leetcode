//301.remove invalid parenthese

class Solution 
{
private:
    void findValidParenthese(int pair,int index,int left_delete,int right_delete,
                                string& s,string solution,unordered_set<string>& res)
    {
        if(index==s.size())
        {
            if(pair==0 && left_delete==0 && right_delete==0) 
                res.insert(solution);
            return;
        }

        if(s[index]=='(')
        {
            if(left_delete>0)   findValidParenthese(pair,index+1,left_delete-1,right_delete,s,solution,res);
            findValidParenthese(pair+1,index+1,left_delete,right_delete,s,solution+'(',res);
        }
        else if (s[index]==')')
            {
                if(right_delete>0) 
                    findValidParenthese(pair,index+1,left_delete,right_delete-1,s,solution,res);
                if(pair>0)
                    findValidParenthese(pair-1,index+1,left_delete,right_delete,s,solution+')',res);
            }
            else
                findValidParenthese(pair,index+1,left_delete,right_delete,s,solution+s[index],res);    
    }
public:
    vector<string> removeInvalidParentheses(string s) 
    {
        unordered_set<string> res;
        int left_delete=0,right_delete=0;

        for(int i=0;i<s.size();++i)
        {
            
            if(s[i]=='(')   ++left_delete;
            else if(s[i]==')')
            {
                if(left_delete>0) --left_delete;
                else    ++right_delete;
            }
        }

        findValidParenthese(0,0,left_delete,right_delete,s,"",res);

        return vector<string>(res.begin(),res.end());
    }
};