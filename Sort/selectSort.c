#include<stdio.h>
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectSort(int* a, int size)
{
    int i, j;
    for(i=0;i<size-1;i++)
    {
        int min = a[i];
        int index = i;
        for(j=i;j<size;j++)
        {
            if(a[j]<min)
            {
                min = a[j];
                index = j;
            }
        }
        swap(&a[i], &a[index]);   
    }
}
void main()
    {
       int a[10] ={8,4,9,3,6,2,5,7,1};
       selectSort(a, 10);
       int i = 0,size = 10;
       for(;i<size;i++)
       {
           printf("%d\t",a[i]);
       }
       printf("\n");
    }
