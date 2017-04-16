/*
题目:统计一个数字在排序数组中出现的次数。
*/
/*
思路: 二分查找配合线性搜索
*/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty() || k < data[0] || k > data.back())
            return 0;
        
        int low = 0; 
        int high = data.size() - 1;
        int mid = (low + high)/2;;
        while(low < high && low < data.size() && high >= 0){
           
            if(data[mid] > k) 
                high = mid - 1;
            else if(data[mid] < k)
                low = mid+1;
            else 
                break; 
            mid = (low + high)/2;
        }
        if(data[mid] == k){
            int cnt = 0;
            int i = mid+1;
            while(i < data.size() && data[i++]==k) cnt++;
            i = mid-1;
            while(i >= 0 && data[i--]==k) cnt++;
            return cnt+1;
        }
        else return 0;
    }
};