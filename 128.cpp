//128. Longest Consecutive Sequence

class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int longest=0;
        if(nums.empty()) return longest;
        unordered_set<int> search(nums.begin(),nums.end()),res;

        for(int i:nums)
        {
            if(res.find(i)!=res.end()) continue;
            res.insert(i);
            int m=i-1,n=i+1;
            while(search.find(m)!=search.end()) res.insert(m--);
            while(search.find(n)!=search.end()) res.insert(n++);
            longest=max(longest,n-m-1);
        }

        return longest;    
    }
};