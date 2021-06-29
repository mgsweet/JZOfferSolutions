class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hash;
        for (auto num: arr) {
            ++hash[num];
        }
        unordered_set<int> my_set;
        for (auto iter = hash.begin(); iter != hash.end(); ++iter) {
            if (my_set.find(iter->second) != my_set.end()) {
                return false;
            } else {
                my_set.insert(iter->second);
            }
        }
        return true;
    }
};