/*
모든 명함의 가로 길이와 세로 길이를 나타내는 2차원 배열 sizes가 매개변수로 주어집니다. 모든 명함을 수납할 수 있는 가장 작은 지갑을 만들 때, 지갑의 크기를 return 하도록 solution 함수를 완성해주세요.
입출력 예 : 명함들을 적절히 회전시켜 겹쳤을 때, 3번째 명함(가로: 8, 세로: 15)이 다른 모든 명함보다 크기가 큽니다. 따라서 지갑의 크기는 3번째 명함의 크기와 같으며, 120(=8 x 15)을 return 합니다.
*/


#include <string>
#include <vector>
#include <algorithm> // min, max를 포함하는 라이브러리

using namespace std;

int solution(vector<vector<int>> sizes) { // 벡터 안에 int로 된 벡터
    int w = 0; // 더 긴쪽을 항상 가로로 두기
    int h = 0;

    for(auto& p : sizes){ // 벡터 안의 벡터가 하나씩 튀어나옴 = [60, 50]
        if(p[0] < p[1]){
            w = max(w, p[1]);
            h = max(h, p[0]);
        }else{
            w = max(w, p[0]);
            h = max(h, p[1]);
        }
    }

    return w * h;
}