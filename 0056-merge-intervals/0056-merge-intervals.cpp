class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>>vf;
        vector<int>v;
        vector<int>copy=v;
        sort(intervals.begin(),intervals.end());
        v.push_back(intervals[0][0]);
        v.push_back(intervals[0][1]);
        for(int i =1; i <intervals.size();)
        {
            if(v[1]>=intervals[i][0] && v[1]>=intervals[i][1])
            {
                i++;
                continue;
            }
            while(i <intervals.size() && v[1]>=intervals[i][0] )
            {
                if(v[1]>=intervals[i][0] && v[1]>=intervals[i][1])
                {
                    i++;
                    continue;
                }
                else if(v[1]>=intervals[i][0])
                {
                    v[1]=intervals[i][1];
                    i++;
                }
                
            }
            if(i==intervals.size())
            {
                break;
            }
            vf.push_back(v);
            v.clear();
            v.push_back(intervals[i][0]);
            v.push_back(intervals[i][1]);
            i++;
        }
        vf.push_back(v);
        return vf;
    }
};