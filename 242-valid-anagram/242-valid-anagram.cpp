class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.size() > s.size())
            return false;
        map<char, int> socc, tocc;
        for (auto &ch: t) tocc[ch]++;
        for (auto &ch: s) socc[ch]++;
        if (tocc == socc)
            return true;
        return false;
    }
};