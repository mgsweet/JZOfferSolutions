class Solution {
public:
    string toLowerCase(string str) {
        for (auto& c : str) {
          c = tolower(c);
        }
        return str;
    }
};