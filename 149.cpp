//149. Max Points on a Line

class Solution 
{
private:
    int GCD(int a,int b)
    {
       return b==0?a:GCD(b,a%b);
    }
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int result=0;
        for(int i=0;i<points.size();++i)
        {
            int samepoint=1;
            
            unordered_map<int,int> map;
            for(int j=i+1;j<points.size();++j)
            {
                if(points[i][0]==points[j][0]&&points[i][1]==points[j][1])
                    ++samepoint;
                else if(points[i][0]==points[j][0])
                    ++map[INT_MAX];
                else
                {
                    int dy=points[i][1]-points[j][1];
                    int dx=points[i][0]-points[j][0];
                    int gcd=GCD(dy,dx);
                    dy/=gcd;dx/=gcd;
                    int s=dy^dx;
                    ++map[s];
                }
            }
            int maxnum=0;
            for(auto it=map.begin();it!=map.end();++it)
                maxnum=max(maxnum,it->second);
            maxnum+=samepoint;
            result=max(result,maxnum);
        }
        return result;
    }
};