//403.frog jump

class Solution 
{
private:
    bool isWrongMark(int curMark,int curDis,unordered_map<int,vector<int>>& fal)
    {
        if(fal.find(curMark)!=fal.end())
        {
            for(int t:fal[curMark])
                if(curDis==t) return true;
        }
    
        return false;
    }
public:
    bool canCross(vector<int>& stones) 
    {
        if(stones.empty()||stones[0]!=stones[1]-1) return false;

        bool res=false;
        int start=stones[0],last=stones[stones.size()-1],curDis=0,curMark=0;
        unordered_map<int,vector<int>> fal;
        stack<pair<int,int>> pathMark;

        for(int s:stones)
            fal[s].push_back(-1);
        pathMark.push(make_pair(curMark,curDis));
        
        while(!pathMark.empty())
        {
            pair cur=pathMark.top();pathMark.pop();
            curMark=cur.first;curDis=cur.second;

            if(isWrongMark(curMark,curDis,fal)) continue;

            if(curMark==last) 
            {
                res=true;
                break;
            }

            int stackSize=pathMark.size();
            if(fal.find(curMark+curDis+1)!= fal.end())
            {
                if(!isWrongMark(curMark+curDis+1,curDis+1,fal))
                    pathMark.push(make_pair(curMark+curDis+1,curDis+1));
                else
                    fal[curMark+curDis+1].push_back(curDis+1);
            }
            if(curDis>=1 && fal.find(curMark+curDis)!=fal.end())
            {
                if(!isWrongMark(curMark+curDis,curDis,fal))
                    pathMark.push(make_pair(curMark+curDis,curDis));
                else
                    fal[curMark+curDis].push_back(curDis);
            }
            if(curDis>=2 && fal.find(curMark+curDis-1)!=fal.end())
            {
                if(!isWrongMark(curMark+curDis-1,curDis-1,fal))
                    pathMark.push(make_pair(curMark+curDis-1,curDis-1));
                else
                    fal[curMark+curDis-1].push_back(curDis-1);
            }
            
            if(stackSize==pathMark.size()) 
                fal[curMark].push_back(curDis);
        }
        return res;
    }
};