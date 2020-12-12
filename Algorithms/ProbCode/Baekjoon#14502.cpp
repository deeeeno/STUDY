#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;


int map[8][8] = { 0, };
int original[8][8] = { 0, };

 
int N, M;
int result = 0;
int wallAmount = 0;

typedef struct virus { int x,y; }VIRUS;
VIRUS virusList[10] = { 0, };
int virusAmount = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = {  0, 0,-1, 1 };

//벽세우기
void BuildWall(int wallAmount, int x, int y);

//Print Virus
int VirusAttack();


void Function();
void SwapMap();

int main(int argc, char** argv)
{

   freopen("input.txt", "r", stdin);
   Function();
   return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


void Function() {
   scanf("%d %d", &N, &M);
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         scanf("%d", &map[i][j]);
         if (map[i][j] == 1) wallAmount += 1;
         else if (map[i][j] == 2) {
            virusList[virusAmount].x = i;
            virusList[virusAmount++].y = j;
         }
      }
   }
   BuildWall(0, 0, 0);
   printf("%d", result);

}
void BuildWall(int wallAmount, int x, int y) {
   if (wallAmount == 3) // 다 설치했다
   {
      int tmp = VirusAttack();
      result = (tmp >= result) ? tmp : result;
      return;
   }

   for(int pivot_y = y; pivot_y < M; pivot_y++){
	   //벽이 아니면 설치를 해보는거지.
        if (map[x][pivot_y] == 0) {
			map[x][pivot_y] = 1;
			BuildWall(wallAmount + 1, x, pivot_y);
			map[x][pivot_y] = 0;
        }
   }
   for (int pivot_x = x+1; pivot_x < N; pivot_x++) {
      for (int pivot_y = 0; pivot_y < M; pivot_y++) {
         //벽이 아니면 설치를 해보는거지.
         if (map[pivot_x][pivot_y] == 0) {
            map[pivot_x][pivot_y] = 1;
            BuildWall(wallAmount + 1, pivot_x, pivot_y);
            map[pivot_x][pivot_y] = 0;
         }
      }
   }
}

//이 함수는 바이러스를 그려버린 다음에 0의 개수를 반환하는 놈.
//0의 개수는 N*M - virusAmount - 퍼진놈 - 벽개수
int VirusAttack() {
   queue<pair<int,int>> que;
   int _2count = 0;

   //먼저 바이러스 죄다 때려박기
   for (int i = 0; i < virusAmount; i++) {
	   que.push({ virusList[i].x, virusList[i].y });
   }
   bool visit[8][8] = { false, }; // 굳이 맵을 볼 피룡가 있나 visit으로만 판단
   while (!que.empty()) {
      
      int virus_x = que.front().first;
      int virus_y = que.front().second;
      que.pop();

      for (int dir = 0; dir < 4; dir++) {
            int movx = virus_x + dx[dir];
            int movy = virus_y + dy[dir]
            if (movx < 0 || movx >= N || movy < 0 || movy >= M) continue;

            if (map[movx][movy] == 0 && !visit[movx][movy]) {
                que.push({ movx, movy });
                visit[movx][movy] = true;
                _2count += 1;
            }
      }
   }

   return N * M - _2count - virusAmount - wallAmount - 3/*새로설치한놈*/;
}
