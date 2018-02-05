#include<iostream>
#include<stdio.h>
using namespace std;

void insertsort(int arr[], int n);

int main()
{
	int * arr;
	int n;

	scanf("%d ", &n);
	arr=new int[n];
	for(int i=0; i<n; i++)
	   scanf("%d ", &arr[i]);
	
	insertsort(arr, n);
	for(int i=0;i<n;i++)
	   printf("%d ", arr[i]);
	return 0;
}

void insertsort(int arr[], int n)
{
	int temp, i, j, k;
	for(i=1;i<n;i++)
	{
	   for(j=0;j<i&&arr[j]<arr[i];j++);
	   temp=arr[i];
	   for(k=i;k>j;k--)
	      arr[k]=arr[k-1];
	   arr[j]=temp;
	}
}
