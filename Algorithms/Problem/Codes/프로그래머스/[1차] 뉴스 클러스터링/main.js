function solution(str1, str2) {
    var answer = 0;
    str1 = str1.toUpperCase();
    str2 = str2.toUpperCase();

    let str1_lists = [];
    let str2_lists = [];
    
    let str1_map = new Map();
    let str2_map = new Map();
    for(var i=0; i<str1.length-1; i++){
        var pivot = str1[i]+str1[i+1];
        if(!pivot.match(/[^A-Z]/gi)){
            var map_pivot = str1_map.get(str1[i]+str1[i+1]);
            str1_map.set(pivot,(map_pivot==undefined) ? 1 : map_pivot+1);
        }
    }
    for(var i=0; i<str2.length-1; i++){
        var pivot = str2[i]+str2[i+1];
        if(!pivot.match(/[^A-Z]/gi)){
            var map_pivot = str2_map.get(str2[i]+str2[i+1]);
            str2_map.set(pivot,(map_pivot==undefined) ? 1 : map_pivot+1);
        }
    }

    if(str1_map.size == 0 && str2_map.size==0) return 65536;
    if(str2_map.size<str1_map.size){
        var tmp = str1_map;
        str1_map = str2_map;
        str2_map = tmp;
    }
    var common_map = new Map();
    for(const ele of str1_map.keys()){
        var str2_map_ele_amount = (str2_map.get(ele)==undefined)? 0 : str2_map.get(ele);
        var str1_map_ele_amount = str1_map.get(ele);

        if(str2_map_ele_amount==0) continue;
        else if (str1_map_ele_amount == str2_map_ele_amount){
            common_map.set(ele,str1_map_ele_amount);
        }else{
            common_map.set(ele,Math.min(str1_map_ele_amount,str2_map_ele_amount));
        }
    }    
    var whole_amount = [...str1_map.values()].reduce((acc,val)=>acc+=val,0)
    + [...str2_map.values()].reduce((acc,val)=>acc+=val,0)
    - [...common_map.values()].reduce((acc,val)=>acc+=val,0);
    var common_amount = [...common_map.values()].reduce((acc,val)=>acc+=val,0)

    answer = Math.floor(65536 * (common_amount/whole_amount));
    return answer;
}

const TEST_CASE = [
    {'str1':'FRANCE','str2':'french'},
    {'str1':'handshake','str2':'shake hands'},
    {'str1':'aa1+aa2','str2':'AAAA12'},
    {'str1':'E=M*C^2','str2':'e=m*c^2'},
]
for(const tc of TEST_CASE){
    console.log(solution(tc.str1,tc.str2));
}