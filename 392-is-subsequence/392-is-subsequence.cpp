class Solution {
public:
    bool isSubsequence(string s, string t) {
        stack<char> checkSub;
        for(auto &ch: s) checkSub.push(ch);
        
        int len = t.size();
        for (int i = len-1; i >= 0; i--) {
            if (!checkSub.empty() && t[i] == checkSub.top())
                checkSub.pop();
        }
        if (!checkSub.empty())
            return false;
        return true;
    }
};