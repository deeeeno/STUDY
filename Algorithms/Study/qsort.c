#include <stdio.h>
#include <time.h>
#define MAX 100000
int arr[MAX+2];

void QS(int left, int right, int* arr){
        int l = left, r = right, pivot = arr[left];
        int t;
        if(left < right){
                while(l<=r){
                        while(l<=right && arr[l] <= pivot) l++;
                        while(r>=left  && arr[r] > pivot)  r--;
                        if(l < r){
                                t = arr[r]; arr[r] = arr[l]; arr[l]=t;
                        }
                }
                t=arr[r]; arr[r] = arr[left]; arr[left] = t;
                QS(left, r-1, arr);
                QS(r+1,right,arr);

        }
}


int main(){
        int i;
        clock_t start_point, end_point;

        for(i=0; i<MAX; i++) arr[i] = MAX-i;
        start_point = clock();
        QS(0,MAX-1,arr);
        end_point = clock();

        printf("EXE TIME : %f sec\n",((double)(end_point - start_point)/CLOCKS_PER_SEC));
        return 0;
}