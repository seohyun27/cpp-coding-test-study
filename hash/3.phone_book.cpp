/*
전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

구조대 : 119
박준영 : 97 674 223
지영석 : 11 9552 4421
전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.
*/


#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {  // 핸드폰 번호는 문자열!!
    unordered_set <string> s;
    
    for(auto p : phone_book){               // set에다가 넣어서 정리
        s.insert(p);
    }
    
    for(auto p : s){                        // set에서 어떤 문자열 하나 꺼내기
        for(int i = 1; i < p.length(); i++){
            string sub = p.substr(0,i);     // 그 문자열의 부분 문자열 생성
            if(s.find(sub) != s.end()){     // set 안에 부분 문자열과 일치하는 문자열이 있다면
                return false; // false 반환
            }
        }
    }
    
    return true;
}


/*
[set 사용 이유]
- unordered_set은 해시 함수를 이용해 저장 위치를 계산
- 평균 O(1)에 검색이 가능함 (해시 충돌이 발생할 경우 O(N)이 될 수도 있음)
- 때문에 s.find(sub) 호출 자체는 순회 없이 바로 확인 가능
- 즉, 해당 프로그램의 시간 효율성 = 바깥 for문(N) × 안쪽 for문(전화번호 길이, 최대 20) = O(20N) ≈ O(N)
*/