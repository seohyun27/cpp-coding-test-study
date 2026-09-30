/*
수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.
가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.
*/


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> p_one = {1, 2, 3, 4, 5};            // 벡터 초기화의 경우 대괄호 대신 중괄호 사용
    vector<int> p_two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> p_three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int one_score = 0;
    int two_score = 0;
    int three_score = 0;
   
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == p_one[i%5]) one_score++;   // 모듈러 연산을 통해 정답을 가져올 수 있음!!
        if(answers[i] == p_two[i%8]) two_score++;
        if(answers[i] == p_three[i%10]) three_score++;
    }
    
    int max_score = max(one_score, two_score);
    max_score = max(max_score, three_score);
    
    if(max_score == one_score) answer.push_back(1);
    if(max_score == two_score) answer.push_back(2);
    if(max_score == three_score) answer.push_back(3);
        
    return answer;
}



/*
위 코드의 경우 학생과 점수에 굳이 각각의 변수명이 필요하지 않음
셋을 하나의 벡터에 담을 수 있음
개선 버전은 아래에
*/