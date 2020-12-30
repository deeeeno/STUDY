#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 2500

#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

char frog[MAX_LENGTH + 2];

int frog_length;
bool visit[MAX_LENGTH + 2] = { false, };

int result = 0;
void Function(int test_case);
int FindFrog(int start_idx);

int croak_idx(char a) {
	switch(a) {
		case 'c':
			return 0;
		case 'r':
			return 1;
		case 'o':
			return 2;
		case 'a':
			return 3;
		case 'k':
			return 4;
	}
}
int strlen(char* text) {
	int i = 0;
	while (text[i]) { i++;  }
	return i;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Function(test_case);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void Function(int test_case) {
	scanf("%s", frog);
	int test;
	int croak_count[6] = { 0, };
	result = 0;
	frog_length = strlen(frog);
	for (int i = 0; i < frog_length; i++) {
		visit[i] = false;
		croak_count[croak_idx(frog[i])] += 1;
	}
	
	int tmp = croak_count[0];
	for (int i = 1; i < 5; i++) {
		if (croak_count[i] != tmp) {
			result = -1;
			printf("#%d %d\n", test_case, result);
			return;
		}
	}

	for (int i = 0; i < frog_length; i++) {
		if (frog[i] == 'c' && !visit[i]) {
			if ((test = FindFrog(i)) == -1) { //croak의 c를 찾았으니 탐색을 시작한다.
				result = -1;
				break;
			}
			result += test;
		}
	}
	if (result >= 1) {
		for (int i = 0; i < frog_length; i++) {
			if (!visit[i]) {
				result = -1; break;
			}
		}
	}
	printf("#%d %d\n", test_case, result);
}

//c를 찾았으니까 지금부터 croak가 이어지는 모든걸 찾는다.
int FindFrog(int start_idx) {
	char croak[6] = "croak";
	int croak_step = 0; // step은 c부터
	for (int pivot = start_idx; pivot < frog_length; pivot++) {
		if (frog[pivot] == croak[croak_step] && !visit[pivot]) {
			visit[pivot] = true;
			croak_step = (croak_step == 4) ? 0 : croak_step + 1;
		}
	}
	//무조건 소리는 k로 끝나야함 고로 croak_step의 마지막은 무조건! 0이어야 한다.
	//왜냐면 마지막 깔끔하게 돌면 0으로 초기화되어있음
	if (croak_step != 0) return -1;
	return 1;
}