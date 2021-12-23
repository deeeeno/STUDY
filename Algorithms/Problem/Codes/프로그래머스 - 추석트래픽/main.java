class Solution {
    public int solution(String[] lines) {
        int answer = -1;
        int total_count = lines.length;
        int[] start_queue = new int[total_count+5];
        int start_queue_length =0;
        int[] end_queue = new int[total_count+5];
        int end_queue_length = 0;
        for(String ST : lines){
            String S = ST.split(" ")[1];
            String T = ST.split(" ")[2];
            
            String[] tmpS = S.split(":");
            
            
            int end_h = Integer.parseInt(tmpS[0]) * 1000 * 60 * 60;
            int end_m = Integer.parseInt(tmpS[1]) * 1000 * 60;
            int end_s = Integer.parseInt(tmpS[2].split("\\.")[0]) * 1000 +
                            Integer.parseInt(tmpS[2].split("\\.")[1]);

            int s_T = (int)(Float.parseFloat(T.replace("s",""))*1000);

            int end_second = end_h + end_m + end_s;
            int start_second = end_second - s_T + 1;

            start_queue[start_queue_length++] = start_second;
            end_queue[end_queue_length++] = end_second;
        }

        for(int i=0; i<total_count; i++){
            int count = 0;
            int pivot = end_queue[i] + 1000;
            
            for(int j=i; j<total_count; j++){
                if(start_queue[j] < pivot) count += 1;
            }
            
            answer = (answer > count) ? answer : count;
        }
        return answer;
    }
}