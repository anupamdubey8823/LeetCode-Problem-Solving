class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string simplePath = "", temp = "";
        int i = 0, len = path.size();
        while (i < len) {
            if (path[i] == '/') {
                i++;
                continue;
            }
            else {
                temp = "";
                while (i < len && path[i] != '/') {
                    temp += path[i];
                    i++;
                }
                if (temp == ".")
                    continue;
                if (temp == "..") {
                    if (!st.empty()) 
                        st.pop();
                }
                else 
                    st.push(temp);
            }
            i++;
        }
        while (!st.empty()) {
            simplePath = "/" + st.top() + simplePath;
            st.pop();
        }
        if (simplePath == "")
            return "/";
        return simplePath;
    }
};