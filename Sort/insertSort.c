#include<stdio.h>
void swap(int* a ,int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b =temp;
}
void insertSort(int* a, int size)
{
	int i, j;
	for(i=1;i<size;i++)
	{
		j = i-1;
		while(j>=0 && a[j]>a[j+1])
		{
			swap(&a[j+1], &a[j]);
			j--;
		}
	}
}
void main()
{
	int a[10] ={8,4,9,3,6,2,5,7,1};
    insertSort(a, 10);
    int i = 0,size = 10;
    for(;i<size;i++)
    {
	    printf("%d\t",a[i]);
    }
    printf("\n");
}
