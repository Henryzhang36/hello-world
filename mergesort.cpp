#include<iostream>
#include<stdio.h>
using namespace std;

void merge(int arr[], int aux[], int lo, int mid, int hi)
{
	int i=lo,j=mid+1;
	for(int k=lo;k<=hi;k++)
	   aux[k]=arr[k];
	for(int k=lo;k<=hi;k++)
	{
	   if(i>mid)              arr[k]=aux[j++];
	   else if(j>hi)          arr[k]=aux[i++];
	   else if(aux[i]<aux[j]) arr[k]=aux[i++];
	   else                   arr[k]=aux[j++];
	}
}

void sort(int arr[], int lo, int hi)
{
	int temp;
	if(arr[lo]>arr[hi])
	{
	  temp=arr[lo];
	  arr[lo]=arr[hi];
	  arr[hi]=temp;
	}
}

void mergesort(int arr[], int aux[], int lo, int hi)
{
	if((hi-lo)>1)	
	{	
	  int mid=(lo+hi)/2;
	  mergesort(arr, aux, lo, mid);
	  mergesort(arr, aux, mid+1, hi);
	  merge(arr, aux, lo, mid, hi);
	}	
	else sort(arr, lo, hi);
}

int main()
{
	int *arr, *aux, i, n;
	cin>>n;
	arr=new int[n];
	aux=new int[n];
	for(i=0;i<n;i++)
	   scanf("%d ", &arr[i]);
	mergesort(arr, aux, 0, n-1);
	for(i=0;i<n;i++)
	   printf("%d ", arr[i]);
	delete []arr;
	delete []aux;	
	return 0;
}
