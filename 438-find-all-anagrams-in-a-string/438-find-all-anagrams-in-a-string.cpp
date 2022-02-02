class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pocc(26, 0), socc(26, 0);
        vector<int> anagrams;
        int slen = s.size(), plen = p.size();
        if (plen > slen)
            return anagrams;
        
        for (int i = 0; i < plen; i++) {
            pocc[p[i] - 'a']++;
            socc[s[i] - 'a']++;
        }
        
        if (pocc == socc) anagrams.emplace_back(0);
        
        for (int end = plen; end < slen; end++) {            
            socc[s[end-plen] - 'a']--;
            socc[s[end] - 'a']++;
            
            // for (auto it: socc) 
            //     cout << it.first;
            // cout << endl;
            
            if (socc == pocc) anagrams.emplace_back(end-plen+1);
        }
        return anagrams;
    }
};