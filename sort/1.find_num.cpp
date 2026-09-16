/*
배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.
- 배열 array
- [i, j, k]를 원소로 가진 2차원 배열 commands
위 두 가지를 매개변수로 받아 모든 결과를 배열에 담아 return
*/


#include <string>
#include <vector>
#include <algorithm> // sort 함수는 algorithm 헤더에 포함

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++){
        // 벡터 생성자의 매개변수는 시작 위치 끝 위치 (시작 위치는 첫 번째 원소, 끝 위치의 경우 마지막 원소 원소의 바로 뒤)
        // 따라서 array.begin()에서 (commands[i][0] - 1) ~ commands[i][1] 범위
        vector<int> cut_array(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]); 
        sort(cut_array.begin(), cut_array.end());
        answer.push_back(cut_array[commands[i][2] - 1]);
    }
    
    return answer;
}