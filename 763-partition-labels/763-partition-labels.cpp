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
//             Extending the ladder each time we find a new last occurence of a variable in the current substring we are considering.
            while (i < len && i <= currPartition) {
                currPartition = max(currPartition, lastIndex[s[i]]);
                i++;
            }
            partitions.emplace_back(currPartition - prevPartition);
//             Updating the prevPartition so we can get the length of the next partitioned string
            prevPartition = currPartition;
//             No point in continuing the loop further as we have already reached the end finding the last occurence. Hence, all elements in that substring, will have last occurence <= currPartition. This is done to save uncessary iterations. 
            if (currPartition == len) {
                break;
            }
//             Updating currPartition so we can start a new ladder from their.
            currPartition = i;
        }
        return partitions;
    }
};