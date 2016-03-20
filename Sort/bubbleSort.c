#include<stdio.h>
void swap(int*a, int*b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void bubbleSort(int*a, int size)
{
	int j=0;
	while(j<size-1)
	{
		int i=size-1;
		while(i>j)
		{
			if(a[i]<a[i-1])
			{
				swap(&a[i], &a[i-1]);
			}
			i--;
		}
		j++;
	}
}
void main()
{
	int a[10] ={8,4,9,3,6,2,5,7,1,0};
	bubbleSort(a,10);
	int i = 0,size = 10;
	for(;i<size;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}
