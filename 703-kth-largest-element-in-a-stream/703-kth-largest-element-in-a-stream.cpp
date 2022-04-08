class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (auto &num: nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        while (pq.size() > kth)
            pq.pop();
        return (int)pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */