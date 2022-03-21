class Solution {
public:
    vector<int> partitionLabels(string s) {
        int currPartition = 0, len = s.size(), prevPartition = -1;
        map<char, int> lastIndex;
        for (int i = 0; i < len; i++) {
            lastIndex[s[i]] = i;
            cout << lastIndex[s[i]] << " ";
            
        }
        vector<int> partitions;
        for (int i = 0; i < len; i++) {
            // while (i <= currPartition) {
            //     currPartition = max(currPartition, lastIndex[s[i]]);
            //     i++;
            // }
            currPartition = max(currPartition, lastIndex[s[i]]);
            if (currPartition == i) {
                partitions.emplace_back(currPartition - prevPartition);
                prevPartition = currPartition;
            }
            if (currPartition == len) {
                break;
            }
        }
        
        return partitions;
    }
};