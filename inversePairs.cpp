/*
题目:在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆
序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果
输出。 即输出P%1000000007 
*/
/*
思路: 利用归并排序的思路计算逆序对；
*/

class Solution {
public:
    int InversePairs(vector<int> data) 
    {
        if(data.empty()) return 0;
        vector<int> copy(data);
        return InversePairsCore(data,copy,0,data.size()-1);
    }
    
    long long InversePairsCore(vector<int>& data,//待排序数组
                     vector<int>& copy, //辅助用来归并排序的数组
                       int start, int end)
    {
        if(start == end)
        {
            copy[start] = data[start];
            return 0;
        }
            
        
        int mid = start + (end - start)/2;
        //避免再次申请辅助数组的空间，此刻用data数组做辅助数组
        long long left = InversePairsCore(copy, data, start, mid)%1000000007;
        long long right = InversePairsCore(copy,data,mid + 1, end)%1000000007;
        
     	long long count = left + right;
        for(int i=start,j=mid+1,k=start;i<=mid+1&&j<=end+1&&k<=end;k++)
        {	//处理复制数组前半部分的元素
            //1)数组后半部分没有元素了
            //2)数组前面的元素小于后面的元素
            if( j==end+1 || (i<=mid && data[i] <= data[j])) 
            {
                copy[k] = data[i++];
            }
            else {
            	copy[k] = data[j++];
                //当后面的元素移到前面的时候，数组前半部分i后面
                //元素和data[j]都是逆序对
                count +=  mid+1 - i;
            }
        }
       
        return count%1000000007;
    }
};