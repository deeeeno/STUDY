# 프로그래머스 - 표 편집
[문제링크](https://programmers.co.kr/learn/courses/30/lessons/81303?language=python3)

#### 언어 - PYTHON
#### 설계
각 노드는 4개의 값을 가진다.
<pre>
number : 현 노드의 real index
next : 다음 노드의 index
prev : 이전 노드의 index
die : 삭제된 노드인지(True,False)
</pre>
그리고 next와 prev는 아래의 특정 규칙을 가진다.
<pre>
첫 번째 노드의 prev값 : 해당 노드의 number값
마지막 노드의 next값 : 해당 노드의 number값
</pre>

각 액션의 동작은 아래와 같이 진행한다.
* U,D 액션
<pre>
U,D의 경우 다음 나오는 정수 만큼 위 혹은 아래 인덱스로 이동하는 것이다. 그냥 +,-로 하면 이상적이지만, 삭제되는 노드를 피해서 움직이기 위해 아래의 for loop를 사용한다.
<code>
for num in range(0,number):
    K = employees[K][prev or next]
</code>
K값은 해당 노드의 prev(U), next(D)값으로 이동하게 된다.
</pre>
* C,Z 액션
<pre>
C의 경우 현위치의 노드를 삭제하는 것이다. queue자료구조를 하나 가지게 되는데(delque) 해당 큐에 현위치인 K값을 push, 타겟 노드의 die를 True로 설정한다. 그리고 3개의 분기로 나뉘어 동작 후 K값을 설정한다.
<code>
1. 삭제 대상 노드가 맨 앞의 노드의 경우
다음 노드의 Prev값을 number로 초기화해주고, K값은 다음 노드
2. 맨 뒤의 노드의 경우
next값을 number로 초기화해주고, K값은 이전 노드
3. 그 외
해당 노드의 이전 노드와 다음 노드를 이어주고, K값은 다음 노드
</code>
Z는 복구 작업이다. delque에서 pop후에 위와 역방향으로 진행한다. 단, 여기서 중요한건 K값의 변화는 없다!
</pre>

* 성공 / 실패
    - 성공(100 - 정확성:30/효율성:70)
