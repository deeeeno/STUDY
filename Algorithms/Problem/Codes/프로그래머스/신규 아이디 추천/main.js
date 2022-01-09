
function solution(new_id) {
    var answer = '';
    if(new_id.length <= 15){

    }
    answer = new_id.toLowerCase().replace(/[^a-z0-9\-\_\.]/gi,'').replace(/\.\.+/gi,'.').replace(/(^\.|\.$)/gi,'');

    if(answer.length==0)
        return 'aaa';
    else if(answer.length <=2){
        return answer + (answer[answer.length-1].repeat(3-answer.length));
    }else if(answer.length >= 16){
        return answer.substring(0,15).replace(/\.$/gi,'');
    }
}

var test_case = [
"...!@BaT#*..y.abcdefghijklm",
"z-+.^.",
"=.=",
"123_.def",
"abcdefghijklmn.p"]
for(const t of test_case){
    console.log('id -> ' + t);
    console.log('ch -> ' + solution(t));
}