class Solution {
public:
    vector<int> partitionLabels(string s) {
        int currPartition = 0, len = s.size(), prevPartition = -1;
        map<char, int> lastIndex;
        for (int i = 0; i < len; i++) {
            lastIndex[s[i]] = i;
        }
        vector<int> partitions;
        for (int i = 0; i < len;) {
            while (i < len && i <= currPartition) {
                currPartition = max(currPartition, lastIndex[s[i]]);
                i++;
            }
            partitions.emplace_back(currPartition - prevPartition);
            prevPartition = currPartition;
            if (currPartition == len) {
                break;
            }
            currPartition = i;
        }
        
        return partitions;
    }
};