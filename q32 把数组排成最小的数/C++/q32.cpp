class Solution {
private:
    static bool mySort(string s1, string s2) {
        string combination1 = s1 + s2;
        string combination2 = s2 + s1;
        return combination1 < combination2;
    }
public:
    string PrintMinNumber(vector<int> numbers) {
        if (numbers.empty()) return "";
        
        vector<string> strOfNums;
        for (auto num : numbers) {
            strOfNums.push_back(to_string(num));
        }
        
        sort(strOfNums.begin(), strOfNums.end(), mySort);
        
        string result = "";
        for (auto str : strOfNums) {
            result.append(str);
        }
        
        return result;
    }
};
