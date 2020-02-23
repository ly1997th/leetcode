//largest rectangle histogram

class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        if(heights.empty()) return 0;

        int globalmax=0,lastmax=0,mincol=INT_MAX;
        for(int i=0;i<heights.size();++i)
        {
            lastmax=0;
            mincol=min(mincol,heights[i]);
            int j=i,h=heights[i];
            while(j>=0&&(heights[j]>mincol))
            {
                h=min(h,heights[j]); 
                int cur=h*(i-j+1);
                lastmax=max(cur,lastmax);
                j--;
            }
            lastmax=max(lastmax,mincol*(i+1));
            globalmax=max(globalmax,max(lastmax,heights[i]));
        }

        return globalmax;
    }
};