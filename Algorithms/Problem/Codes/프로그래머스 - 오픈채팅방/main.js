function solution(record) {
    var answer = [];
    const memberMap = new Map();
    var log_list = [];
    for(const rec of record){
        var [action,id,nickName] = rec.split(' ');
        if(action == 'Leave'){
            log_list.push([id,'님이 나갔습니다.']);
            continue;
        }
        if(action == 'Enter'){
            log_list.push([id,'님이 들어왔습니다.']);
        }
       
        memberMap.set(id,nickName);
    }
    answer = log_list.map(ele=>memberMap.get(ele[0])+ele[1]);
    return answer;
}


var records = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"];
console.log(solution(records));