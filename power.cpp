/*
题目: 给定一个double类型的浮点数base和int类型的整数
exponent。求base的exponent次方。
*/
/*
思路:base^exp = base^(exp/2)^2;
注意：exp正负,当exp为负时,base==0的情形
*/

class Solution {
public:
    const double ERR = 0.00000001;
    double Power(double base, int exponent) {
        
        if(exponent >= 0)
            return powerHelper(base,exponent);
        else
            if(equal(base,0.0)) throw new exception;
            return 1.0/powerHelper(base,-exponent);
    }
    
    //正整数的指数运算
    double powerHelper(double base, int exp) {
        if(exp == 0) return 1.0;   
        double res = powerHelper(base, exp>>1);
        res *= res;
        if(exp & 1) {
            return res*base;
        }
        return res;
    }

    bool equal(double num1, double num2){
        if(num1 - num2 < ERR && num1 - num2 > ERR) 
            return true;
        return false;
    }
};