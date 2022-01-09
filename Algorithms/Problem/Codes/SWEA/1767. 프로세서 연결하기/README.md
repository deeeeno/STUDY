# SWEA#1767 - 프로세서 연결하기

### 처음 설계
프로세서가 전선을 연결할 수 있는지 없는지 체크, 가능하면 연결하고 다음 프로세서, 아니면 안하고 다음 프로세서

### 처음결과
`Memory(12544kb)`  
`Runtime(1710ms)`  

#### 성공 / 실패
- 성공
# 고찰 
전선 연결이 가능한지를 따질 때, 전선을 그리면서 판단하는게 아닌 그리기 전에 가능한지부터 판단하자! 그리고 문제 좀 잘 읽자!
runtime이 1.2초나 나오는 불상사가 생겨서 보았더니... 
    
```
    for (int dir = 0; dir < 4; dir++) {
      if (MakeLine(pivot_x, pivot_y, dir)) {
         Solution(coreIndex + 1, enableCores + 1, lineAmount + GetLength(dir,pivot_x,pivot_y));
         DelLine(pivot_x, pivot_y, dir);
      }
      else {
         Solution(coreIndex + 1, enableCores, lineAmount);
      }
```
    
동서남북 모두를 못 들어가는 경우 다음 프로세서로 recursive해야하는걸 동쪽 못가면 recur, 서쪽 못가면 recur 이렇게 했다... 으악!
    
### 수정 후 결과 
`Memory(12544kb)`  
`Runtime(10ms)`

Runtime 약 100배 개선
