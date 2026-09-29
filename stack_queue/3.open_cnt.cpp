/*
'(' 또는 ')' 로만 이루어진 문자열 s가 주어졌을 때, 문자열 s가 올바른 괄호이면 true를 return 하고, 올바르지 않은 괄호이면 false를 return 하는 solution 함수를 완성해 주세요.
*/


#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int open_cnt = 0;
    
    for(auto& p : s){
        if(p == '(') open_cnt++;
        else if(p == ')') open_cnt--;
        
        if(open_cnt < 0) return false;
    }

    return open_cnt == 0;
}


/*
[false를 반환하는 두 가지 경우]
1. 앞에 나온 '('보다 뒤에 나온 ')'이 더 많아서 cnt가 마이너스가 되는 경우
2. 반복문이 끝났는데 닫히지 못한 '('가 남아있어 cnt가 0보다 큰 경우
*/