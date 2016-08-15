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

int partition(int *a, int low, int high){
    comparisons+=high-low;
    int pivot = a[low];
    while(low<high){
        if(a[low]>pivot && a[high]<pivot){
            swap(&a[low], &a[high]);
            low++; high--;
            //comparisons++;
        }
        else{
            if(a[low]<=pivot){
                low++;
                //comparisons++;
            }
            if(a[high]>=pivot){
                high--;
                //comparisons++;
            }
        }
    }
    swap(&pivot, &a[high]);
    return high;
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
    QuickSort(a,0, n-1);
    cout<<comparisons<<endl;
    //for(int i=0;i<n;i++)
      //  cout<<a[i]<<endl;
}
