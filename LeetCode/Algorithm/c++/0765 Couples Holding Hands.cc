class Solution {
public:
    static int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int> my_map;
        for (int i = 0; i < row.size(); i += 2) {
            my_map[row[i]] = row[i + 1];
            my_map[row[i + 1]] = row[i];
        }
        int count = 0;
        for (int i = 0; i < row.size(); i += 2) {
          if (my_map[i] != i + 1) {
                ++count;
                my_map[my_map[i]] = my_map[i + 1];
                my_map[my_map[i + 1]] = my_map[i];
          }
        }
        return count;
    }
};