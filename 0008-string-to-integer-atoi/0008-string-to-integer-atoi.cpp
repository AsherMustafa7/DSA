class Solution {
public:
    int myAtoi(string s) 
    {
        s.erase(0,s.find_first_not_of(' '));
        int sign =1;
        int i =0;
        cout<<"i "<<i<<endl;
        if(s[0]=='-')
        {
            sign=-1;
            i++;
        }
        else if(s[0]=='+')
        {
            sign=1;
            i++;
        }
        cout<<"i "<<i<<endl;
        if(!isdigit(s[i]))
        {
            return 0;
        }
        cout<<"i "<<i<<endl;
        return number(s,0,i,sign);
    }
    int number(string &s,long long num,int index, int sign)
    {
        if(index>=s.size() || !isdigit(s[index]))
        {
            return sign*num;
        }
        num= num*10+(s[index]-'0');
        cout<< num<< endl;
        if(sign==1&& num>INT_MAX)
        {
            return INT_MAX;
        }
        if(sign==-1 && -num<INT_MIN)
        {
            return INT_MIN;
        }
        return number(s,num,index+1,sign);
    }
};