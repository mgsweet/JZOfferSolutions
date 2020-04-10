class Solution {
public:
    bool rVerifySquenceOfBST(const vector<int> & sequence,
                             int start, int end) {
        if (start >= end) return true;
        int i = start;
        while (sequence[i] < sequence[end] && i < end) {
            i++;
        }
        int sep = i;
        while (i < end) {
            if (sequence[i] < sequence[end])
                return false;
            i++;
        }
        return rVerifySquenceOfBST(sequence, start, sep - 1)
            && rVerifySquenceOfBST(sequence, sep, end - 1);
        
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        return sequence.size() > 0 ? rVerifySquenceOfBST(sequence, 0, sequence.size() - 1) : false;
    }
};
