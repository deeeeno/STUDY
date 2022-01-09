#include <cstdio>
#include <iostream>
using namespace std;

int map[12][12] = { 0, };
int N;

typedef struct core { int x, y; }CORE;
CORE coreList[12] = { 0, };
int coreAmount = 0;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int max_enableCores = 0;
int min_lineAmount = 12345678;

//함수
//애초에 켜져있는지?
bool already(int x, int y) {
	if (x == 0 || x == N - 1 || y == 0 || y == N - 1) return true;
	return false;
}
//backtracking - jongja skill
bool MakeLine(int x, int y, int dir);
void DelLine(int x, int y, int dir);
int GetLength(int dir, int x, int y);
//문제풀이 함수
void Function(int test_case);

//전선 설치 함수
void Solution(int coreIndex, int enableCores, int lineAmount);




int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		coreAmount = 0;
		max_enableCores = 0;
		min_lineAmount = 12345678;
		Function(test_case);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int GetLength(int dir, int x, int y) {
	switch (dir) {
	///dir == 0 북
	case 0:
		return x;
		break;
	//dir == 1 남
	case 1:
		return N - x - 1;
		break;
	//dir == 2 서
	case 2:
		return y;
		break;
	//dir == 3 동
	case 3:
		return N - y - 1;
		break;
	default:
		return -1;
	}
	
}
/* 설치 불가한 위치면 -1 반환, 설치 가능하면 전선의 길이 return*/
bool MakeLine(int x, int y, int dir) {
	int directionX = dx[dir], directionY = dy[dir];
	int chkX = x + directionX, chkY = y + directionY;

	while (chkX >= 0 && chkX < N && chkY >= 0 && chkY < N) {
		if (map[chkX][chkY] > 0) return false;
		chkX += directionX; chkY += directionY;
	}

	x += directionX; y += directionY;
	while (x >= 0 && x < N && y >= 0 && y < N) {
		map[x][y] = 2;
		x += directionX; y += directionY;
	}
	return true;
}
void DelLine(int x, int y, int dir) {
	int directionX = dx[dir], directionY = dy[dir];
	x += directionX; y += directionY;
	while (x >= 0 && x < N && y >= 0 && y < N) {
		map[x][y] = 0;
		x += directionX; y += directionY;
	}
}


void Function(int test_case) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				if (!already(i, j)) {
					coreList[coreAmount].x = i;
					coreList[coreAmount++].y = j;
				}
			}
		}
	}
	Solution(0, 0, 0);
	printf("#%d %d\n", test_case, (min_lineAmount == 12345678) ? 0 : min_lineAmount);
}

void Solution(int coreIndex, int enableCores, int lineAmount) {
	//판단할 코어가 이제 없다면
	if (coreAmount <= coreIndex) {
		//코어의 개수를 따지자
		if (enableCores == max_enableCores) {
			min_lineAmount = (lineAmount < min_lineAmount) ? lineAmount : min_lineAmount;
		}
		else if (enableCores > max_enableCores) {
			max_enableCores = enableCores;
			min_lineAmount = lineAmount;
		}
		return;
	}

	//양방향을 따져~
	bool isWent = false;
	int make = -1;
	int pivot_x = coreList[coreIndex].x;
	int pivot_y = coreList[coreIndex].y;
	
	for (int dir = 0; dir < 4; dir++) {
		if (MakeLine(pivot_x, pivot_y, dir)) {
			isWent = true;
			Solution(coreIndex + 1, enableCores + 1, lineAmount + GetLength(dir,pivot_x,pivot_y));
			DelLine(pivot_x, pivot_y, dir);
		}
	}
	//아니 이걸 다 들어가고 있었네
	if (!isWent)
		Solution(coreIndex + 1, enableCores, lineAmount);
}