#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

#define A 0
#define B 1
#define MAX_W 25
#define MAX_D 17
#define WRONG 9858
using namespace std;

int map[MAX_D][MAX_W];
int W, D, K;
int result = WRONG;

bool TEST();
void simulation(int next, int amount, int M[MAX_D][MAX_W]);


int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = WRONG;
		scanf("%d %d %d", &D, &W, &K);
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		simulation(0, 0, map);
		printf("#%d %d\n", test_case, result);

	}
	return 0;
}

bool TEST() {
	int pivot, amount;
	for (int y = 0; y < W; y++) {
		pivot = map[0][y];
		amount = 1;
		for (int x = 1; x < D; x++) {
			if (map[x][y] == pivot) {
				amount += 1;
				if (amount >= K) break;
			}
			else {
				amount = 1;
				pivot = map[x][y];
			}
		}
		if (amount < K) return false;
	}
	return true;
}

void swap_arr(int* a, int* b) {
	for (int i = 0; i < W; i++) {
		a[i] = b[i];
	}
}
void simulation(int next, int amount, int M[MAX_D][MAX_W]) {
	/*
	종료 조건
		1. TEST를 통과한다.
		2. TEST를 통과하지 못한 경우엔 이미 있는 result가 amount보다 작은 경우
	*/
	if (K < amount || result <= amount) return;

	if (TEST() == true) {
		result = (result < amount) ? result : amount;
		return;
	}

	//뭣도 아닌 경우니까 절차를 진행한다.
	//절차는 next열에 대해서부터 막을 넣어서 진행
	//안 넣는 경우도 생각.
	//진행할 때에는 A를 넣고 B
	int tmp[MAX_W];
	for (int d = next; d < D; d++) {
		//안 넣는 경우
		// 
		//A를 넣어		
		for (int i = 0; i < W; i++) {
			tmp[i] = M[d][i];
		}
		for (int i = 0; i < W; i++)
		{
			M[d][i] = A;
		}
		simulation(d + 1, amount + 1, M);
		for (int i = 0; i < W; i++) {
			M[d][i] = tmp[i];
		}

		//B
		for (int i = 0; i < W; i++) {
			tmp[i] = M[d][i];
		}
		for (int i = 0; i < W; i++) {
			M[d][i] = B;
		}
		simulation(d + 1, amount + 1, M);
		for (int i = 0; i < W; i++) {
			M[d][i] = tmp[i];
		}
	}
}