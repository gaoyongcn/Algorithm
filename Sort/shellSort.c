#include<stdio.h>
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
//dk为增量
void shellSort(int*a, int size, int dk)
{
	int i,j,k;
	while(dk>0)
	{
		for(i=0;i<dk;i++)
		{
			j = i;
			while(j<size)
			{
				k=j;
				while(k>=i+dk)
				{
					if(a[k]<a[k-dk])
					{
						swap(&a[k], &a[k-dk]);
					}
					k -= dk;
				}
				j += dk;		
			}
		}
		dk--;
	}
}
void main()
{
	int a[10] ={0,8,4,9,3,6,2,5,7,1};
	shellSort(a, 10, 3);
	int i = 0,size = 10;
	for(;i<size;i++)
	{
	   printf("%d\t",a[i]);
	}
	printf("\n");
}
