function solution(id_list, report, k) {
    var answer = [];
    var call_count = {};        //몇번 신고 당했나요?
    var call_reporter = {};     //누가 신고 했나요?
    var mail = {};
    for(let id of id_list){
        call_count[id] = 0;
        call_reporter[id] = [];
        mail[id] = 0;
    }
    
    let report_set = new Set(report);
    for(let ret of [...report_set]){
        let [caller,callee] = ret.split(' ')
        call_count[callee] += 1;
        call_reporter[callee].push(caller);
    }

    for(const id of id_list){
        if(call_count[id]>=k){
            for(const target of call_reporter[id]){
                mail[target]+=1;
            }
        }
    }
    answer = id_list.map((ele)=>mail[ele]);
    return answer;
}

const id_list = ["muzi", "frodo", "apeach", "neo"];
const report = ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"];
const k = 2
solution(id_list,report,k)