#include <iostream>
#include <limits>
#include <map>
#include <array>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <list>

using namespace std;

class Solution{
    enum CharTypes {
        DIGIT = 0,
        SIGN = 1,
        OTHER = 2,
    };
    
    static CharTypes GetCharType(char c) {
        if (c >= '0' && c <= '9') {
            return CharTypes::DIGIT;
        } else if (c == '+' || c == '-') {
            return CharTypes::SIGN;
        } else {
            return CharTypes::OTHER;
        }
    }
    
    static bool IsOverflow(int num, int next, int sign) {
        if (sign == 1) {
            if (num > INT_MAX / 10 || num * 10 > INT_MAX - next) {
                return true;
            }
        } else if (sign == -1) {
            if (num < INT_MIN / 10 || num * 10 < INT_MIN - next) {
                return true;
            }
        }
        return false;
    }
public:
    static int StrToInt(string str) {
        int sign = 1;
        int ans = 0;
        int next = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (0 == i && GetCharType(str[i]) == CharTypes::SIGN) {
                sign = str[i] == '+' ? 1 : -1;
            } else {
                if (GetCharType(str[i]) != CharTypes::DIGIT)
                    return 0;
                next = sign * static_cast<int>(str[i] - '0');
                if (IsOverflow(ans, next, sign))
                    return 0;
                ans = ans * 10 + next;
            }
        }
        return ans;
    }
};

int main(int argc, const char* argv[]) {
    cout << Solution::StrToInt("-2147483649") << endl;
    cout << INT_MIN << endl;
    return 0;
}
