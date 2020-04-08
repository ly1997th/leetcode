//135.分发糖果
class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        int length=ratings.size();
        vector<int> candyLeft(length,1);
        vector<int> candyRight(length,1);

        for(int i=0;i<length-1;++i)
            if(ratings[i]<ratings[i+1])
                candyLeft[i+1]=candyLeft[i]+1;
        for(int i=length-1;i>0;--i)
            if(ratings[i]<ratings[i-1])
                candyRight[i-1]=candyRight[i]+1;

        int sum=0;
        for(int i=0;i<length;++i)
            sum+=max(candyLeft[i],candyRight[i]);

        return sum;
    }
};