class Solution {
public:
    int myAtoi(string s) 
    {
        bool f=true;
        int q=0;
        for( q =0; q <s.size();q++)
        {
            if(s[q]!=' ')
            {
                break;  
            }
        }
        if((s[q]<48 || s[q]>57) && s[q]!='-' && s[q]!='+')
        {
            return 0;
        }
        if((s[q]<48 || s[q]>57)&&(s[q+1]<48 || s[q+1]>57))
        {
            return 0;
        }

        
        
        char sign='+';
        int index=-1;
        for(int i =0; i <s.size()-1;i++)
        {
            if((s[i]=='-' || s[i]=='+')&& (s[i+1]>=48 && s[i+1]<=57))
            {
                sign =s[i];
                index=i;
                break;
                
            }
        }
        long long number=0;
        int p=-1;
        bool flag=false;
        
        for(int i =0; i<s.size();i++)
        {

            if(i!=s.size()-1)
            {
                
                if( (s[i]>=48 && s[i]<=57) &&  (s[i+1]<48 || s[i+1]>57))
                {
                    if(flag==0)
                    {
                        p=i;
                        flag=true;
                    }
                    
                    int d= s[i]-'0';
                    if(number > INT_MAX/10 ||
                        (number == INT_MAX/10 && d > 7))
                        {
                            if(sign=='-')
                                return INT_MIN;
                            return INT_MAX;
                        }

                        number = number*10 + d;
                    
                    break;
                }
            } 
            if((s[i]>=48 && s[i]<=57))
            {
                if(flag==0)
                    {
                        p=i;
                        flag=true;
                    }
                int d= s[i]-'0';
                if(number > INT_MAX/10 ||
                    (number == INT_MAX/10 && d > 7))
                    {
                        if(sign=='-')
                            return INT_MIN;
                        return INT_MAX;
                    }

                        number = number*10 + d;
            }
            if(number==2147483647 && sign=='-')
            {

                return INT_MAX*-1;
                break;
            }
            if(number>2147483647 && sign=='-')
            {

                return INT_MIN;
            }
            if(number>2147483647 && sign!='-')
            {

                return INT_MAX;
            }
            cout<<number <<endl;
        }
        cout <<number<<endl;
        if(p<index)
        {
            sign=NULL;
        }
        else if(sign=='-')
        {
            number= number*-1;
        }
        
        return number;
    }
};