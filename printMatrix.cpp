/*
题目:输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,
11,10.
*/
/*
思路:每次循环打印一个圆环，尤其要注意各种边界条件
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        
        vector<int> res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0, col = 0;
        while(2*col + 1 <= cols && 2*row + 1 <= rows){
            
            for(int j = col; j < cols - col; j++ ) 
                res.push_back(matrix[row][j]);
            

            for(int i = row+1; i < rows - row; i++)
                res.push_back(matrix[i][cols-col-1]);

            if(rows-row-1 > row)
            	for(int j = cols-col-2; j >= col; j-- ) 
                	res.push_back(matrix[rows-row-1][j]);
            
	    if(col < cols-col-1)
            	for(int i = rows-row-2; i > row; i--)
			res.push_back(matrix[i][col]);
            
            row++; col++;
        }
        
        return res;
    }
};
