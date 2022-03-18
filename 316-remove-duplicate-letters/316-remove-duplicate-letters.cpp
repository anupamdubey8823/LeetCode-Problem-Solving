class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.size();
        vector<int> occ(26, 0), visited(26, 0);
        string uniqueStr = "";
        
        for (auto &ch: s) 
            occ[ch - 'a']++;
        
        stack<char> st;
        for (int i = 0; i < len; i++) {
            int index = s[i] - 'a';
            occ[index]--;
            if (visited[index])
                continue;
            
            while (!st.empty() && s[i] < st.top() && occ[st.top() - 'a'] != 0) {
                visited[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            visited[index] = 1;
        }
        while (!st.empty()) {
            uniqueStr = st.top() + uniqueStr;
            st.pop();
        }
        return uniqueStr;
    }
};