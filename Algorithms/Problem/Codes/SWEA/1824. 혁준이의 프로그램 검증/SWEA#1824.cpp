#define _CRT_SECURE_NO_WARNINGS
#define EAST  0
#define WEST  1
#define SOUTH 2
#define NORTH 3
#define ALL	  4
#define MAX_R 20
#define MAX_C 20

#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef struct data {
	int x, y;
	int memory;
	int dir;
}DATA;

char assemble[MAX_R + 1][MAX_C + 1] = { 0, };

int r, c;
bool isGolbang = false;
bool canExit = false;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void letsGo();
int get_memory_by_code(char code, int mem);
int get_direction_by_code(char code, int original, int mem);
void Function(int test_case);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		canExit = false;
		Function(test_case);
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
//얘는 방향을 리턴해줌
//방향을 바꿔주는 기호눈<,>,^,v,_,|,?
//원 방향 그대로 가는 기호는 +,-,0~9,.
int get_direction_by_code(char code,int original, int mem) {
	int rtn_dir = original;
	switch (code) {
	case '<':
		rtn_dir = WEST;
		break;
	case '>':
		rtn_dir = EAST;
		break;
	case 'v':
		rtn_dir = SOUTH;
		break;
	case '^':
		rtn_dir = NORTH;
		break;
	case '_':
		if (mem == 0) rtn_dir = EAST;
		else             rtn_dir = WEST;
		break;
	case '|':
		if (mem == 0) rtn_dir = SOUTH;
		else             rtn_dir = NORTH;
		break;
	case '?':
		rtn_dir = ALL;
		break;
	default:
		rtn_dir = original;
		break;
	}
	return rtn_dir;
}

//기호에 따른 메모리 값 return해준다.
//메모리 값 바뀌게 하는 놈 : 0~9, +, -
//그 외는 나띵
int get_memory_by_code(char code, int mem) {
	int rtn_mem = mem;
	if (code >= '0' && code <= '9') {
		rtn_mem = code - '0';
	}
	else if (code == '+') {
		rtn_mem = (mem += 1);
		if (rtn_mem == 16) rtn_mem = 0;
	}
	else if (code == '-') {
		rtn_mem = (mem -= 1);
		if (rtn_mem == -1) rtn_mem = 15;
	}
	return rtn_mem;
}


void letsGo() {
	queue<DATA> que;
	bool visit[MAX_R][MAX_C][16][4] = { false, };

	que.push({ 0,0,0,EAST });

	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int dir = que.front().dir;
		int memory = que.front().memory;
		que.pop();
		char code = assemble[x][y];
		if (code == '@') {
			canExit = true;
			break;
		}
		int next_dir = get_direction_by_code(code, dir, memory);
		int next_mem = get_memory_by_code(code, memory);

		if (next_dir == ALL) {
			for (int dir = 0; dir < 4; dir++) {
				int movx = x + dx[dir], movy = y + dy[dir];
				if (movx == r) movx = 0;
				else if (movx == -1) movx = r - 1;
				if (movy == c) movy = 0;
				else if (movy == -1) movy = c - 1;
				if (visit[movx][movy][next_mem][dir] == false) {
					que.push({ movx,movy,next_mem,dir });
					visit[movx][movy][next_mem][dir] = true;
				}
			}
		}
		else {
			int movx = x + dx[next_dir], movy = y + dy[next_dir];
			if (movx == r) movx = 0;
			else if (movx == -1) movx = r - 1;
			if (movy == c) movy = 0;
			else if (movy == -1) movy = c - 1;
			if (visit[movx][movy][next_mem][next_dir] == false) {
				que.push({ movx,movy,next_mem,next_dir });
				visit[movx][movy][next_mem][next_dir] = true;
			}
		}
	}	
}

void Function(int test_case) {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		scanf("%s", assemble[i]);
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (assemble[i][j] == '@') {
				isGolbang = true;
				break;
			}
		}
	}
	if (isGolbang == false) {
		printf("#%d NO\n", test_case);
		return;
	}
	letsGo();

	printf("#%d %s\n", test_case, (canExit) ? "YES" : "NO");
}