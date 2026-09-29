/*
어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.
*/


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int a, int b);

int solution(vector<int> citations) {
    int n = citations.size();
    
    sort(citations.begin(), citations.end());
    
    for(int i = n; i > 0; i--){
        if(citations[n-i] >= i) return i;
    }
        
    return 0;
}


/*
[1, 3, 5, 6]
h가 될 수 있는 가장 큰 값은 논문의 개수인 4
최대값을 찾아야하므로 뒤에서부터 비교할 것
4번 이상 인용된 논문이 4편 이상 X → 1은 4보다 작으므로 불가
3번 이상 인용된 논문이 3편 이상 O → 3는 3보다 같거나 크므로 가능
2번 이상 인용된 논문이 2편 이상 O
...
따라서 h의 최대값은 3
(이때 나머지 논문이 h번 이하 인용되었다는 것은 당연한 말이므로 확인하지 않아도 괜찮음)
(처음 h가 성립하는 3에서 loop를 멈추면 됨)
*/