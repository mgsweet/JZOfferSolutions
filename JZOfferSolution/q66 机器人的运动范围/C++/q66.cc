class Solution {
int getSumOfDigit(int num) {
    int sum = 0;
    while(num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
    
public:
    typedef pair<int, int> point;
    
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold < 1 || rows < 1 || cols < 1)
            return 0;
        
        vector<bool> hasVisited(rows * cols, false);
        
        queue<point> queueData;
        queueData.push(point(0, 0));
        hasVisited[0] = true;
        
        int count = 0;
        while (!queueData.empty()) {
            point top = queueData.front();
            int i = top.first;
            int j = top.second;
            if (i + 1 < rows 
                && (getSumOfDigit(i + 1) + getSumOfDigit(j) <= threshold)
               && hasVisited[(i+1) * cols + j] != true) {
                queueData.push(point(i+1, j));
                hasVisited[(i + 1) * cols + j] = true;
            }
            if (j + 1 < cols 
                && (getSumOfDigit(i) + getSumOfDigit(j + 1) <= threshold)
               && hasVisited[i * cols + j + 1] != true) {
                queueData.push(point(i, j + 1));
                hasVisited[i * cols + j + 1] = true;
            }
            queueData.pop();
            count++;
        }
        
        return count;
    }
};
