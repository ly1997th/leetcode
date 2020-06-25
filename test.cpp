class Solution 
{
public:
    int minCut(string s) 
    {
        int N=s.size();
        if(N<=1) return 0;

        bool isPalin[N][N];
        fill_n(&isPalin[0][0],N*N,false);
        int minCut[N+1];
        for(int i=0;i<N;++i) minCut[i]=i-1;

        for(j=1;j<N;++j)
            for(int i=j;i>=0;--i)
            {
                if(s[i]==s[j] && (j-i<2 || isPalin[j-1][i+1]) )
                {
                    isPalin[j][i]=true;
                    minCut[j+1]=min(minCut[j+1],minCut[i]+1);
                }
            }
        return minCut[N];
    }
};