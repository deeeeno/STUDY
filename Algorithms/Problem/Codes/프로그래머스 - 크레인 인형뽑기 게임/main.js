
function solution(board, moves) {
    var answer = 0;
    let board_X = board[0].length;
    let board_Y = board.length;
    const NO = board_Y;

    let last_pang = new Array(board_X);
    last_pang.fill(NO);
    
    let dolls = [];

    for(var y=0; y<board_Y; y++){
        for(var x=0; x<board_X; x++){
            if(board[x][y] != 0){
                last_pang[y] = x;
                break;
            }
        }
    }
    for(const mv of moves){
        if(last_pang[mv-1] == NO) continue;

        dolls.push(board[last_pang[mv-1]][mv-1]);
        last_pang[mv-1] += 1;

        if(dolls[dolls.length-1] == dolls[dolls.length-2]){
            answer += 2;
            dolls.pop();
            dolls.pop();
        }
    }
    return answer;
}

const TEST_CASE = [
    {'board':[[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]],'moves':[1,5,3,5,1,2,1,4]}
]
for(const tc of TEST_CASE){
    console.log(solution(tc['board'],tc['moves']))
}
