#define _CRT_SECURE_NO_WARNINGS
#define MAX_F	200001
#define MAX_HASH_SIZE 20000
#define salloc() &hnodes[sidx++]

#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

typedef struct node {
	char name[20];
	int  network;
	struct node* next;
}HNODE;

HNODE hnodes[MAX_F]; // 미리 할당 해놔요
int sidx = 0;
HNODE* hashtable[MAX_HASH_SIZE];

int GetHashKey(char* str);
void PushTable(HNODE* newNode);
HNODE* GetHNode(char* str);
void HASHINIT();




int friend_amount = 0;
int  HowManyFriend[MAX_F];	 // 친구 idx에 대해서 친구 수 정보
int  network[MAX_F];	 // 친구 idx에 대해서 가장 끝에 연결된 root 친구 idx 정보
int  F;



//find- union disjoint-set

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
	HASHINIT();
	scanf("%d", &F);
	int number = 0;
	for (int i = 0; i < 2 * F; i++) {
		HowManyFriend[i] = 1;
		network[i] = i;
	}
	for (int i = 0; i < F; i++) {
		char name1[20], name2[20];
		scanf("%s %s", name1, name2);

		HNODE *name1hash, *name2hash;
		if ((name1hash = GetHNode(name1)) == NULL) {
			name1hash = salloc();
			strcpy(name1hash->name, name1);
			name1hash->network = number++;
			name1hash->next = NULL;
			PushTable(name1hash);
		}

		if ((name2hash = GetHNode(name2)) == NULL) {
			name2hash = salloc();
			strcpy(name2hash->name, name2);
			name2hash->network = number++;
			name2hash->next = NULL;
			PushTable(name2hash);
		}

		int res = GetHowManyFriends(name1hash->network, name2hash->network);
		printf("%d\n", res);

	}

}

int main() {
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int i = 0; i < T; i++) {
		Function();
	}
	return 0;
}



void HASHINIT() {
	for (int i = 0; i < MAX_HASH_SIZE; i++) hashtable[i] = NULL;
	sidx = 0;
}
int GetHashKey(char* str) {
	unsigned int key = 0, step = 1;
	int prime = 17;
	for (int i = 0; str[i]; i++) {
		key += (str[i] * step);
		step *= prime;
	}
	return key % MAX_HASH_SIZE;
}

void PushTable(HNODE* newNode) {
	//키를 가져와
	//그리고 집어넣어
	//만약 같은 키가 있는 경우 이어버려
	//아니면 그냥 넣어
	int key = GetHashKey(newNode->name);
	
	if (hashtable[key] == NULL) // 해당 키에 대한 값이 없다는 것
		hashtable[key] = newNode;
	else { //해당 키에 대한 값이 이미 있는 경우는?
		newNode->next = hashtable[key];
		hashtable[key] = newNode;
	}
}

HNODE* GetHNode(char* str) {
	//키를 가져오고
	//이름에 대해서 링크드리스트 검색
	//그 후 리턴
	int key = GetHashKey(str);
	HNODE* pivot = hashtable[key];
	while (pivot != NULL) {
		if (!strcmp(str, pivot->name))
			return pivot;
		pivot = pivot->next;
	}
	return NULL;
}