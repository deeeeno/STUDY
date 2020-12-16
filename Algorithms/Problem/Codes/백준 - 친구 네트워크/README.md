# 백준#4195 - 친구 네트워크

### 처음 설계
메인 알고리즘은 MST를 구성하는 알고리즘인 disjoint-set 알고리즘으로 구성함. 친구 이름에 대한 인덱스를 보다 쉽게 구성하기 위해서
문자열 배열을 두고, 해당 인덱스에 대한 root 친구 정보, 친구 수 정보를 저장하는 배열을 두었음.


### 처음결과
`Memory(19164kb)`  
`Runtime(272ms)`  

#### 성공 / 실패
- 성공(but need to fix!!!)
# 고찰 
맨 처음 기존 친구인지 아닌지를 판단하기 위해서 O(N)의 전수조사를 실시했었으나 시간이 초과되었음.
```
int FindFriendIDX(char* name) {
	for (int i = 0; i < friend_amount; i++) {
		if (!strcmp(friends[i], name)) return i;
	}
	strcpy(friends[friend_amount], name); // 친구 이름 저장
	return friend_amount++;
}
```
후에 heap으로 설계하여 시간을 줄이고자 하였으나 이 또한 시간초과가 발생.
```
int FindAndInsert(char* name) {
	int pivot = 1;
	if (btree_size > 0) {
		while (pivot <= btree_size) {
			int tmp = strcmp(name, btree[pivot]);
			switch (tmp) {
			case 0: return pivot; break;//찾았다.
			case 1: pivot = 2 * pivot + 1; break;//name이 현재 pivot에 대한 값보다 크다
			case -1: pivot = 2 * pivot; break;	//name이 현재 pivot에 대한 값보다 작다
			default: break;
			}
		}
	}
	btree_size = pivot;
	strcpy(btree[pivot], name);
	return pivot;
}
```
결국 STL의 map을 사용해서(map은 이진트리를 베이스로 진행함) 친구 정보를 저장하도록 함.
```
map<string, int> friendMap;
```
또한 disjoint set 알고리즘에서 union을 하는 단계에 친구 관계가 합쳐지면 합쳐지는 대상의 정보를 초기화해야하는데 이를 하지 않아서 수정했어야함.
```
network[j] = i;  // 나는 인덱스가 작은놈으로 모이게 할꺼야
HowManyFriend[i] += HowManyFriend[j];
HowManyFriend[j] = 1; //이놈
```