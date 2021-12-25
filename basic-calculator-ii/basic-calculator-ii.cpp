class Solution {
public:
    int calculate(string s) {
        stack<int> operands;
        char sign = '+';
        long int prevOperand = 0, strlen = s.size();
        for (unsigned int i = 0; i < strlen; i++) {
            if (isdigit(s[i]))
                prevOperand = prevOperand*10 + s[i] - '0';
            if (!isdigit(s[i]) and !isspace(s[i]) || i == strlen - 1) {
                if (sign == '+')
                    operands.push(prevOperand);
                else if (sign == '-')
                    operands.push(-prevOperand);
                else { // If '*' or '/'
                    int num, stackTop = operands.top();
                    operands.pop();
                    if (sign == '*')
                        num = stackTop * prevOperand;
                    else if (sign == '/')
                        num = stackTop / prevOperand;
                    operands.push(num);
                }
                sign = s[i];
                prevOperand = 0;
            }
        }
//         Now after resolving all * and / signs, we just add the remaining elements of the stack
        unsigned int result = 0;
        while (!operands.empty()) {
            result += operands.top();
            operands.pop();
        }
        return result;
    }
};