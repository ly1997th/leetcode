//218.the skyline problem
class Solution 
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<vector<int>> res;
        priority_queue<pair<int,int>> buildlist;
        int cur=0,cur_h=-1,cur_x,len=buildings.size();
        
        while(cur<len||!buildlist.empty())
        {
            cur_x=buildlist.empty()?buildings[cur][0]:buildlist.top().second;
            
            if(cur==len||(cur_x<buildings[cur][0]))
            {
                 while(!buildlist.empty()&&(buildlist.top().second<=cur_x)) buildlist.pop();
            }
            else
            {
                cur_x=buildings[cur][0];
                while(cur<len&&buildings[cur][0]==cur_x)
                {
                    buildlist.push(make_pair(buildings[cur][2],buildings[cur][1]));
                    cur++;
                }                 
            }
            
            cur_h=buildlist.empty()?0:buildlist.top().first;
            if(res.empty())
            {
                vector<int> element{cur_x,cur_h};
                res.push_back(element);
            }   
            else  
            {
                vector<int> last=res.back();
                if(cur_h!=last[1])
                {
                    vector<int> element{cur_x,cur_h};
                    res.push_back(element);
                }
            }
        }
        return res;
    }
};