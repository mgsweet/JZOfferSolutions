class Solution {
public:
    int calculate(int n) {
        int sum = 0;
        while (n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        unordered_map<int, bool> my_hashmap;
        while (1) {
            n = calculate(n);
            if (n == 1) return true;
            if (my_hashmap.find(n) != my_hashmap.end()) return false;
            my_hashmap[n] = true;
        }
        return false;
    }
};