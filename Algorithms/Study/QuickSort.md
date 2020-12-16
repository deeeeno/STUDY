# QuickSort
정렬 알고리즘 중 O(NlogN)의 평균속도를 가지는 Quick Sort에 대해서 알아보자.
퀵소트는 정렬의 기준이 되는 값인 pivot값을 가지고 pivot을 중심으로 왼쪽, 오른쪽이 정렬의 기준에 맞게 값이 존재한다는걸 목표로 sorting하는 알고리즘이다. 오름차순을 예시로 아래의 그림과 같은 모습이 되어야 한다.
![qsort and pivot](/Algorithms/Study/resource/qsort1.PNG)

이 구조를 만들기 위해서 알고리즘이 진행되는 flow는 아래와 같다.
![qsort and pivot](/Algorithms/Study/resource/qsort2.PNG)

pivot이 될 값은 가장 좌측의 data로 설정하고, data를 탐색할 left, right값을 양 끝 index로 설정한다. 우리는 오름차순의 quick sort를 확인할 것이므로, left index에 대한 값은 pivot보다 작거나 같게, right index에 대한 값은 pivot보다 커야한다.
data를 순회하다가 기준에 맞지 않는 left,right index를 찾으면 값을 변경시켜주자.
그 후에 두 값이 교차되는 지점이 생긴다. 교차되는 시점에 pivot과 right index의 값을 변경해주면 처음 quick sort의 목표와 맞게 pivot 중심으로 값들이 나눠지게 된다.
그 후엔 pivot을 기점으로 나눈 두 부분을 동일한 flow로 정렬을 시작한다. 코드로 보면 아래와 같다.

```
void QS(int left, int right, int* arr){
        int l = left, r = right, pivot = arr[left];
        int t;
        //배열을 분할하다보면 길이가 1의 배열이 되는데 이 경우는 탐색할 필요가 없다.
        if(left < right){           
                while(l<=r){
                        while(l<=right && arr[l] <= pivot) l++; // left 탐색
                        while(r>=left  && arr[r] > pivot)  r--; // right 탐색
                        if(l < r){
                                t = arr[r]; arr[r] = arr[l]; arr[l]=t;
                        }
                }
                t=arr[r]; arr[r] = arr[left]; arr[left] = t; // pivot 위치 변경
                QS(left, r-1, arr);
                QS(r+1,right,arr);

        }
}
```