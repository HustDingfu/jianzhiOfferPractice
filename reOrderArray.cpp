/*
题目:输入一个整数数组，实现一个函数来调整该数组中
数字的顺序，使得所有的奇数位于数组的前半部分，所有
的偶数位于位于数组的后半部分，并保证奇数和奇数，
偶数和偶数之间的相对位置不变。
*/
/*
思路1:类似插入排序,遇到奇数就往前移
思路2:stable_partition,这个实现事实上也应该采用了
辅助空间
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
		for(int i = 1; i < array.size(); i++) {
			//偶数就进入下一次循环
            if((array[i]&1)==0) continue;
        	
			int pivot = array[i];         
        	int j = i-1;
			//奇数就插入排序式后移
        	while( (array[j]&1) == 0 && j >= 0){
            	array[j+1] = array[j];
            	j--;
          	}
          	array[j+1] = pivot;
      	}
    }
};

class Solution {
public:
    void reOrderArray(vector<int> &array) {
		stable_partition(array.begin(),array.end(),
         [](int a){return (a&1)== 1;});
    }
};