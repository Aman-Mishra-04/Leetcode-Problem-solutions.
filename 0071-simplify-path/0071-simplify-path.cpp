class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string current;

        for (int i = 0; i <= path.size(); i++) {

            // '/' ya end of string par current part process karo
            if (i == path.size() || path[i] == '/') {

                if (current == "..") {
                    if (!st.empty()) {
                        st.pop_back();
                    }
                }
                else if (current != "" && current != ".") {
                    st.push_back(current);
                }

                current = "";
            }
            else {
                current += path[i];
            }
        }

        // Canonical path construct karo
        string ans = "";

        for (string dir : st) {
            ans += "/" + dir;
        }

        // Agar kuch bhi nahi hai, root directory
        if (ans == "") {
            return "/";
        }

        return ans;
    }
};