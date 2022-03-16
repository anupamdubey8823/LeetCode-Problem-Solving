class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        int pushLen = pushed.size(), popLen = popped.size();
        for (auto &elem: pushed) {
            st.push(elem);
            while (!st.empty() && j < popLen && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};