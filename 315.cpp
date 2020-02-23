//315. Count of Smaller Numbers After Self

class Solution 
{
public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        vector<int> counts;
        if(nums.empty()) return counts;
        
        for(int i=0;i<nums.size();++i)
        {
            int j=i+1,cou=0;
            while(j<nums.size())
            {
                if(nums[j]<nums[i])
                    cou++;
                ++j;
            }
            counts.push_back(cou);
        }
        return counts;
    }
};