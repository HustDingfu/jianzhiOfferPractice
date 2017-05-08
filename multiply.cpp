/*
题目:给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。
*/

/*
思路:设tmp[i] = A[0]*A[1]*A[i-1]表示下表i之前的元素乘积; 
tmp[i+1]= A[i]*tmp[i];在o(n)时间算出tmp[1,2……n]，然后
再逆序用一个临时变量计算i后面的元素乘积，两者相乘即可得到最后
的结果
*/
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	vector<int> res(A.size(),1);
        for(int i = 1; i < A.size(); i++){
            res[i] = res[i-1]*A[i-1];
        }
        
        int tmp = 1;
        for(int i = A.size() - 2; i>=0; i--){
            tmp *= A[i+1];
            res[i] *= tmp; 
        }
        
        return res;
    }
};