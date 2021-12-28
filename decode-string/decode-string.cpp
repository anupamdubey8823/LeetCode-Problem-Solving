class Solution {
public:
    string decodeString(string s) {
        stack<string> remString;
        stack<int> countStack;
        string answer = "";
        int i = 0, strlen = s.size();
        while (i < strlen) {
            int count = 0;
            if (isdigit(s[i])) {
                while (i < strlen and isdigit(s[i])) {
                    count = 10*count + s[i] - '0';
                    i++;
                }
                countStack.push(count);
            }
            else if (s[i] == '[') {
                remString.push(answer);
                answer = "";
                i++;
            }
            else if (s[i] == ']') {
                string temp = remString.top();
                int repeatTimes = countStack.top();
                remString.pop(), countStack.pop();
                for (int i = 0; i < repeatTimes; i++) {
                    temp += answer;
                }
                answer = temp;
                i++;
            }
            else {
                answer += s[i++];
            }
        }      
        return answer;
    }
};