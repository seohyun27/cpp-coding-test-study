/*
Leo는 카펫을 사러 갔다가중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.
- Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.
- 카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.
*/


#include <string>
#include <vector>

using namespace std;

// 갈색 개수 = 2w + 2h + 4
// 노랑 개수 = w * h
// 카펫 가로 = (w + 2), 카펫 세로 = (h + 2)
// 가로는 항상 세로보다 길다. 가로 세로 순서로 배열에 담아 반환할 것
    
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // h를 1부터 순서대로 늘려가며 확인하므로, 값이 나올 시점에서 h는 항상 w보다 짧다
    // yellow가 1인 경우를 감안하여 h <= yellow로 설정
    for(int h = 1; h <= yellow; h++){
        
        // 나눗셈이 성립하지 않는다면 애초에 고려 대상도 X
        if(yellow % h != 0) continue;
        
        int w = yellow / h;
        
        if(brown == 2*w + 2*h + 4) {
            answer.push_back(w + 2);
            answer.push_back(h + 2);
            return answer;
        }        
    }
    
    return answer;
}