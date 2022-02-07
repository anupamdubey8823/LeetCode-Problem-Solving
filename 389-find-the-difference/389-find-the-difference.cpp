class Solution {
public:
    char findTheDifference(string s, string t) {
        int tsum = 0, ssum = 0, charDiff;
        for (auto &ch: t) tsum += (int)ch;
        for (auto &ch: s) ssum += (int)ch;
        return (char)(tsum-ssum);
    }
};