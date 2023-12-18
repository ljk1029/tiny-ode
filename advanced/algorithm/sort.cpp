/**
 * 文件名: Xxx.c
 * 作者: ljk
 * 创建时间: 2023-08-03
 * 文件描述: 8大排序
 * 版本: V 1.0.0
 */
#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

/*
1、冒泡:遍历 比较大的交换到后面，每次后面都是排好的（所有数）。
2、插入:先排好前面，每次后面往比前面小交换，直到到前面比他小，前面是排好的（已排索引号前的数）。
3、快排:每次选取一个数据，将所有比它小的数都放到它的左边，所有比它大的数都放到它的右边。
4、选择:对每个下标i,从i后面的元素中选择最小的那个和s[i]交换，前面是排好（所有数）
5、希尔:先按间距n/2 ... 2 1个数据分组进行插入排序（也可以按3k+1个元素这样分组）
6、并归:分别n/2...分组，最小组先排，小组组成大组排序，最后整个排序。
7、堆:近似完全二叉树，
    (1)最后子节点往上排，最大点在顶点，次最大点在顶点左右子叶中
	(2)最大点放到最后;剩下的点从顶排序，次最大点会移到顶点，顺着次最大所在子叶会重排
	(3)接着2排到最后
	i的子节点2*i+1 / 2*i+2
8、基: 将数据按位数切割成不同的数字，然后按每个位数分别比较排序，先排个，十，百，千，万顺序
*/

#define SIZE 10


