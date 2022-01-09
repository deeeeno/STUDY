# SWEA - 혁준이의 프로그램 검증

### 처음 설계
처음 이 문제를 보고 아무런 감이 오지 않았다. 어떻게 하면 무한루프가 돌고 있다는 것을 확인하는지 아무 생각이 없었기 때문이다..! 그로인해 구글링으로 설계를 시작했다..!!(?) 그 결과.. 너무 간단하게도 (x,y)위치에 대해서 같은 값, 같은 방향에 대해 접근을 했었는지 확인하며 BFS탐색을 하는 것이었다..!
```
bool visit[R][C][16][4];
```
정말 간단하면서도 생각하지 못한 답을 얻어 설계를 시작하였다. 이것만 해결되니 BFS설계는 queue로 하여금 간단하게 진행되었다.


### 처음결과
`Memory(12688kb)`  
`Runtime(15ms)`  

#### 성공 / 실패
- 성공

# 코드 설명
 코드는 크게 4개의 함수로 이루어져 있다.
 1. Function 함수 - test_case에 대한 실행 함수
 2. letsGo함수 - BFS 실행 함수
 3. `get_memory_by_code` 함수 - 위치 xy에 대한 코드에 의해 변환된 memory값을 return
 4. `get_direction_by_code` 함수 - 위치 xy에 대한 코드에 의해 변환된 진행 방향값을 return

함수 내 코드는 어렵지 않다. 다만 특이한 점은 `?`기호의 경우 4가지 방향 모두를 진입할 수 있기 때문에 이 경우는 동,서,남,북 네개에 대한 검증을 실시한다는 것이다! 여기서 내가 아무 생각없이 define값을 자꾸 넣어서 런타임 오류남!! 주의!!
```
if (next_dir == ALL) {
    for (int dir = 0; dir < 4; dir++) {
        int movx = x + dx[dir], movy = y + dy[dir];
        if (movx == r) movx = 0;
        else if (movx == -1) movx = r - 1;
        if (movy == c) movy = 0;
        else if (movy == -1) movy = c - 1;
        if (visit[movx][movy][next_mem][dir] == false) {
            que.push({ movx,movy,next_mem,dir });
            visit[movx][movy][next_mem][dir] = true;
        }
    }
}
else {
    int movx = x + dx[next_dir], movy = y + dy[next_dir];
    if (movx == r) movx = 0;
    else if (movx == -1) movx = r - 1;
    if (movy == c) movy = 0;
    else if (movy == -1) movy = c - 1;
    if (visit[movx][movy][next_mem][next_dir] == false) {
        que.push({ movx,movy,next_mem,next_dir });
        visit[movx][movy][next_mem][next_dir] = true;
    }
}
```

