/*
프로그래머스 팀에서는 기능 개선 작업을 수행 중입니다. 각 기능은 진도가 100%일 때 서비스에 반영할 수 있습니다.
또, 각 기능의 개발속도는 모두 다르기 때문에 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고, 이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.
먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 정수 배열 progresses와 각 작업의 개발 속도가 적힌 정수 배열 speeds가 주어질 때 각 배포마다 몇 개의 기능이 배포되는지를 return 하도록 solution 함수를 완성하세요.
*/


#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> days;
    vector<int> answer;
    
    for(int i = 0; i < progresses.size(); i++){
        int need_day = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0) need_day += 1; // speeds 이하의 남은 값이 있다면 하루로 계산
        days.push_back(need_day);
    }
    
    int stand_day = days[0];
    int count = 0;
    
    for(auto& p : days){
        if(stand_day < p){
            answer.push_back(count);
            stand_day = p;
            count = 0;
        }
        count += 1;
    }
    answer.push_back(count); // 순회가 끝나고 마지막에 남은 것들은 한거번에 배포
    
    return answer;
}


/*
[실수 point]
1. 완료까지 걸리는 날짜를 구할 때, speeds 이하의 나머지가 남으면 하루를 더해줘야 함
2. 반복문 안에서는 기준일보다 더 긴 날짜가 나왔을 때만 배포 개수를 answer에 추가. 반복문이 끝난 뒤 마지막 그룹은 별도로 한 번 더 push해줘야 함
*/