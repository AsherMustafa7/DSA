class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string prefix = "";

        for (int i = 0; i < target.size(); i++) {

            int x = target[i] - 'a';

            // We cannot match target[i]
            if (freq[x] == 0) {

                // Make the answer bigger at this position
                for (int c = x + 1; c < 26; c++) {

                    if (freq[c] > 0) {

                        string ans = prefix;
                        ans += char('a' + c);

                        freq[c]--;

                        // Smallest possible suffix
                        for (int j = 0; j < 26; j++) {
                            while (freq[j] > 0) {
                                ans += char('a' + j);
                                freq[j]--;
                            }
                        }

                        return ans;
                    }
                }

                // No bigger character here.
                // We need to backtrack.
                break;
            }

            prefix += target[i];
            freq[x]--;
        }

        // We matched as much of target as possible.
        // Backtrack and increase an earlier character.

        for (int i = prefix.size() - 1; i >= 0; i--) {

            // Return prefix[i] to the available characters
            freq[prefix[i] - 'a']++;

            int x = target[i] - 'a';

            // Find the smallest available character
            // that is greater than target[i]
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string ans = prefix.substr(0, i);

                    ans += char('a' + c);

                    freq[c]--;

                    // Everything after this should be minimum
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};