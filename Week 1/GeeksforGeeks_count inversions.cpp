#include <bits/stdc++.h>
#include<cstdio>
#include<iostream>
using namespace std;
long int  _mergeSort(long int arr[], long int temp[], long int left, long int right);
long int merge(long int arr[], long int temp[], long int left, long int mid, long int right);
long int mergeSort(long int arr[], long int array_size)
{
    long int *temp = (long int *)malloc(sizeof(long int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}

long int _mergeSort(long int arr[], long int temp[], long int left, long int right)
{
  long int mid, inv_count = 0;
  if (right > left)
  {
    mid = (right + left)/2;
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

long int merge(long int arr[], long int temp[], long int left, long int mid, long int right)
{
  long int i, j, k;
  long int inv_count = 0;

  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }

  while (i <= mid - 1)
    temp[k++] = arr[i++];

  while (j <= right)
    temp[k++] = arr[j++];

  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}

int main(long int argv, char** args)
{
  long int arr[] = {1, 20, 6, 4, 5};
  long int a[100002];
  FILE *p= fopen("IntegerArray.txt","r");
  if(p==NULL)
    cout<<"File not found"<<endl;
  long int i=0, num;
  while(fscanf(p, "%d", &num) > 0) {
        a[i] = num;
        //cout<<a[i]<<endl;
        i++;
    }
  long int n=i;
  //cout<<n<<endl;
  //printf(" Number of inversions are %d \n", mergeSort(a, n));
  printf(" Number of inversions are %d \n", mergeSort(arr, 5));
  return 0;
}
