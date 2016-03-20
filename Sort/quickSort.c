/*************************************************************************
	> File Name: quicksort.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月19日 星期六 19时09分04秒
 ************************************************************************/

#include<stdio.h>

void quickSort(int* a, int left, int right)
{
        int key = a[left];
        int i = left, j = right; 
        while(i<j)
    {
                while(i<j && a[j]>key)
        {
                        j--;
                    
        }
                a[i++] = a[j];
                while(i<j && a[i]<key)
        {
                        i++;
                    
        }
                a[j--] = a[i];
            
    }
        a[i] = key;
        quickSort(a, left, i-1);
        quickSort(a, i+1, right);

}
void main()
{
        int a[10] ={8,4,9,3,6,2,5,7,1};
        quickSort(a,0,9);
        int i = 0,size = 10;
        for(;i<size;i++)
    {
                printf("%d\t",a[i]);
            
    }
        printf("\n");

}
