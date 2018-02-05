#include<iostream>
#include<stdio.h>
using namespace std;

void shellsort(int arr[], int n)
{
	int h=n, i, j, k, l, m, p, tem;
//find h
	while(h>1)
	{
	     h=(h+1)/2;
//sort each of the subsequence
	     for(i=0;i<h;i++)
	     {
//enumerate the length m of subsequence
		m=1;
		p=i;
		while(p+h<n)
		{
		     p=p+h;
		     m++;
		}
//insert sort the subsequence
		for(j=1;j<m;j++)
		{
		   for(k=0;k<j&&arr[i+k*h]<arr[i+j*h];k++);
		   tem=arr[i+j*h];
		   for(l=j;l>k;l--)
		      arr[i+l*h]=arr[i+(l-1)*h];
		   arr[i+k*h]=tem;
		}
	     }
	}
}



int main()
{
	int* arr;
	int n, i;
	cin>>n;
	arr=new int[n];
	for(i=0;i<n;i++)	
	scanf("%d ", &arr[i]);
	shellsort(arr, n);
	for(i=0;i<n;i++)
	printf("%d ", arr[i]);
	delete []arr;	
	return 0;
}
