class Solution {
public:
    vector<int> partitionLabels(string s) {
        int currPartition = 0, len = s.size(), prevPartition = -1;
        map<char, int> lastIndex;
//         Storing last indices of each element in the string
        for (int i = 0; i < len; i++) {
            lastIndex[s[i]] = i;
        }
        vector<int> partitions;
//         Partitioning the array based on ladder and stair methodology.
//         Here we find the max size of the ladder i.e. maximum the current partition can go.
//         Then traversing in that ladder, we see if we have any element with further last occurence than the current ladder size. If yes, then we update the ladder size and consider the max ladder size with each iteration as the current partition.
//         When we reach the max len of a ladder any any iteration, we partition the array after that index and set current partition to next index so we can start a new ladder.
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