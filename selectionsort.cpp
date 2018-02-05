#include<stdio.h>
#include<iostream>
using namespace std;

class array
{
 public:
  int* sta;
  int siz;
  void selectionsort();
  array(int loc[], int n);
};

array::array(int loc[], int n)
{
  sta=loc;
  siz=n;
}

void array::selectionsort()
{
 int min, pos, swi, i, j;
 for(i=0;i<(this->siz);i++)
 {
    min=*((this->sta)+i);
    pos=i;
    for(j=i+1;j<(this->siz);j++)
    {
       if(*((this->sta)+j)<min)
       {
         min=*((this->sta)+j);
         pos=j;
       }
    }
    swi=*((this->sta)+i);
    *((this->sta)+i)=min;
    *((this->sta)+pos)=swi;
 }
}

main()
{
 int* loc;
 int n, i;
 cin>>n;
 loc=new int[n];
 for(i=0;i<n;i++)
    scanf("%d ", &loc[i]);
 array arr(loc, n);
 arr.selectionsort();
 for(i=0;i<n;i++)
    printf("%d ", loc[i]);
 delete []loc;
}
