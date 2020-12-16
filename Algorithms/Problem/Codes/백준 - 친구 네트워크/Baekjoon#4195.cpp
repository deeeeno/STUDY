#define _CRT_SECURE_NO_WARNINGS
#define MAX_F	200001
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <string>
using namespace std;


int friend_amount = 0;
int  HowManyFriend[MAX_F];	 // 친구 idx에 대해서 친구 수 정보
int  network[MAX_F];	 // 친구 idx에 대해서 가장 끝에 연결된 root 친구 idx 정보
int  F;

int FindFriendNetwork(int idx) {
	if (idx == network[idx]) return idx;
	return network[idx] = FindFriendNetwork(network[idx]);
}
int GetHowManyFriends(int x, int y) {
	int i = FindFriendNetwork(x);
	int j = FindFriendNetwork(y);

	if (i > j) { int t = j; j = i; i = t; }
	if (i != j) {
		network[j] = i;  // 나는 인덱스가 작은놈으로 모이게 할꺼야
		HowManyFriend[i] += HowManyFriend[j];
        HowManyFriend[j] = 1;
	}
	return HowManyFriend[i];
}



void Function() {
	map<string, int> friendMap;
	friend_amount = 0;
	scanf("%d", &F);
	for (int i = 0; i < 2*F; i++) {
		HowManyFriend[i] = 1;
		network[i] = i;
	}
	for (int i = 0; i < F; i++) {
		char name1[20], name2[20];
		scanf("%s %s", name1, name2);

		if (friendMap.count(name1) == 0) friendMap[name1] = friend_amount++;
		if (friendMap.count(name2) == 0) friendMap[name2] = friend_amount++;

		int res = GetHowManyFriends(friendMap[name1], friendMap[name2]);
		printf("%d\n", res);

	}

}

int main() {
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (int i = 0; i < T; i++) {
		Function();
	}
	return 0;
}