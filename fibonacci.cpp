/*
题目:现在要求输入一个整数n，请你输出斐波
那契数列的第n项。
*/
/*
思路: 循环
*/
int Fibonacci(int n) {
    if(n <=0 ) return 0;
    int a1 = 1, a2 = 1, res = a1;
                 
    for(int i = 2; i < n; i++){
        res = a1 + a2;
        a1 = a2;
        a2 = res;
    }
    return res;
}

/*
题目:一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
/*
思路: f(n) = f(n-1) + f(n-2);实际上也是fibonacci序列
*/
class Solution {
public:
    int jumpFloor(int number) {
    	if(number <= 0) return 0;
    	int a1 = 1, a2 = 1, res = a1;
       
        for(int i = 1; i < number; i++){
            res = a1 + a2;
            a1 = a2;
            a2 = res;
        }
        return res;
    }
};

/*
题目:一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
/*
思路: f(n) = f(n-1) + f(n-2) + …… + f(1);
	  f(n+1) = f(n) + f(n-1) + f(n-2) + …… + f(1);
	得到 f(n) = 2* f(n-1);
*/
class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 0) return 0;
        return 1 << (number-1);
    }
};