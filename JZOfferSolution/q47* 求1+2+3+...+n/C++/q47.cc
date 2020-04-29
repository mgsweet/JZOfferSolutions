class SumN {
public:
    static void Reset() {
        n_ = 0;
        sum_ = 0;
    }
    
    static int sum() {
        return sum_;
    }
    
    SumN() {
        ++n_;
        sum_ += n_;
    }
private:
    static int n_;
    static int sum_;
};

int SumN::n_ = 0;
int SumN::sum_ = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        SumN::Reset();
        SumN *tmp = new SumN[n];
        delete []tmp;
        tmp = nullptr;
        return SumN::sum();
    }
};
