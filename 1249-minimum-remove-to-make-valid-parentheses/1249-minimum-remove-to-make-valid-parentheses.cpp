class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                if (!st.empty())
                    st.pop();
                else s[i] = '*';
            }
        }
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};