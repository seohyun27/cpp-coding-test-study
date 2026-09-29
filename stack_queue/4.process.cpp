/*
운영체제가 다음 규칙에 따라 프로세스를 관리할 경우 특정 프로세스가 몇 번째로 실행되는지 알아내기
1. 실행 대기 큐(Queue)에서 대기중인 프로세스 하나를 꺼냅니다.
2. 큐에 대기중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면 방금 꺼낸 프로세스를 다시 큐에 넣습니다.
3. 만약 그런 프로세스가 없다면 방금 꺼낸 프로세스를 실행합니다.
  3.1 한 번 실행한 프로세스는 다시 큐에 넣지 않고 그대로 종료됩니다.
*/


#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    vector<int> answer;
    vector<vector<int>> processes;
    
    for(int i =0; i < priorities.size(); i++){
        vector<int> temp;
        temp.push_back(i);
        temp.push_back(priorities[i]);
        processes.push_back(temp);
    }
    
    while(!processes.empty()){
        // 현재 프로세스 벡터 안에 남아있는 프로세스 중 최고 우선순위 구하기
        int max_prio = 0;
        for(auto& p : processes){
            if(max_prio < p[1]) max_prio = p[1];
        }
        
        while(true){
            // 프로세스 제일 앞의 벡터
            vector<int> temp = processes.front();
            
            // 해당 벡터가 최고 우선순위라면 정답에 추가하고 삭제
            if(max_prio == temp[1]){
                // 해당 벡터가 내가 찾는 location이라면 바로 리턴
                if(temp[0] == location) return answer.size() + 1; 
                
                // 아니라면 최상위 while문 계속 진행
                processes.erase(processes.begin());
                answer.push_back(temp[0]);
                break;
            } else{ // 해당 벡터가 최고 우선 순위가 아니라면 다시 pop & push
                processes.push_back(temp);
                processes.erase(processes.begin());
            }
        }
    }
    return 0;
}


/*
[실수 point]
마지막에 리턴해야 하는 정답은 location의 프로세스가 몇 번째로 실행되었는지임! 반드시 문제의 정답이 무엇을 요구하는지 잘 읽어볼 것
*/