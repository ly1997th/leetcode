//76. Minimum Window Substring

class Solution 
{
    
public:
    string minWindow(string s, string t) 
    {
        string result;
        if(s.empty()||t.empty()||s.size()<t.size()) return result;
        
        unordered_map<char,int> map;
        for(int i=0;i<t.size();++i)
            if(map.find(t[i])==map.end())
                map[t[i]]=1;
            else
                ++map[t[i]];
        
        int length=0,total=0,tail=0;
        for(int start=0,end=0;end<s.size();++end)
        {
            if(map.find(s[end])==map.end())
                continue;
            if(--map[s[end]]>=0)
                ++total;
            if(total==t.size())
            {
                while(map.find(s[start])==map.end()||map[s[start]]<0)
                {
                    if(map.find(s[start])!=map.end())
                        ++map[s[start]];
                    ++start;
                }
                
                if(length==0||(length>end-start+1)) 
                {
                    length=end-start+1;
                    tail=start; 
                }
            }
        }
        return s.substr(tail,length); 
    }
};