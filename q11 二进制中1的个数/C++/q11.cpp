class Solution {
public:
     int NumberOf1(int n) {
         int count = 0;
         unsigned int t = n;
         if (t >= 0) {
             while (t) {
                 if (t & 1) {
                     count ++;
                 }
                 t = t >> 1;
             }
         }
         return count;
     }
};
