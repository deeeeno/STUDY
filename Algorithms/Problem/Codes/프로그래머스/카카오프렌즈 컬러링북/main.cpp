#include <vector>
#include <queue>
using namespace std;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int resultArea = -123;
    int resultCount = 0;
    int searchArea = 0;

    bool visit[101][101] = {false,};

    int dx[] = {-1, 1, 0, 0};
    int dy[] = { 0, 0, 1,-1};

    for(int x=0; x<m; x++){
        for(int y=0; y<n; y++){
            if(!visit[x][y] && picture[x][y]!=0){
                queue<pair<int,int>> que;
                que.push({x,y});
                searchArea = 0;
                resultCount += 1;
                int pivot = picture[x][y];
                while(!que.empty()){
                    int searchX = que.front().first;
                    int searchY = que.front().second;
                    que.pop();
                    if(visit[searchX][searchY]) continue;
                    visit[searchX][searchY] = true;
                    
                    searchArea += 1;
    
                    for(int move=0; move<4; move++){
                        if(searchX+dx[move] < 0 || searchX+dx[move] >=m){
                            
                        }else if(searchY+dy[move]<0 || searchY+dy[move] >= n){
                            
                        }else if(visit[searchX+dx[move]][searchY+dy[move]]){
                            
                        }else if(picture[searchX+dx[move]][searchY+dy[move]] != pivot){
                        }else{
                            que.push({searchX+dx[move],searchY+dy[move]});
                        }  
                    }
                }
                resultArea = (resultArea > searchArea) ? resultArea : searchArea;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = resultCount;
    answer[1] = resultArea;
    return answer;
}