class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        vector<int> freq(26, 0);

        for(char c : tasks)
        {
            freq[c - 'A']++;
        }

        // Max Heap
        priority_queue<int> pq;

        for(int x : freq)
        {
            if(x > 0)
                pq.push(x);
        }

        int time = 0;

        while(!pq.empty())
        {
            vector<int> temp;

            // One cycle = n + 1 slots
            for(int i = 0; i <= n; i++)
            {
                if(!pq.empty())
                {
                    int cnt = pq.top();
                    pq.pop();

                    cnt--;

                    if(cnt > 0)
                        temp.push_back(cnt);
                }

                time++;

                // If everything is finished
                if(pq.empty() && temp.empty())
                    return time;
            }

            // Put unfinished tasks back
            for(int x : temp)
            {
                pq.push(x);
            }
        }

        return time;
    }
};