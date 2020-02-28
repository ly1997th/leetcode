//329. Longest Increasing Path in a Matrix
class Solution 
{
private:
    int longestSubPath(vector<vector<int>>& matrix,int m,int n,vector<vector<int>>& ref)
    {
        if(ref[m][n]!=0) return ref[m][n];
        int res=0;
        if(m-1>=0 && matrix[m-1][n]>matrix[m][n])
        {
            ref[m-1][n]=longestSubPath(matrix,m-1,n,ref)
            res=max(res,ref[m-1][n]);
        }
        if(m+1<matrix.size() && matrix[m+1][n]>matrix[m][n])
        {
            ref[m+1][n]=longestSubPath(matrix,m+1,n,ref)
            res=max(res,ref[m+1][n]);
        }
        if(n-1>=0 && matrix[m][n-1]>matrix[m][n])
        {
            ref[m][n-1]=longestSubPath(matrix,m,n-1,ref)
            res=max(res,ref[m][n-1]);
        }
        if(n+1<matrix[0].size() && matrix[m][n+1]>matrix[m][n])
        {
            ref[m][n+1]=longestSubPath(matrix,m,n+1,ref)
            res=max(res,ref[m][n+1]);
        }

        return res+1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int maxpath=0;
        if(matrix.empty()) return maxpath;
        int M=matrix.size(),N=matrix[0].size();
        vector<vector<int>> ref(M,vector<int>(N,0));
        for(int i=0;i<M;++i)
            for(int j=0;j<N;++j)
            {
                ref[i][j]=longestSubPath(matrix,i,j,ref);
                maxpath=max(maxpath,ref[i][j]);
            }
        return maxpath;
    }
};