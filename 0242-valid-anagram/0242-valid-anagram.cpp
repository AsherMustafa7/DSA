class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int> s1;
        for(char x : s){
            s1[x]++;
        }
        for(char c : t){
            --s1[c];
            if(s1[c]<0){
                return false;
            }
        }
        return true;
    }
};