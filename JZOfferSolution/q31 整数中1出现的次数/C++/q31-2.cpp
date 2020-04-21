#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include "MyHeap.hpp"
#include <cmath>

using namespace std;

int getCountWithNChange(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int combination = 1;
        for (int j = n; j > n - i; j--) {
            combination *= j;
        }
        for (int j = 1; j <= i; j++) {
            combination /= j;
        }
        count += i * combination * pow(9, n - i);
    }
    return count;
}

int NumberOf1Between1AndN_Solution(int n)
{
    if (n <= 0) return 0;
    int tmp = n;
    int digit = 0;
    while (tmp) {
        digit++;
        tmp /= 10;
    }
    int highestDigitNum = n / int(pow(10, digit - 1));
    if (digit == 1) return highestDigitNum >= 1? 1 : 0;
    
    int res = 0;
    res += highestDigitNum * getCountWithNChange(digit - 1);
    if (highestDigitNum > 1) res += pow(10, digit - 1);
    int rest = n % int(highestDigitNum * pow(10, digit - 1));
    if (highestDigitNum == 1) res += (rest + 1);
    res += NumberOf1Between1AndN_Solution(rest);
    return res;
}

int main(int argc, const char * argv[]) {
    cout << NumberOf1Between1AndN_Solution(13) << endl;
    return 0;
}
