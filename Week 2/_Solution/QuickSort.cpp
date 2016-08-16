#include<iostream>
#include<cstdio>
//#include<cfile>
using namespace std;

int comparisons=0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*int median_of_three(int *a, int low, int high){
    int mid = low+(high-low)/2;
    if(a[mid]<a[left])
        swap(&a[mid], &a[left])
}*/

int partition(int *a, int low, int high){
    comparisons+=high-low;
    int i=low+1, j, pivot=a[low];
    for(j=low+1; j<=high; j++){
          if(a[j]<pivot){
              swap(&a[j], &a[i]);
              i++;
          }
    }
    swap(&a[i-1], &a[low]);
    return i-1;
}

void QuickSort(int *a, int low, int high){
    if(low<high){
        int p = partition(a, low, high);
        QuickSort(a, low, p-1);
        QuickSort(a, p+1, high);
    }
}
int main(){
    FILE *p;
    p= fopen("QuickSort.txt","r");
    int num,a[100001],i=0;
    while(fscanf(p,"%d",&num)>0){
        a[i] = num;
        i++;
    }
    int n=i;
    QuickSort(a, 0, n-1);
    cout<<comparisons<<endl;
}
