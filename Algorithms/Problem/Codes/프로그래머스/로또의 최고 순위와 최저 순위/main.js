function solution(lottos, win_nums) {
    var answer = [];

    const win_table = {
        6:1,
        5:2,
        4:3,
        3:4,
        2:5,
        1:6,
        0:6
    }
    let max_match = 6;
    let min_match = 0;
    let count_unknown = 0;
    //모든 것은 6개가 다 맞는다는 가정 하에 진행한다.
    for(const lotto of lottos){
        if(lotto==0){
            count_unknown += 1;
            continue;
        }
        const idx = win_nums.indexOf(lotto);
        if(idx!=-1){
            //내가 맞춴던 거야 제거
            min_match += 1;
        }else{
            max_match -= 1;
        }
    }

    return [win_table[max_match],win_table[min_match]];
}

const lottos1 = [44, 1, 0, 0, 31, 25];
const win_nums1 = [31, 10, 45, 1, 6, 19];

const lottos2 = [0, 0, 0, 0, 0, 0]
const win_nums2 = [38, 19, 20, 40, 15, 25]

const lottos3 = [45, 4, 35, 20, 3, 9]
const win_nums3 = 	[20, 9, 3, 45, 4, 35]
solution(lottos1,win_nums1)
solution(lottos2,win_nums2)
solution(lottos3,win_nums3)