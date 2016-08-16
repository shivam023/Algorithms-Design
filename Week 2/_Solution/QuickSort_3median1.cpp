#include <cstdlib>
#include <iostream>
#include <stdio.h>
#define SIZE 10000

using namespace std;

void swap(int *x, int *y)
{
     int temp=*x;
     *x=*y;
     *y=temp;
}

void getPivot(int *arr, int l, int u)
{
    int m=l+(u-l)/2;
    if(arr[l]>=arr[m] && arr[l]>=arr[u])
    {
        if(arr[m]>=arr[u]) swap(&arr[m], &arr[l]);
        else swap(&arr[u],&arr[l]);
    }
    else if(arr[m]>=arr[l] && arr[m]>=arr[u])
    {
        if(arr[u]>=arr[l]) swap(&arr[u], &arr[l]);
    }
    else if(arr[m]>=arr[l]) swap(&arr[m], &arr[l]);
}

int partition_arr(int *arr, int l, int u)
{
    int i=l+1, j, p=arr[l];
    for(j=l+1; j<=u; j++)
    {
          if(arr[j]<p)
          {
                      swap(&arr[j], &arr[i]);
                      i++;
          }
    }
    swap(&arr[i-1], &arr[l]);
    return i-1;
}

long long quick(int *arr, int l, int u)
{
     if(u<=l) return 0;
     long long comp=u-l;
     //swap(&arr[l], &arr[u]);            /*For Question 2*/
     //getPivot(arr, l, u);               /*For Question 3*/
     int j=partition_arr(arr, l, u);
     comp+=quick(arr, l, j-1);
     comp+=quick(arr, j+1, u);
     return comp;
}

int main(int argc, char *argv[])
{
    int *arr=new int[SIZE+1];
    char a[10];
    FILE *f=fopen("QuickSort.txt","r");
    for(int i=1; i<=SIZE; i++)
    {
            fgets(a,10,f);
            arr[i]=atoi(a);
    }
    fclose(f);
    cout<<"Total number of comparisons: "<<quick(arr,1,SIZE)<<endl;
    delete arr;
    system("PAUSE");
    return EXIT_SUCCESS;
}
