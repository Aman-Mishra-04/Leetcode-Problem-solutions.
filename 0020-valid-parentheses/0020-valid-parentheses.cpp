class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {

            // Opening brackets
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else {
                // Closing bracket but no opening bracket
                if (st.empty())
                    return false;

                char top = st.top();

                // Check matching pair
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) {
                    return false;
                }

                st.pop();
            }
        }

        // Valid only if no opening bracket is left
        return st.empty();
    }
};