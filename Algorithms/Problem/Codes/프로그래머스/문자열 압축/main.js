function solution(s) {
    var answer = Infinity;

    var pivot = '';
    var t, tmp_answer,cnt;

    for(var size=1; size<=s.length; size++){
        tmp_answer = 0;
        
        //{n,m} : n <= 문장의 길이 <= m 으로 탐색하는 정규식을 이용
        t = s.match(new RegExp('.{1,'+size+'}','g'));
        pivot = t[0]; cnt = 1;
        for(var i=1; i<t.length; i++){
            if(pivot == t[i]){
                cnt += 1;
            }else{
                //현재 탐색중인 문자열과 다른 경우 길이값에 포함시켜버린다.
                //정수인 cnt는 ''+cnt로 문자열 치환 후 길이를 얻어낸다.
                tmp_answer += pivot.length;
                tmp_answer += (cnt==1) ? 0 : (''+cnt).length;
                pivot = t[i];
                cnt = 1;
            }
        }
        //마지막 탐색 기준이었던 pivot은 루프에서 계산되지 않기 때문에 밖에서 한번 더 해준다.
        tmp_answer += pivot.length;
        tmp_answer += (cnt==1) ? 0 : (''+cnt).length;

        //이번 연산 결과와 비교하기.
        answer = (answer > tmp_answer) ? tmp_answer : answer;
    }
    return answer;
}

var test_case = ["aabbaccc","ababcdcdababcdcd","abcabcdede","abcabcabcabcdededededede","xababcdcdababcdcd"];
//var test_case = ["abcabcdede"];
for(t of test_case){
    console.log('TEST CASE : ' + t);
    console.log('COUNT : ' + solution(t));
}
