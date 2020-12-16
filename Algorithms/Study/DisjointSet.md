# Disjoint-Set
Disjoint-Set 알고리즘은 다수의 노드들 중 연결된 노드를 찾거나 노드들을 합칠때 사용하는 알고리즘이다. 아래의 그림을 보면 (1,2,3,4) (5,6,7) 끼리 연결된 것을 확인할 수 있다.

![disjointset](/Algorithms/Study/resource/disjointset1.PNG)

각 원소에 대해서 연결된 관계를 생각해보면 아래의 표와 같다.

![qsort and pivot](/Algorithms/Study/resource/disjointset2.PNG)

이 노드들에 대해서 연결된 노드들끼리 그룹을 지어준다고 생각해보자. 가령, 그룹 넘버를 연결 관계 중 가장 작은 노드의 번호라고 한다면.... (1,2,3,4)번은 1번 그룹, (5,6,7)번은 5번 그룹이라고 생각해보자. 그럼 3번 노드는 2번노드에 연결 되어있고, 2번은 1번에 연결되어있고,... 이 모든걸 다 고려해야 하는 것이다....!!

disjoint-set 알고리즘은 union find구조의 알고리즘이다. 이는 핵심적으로 초기화, find, union연산 단계를 가지고 있다.

1. 초기화 : N개의 노드에 대해서 정보를 초기화. 보통 자기 자신과 연결되어 있다고 초기화 함.
2. find연산 : 노드에 대해 자신이 속한 그룹 번호를 return
3. union 연산 : 두 노드에 대한 집합을 합쳐버리기

먼저, find연산을 살펴보면 자신이 속한 그룹의 번호를 return하도록 되어있다. 이는 결국 연결된 가장 마지막의 노드를 탐색하는 것이다. 그럼 계속 파고파고파고... 결국 재귀가 답.

union은 사실상 두 개의 노드에 대한 그룹 번호를 추출, 그 후 그룹 번호가 다르면 기준에 맞춰 그룹을 합치는 연산을 하면 된다.

```
int group[7];

int find(int x){
        if(x == group[x]) return x; // 가장 root node
        return group[x] = find(group[x]); //재귀를 사용해서 가장 root까지 들어가
}
void union(int x, int y){
        int i = find(x);
        int j = find(y); // 두 노드에 대한 그룹 번호를 추출

        if(i != j){ // 그룹이 다르면 통합시켜 버리기
                group[j] = i;
        }
}
int main(){
        //초기화
        for(int i=0; i<7; i++){
                group[i] = i;
        }
        //위의 관계라면 (1,2,3,4)가 이어져있고, (5,6,7)이 이어져있으므로
        //1,2,3,4끼리 union, 5,6,7끼리 union을 하면 위의 그림의 관계가 된다.
        union(0,1);
        union(1,2);
        union(2,3);
        union(5,6);
        union(6,7);
        union(7,8);
}

```
