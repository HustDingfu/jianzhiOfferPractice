/*
题目: 在一个二维数组中，每一行都是按照从左到右递增排序
每一列都是从上到下递增排序。请完成一个函数，输入二维数组
一个整数，判断数组是否含有该整数。
*/

/*
思路: 从矩阵的右上角(或者左下角)开始遍历，这样每次比较之后，
待搜索的元素要么往左(右)要么往下(上)，遍历范围逐渐缩小，直到
搜索结束或找到目标元素
*/
bool Find(int target, const vector<vector<int>>& array) {
    // 判断数组是否为空
    if(array.empty() || array[0].empty()) return false;
        
    int col = array[0].size() - 1;
    int row = 0;
    while(col >=0 && row < array.size()) {
        if(array[row][col] == target) 
                return true;
        if(array[row][col] > target){
             col--;
        }else {
            row++;
        }
    }
    return false;
}