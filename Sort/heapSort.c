#include<stdio.h>
    //最大堆排序
    void heapAjust(int* a, int i,int size)
    {
	    int nChild = 2*i+1;
	    int temp;
	    while(nChild<size)
	    {
			    if((nChild+1<size)&&(a[nChild+1]>a[nChild]))
			    {
					nChild++;
			    }
				if(a[nChild]<a[i])
				{
					break;
					
				}
				temp = a[i];
				a[i] = a[nChild];
				a[nChild] = temp;
				i = nChild;
				nChild = 2*i + 1;
	    }    
    }
    void heapSort(int* a,int size)
    {
	    int i = size/2 -1;
	    int temp; 
	    for(;i>=0;i--)
	    {
		    heapAjust(a, i, size);
	    }
	    for(i=size-1;i>0;i--)
	    {
		    temp = a[i];
		    a[i] = a[0];
		    a[0] = temp;
		    size--;
		    heapAjust(a,0,size);
	    }
    }
    void main()
    {
	   int a[10] ={8,4,9,3,6,2,5,7,1,0};
	   heapSort(a,10);
	   int i = 0,size = 10;
	   for(;i<size;i++)
	   {
		   printf("%d\t",a[i]);
	   }
	   printf("\n");
	}

