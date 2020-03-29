class Solution {
public:
    double Power(double base, int exponent) {
        if (equal(base, 0) && exponent == 0) exit(EXIT_FAILURE);
        
        unsigned int absExponent = (unsigned int)exponent;
        if (exponent < 0) absExponent = (unsigned int)(-exponent);
        
        if (equal(base, 0)) return 0;
        
        double result = powerWithUnsignedExponent(base, absExponent);
        
        if (exponent < 0) return 1 / result;
        return result;
    }
    
private:
    double powerWithUnsignedExponent(double base, unsigned int exponent) {
        if (exponent == 0) return 1;
        if (exponent == 1) return base;
        
        double result = powerWithUnsignedExponent(base, exponent >> 1);
        result *= result;
        if (exponent & 1)
            result *= base;
        return result;
    }
    
    bool equal(double d1, double d2) {
        double precision = 0.00000001;
        return abs(d1 - d2) < precision;
    }
};
