const DIGIT = {
    '*' : [3,0],
    '#' : [3,2],
    '1' : [0,0],
    '2' : [0,1],
    '3' : [0,2],
    '4' : [1,0],
    '5' : [1,1],
    '6' : [1,2],
    '7' : [2,0],
    '8' : [2,1],
    '9' : [2,2],
    '0' : [3,1]
}
function solution(numbers, hand) {
    var answer = '';
    let right_position = '#';
    let left_position = '*'
    
    function DISTANCE(from,to){
        let from_xy = DIGIT[from];
        let to_xy = DIGIT[to];

        return Math.abs(from_xy[0] - to_xy[0]) + Math.abs(from_xy[1] - to_xy[1]);
    }
    for(const number of numbers){
        if(number == 1 || number == 4 || number == 7){
            //1,4,7이면 무조건 왼손
            left_position = number;
            answer += 'L';
        }else if(number == 3 || number == 6 || number == 9){
            //3,6,9이면 무조건 오른손
            right_position = number;
            answer += 'R';
        }else{
            //2,5,8,0이면 따져야지
            if(DISTANCE(left_position,number) > DISTANCE(right_position,number)){
                right_position = number;
                answer += 'R';
            }else if(DISTANCE(left_position,number) < DISTANCE(right_position,number)){
                left_position = number;
                answer += 'L';
            }else{
                if(hand == 'right'){
                    right_position = number;
                    answer += 'R';
                }else{
                    left_position = number;
                    answer += 'L';
                }
            }
        }
    }
    return answer;
}
const TEST_CASE= [
    {'list':[1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5],'hand':'right'},
    {'list':[7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2],'hand':'left'},
    {'list':[1, 2, 3, 4, 5, 6, 7, 8, 9, 0],'hand':'right'},
]
for(const tc of TEST_CASE){
    console.log(solution(tc['list'],tc['hand']))
}