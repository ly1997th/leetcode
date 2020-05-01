class Solution 
{
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int M=dungeon.size(),N=dungeon[0].size();
        //health元素代表从当前节点到公主节点的最小生命值
        vector<vector<int>> health(M,vector<int>(N,0));
        //初始化公主节点
        health[M-1][N-1]=1;
        if(dungeon[M-1][N-1]<0)
            health[M-1][N-1]=health[M-1][N-1]-dungeon[M-1][N-1];
        else
            health[M-1][N-1]=(health[M-1][N-1]-dungeon[M-1][N-1])>0?health[M-1][N-1]-dungeon[M-1][N-1]:1;  
        //开始循环更新列表，如果遇见负值就减去该值；如果正值，就看是否可以覆盖health中的负债，可以就设为1，不可以就减少对应负债
        for(int i=M-1;i>=0;--i)
            for(int j=N-1;j>=0;--j)
                if(!(i==M-1 && j==N-1)) 
                {
                    int t1=INT_MAX,t2=INT_MAX;
                    //向下更新
                    if(i+1<M)
                        if(dungeon[i][j]<0)
                            t1=health[i+1][j]-dungeon[i][j];
                        else
                            t1=(health[i+1][j]-dungeon[i][j])>0?health[i+1][j]-dungeon[i][j]:1;
                    //向右更新
                    if(j+1<N)
                        if(dungeon[i][j]<0)
                            t2=health[i][j+1]-dungeon[i][j];
                        else
                            t2=(health[i][j+1]-dungeon[i][j])>0?health[i][j+1]-dungeon[i][j]:1;
                    health[i][j]=min(t1,t2);
                }
        return health[0][0];
    }
};