/*
k는 나의 피로도
dungeons에는 각 던전의 최소 필요 피로도와 소모 피로도가 존재
현재 피로도 k를 사용하여 유저가 탐험할수 있는 최대 던전 수를 return 하도록 solution 함수를 완성해주세요
*/


#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// 선언 순서대로 읽히므로 solution에서 사용하기 위해서는 프로토타입 선언 필수
// 또는 아예 이 위치에서 작성할 것
int go_dungeons(int k, int count, vector<bool> finish, vector<vector<int>> dungeons); 


int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> finish(dungeons.size(), false); // 던전과 같은 사이즈의 false 벡터 생성    
    return go_dungeons(k, 0, finish, dungeons);
}


int go_dungeons(int k, int count, vector<bool> finish, vector<vector<int>> dungeons){
    int best_count = count;
    
    for(int i = 0; i < dungeons.size(); i++){ // 모든 경우의 수를 테스트하기 위한 for문
        if(finish[i] == false && k >= dungeons[i][0]){
            finish[i] = true;
            
            int result = go_dungeons(k-dungeons[i][1], count+1, finish, dungeons);
            
            best_count = max(best_count, result); // best_count값을 항상 최고 카운트로 유지
            
            finish[i] = false; // 이 시점에서 k, count, finish는 모두 처음과 같아짐 = 백트래킹
        }
    }
    
    return best_count;
}

