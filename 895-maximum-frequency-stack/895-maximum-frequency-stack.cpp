class FreqStack {
    map<int, int> freq;
    map<int, stack<int>> mostRecentMaxFreq;
    int maxFreq = 0;
public:
    FreqStack() {
//         Have a DS to store values.
//         Entry will be from the front.
//         Vector - push_front()
//         Exit would be the most frequent element. Maybe use of Map DS to store freq. 
//         Or use a pq(Heap) of pairs where we will keep popping from the top().
    }
    
    void push(int val) {
        maxFreq = max(maxFreq, ++freq[val]);
        mostRecentMaxFreq[freq[val]].push(val);
    }
    
    int pop() {
        int smallest = mostRecentMaxFreq[maxFreq].top();
        mostRecentMaxFreq[maxFreq].pop();
        if (!mostRecentMaxFreq[freq[smallest]--].size()) 
            maxFreq--;
        return smallest;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */