class Solution {
public:
    Solution(vector<int>& nums) {
        ori = arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        arr = ori;
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < arr.size(); ++i) {
            swap(arr[rand() % (arr.size() - i) + i], arr[i]);
        }
        return arr;
    }
private:
    vector<int> arr;
    vector<int> ori;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */