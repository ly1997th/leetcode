//140. Word Break II

class Solution 
{
private:
    bool findSentences(string &s, int start,vector<bool> &dp, string partial,unordered_set<string>& words,unordered_set<string>& result)
    {
        if(start==s.size())
        {
            result.emplace(partial);
            return true;
        }
        
        int orig=result.size();
        for(int i=start;i<s.size();++i)
        {
            if(dp[i+1]==true)
            {
                string currWord=s.substr(start,i-start+1);
                if(words.find(currWord)!=words.end())
                {
                    findSentences(s,i+1,dp,partial.empty()?currWord:partial+" "+currWord,words,result);
                }
            }
        }
        dp[start]=(orig!=result.size());
        return true;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        unordered_set<string> result;
        string partial;
        int start=0;
        vector<bool> dp(s.size()+1,true);
        
        findSentences(s,start,dp,partial,words,result);
        
        return vector<string>{result.begin(),result.end()};
    }
};