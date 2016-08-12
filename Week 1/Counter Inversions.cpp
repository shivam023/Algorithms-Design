#include<iostream>
#include<cstdio>
using namespace std;
int temp[100002];

long long int merge(int *a, int low, int mid, int high){
    int i=low, j=mid+1;
    int k=low, siz=high-low+1;
    long long int inv=0;
    while(i<=mid&&j<=high){
            //cout<<"hello"<<endl;
        if(a[i]<=a[j]){
            temp[k++]=a[i];
            //cout<<temp[k-1]<<endl;
            i++;
        }
        else{
            temp[k++]=a[j];
            inv+=mid-i+1;
            j++;
        }
    }
    while(i<=mid){
        temp[k++]=a[i];
        i++;
    }
    while(j<=high){
        temp[k++]=a[j];
        j++;
    }
    i=0;
    while(i<=siz)
    {
        a[high]=temp[high];
        high--;
        i++;
    }
    return inv;
}
long long int merge_sort(int *a, int low, int high){
    //int inv=0;
    long long int inv=0;
    if(low<high){
        int mid = low+ (high-low)/2;
        inv=merge_sort(a, low, mid);
        inv+=merge_sort(a, mid+1, high);
        inv+=merge(a, low, mid, high);
    }
    return inv;
}
int main(){
    int arr[]={2,5,4,7,1,9};

    int a[100002];
      FILE *p= fopen("IntegerArray.txt","r");
      if(p==NULL)
        cout<<"File not found"<<endl;
      int i=0, num;
      while(fscanf(p, "%d", &num) > 0) {
            a[i] = num;
            //cout<<a[i]<<endl;
            i++;
        }
      int n=i;
      long long int inv=merge_sort(a, 0, n-1);
      //long long int inv=merge_sort(arr, 0, 5);
    cout<<"inversion_count: "<<inv<<endl;
}
