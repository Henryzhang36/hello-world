#include<iostream>
#include<stdio.h>
using namespace std;

void swap(int a[], int i, int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

void quick3way(int a[], int low, int high)
{
	if(low>=high)
	  return;
	int first=low, middle=low, last=high, key=a[first];
	while(middle<last+1)
	{
	     if(a[middle]<key)
	     {
	       swap(a, first, middle);
	       first++;
	       middle++;
	     } 
	     else if(a[middle]>key)
	     {
	       swap(a, last, middle);
	       last--;
	     }
	     else
		 middle++;
	}
	quick3way(a, low, first-1);
	quick3way(a, last+1, high);
}

int main()
{
	int *arr, i, n;
	cin>>n;
	arr=new int[n];
	for(i=0;i<n;i++)
	   scanf("%d ", &arr[i]);
	quick3way(arr, 0, n-1);
	for(i=0;i<n;i++)
	   printf("%d ", arr[i]);
	delete []arr;	
	return 0;
}
