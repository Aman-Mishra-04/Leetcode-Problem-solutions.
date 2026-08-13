class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int star = -1;
        int match = 0;

        while (i < s.size()) {

            // Normal character or '?'
            if (j < p.size() && (p[j] == '?' || p[j] == s[i])) {
                i++;
                j++;
            }

            // '*'
            else if (j < p.size() && p[j] == '*') {
                star = j;
                match = i;
                j++;
            }

            // Mismatch, but we have a previous '*'
            else if (star != -1) {
                j = star + 1;
                match++;
                i = match;
            }

            // Mismatch and no '*'
            else {
                return false;
            }
        }

        // Remaining pattern must contain only '*'
        while (j < p.size() && p[j] == '*') {
            j++;
        }

        return j == p.size();
    }
};