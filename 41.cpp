//41. First Missing Positive 
class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        unordered_set<int> p(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i)
            if(p.find(i+1)==p.end())
                return i+1;
        return nums.size()+1;
            
    }
};