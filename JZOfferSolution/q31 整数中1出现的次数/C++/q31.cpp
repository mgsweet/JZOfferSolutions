class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n <= 0)
            return 0;
        int count = 0;
        for(long i = 1; i <= n; i *= 10){
            long diviver = i * 10;
            int variable = n % diviver - i + 1 > 0 ? n % diviver - i + 1 : 0;
            variable = variable > i ? i : variable;
            count += (n / diviver) * i + variable;
        }
        return count;
    }
};
