/*
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.
마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

- completion의 길이는 participant의 길이보다 1 작습니다.
- 참가자 중에는 동명이인이 있을 수 있습니다.
*/


#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m; // unordered_map 선언
    
    for(auto p : participant){ // 맵 participant의 모든 요소를 꺼내서 p로 순회 
        m[p]++;
    }
    
    for(auto p : completion){ // 완주자 제외
        m[p]--;
    }

    string answer = "";
    
    for (auto& p : m) { // auto&로 참조 접근
        if(p.second != 0){ // first는 key, second는 value
            answer = p.first;
            break;
        }
    }
    
    return answer;
}