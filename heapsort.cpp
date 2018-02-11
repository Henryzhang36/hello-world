#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 10000

class priorQ{
	public:
	     int array[MAX];
	     int n;
	     
	     bool isbigger(int a, int b);
	     void exchange(int a, int b);
	     void swim(void);
	     void sink(int p);
	     void insert(int a);
	     int deletemax();
	     priorQ();
};

priorQ::priorQ(void)
{
	n=0;
}

void priorQ::exchange(int a, int b)
{
	int temp=this->array[a];
	this->array[a]=this->array[b];
	this->array[b]=temp;
}

bool priorQ::isbigger(int a, int b)
{
	if(this->array[a]>this->array[b])
	  return 1;
	else 
	  return 0;
}

void priorQ::swim()
{
	int h=n;
	while((h/2)>0&&isbigger((h-1), (h/2-1)))
	{
	     exchange((h-1), (h/2-1));
	     h=h/2;
	}
}

void priorQ::sink(int p)
{
	int h=p;
	while(2*h<=n)
	{
	   int j=2*h;
	   if(j<this->n&&isbigger(j+1, j)) j++;
	   if(!isbigger(h,j)) break;
	   exchange(h, j);
	   h=j;
	}
}

void priorQ::insert(int a)
{
	n++;
	array[n-1]=a;
	swim();
}	

int priorQ::deletemax()
{
	int max=array[0];
	exchange(0,n-1);
	n--;
	array[n]='\0';
	sink(1);
	return max;
}

int main()
{
	int a, n, i;
	priorQ pri;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
	   scanf("%d", &a);
	   pri.insert(a);
	}
	for(i=0; i<n;i++)
	   printf("%d ", pri.array[i]);
	return 0;
}
