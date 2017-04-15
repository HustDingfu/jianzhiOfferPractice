/*
题目:数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中
出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0
*/
/*
思路:两个临时变量，一个保存当前记录的整数recordNumber，一个记录recordNumber
的出现次数与其他数字出现之差。那个出现次数超过数组长度一半的元素与其他元素的
出现次数之差可定要大于零的。
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(const vector<int>& numbers) {
        int recordNumber = 0;
        int recordCounter = 0;
        
        for(auto num : numbers) {
            if(recordNumber == num){
                recordCounter++;
            }else if(recordCounter >0) 
                recordCounter--;
            else {
               	recordNumber = num;
                recordCounter = 1;
            }
        }
       	recordCounter = 0;
        //判断recordNumber出现次数是否真的超过了数组的一半
      	for(auto num : numbers) {
           	if(num == recordNumber)
                recordCounter++;        
        }
       	if(recordCounter > numbers.size()/2)
        	return recordNumber;
        
        return 0;
    
    }
};