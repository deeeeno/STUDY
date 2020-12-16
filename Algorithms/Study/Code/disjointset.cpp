#define _CRT_SECURE_NO_WARNINGS
#define MAX_F	200001
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int group[7];

int find(int x) {
    if (x == group[x]) return x; // 가장 root node
    return group[x] = find(group[x]); //재귀를 사용해서 가장 root까지 들어가
}
void Union(int x, int y) {
    int i = find(x);
    int j = find(y); // 두 노드에 대한 그룹 번호를 추출

    if (i != j) { // 그룹이 다르면 통합시켜 버리기
        group[j] = i;
    }
}
int main() {
    //초기화
    for (int i = 0; i < 7; i++) {
        group[i] = i;
    }
    //위의 관계라면 (0,1,2,3)가 이어져있고, (4,5,6)이 이어져있으므로
    //0,1,2,3끼리 union, 4,5,6끼리 union을 하면 위의 그림의 관계가 된다.
    Union(0, 1);
    Union(1, 2);
    Union(2, 3);
    Union(4, 5);
    Union(5, 6);
    return 0;
}