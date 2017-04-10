/*
题目:输入一个非递减排序的数组的一个旋转，输出旋转数组
的最小元素。例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转
该数组的最小值为1。NOTE：给出的所有元素都大于0,
若数组大小为0，请返回0。
*/
/*
思路:最干脆的思路是O(n)找到最小值;事实上,这个数组有这样的
特性:分段有序,所以可以考虑用二分查找进行搜索;但有些特殊
情况需要考虑
*/
const int IsEmpty = 0;
int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.empty())
        return IsEmpty;
         
    int low = 0, high = rotateArray.size() - 1;
    while(low < high) {
        int mid = low + (high-low)/2;
        if(rotateArray[mid] < rotateArray[high]) {
            high = mid;
        }else if(rotateArray[mid] > rotateArray[high]){
            low = mid + 1;
        }else {
            int minNumber = rotateArray[low];
            for(int i = low; i <=high; i++) {
                if(minNumber > rotateArray[i])
                     minNumber = rotateArray[i];
            }
            return minNumber;
        }
    }
    return rotateArray[low];
}
