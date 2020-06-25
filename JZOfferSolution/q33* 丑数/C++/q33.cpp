class Solution {
private:
    int Min(int num1, int num2, int num3) {
        int min = (num1 < num2) ? num1 : num2;
        return (min < num3) ? min: num3;
    }
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0)
            return 0;
        //init
        vector<int> uglyNumbers({1});
        int nextUglyIndex = 1;
        int pMulti2 = 0;
        int pMulti3 = 0;
        int pMulti5 = 0;
        
        while (nextUglyIndex < index) {
            int min = Min(uglyNumbers[pMulti2] * 2,
                          uglyNumbers[pMulti3] * 3,
                          uglyNumbers[pMulti5] * 5);
            
            uglyNumbers.push_back(min);
            while(uglyNumbers[pMulti2] * 2 <= uglyNumbers[nextUglyIndex]) {
                pMulti2++;
            }
            while(uglyNumbers[pMulti3] * 3 <= uglyNumbers[nextUglyIndex]) {
                pMulti3++;
            }
            while(uglyNumbers[pMulti5] * 5 <= uglyNumbers[nextUglyIndex]) {
                pMulti5++;
            }
            nextUglyIndex++;
        }
        
        return uglyNumbers[nextUglyIndex - 1];
    }
    
    
};
