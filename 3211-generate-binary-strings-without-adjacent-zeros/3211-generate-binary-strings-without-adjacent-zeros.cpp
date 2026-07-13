class Solution {
public:
    vector<string> validStrings(int n) 
    {
        string s(n,'0');
        vector<string>result;
        generate(n,"",result);
        return result;
    }
    
    void generate(int n, string curr, vector<string>& result) 
    {
        // Base case: if length is n, add to result
        if (curr.length() == n) {
            result.push_back(curr);
            return;
        }

        // Always try adding '0'
        generate(n, curr + "1", result);

        // Add '1' only if previous char is not '1'
        if (curr.empty() || curr[curr.size()-1] != '0') {
            generate(n, curr + "0", result);
        }
    }
};