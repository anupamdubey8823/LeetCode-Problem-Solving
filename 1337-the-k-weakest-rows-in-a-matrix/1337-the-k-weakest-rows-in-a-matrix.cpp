class Solution {
    struct CustomComparator {
        bool operator()(pair<int, int>const &p1, pair<int, int>const &p2) {
            if (p1.first > p2.first) 
                return true;
            else if (p1.first == p2.first && p1.second > p2.second)
                return true;
            return false;
        }
    };
    
    void countSoldiers(vector<vector<int>> &mat, vector<int> &soldiers) {
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1)
                    count++;
                else break;
            }
            soldiers.emplace_back(count);
            count = 0;
        }
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> kWeakest;
        priority_queue<pair<int, int>, vector<pair<int, int>>, CustomComparator> pq;
        vector<int> soldiers;
        countSoldiers(mat, soldiers);
        int rows = mat.size(), cols = mat[0].size();
        for (int i = 0; i < soldiers.size(); i++) {
            pq.push(make_pair(soldiers[i], i));
        }
        while (k--) {
            kWeakest.emplace_back((int)pq.top().second);
            pq.pop();
        }
        return kWeakest;
    }
};