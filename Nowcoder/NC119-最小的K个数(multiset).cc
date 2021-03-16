class Solution {
    
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    typedef multiset<int, greater<int>> MyHeap;
    MyHeap myheap;
    
    if (k < 1 || k > input.size()) return vector<int>();
    
    for (auto num: input) {
        if (myheap.size() < k) {
            myheap.insert(num);
        } else {
            if (num < *myheap.begin()) {
                myheap.erase(myheap.begin());
                myheap.insert(num);
            }
        }
    }
    return vector<int>(myheap.rbegin(), myheap.rend());
}
};