class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
//         This is done to couple lightest people with the heaviest.
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1, minRescueBoats = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit)
                left++;
            right--;
//             Each time irrespective of whether a couple can be formed or not, we increment this. Because if we don't find a light person to couple with heavier one, the heavier one has to go alone on a boat. 
//             It is also the reason why we are doing right-- each time irrespective of 'if' condition. And, only increment left when a lighter can be coupled with a heavier one.
            minRescueBoats++;
        }
        return minRescueBoats;
    }
};