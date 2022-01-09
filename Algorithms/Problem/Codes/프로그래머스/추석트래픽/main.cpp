#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
   int answer = 0;
    vector<int> start_t, end_t;
    
    for(int i = 0; i < lines.size(); i++)
    {
        int h, m, s, process;
        
        lines[i].pop_back();
        h = stoi(lines[i].substr(11, 2)) * 1000 * 60 * 60;
        m = stoi(lines[i].substr(14, 2)) * 1000 * 60;
        s = stoi(lines[i].substr(17, 2)) * 1000 + stoi(lines[i].substr(20, 3));
        process = stof(lines[i].substr(24, 5)) * 1000;
        
        int end_time = h + m + s;
        int start_time = end_time - process + 1;
        
        start_t.push_back(start_time);
        end_t.push_back(end_time);
    }
    
    for(int i = 0; i < lines.size(); i++)
    {
        int end_time = end_t[i] + 1000;
        int count = 0;
        
        for(int j = i; j < lines.size(); j++)
        {
            if(start_t[j] < end_time)
                count++;
        }
        
        if(answer < count)
            answer = count;
    }
    return answer;
}