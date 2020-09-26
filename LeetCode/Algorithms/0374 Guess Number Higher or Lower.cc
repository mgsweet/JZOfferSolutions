/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
  int guessNumber(int n) {
    int lhs = 0, rhs = n, mid;
    while (lhs < rhs) {
      mid = lhs / 2 + rhs / 2;
      switch (guess(mid)) {
        case -1:
          rhs = mid - 1;
          break;
        case 1:
          lhs = mid + 1;
          break;
        case 0:
          return mid;
          break;
      }
    }
    return lhs;
  }
};