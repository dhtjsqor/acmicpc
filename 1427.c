#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *arr,int mid, int len){
    int i=0, j=mid,k=0;
    int *temp = malloc(sizeof(int)*len);
    while(i<mid && j<len){
        if(arr[i]>=arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while(i<mid) temp[k++]=arr[i++];
    while(j<len) temp[k++]=arr[j++];
    memcpy(arr,temp,sizeof(int) * len);
    free(temp);
}
void merge_sort(int *arr, int size){
    if(size<=1) return;
    merge_sort(arr, size/2);
    merge_sort(arr+size/2,size-size/2);
    merge(arr,size/2,size);
}
int main(void){
    int *arr;
    int N,m,i=0;
    scanf("%d",&N);
    for(m=N;m>0;m/=10) i++;
    arr = (int*)malloc(sizeof(int)*i);
    for(int j=0;j<i;j++){
        arr[j]=N%10;
        N/=10;
    }
    merge_sort(arr,i);
    for(int j=0;j<i;j++){
        printf("%d",arr[j]);
    }
}
