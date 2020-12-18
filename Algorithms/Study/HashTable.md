# Hash Table
컴퓨터 CPU가 사용한다는 Hash Table 기법. 데이터 검색 기법 중 가장 빠르다고 해도 과언이 아닌 듯 싶다. Hash Table은 아래의 그림으로 한번에 설명이 가능하다.

![hash table](/Algorithms/Study/resource/hashtable1.png)

Hash Function을 통해서 데이터의 index를 구한 후에 저장을 하는 방식을 쓰는 것이다! 너무 simple하면서 강력!! 

`하지만` Hash Table이 무한한 크기를 가지는 것은 절대 아니다. 즉, 어느샌가 Hash Function을 통해 같은 index가 나올 수 있다는 것!! 이런 경우를 `Collision`이라고 한다.

이 경우를 해결하기 위한 방법이 있으니, 이는 `Linked List`를 사용하는 것이다. 같은 index라면 데이터를 link 시켜놓는 것이다. 물론 찾을때 약간의 시간이 더 소요되겠지만, hash table의 size를 늘리면 메모리를 많이 사용하기 때문에 절충안이라고 생각하자.
![hash table](/Algorithms/Study/resource/hashtable2.png)

알고리즘의 개념이 어렵지 않은 만큼, 코딩도 어렵지 않다. 우리가 필요한 것은 hash function과 linked list의 개념 뿐이다!

코딩을 하면서 쟁점으로 두어야할 것은 서로 다른 데이터에 대한 같은 index가 나오는 Collision을 방지하는 것이다. 사칙연산 중 가장 데이터가 다르게 나올 수 있는 연산은 `소수(Prime Number)`를 곱하는 연산이다. 왜냐면 인수가 1과 자기 자신 뿐이니까! 설계한 Hash Function을 보면 아래와 같다.
```
typedef struct node {
	char name[20];
	int  network;
	struct node* next;
}HNODE;
HNODE* hashtable[MAX_HASH_SIZE];

int HashFunction(char* str) {
	unsigned int key = 0, step = 1;
	int prime = 17;
	for (int i = 0; str[i]; i++) {
		key += (str[i] * step);
		step *= prime;
	}
	return key % MAX_HASH_SIZE;
}
```
너무 간단하다!! 그저 문자열(데이터)의 성분마다 소수의 제곱수를 곱해주고 더한다음에 hash size로 모듈러스 연산! 여기서 중요한건 key가 overflow날 수 있기 때문에 unsigned로 수치의 범위를 확장시키는 것이다.

```
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
```
데이터 주입도 매우 간단하다. key를 구하고 해당 key에 대해 데이터가 없으면 넣고 있으면 이어주고... 마지막으로 데이터를 꺼내는 함수를 확인해보자.
```
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
```
그냥 찾고 링크드리스트 돌려주고 떙!