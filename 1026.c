#include <stdio.h>
#include <stdlib.h>
int main(void){
    int n,check,k,sum=0;
    int *A,*B,*B_sort;
    scanf("%d",&n);
    A=(int*)malloc(sizeof(int)*n);
    B=(int*)malloc(sizeof(int)*n);
    B_sort=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&B[i]);
    }
    for(int i=0;i<n;i++){
        B_sort[i]=B[i];
    }
    
    while(1){
        check=0;
        for(int i=0;i<n-1;i++){
            if(B_sort[i]>B_sort[i+1]){
                k=B_sort[i+1];
                B_sort[i+1]=B_sort[i];
                B_sort[i]=k;
                check++;
            }
        }
        if(check==0) break;
    }
    while(1){
        check=0;
        for(int i=0;i<n-1;i++){
            if(A[i]<A[i+1]){
                k=A[i+1];
                A[i+1]=A[i];
                A[i]=k;
                check++;
            }
        }
        if(check==0) break;
    }
    for(int i=0;i<n;i++){
        sum+=A[i]*B_sort[i];
    }
    printf("%d\n",sum);
}