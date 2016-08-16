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

int median3(int *a, int left, int right)//Uses median of three partitioning technique
{
    int center = (left + right)/2;
    if (a[center] < a[left])
        swap(&a[left],&a[center]);
    if (a[right] < a[left])
        swap(&a[left],&a[right]);
    if (a[right]< a[center])
        swap(&a[center],&a[right]);

    swap(&a[center], &a[right - 1]);//since the largest is already in the right.
    return a[right - 1];
}



  void quicksort(int a[], int left, int right)
    {
      if (left < right) {
        comparisons+=right-left;
    	int pivot = median3(a,left,right);
        if (left == right - 1) return;
    	int i = left;
    	int j = right - 1;
    	for ( ; ;) {
    		while(a[++i]<pivot) {}
    		while(pivot<a[--j]) {}
    		if ( i < j)
    			swap(&a[i],&a[j]);
    		else
    			break ;
    	}
    	swap(&a[i],& a[right -1]);
    	quicksort(a,left,i-1);
    	quicksort(a,i+1,right);
      }
    	return ;
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
    quicksort(a, 0, n-1);
    cout<<comparisons<<endl;

}
