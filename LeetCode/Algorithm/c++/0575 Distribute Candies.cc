class Solution {
public:
  int distributeCandies(vector<int>& candyType) {
    unordered_map<int, bool> visited;
    for (int i = 0; i < candyType.size(); ++i) {
      if (visited.find(candyType[i]) == visited.end())
        visited[candyType[i]] = true;
    }
    return min(visited.size(), candyType.size() / 2);
  }
};