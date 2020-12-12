#define _CRT_SECURE_NO_WARNINGS
#define MAX_N	200


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int N;

int MaxShareWay(int* way);
void Function(int test_case);

int main(int argc, char** argv)
{
	int test_case;
   freopen("input.txt", "r", stdin);
   cin >> test_case;
   for(int t=1; t<=test_case; t++){
	   Function(t);
   }
   return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


void Function(int test_case) {
	int start,end;
	scanf("%d",&N);
	int way[MAX_N+3] = {0,};
	for(int i=0; i<N; i++){
		scanf("%d %d",&start,&end);
		int way_start = (start%2 == 0) ? start/2 : (start+1)/2;
		int way_end = (end%2 == 0) ? end/2 : (end+1)/2;

		//not scala! it's vector!
		if(way_start > way_end){
			int tmp = way_end;
			way_end = way_start;
			way_start = tmp;
		}
		
		for(int i=way_start; i<=way_end; i++) way[i] += 1;
	}
	int result = MaxShareWay(way);
	printf("#%d %d\n",test_case,result);
}

int MaxShareWay(int* way){
	int returnValue = 0;
	for(int i=1; i<=MAX_N; i++){
		returnValue = (way[i] >= returnValue) ? way[i] : returnValue;
	}
	return returnValue;
}
