#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include<iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 100
#define MAX_M 20

int map[MAX_N + 1][MAX_N + 1] = { 0, };
bool visit[MAX_N + 1][MAX_N + 1] = { false, };

typedef struct chemmatrix { int hang, yeol, area; } CHEMMATRIX;
CHEMMATRIX chemMatrixList[MAX_M + 1] = { 0, };
int chemMatrixAmount = 0;
int N;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool cmp(CHEMMATRIX a, CHEMMATRIX b) {
	if (a.area > b.area) return false;
	else if (a.area == b.area && a.hang > b.hang) return false;
	else return true;
}

void Function(int test_case);
void FindChemMatrix(int x, int y);
int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		Function(test_case);
		printf("#%d %d", test_case, chemMatrixAmount);
		for (int i = 0; i < chemMatrixAmount; i++) printf(" %d %d", chemMatrixList[i].hang, chemMatrixList[i].yeol);
		cout << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


void Function(int test_case) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	//INIT SECTOR
	for (int i = 0; i < N; i++) memset(visit, false, sizeof(visit[i])*N);
	chemMatrixAmount = 0;

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (!visit[x][y] && map[x][y] != 0) {
				visit[x][y] = true;
				FindChemMatrix(x, y);
			}
		}
	}
	sort(chemMatrixList, chemMatrixList + chemMatrixAmount, cmp);
}

void FindChemMatrix(int x, int y) {
	queue<pair<int, int>> que;

	que.push({ x,y });
	int max_x = x;
	int max_y = y;
	
	while (!que.empty()) {
		int pivot_x = que.front().first;
		int pivot_y = que.front().second;
		que.pop();
		for (int dir = 0; dir < 4; dir++) {
			int movx = pivot_x + dx[dir];
			int movy = pivot_y + dy[dir];

			if (movx >= 0 && movx < N && movy >= 0 && movy < N && !visit[movx][movy] && map[movx][movy] != 0) {
				visit[movx][movy] = true;
				que.push({ movx,movy });
				max_x = (max_x > movx) ? max_x : movx;
				max_y = (max_y > movy) ? max_y : movy;
			}
		}
	}
	int yeol = max_y - y + 1;
	int hang = max_x - x + 1;
	chemMatrixList[chemMatrixAmount].hang = hang;
	chemMatrixList[chemMatrixAmount].yeol = yeol;
	chemMatrixList[chemMatrixAmount++].area = hang * yeol;
}