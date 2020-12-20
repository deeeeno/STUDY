#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#define MAX		100

using namespace std;

typedef struct pair { int num, amount,score; }PAIR;
int map[MAX + 1][MAX + 1] = { 0, };

void qsort(int left, int right, PAIR* p);
void R();
void C();
void Function();

int row_amount = 3; // 행의 갯수 -> 총 열을 의미
int col_amount = 3; // 열의 갯수 -> 총 행을 의미

int result = -1;
int r, c, k;

int main() {
	freopen("input.txt", "r", stdin);
	Function();
}
void Function() {
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int step = 0; step <= MAX; step++) {
		if (map[r - 1][c - 1] == k) {
			result = step;
			break;
		}
		if (row_amount >= col_amount) // 행이 열보다 큰 경우 R연산
		{
			R();
		}
		else {
			C();
		}
	}
	printf("%d", result);
}
void R() {
	int next_col_amount = -1;
	for (int c = 0; c < row_amount; c++) {
		int cnt[MAX + 1] = { 0, };
		for (int x = 0; x < col_amount; x++) {
			int idx = map[c][x];
			cnt[idx] += 1;
			map[c][x] = 0;
		}
		PAIR list[MAX + 1] = { 0, };
		int list_amount = 0;
		for (int i = 1; i <= MAX; i++) {
			if (cnt[i] != 0) {
				list[list_amount].num = i;
				list[list_amount].amount = cnt[i];
				list[list_amount++].score = cnt[i] * 10000 + i;
			}
		}
		
		qsort(0, list_amount - 1, list); // 개수에 따른 정렬

		int p = 0;
		for (int i = 0; i < list_amount; i++) {
			map[c][p++] = list[i].num;
			map[c][p++] = list[i].amount;
		}
		next_col_amount = (p > next_col_amount) ? p : next_col_amount;
		if (next_col_amount > MAX) next_col_amount = MAX;
	}
	col_amount = next_col_amount;
}

void C() {
	int next_row_amount = -1;
	for (int r = 0; r < col_amount; r++) {
		int cnt[MAX + 1] = { 0, };
		for (int y = 0; y < row_amount; y++) {
			int idx = map[y][r];
			cnt[idx] += 1;
			map[y][r] = 0;
		}
		PAIR list[MAX + 1] = { 0, };
		int list_amount = 0;
		for (int i = 1; i <= MAX; i++) {
			if (cnt[i] != 0) {
				list[list_amount].num = i;
				list[list_amount].amount = cnt[i];
				list[list_amount++].score = cnt[i] * MAX + i;
			}
		}
		qsort(0, list_amount - 1, list); // 개수에 따른 정렬

		int p = 0;
		for (int i = 0; i < list_amount; i++) {
			map[p++][r] = list[i].num;
			map[p++][r] = list[i].amount;
		}
		next_row_amount = (p > next_row_amount) ? p : next_row_amount;
		if (next_row_amount > MAX) next_row_amount = MAX;
	}
	row_amount = next_row_amount;
}
void qsort(int left, int right, PAIR* p) {
	if (left < right) {
		int l = left, r = right;
		int pivot = p[left].score;

		while (l <= r) {
			while ((l <= right) && (p[l].score <= pivot)) l++;
			while ((r >= left) && (p[r].score > pivot)) r--;
			if (l < r) {
				PAIR t = p[l]; p[l] = p[r]; p[r] = t;
			}
		}
		PAIR t = p[left]; p[left] = p[r]; p[r] = t;
		qsort(left, r - 1, p);
		qsort(r + 1, right, p);
	}
}
