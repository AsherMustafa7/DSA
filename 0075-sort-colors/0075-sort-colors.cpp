class Solution {
public:
    void sortColors(vector<int>& ar) 
    {
        int n =ar.size();
        for(int i =n-1; i >=0;i--)
        {
            for(int j=0;j<i;j++)
            {
                if(ar[j]>ar[j+1])
                {
                    swap(ar[j],ar[j+1]);
                }
            }
        }
    }
};