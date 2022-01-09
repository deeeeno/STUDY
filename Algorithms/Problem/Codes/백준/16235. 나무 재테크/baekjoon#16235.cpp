#define _CRT_SECURE_NO_WARNINGS
#define MAX_N	10
#define MAX_M	100
#define MAX_K	1000
#define MAX_HEAP_SIZE 20000

#define SPRING	0
#define AUTUNM	1
#define WINTER	2

#include <iostream>
#include <cstdio>
using namespace std;

int N, M, K;
typedef struct heap {
	int element[MAX_HEAP_SIZE] = { 0, };
	int heapSize = 0;
}HEAP;

int dx[8] = { -1,-1,-1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1,-1, 1,-1, 0, 1 };
int s2d2[MAX_N + 2][MAX_N + 2] = { 0, };
int fuel[MAX_N + 2][MAX_N + 2] = { 0, };
HEAP tree[MAX_N + 2][MAX_N + 2] = { NULL, };



void insert_into_tree(HEAP* tree_heap, int ele) {
	int i = ++(tree_heap->heapSize);
	//처음 들어온놈 i=1인 경우 걍 데이터 넣고 끝내
	tree_heap->element[i] = ele;
	if (i != 1) {//아닌경우 탐색을 시작한다.
		//헤드의 노드 경우 1번이다. 그리고 부모 노드가 있어야 함.
		while (i > 1 && tree_heap->element[i / 2] > ele) {
			tree_heap->element[i] = tree_heap->element[i / 2]; // 부모가 내려와있으면 되자너
			i /= 2;
		}
		tree_heap->element[i] = ele; // 마지막 부모의 자리를 메꿔주는거지
	}
}

int push_from_tree(HEAP* tree_heap) {
	int rtn_value = tree_heap->element[1];
	int i = 1;
	tree_heap->element[1] = tree_heap->element[tree_heap->heapSize]; // 마지막 노드를 끌어올려
	tree_heap->heapSize -= 1;

	int pivot = tree_heap->element[1];
	while (2 * i <= tree_heap->heapSize) { // 내려가면서 정렬 시작.
		int left_child = 2 * i;
		int right_child = (left_child <= (tree_heap->heapSize - 1)) ? left_child + 1 : left_child;

		int target_child = (tree_heap->element[left_child] < tree_heap->element[right_child]) ? left_child : right_child;

		if (pivot > tree_heap->element[target_child]) {
			tree_heap->element[i] = tree_heap->element[target_child];
		}
		else break;
		i = target_child;
	}
	tree_heap->element[i] = pivot;
	return rtn_value;
}

void springAndsummer();
void autunm();
void winter();
void GetBaby(int x, int y);
void Function();

int main() {
	freopen("input.txt", "r", stdin);
	Function();


	return 0;
}

void Function() {
	scanf("%d %d %d", &N, &M, &K);
	
	//먼저 양분 값을 줍니다.초기값 and fuel
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &s2d2[i][j]);
			fuel[i][j] = 5; //init fuel
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		insert_into_tree(&tree[x][y], z);
	}
	for (int year = 0; year < K; year++) {
		springAndsummer();
		autunm();
		winter();
	}

	//다 보냈으니 보자
	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].heapSize == 0) continue;
			result += tree[i][j].heapSize;
		}
	}
	printf("%d", result);
}

//봄엔 나무가 양분을 먹지.... 양분을 못먹은 놈은 양분이 되지...
void springAndsummer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].heapSize == 0) continue; // 나무가 없으면 바이바이
			HEAP tmp_heap;
			int fuels = fuel[i][j];
			int dead_fuels = 0;

			while (tree[i][j].heapSize != 0) {
				int tree_age = push_from_tree(&tree[i][j]);
				
				//먼저 양분을 먹먹
				if (fuels >= tree_age) {
					insert_into_tree(&tmp_heap, tree_age + 1);
					fuels -= tree_age;
				}
				//다음은 여름 단계. 양분을 먹지못하는 나무들이 죽어서 양분이 된다. 양분은 나이/2만큼 증가
				else {
					dead_fuels += (tree_age / 2);
				}
			}
			tree[i][j] = tmp_heap;
			
			fuel[i][j] = (fuels + dead_fuels); //모든 양분 계산 후 양분 변화
		}
	}
}

//가을엔 나무가 번식 -> 나무의 나이가 5의 배수인 경우 근처 8칸에 뿌리를 내리지.
//번식하는 나무는 해당 tree의 헤드가 됨 -> 왜냐 젊은놈부터 양분을 먹어야 하는데 방금 태어난놈이 가장 젊잖아.
void autunm() {
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			if (tree[x][y].heapSize == 0) continue;
			int* trees = tree[x][y].element;
			for (int i = 1; i <= tree[x][y].heapSize; i++) {
				if (trees[i] % 5 == 0) {
					GetBaby(x, y);
				}
			}
		}
	}
}

//응애에요
void GetBaby(int x, int y) {
	for (int dir = 0; dir < 8; dir++) {
		int movx = x + dx[dir];
		int movy = y + dy[dir];

		if (movx >= 1 && movx <= N && movy >= 1 && movy <= N) {
			insert_into_tree(&tree[movx][movy], 1);
		}
	}
}

//겨울엔 양분을 뿌려
void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			fuel[i][j] += s2d2[i][j];
		}
	}
}