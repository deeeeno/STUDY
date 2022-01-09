function solution(s) {
    var answer = 0;
    answer =s.replace(/one/gi,'1').replace(/two/gi,'2').replace(/three/gi,'3').replace(/four/gi,'4')
                .replace(/five/gi,'5').replace(/six/gi,'6').replace(/seven/gi,'7').replace(/eight/gi,'8')
                .replace(/nine/gi,'9').replace(/zero/gi,'0');
    answer = parseInt(answer);
    return answer;
}

const test_case = ["one4seveneight","23four5six7","2three45sixseven","123"];
for(const tc of test_case){
    console.log(solution(tc));
}