// 1、冒泡排序 时间n^2 空间1 稳定
void bubble_sort(int a[], int n)
{
    printf("冒泡排序:");
    int i, j, temp;
    for (j = 0; j < n - 1; j++){
        for (i = 0; i < n - 1 - j; i++)
        {
            if(a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

// 2、插入排序 时间n^2 空间1 稳定
void insert_sort(int array[],unsigned int n)
{
    printf("插入排序:");
    int i, j;
    int temp;
    for(i = 1; i < n; i++)
    {
        temp = array[i];
        for(j = i; j > 0 && array[j - 1] > temp; j--)
        {
            array[j] = array[j - 1];
        }
        array[j] = temp;
    }
}

// 3、快速排序 
void Qsort(int a[], int low, int high)
{
    if(low >= high){
        return;
    }
    int first = low;
    int last  = high;
    int key   = a[first];/*用字表的第一个记录作为枢轴*/
 
    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }
 
        a[first] = a[last];/*将比第一个小的移到低端*/
 
        while(first < last && a[first] <= key)
        {
            ++first;
        }
         
        a[last] = a[first];/*将比第一个大的移到高端*/
    }
    a[first] = key;/*枢轴记录到位*/
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}

// 4、选择排序
void select_sort(int *a,int n)
{
    printf("选择排序:");
    int i,j, min, t;
    for(i = 0; i < n-1; i++)
    {
        min = i;//查找最小值
        for(j = i + 1; j < n; j++)
        {
            if(a[min] > a[j])
                min = j;//交换
        }
        if(min != i)
        {
            t = a[min];
            a[min] = a[i];
            a[i] = t;
        }
    }
}

// 打印
void print(int* a, int n)
{
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

// 复位
void restore(int* a)
{
    const int number[SIZE] = {95, 45, 15, 78, 84, 51, 24, 12, 89, 21};
    for(int i=0; i<sizeof(number)/sizeof(int); i++)
    {
        a[i] = number[i];
    }
}

void shellSort(int array[],int n,int t);
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex);
void HeapSort(int array[],int length);
void radixsort(int data[], int n);

int main()
{
    int number[SIZE] = {95, 45, 15, 78, 84, 51, 24, 12};

    restore(number);
    print(number, SIZE);
    bubble_sort(number, SIZE);
    print(number, SIZE);

    restore(number);
    print(number, SIZE);
    insert_sort(number, SIZE);
    print(number, SIZE);

    restore(number);
    print(number, SIZE);
    printf("插入排序:");
    Qsort(number, 0, SIZE-1);
    print(number, SIZE);

    restore(number);
    print(number, SIZE);
    select_sort(number, SIZE);
    print(number, SIZE);

    restore(number);
    print(number, SIZE);
    int l = int(log(SIZE + 1) / log(2));
    //shellSort(number, SIZE, l);//排序趟数应为log2(n+1)的整数部分
    print(number, SIZE);
    
    restore(number);
    print(number, SIZE);
    printf("递归排序:");
    int b[SIZE];
    //MergeSort(number, b, 0, SIZE);
    print(number, SIZE);

    restore(number);
    print(number, SIZE);
    HeapSort(number, SIZE);
    print(number, SIZE);

    restore(number);
    print(number, SIZE);
    radixsort(number, SIZE);
    print(number, SIZE);

    return 0;
}


/*
* 5、希尔排序（Shell`s Sort）
* 分别先分 1 2 ... n组进行插入排序（也可以3k+1这样分组）
* 这样是更有序，越有序插入排的越快，
* 最后一个全部元素一组，排完
*/
//根据当前增量进行插入排序
void shellInsert(int array[],int n,int dk)
{
    int i,j,temp;
   // 分n/dk+1组
	for(i = dk; i < n; i++)
	{
		// 从每组第一个元素开始，插入排序
		for(j = i;	(j >= i-dk) && array[j] < array[j-dk];	j -= dk)
		{
			temp = array[j];
			array[j] = array[j-dk];
			array[j-dk] = temp;
		}
	}
}
 
//计算Hibbard增量
int dkHibbard(int t,int k)
{
    return int(pow(2,t - k + 1) - 1);
}
 
//此写法便于理解，实际应用时应将上述三个函数写成一个函数。
void shellSort(int array[],int n,int t)
{
    printf("希尔排序:");
    int i;
    for(i = 1;i <= t;i++){
        shellInsert(array,n,dkHibbard(t,i));
    }
}

// 6、并归排序
void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i != midIndex + 1 && j != endIndex + 1)
    {
        if(sourceArr[i] >= sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i = startIndex; i <= endIndex; i++)
        sourceArr[i] = tempArr[i];
}
 
// 内部使用递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = (startIndex + endIndex) / 2;
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

// 7、堆排序
//array是待调整的堆数组，i是待调整的数组元素的位置，nlength是数组的长度
//本函数功能是：根据数组array构建大根堆
void HeapAdjust(int array[],int i,int nLength)
{
    int nChild;
    int nTemp;
    for( ; 2 * i + 1 < nLength; i = nChild)
    {
        //子结点的位置=2*（父结点位置）+1
        nChild = 2 * i + 1;
        //得到子结点中较大的结点
        if(nChild < nLength - 1 && array[nChild + 1] > array[nChild]) ++nChild;
        //如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
        if(array[i] < array[nChild])
        {
            nTemp = array[i];
            array[i] = array[nChild];
            array[nChild] = nTemp; 
        }
        else break; //否则退出循环
    }
}

void HeapSort(int array[],int length)
{
    printf("堆排序:");
    int i;
    //调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
    //length/2-1是最后一个非叶节点，此处"/"为整除
    for(i = length / 2 - 1;i >= 0;--i)
    HeapAdjust(array,i,length);
    //从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for(i = length - 1;i > 0;--i)
    {
        //把第一个元素和当前的最后一个元素交换，
        //保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
        array[i] = array[0] ^ array[i];
        array[0] = array[0] ^ array[i];
        array[i] = array[0] ^ array[i];
        //不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        HeapAdjust(array,0,i);
    }
}

// 8、基排序
int maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
    int d = 1; //保存最大的位数
    int p = 10;
    for(int i = 0; i < n; ++i)
    {
        while(data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}

void radixsort(int data[], int n) //基数排序
{
    printf("基排序:");
    int d = maxbit(data, n);
    int *tmp = new int[n];
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete[]tmp;
    delete[]count;
}


