//remove boxes

class Solution 
{
public:
    int removeBoxes(vector<int>& boxes) 
    {
        int length=boxes.size();
        int memo[100][100][100]={0};

        return DFS(boxes,memo,0,length-1,0);
    }
private:
    int DFS(vector<int>& boxes,int memo[100][100][100],int l,int r,int k)
    {
        if(r<l) return 0;
        if(memo[l][r][k]!=0) return memo[l][r][k];

        while(r>l && boxes[r]==boxes[r-1]) {r--;++k;}
        memo[l][r][k]=DFS(boxes,memo,l,r-1,0)+(k+1)*(k+1);
        for(int i=l;i<r;++i)
        {
            if(boxes[i]==boxes[r])
                memo[l][r][k]=max(memo[l][r][k],DFS(boxes,memo,l,i,k+1)+DFS(boxes,memo,i+1,r-1,0));
        }

        return memo[l][r][k];
    }
};
