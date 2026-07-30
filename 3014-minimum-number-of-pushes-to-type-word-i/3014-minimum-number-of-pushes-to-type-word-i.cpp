class Solution {
public:
    int minimumPushes(string word) {
        int n =word.size();
        if(n<=8) return n;
        if(n<16) return 8+((n%8)*2);
        if(n==16) return 24;
        if(n<24) return 24+(3*(n%8));
        if(n==24) return 48;
        if(n<=26) return 48 +(4*(n%8));
        return -1;
    }
};