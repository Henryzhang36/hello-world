#include<iostream>
#include<stdio.h>
using namespace std;

void quicksort(int a[], int low, int high)
{
	if(low>=high)
	  return;
	int first=low, last=high, key=a[first];
	while(first<last)
	{
	     while(first<last&&a[last]>=key)
		  --last;
	     a[first]=a[last];
	     while(first<last&&a[first]<=key)
		  ++first;
	     a[last]=a[first];
	}
	a[first]=key;
	quicksort(a, low, first-1);
	quicksort(a, first+1, high);
}

int main()
{
	int *arr, i, n;
	cin>>n;
	arr=new int[n];
	for(i=0;i<n;i++)
	   scanf("%d ", &arr[i]);
	quicksort(arr, 0, n-1);
	for(i=0;i<n;i++)
	   printf("%d ", arr[i]);
	delete []arr;	
	return 0;
}
