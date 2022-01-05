class Solution {
    bool isPalindrome(string s) {
        int start = 0, end = s.size()-1;
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++, end--;
        }
        return true;
    }
    void partitionUtil(int index, string s, vector<string> &partedStrings, vector<vector<string>> &palindromes) {
        if (index == s.size()) {
            palindromes.emplace_back(partedStrings);
            return;
        }
        int strLen = s.size();
        for (int i = index; i < strLen; i++) {
            string temp = s.substr(index, i+1 - index);
            if (isPalindrome(temp)) {
                partedStrings.emplace_back(temp);
                partitionUtil(i+1, s, partedStrings, palindromes);
                partedStrings.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> palindromes;
        vector<string> partedStrings;
        partitionUtil(0, s, partedStrings, palindromes);
        return palindromes;
    }
};