class Solution {
    private int score=0;
    private String[] nameList = {"A","C","F","J","M","N","R","T"};
    public boolean DataCheck(String line, String[] datas){
        for(String data : datas){
            int from = line.indexOf(data.charAt(0));
            int to = line.indexOf(data.charAt(2));
            char operator = data.charAt(3);
            int amount = (data.charAt(4) - '0');
            
            int res = Math.abs(from-to);
            
            if(operator == '='){
                if(res != amount+1)
                        return false;
            }else if(operator == '<'){
                 if(!(res < amount+1))
                        return false;
            }else if(operator == '>'){
                if(!(res > amount+1))
                        return false;
            }
        }
        return true;
    }
    public void LineUp(String line, boolean[] visited,String[] data){
        if(line.length() == 8){
            boolean ret = DataCheck(line,data);
            if(ret) score+=1;
            return;
        }
        
        for(int i=0; i<8; i++){
            if(!visited[i]){
                visited[i] = true;
                LineUp(line+nameList[i],visited,data);
                visited[i] = false;
            }
        }
        
    }
    public int solution(int n, String[] data) {
        int answer = 0;
        boolean[] visit =  new boolean[8];
        LineUp("",visit,data);
        return score;
    }
     
}