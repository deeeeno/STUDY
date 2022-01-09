# 프로그래머스 - 추석트래픽
[문제링크](https://programmers.co.kr/learn/courses/30/lessons/17676?language=java)

#### 언어 - C++, JAVA
#### 설계
처음 나의 설계   
처음엔 모두 ms로 바꾸고 각 꾸ㅏㄴ을 전수조사 하면서 겹치는 count를 세려고 했으나 이는 너무 오래걸리기에 다른 것들을 참고하였다.   
그리하여 얻은 것은 **힌트** 를 사용하는 것! 힌트는 문제 속 두 개가 있었다.   
1. S에 대해서 오름차순으로 데이터를 준다.
2. 1초 내 최대 트래픽 수   

이 힌트로 인해 한 개의 트래픽 구간은 이전 트래픽 구간보다 endTime이 크므로 다음 데이터에 대해서 탐색을 하면 됨을 알 수 있다.
<pre>
for(int i = 0; i < lines.size(); i++)
    {
        int end_time = end_t[i] + 1000;
        int count = 0;
        
        //다음 시간의 start time을 조사한다.
        for(int j = i; j < lines.size(); j++)
        {
            if(start_t[j] < end_time)
                count++;
        }
        
        if(answer < count)
            answer = count;
    }
</pre>
누군가의 힌트를 빌렸기 때문에 연습하고자 C++,JAVA 두 언어로 풀어봤다.   
* 성공 / 실패
    - 성공(100)
