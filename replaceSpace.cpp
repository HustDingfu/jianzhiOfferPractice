/*
题目:请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为
We%20Are%20Happy。
*/
/*
思路1:如果可以用C++的string，直接从str的元素一个一个append过去，
遇到空格append("%20")即可。时间复杂度空间复杂度都是O(n)
思路2:如果不允许分配多的空间，先一趟遍历统计空格数目，然后
从后往前拷贝元素,时间复杂度是O(n),空间复杂度O(1)。这种方法的
假设str指向的内存有足够的空间允许str进行替换
*/
void replaceSpace(char *str,int length) {
    if(nullptr == str || length <= 0)
        return;
        
    int cntOfSpace = 0;
    for(int i= 0; i < length; i++) {
        if(' ' == str[i]) cntOfSpace++;
    }
    int i=length, j=length+2*cntOfSpace;
    // j > i当j==i，就不会再发生替换了，提前结束循环
    while( i>=0 && j>i){
        if(' ' == str[i]){
            str[j] = '0';
            str[j-1] = '2';
            str[j-2] = '%';
            j -= 3;
        }else {
            str[j--] = str[i];
        }
        i--;
    }
}