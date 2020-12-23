#include <iostream>
#include <cstdio>
#define MAX 100
using namespace std;

typedef struct heap{
    int element[MAX];
    int heapSize = 0;
}HEAP;

HEAP max_heap, min_heap;

//HEAP 자료구조
/*
기본 노드
부모노드 n번에 대해서 자식 노드는 2n, 2n+1이 된다.
*/


/*
MAX HEAP의 경우
1. insert
insert의 경우 맨 마지막 인덱스로 새로운 데이터를 넣고 부모노드와 크기를 비교한다
MAX HEAP이니까 새롭게 들어온놈이 더 크면 부모와 swap

2. pop
힙은 우선순위 큐이다. 이 소리는? 헤드가 튀어나온다는거.
이번엔 헤드부터 자식간 비교를 한다. 자식노드는 두개! 그러므로 둘 중 더 큰놈과 swap을 한다. 왜냐? max heap이니까.
*/

//max heap은 큰놈부터 나오는 것이다.
//insert의 경우 ehwkd
void insert_max_heap(int ele) {
    int i = ++(max_heap.heapSize);
    //처음 들어온놈 i=1인 경우 걍 데이터 넣고 끝내
    max_heap.element[i] = ele;
    if (i != 1) {//아닌경우 탐색을 시작한다.
        //헤드의 노드 경우 1번이다. 그리고 부모 노드가 있어야 함.
        while (i > 1 && max_heap.element[i / 2] < ele) {
            //내 첫번째 생각.난 지금 스와핑을 씀.
            /*int tmp = min_heap.element[i / 2];
            min_heap.element[i / 2] = min_heap.element[i];
            min_heap.element[i] = tmp;*/

            //참고 및 두번째 생각
            max_heap.element[i] = max_heap.element[i / 2]; // 부모가 내려와있으면 되자너
            i /= 2;
        }
        max_heap.element[i] = ele;
    }
}

int push_max_heap() {
    int rtn_value = max_heap.element[1];
    int i = 1;
    max_heap.element[1] = max_heap.element[max_heap.heapSize]; // 마지막 노드를 끌어올려
    max_heap.heapSize -= 1;

    int pivot = max_heap.element[1];
    while (2 * i <= max_heap.heapSize) { // 내려가면서 정렬 시작.
        int left_child = 2 * i;
        int right_child = (left_child <= (max_heap.heapSize - 1)) ? left_child + 1 : left_child;

        int target_child = (max_heap.element[left_child] >= max_heap.element[right_child]) ? left_child : right_child;

        if (pivot < max_heap.element[target_child]) {
            max_heap.element[i] = max_heap.element[target_child];
        }
        else break;
        i = target_child;
    }
    max_heap.element[i] = pivot;
    return rtn_value;
}

void insert_min_heap(int ele) {
    int i = ++(min_heap.heapSize);
    //처음 들어온놈 i=1인 경우 걍 데이터 넣고 끝내
    min_heap.element[i] = ele;
    if (i != 1) {//아닌경우 탐색을 시작한다.
        //헤드의 노드 경우 1번이다. 그리고 부모 노드가 있어야 함.
        while (i > 1 && min_heap.element[i / 2] > ele) {
            //내 첫번째 생각.난 지금 스와핑을 씀.
            /*int tmp = min_heap.element[i / 2];
            min_heap.element[i / 2] = min_heap.element[i];
            min_heap.element[i] = tmp;*/

            //참고 및 두번째 생각
            min_heap.element[i] = min_heap.element[i / 2]; // 부모가 내려와있으면 되자너

            i /= 2;
        }
        min_heap.element[i] = ele; // 마지막 부모의 자리를 메꿔주는거지
    }
}

int push_min_heap() {
    int rtn_value = min_heap.element[1];
    int i = 1;
    min_heap.element[1] = min_heap.element[min_heap.heapSize]; // 마지막 노드를 끌어올려
    min_heap.heapSize -= 1;

    int pivot = min_heap.element[1];
    while (2*i <= min_heap.heapSize) { // 내려가면서 정렬 시작.
        int left_child = 2 * i;
        int right_child = (left_child <= (min_heap.heapSize-1)) ? left_child + 1 : left_child;

        int target_child = (min_heap.element[left_child] < min_heap.element[right_child]) ? left_child : right_child;

        if (pivot > min_heap.element[target_child]) {
            min_heap.element[i] = min_heap.element[target_child];
        }
        else break;
        i = target_child;
    }
    min_heap.element[i] = pivot;
    return rtn_value;
}


int main()
{
    insert_max_heap(5);
    insert_max_heap(7);
    insert_max_heap(1);
    insert_max_heap(9);
    insert_max_heap(2);
    insert_max_heap(3);

    printf("%d\n", push_max_heap());
    printf("%d\n", push_max_heap());
    printf("%d\n", push_max_heap());
    printf("%d\n", push_max_heap());
    printf("%d\n", push_max_heap());
    printf("%d\n\n\n", push_max_heap());

    insert_min_heap(5);
    insert_min_heap(7);
    insert_min_heap(1);
    insert_min_heap(9);
    insert_min_heap(2);
    insert_min_heap(3);

    printf("%d\n", push_min_heap());
    printf("%d\n", push_min_heap());
    printf("%d\n", push_min_heap());
    printf("%d\n", push_min_heap());
    printf("%d\n", push_min_heap());
    printf("%d\n", push_min_heap());
}
