//132. Palindrome Partitioning II

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
        for(int i=0;i<=N;++i) minCut[i]=i-1;

        for(int j=1;j<N;++j)
            for(int i=j;i>=0;--i)
            {
                //判断是否是回文，根据首尾元素相等以及其中间是否是回文串
                if(s[i]==s[j] && (j-i<2 || isPalin[j-1][i+1]) )
                {
                    isPalin[j][i]=true;
                //字符串从0算起，但是dp串从一算起，字符串元素0作为初始化元素
                    minCut[j+1]=min(minCut[j+1],minCut[i]+1);
                }
            }
        return minCut[N];
    }
};