class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()==0)
        return 0;
        set<int>s;
        vector<int>v;
        for(int i =0; i <nums.size();i++)
        {
            s.insert(nums[i]);
        }
    
        for(auto it=s.begin();it!=s.end();it++)
        {
            cout<<*it<<" ";
            v.push_back(*it);
        
        }
        int f=v[0];
        int count =0;
        int maxcount=0;
        cout<< endl;
        // 
        for(int i =0; i <v.size();i++)
        {
           
            if(f==v[i])
            {
                
                count++;
                f++;
                cout<<"f "<<f<<" count "<<count<< endl;
            }
            else
            {
                cout<<"count "<<count<< endl;
                if(count>maxcount)
                {
                    maxcount=count;
                }
                    f=v[i];
                    i--;
                count =0;
            }

        }
        cout<<"count "<<count<< endl;
        if(count>maxcount)
        maxcount=count;
        return maxcount;
    }
};