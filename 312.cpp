//312 burst ballons

class Solution 
{
public:
    int maxCoins(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        int M=nums.size();
        vector<vector<int>> rangeCoin(M+2,vector<int>(M+2,0));

        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        for(int len=1;len<=M;++len)
            for(int start=1;start<=M-len+1;++start)
            {
                int end=start+len-1;
                int maxCoin=0;
                for(int final=start;final<=end;++final)
                {
                    int coin=rangeCoin[start][final-1]+rangeCoin[final+1][end];
                    coin+=nums[start-1]*nums[final]*nums[end+1];
                    maxCoin=max(maxCoin,coin);
                }
                rangeCoin[start][end]=maxCoin;
            }
        return rangeCoin[1][M];
    }
};