class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        map<string, vector<string>> mp;
        
        for (string s: strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].emplace_back(s);
        }
        for (auto it: mp) {
            anagrams.emplace_back(it.second);
        }
        return anagrams;
    }
};