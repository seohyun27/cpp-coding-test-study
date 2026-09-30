/*
- maps는 n x m 크기의 게임 맵의 상태가 들어있는 2차원 배열로, n과 m은 각각 1 이상 100 이하의 자연수입니다.
- maps는 0과 1로만 이루어져 있으며, 0은 벽이 있는 자리, 1은 벽이 없는 자리를 나타냅니다.
- 게임 맵의 상태 maps가 매개변수로 주어질 때, 캐릭터가 상대 팀 진영에 도착하기 위해서 지나가야 하는 칸의 개수의 최솟값을 return 하도록 solution 함수를 완성해주세요. 단, 상대 팀 진영에 도착할 수 없을 때는 -1을 return 해주세요.
*/


#include<vector>
#include<queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int n = maps.size();    // maps 내부 벡터 개수 
    int m = maps[0].size(); // maps 내부 벡터 안의 원소 개수

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    q.push({0, 0});
    dist[0][0] = 1; 

    vector<int> mx = {0, 0, 1, -1};
    vector<int> my = {1, -1, 0, 0};

    while(q.empty() != true){
       pair<int, int> stand = q.front();
       q.pop();
    
       int x = stand.first;
        int y = stand.second;

       // 상하좌우 4번 반복
        for(int i = 0; i < 4; i++){
          int nx = x + mx[i];
          int ny = y + my[i];

            if(nx < 0 || ny < 0 || nx > n-1 || ny > m-1) continue;
            if(maps[nx][ny] == 0) continue;
            if(dist[nx][ny] != -1) continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
    
    return dist[n-1][m-1];
}