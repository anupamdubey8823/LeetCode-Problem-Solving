class Solution {
    void swap(int start, int end, vector<char> &s) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
    }
    void revUtil(int start, int end, vector<char> &s) {
        if (start >= end)
            return;
        swap(start, end, s);
        revUtil(start+1, end-1, s);
    }
public:
    void reverseString(vector<char>& s) {
        if (s.empty())
            return;
        int end = s.size()-1;
        revUtil(0, end, s);
    }
};