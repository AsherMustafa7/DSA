class Solution {
public:
    bool isValid(string s) 
    {
        map<char,char>mp;
        mp['(']=')';
        mp['{']='}';
        mp['[']=']';
        stack<char>st;
        int i =0;
        
        while(i!=s.size())
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(!st.empty() && s[i]=='}')
            {
                if(!st.empty() && st.top()=='{') st.pop();
                else return false;
            }
            else if(!st.empty() && s[i]==')')
            {
                if(st.top()=='(') st.pop();
                else return false;
            }
            else if(!st.empty() && s[i]==']')
            {
                if(st.top()=='[') st.pop();
                else return false;
            }
            else if(st.empty())
            {
                if(s[i]==')' || s[i]=='}' || s[i]==']') return false;
            }
            i++;
        }
        if(!st.empty()) return false;
        return true;
    }
};