# 백준#17140 - 이차원 배열과 연산

### 처음 설계
R연산 C연산을 조건에 맞춰서 진행하도록 함.  숫자와 해당 숫자의 갯수를 가지는 구조체를 만들어서 quick sort로 빠르게 정렬 -> 새로이 배열을 만듬. 배열을 만들때 주의해야할 것은 R연산을 하면 column크기가 커지고, C연산을 하면 row의 크기가 커진다는 것!


### 처음결과
`Memory(2056kb)`  
`Runtime(0ms)`  

#### 성공 / 실패
- 성공
# 고찰 
코드 제출할 땐 freopen을 주석처리 하자. 왜틀렸는지 찾다보니 그것 때문이었음.
설계할 때 조금 더 자세하게 하기! 아직 주저하는게 조금 있음.