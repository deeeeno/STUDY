# HEAP
힙(heap)은 완전 이진 트리의 하나로 부모노드와 자식노드 간의 정렬 기준이 명확한 자료구조이다. 우선순위 큐라고도 불리우며, min heap, max heap이 있다. heap의 자료구조 이론은 매우 간단하다. 모든 노드에 대해서 부모, 자식 노드의 정렬이 명확하다는 것!! 아래 그림을 보면 더 이해가 쉬울 것이다.

![heap](/Algorithms/Study/resource/heap.png)

이를 코드로 구현하기 위해선 두개의 전재 조건이 필요하다.

1. 힙 구조의 시작 노드는 1번
2. 부모노드 n번에 대해서 자식 노드는 2n, 2n+1번

이 두가지를 염두해두고, 힙 자료구조에 데이터를 insert, 데이터 pop하는 알고리즘을 확인해보자.


### INSERT
동양 무술 영화를 보면 꼭 존재하는 콘텐츠 중 하나는 `도장깨기`이다. 고수는 밑바닥 도장부터 최고의 도장까지 격파해나아간다. 데이터 insert도 이와 동일하다. 새로 들어온 데이터 element는 맨 마지막 index로 들어가고 부모노드와 크기를 비교해가며 head로 향하게 된다. 그림으로 보면 아래와 같다.

![heap](/Algorithms/Study/resource/min_heap1.gif)

코드로보면 아래와 같다.
```
void insert_min_heap(int ele) {
    if(min_heap.heapSize == MAX){
        return;
    }
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
```

### POP
데이터를 빼오는 작업은 어떻게 될까? 이제 최고의 고수가 물러가고 다음 고수를 뽑을 차례다. 하지만 신기하게도 맨 마지막 index의 흐접이 헤드로 올라온다. 흐접이 올라와서 어떻게 되겠는가? 당연히 밑에있던 고수들이 반발이 일어날 것이다. 얻어 터지는 흐접은 계속 밑으로 내려가게 된다.

![heap](/Algorithms/Study/resource/min_heap2.gif)

```
int pop() {
    if(min_heap.heapSize == 0){
        return -1;
    }
    
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
```
