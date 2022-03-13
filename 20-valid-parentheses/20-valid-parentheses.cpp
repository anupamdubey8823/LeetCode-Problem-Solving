class Solution {
public:
    bool isValid(string s) {
        stack<char> pairs;
        int len = s.size();
        if (len & 1) 
            return false;
        for (auto &ch: s) {
            if (ch == '(' || ch == '[' || ch == '{')
                pairs.push(ch);
            else {
                if (ch == ')') {
                    if (!pairs.empty() && pairs.top() == '(')
                        pairs.pop();
                    else return false;
                }
                else if (ch == '}') {
                    if (!pairs.empty() && pairs.top() == '{')
                        pairs.pop();
                    else return false;
                }
                else if (ch == ']') {
                    if (!pairs.empty() && pairs.top() == '[')
                        pairs.pop();
                    else return false;
                }
            }
        }
        if (!pairs.empty())
            return false;
        return true;
    }
}; 