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

int main() {
	int T;
	HASHINIT();
	char test1[] = "KIM";
	char test2[] = "CHO";

	HNODE* name1hash, * name2hash;
	name1hash = salloc();
	strcpy(name1hash->name, test1);
	name1hash->next = NULL;
	PushTable(name1hash);

	name2hash = salloc();
	strcpy(name2hash->name, test1);
	name2hash->next = NULL;
	PushTable(name2hash);
	
	HNODE* data1 = GetHNode(test1);
	HNODE* data2 = GetHNode(test2);
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