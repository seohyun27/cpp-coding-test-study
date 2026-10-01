# C++을 활용한 코딩 테스트 연습
연습을 위해 작성한 코드를 카테고리별로 정리한 레파지토리 (개념 정리 포함)

<br>

## 헤더

### 1. 만능 헤더
`vector`, `string`, `unordered_map`, `unordered_set`, `algorithm`, `queue`, `stack` 등 표준 라이브러리 거의 전부 포함
```cpp
#include <bits/stdc++.h>
using namespace std;
```

### 2. 구체적인 헤더
| 자료구조/기능 | 헤더 |
|---|---|
| `vector` | `<vector>` |
| `string` | `<string>` |
| `unordered_map`, `unordered_set` | `<unordered_map>`, `<unordered_set>` |
| `map`, `set` | `<map>`, `<set>` |
| `sort`, `max`, `min` 등 | `<algorithm>` |
| `queue`, `stack` | `<queue>`, `<stack>` |
| 입출력(`cin`, `cout`) | `<iostream>` |

<br>

## 자료구조별 순회

| 순회 대상 | 나오는 타입 | 접근 방법 |
|---|---|---|
| `vector<T>` | `T` (원소 하나) | 원소 값 그대로 사용 |
| `vector<vector<T>>` | `vector<T>` (안쪽 벡터) | `[0]`, `[1]`... (인덱스) |
| `unordered_map<K,V>` | `pair<K,V>` | `.first`, `.second` |

#### vector<T>
```cpp
for (const auto& p : v) {
    // p가 곧 원소
}
```

#### vector<vector<T>>
```cpp
for (const auto& p : v) {
    // p는 벡터 안의 벡터를 반환. 해당 벡터 내의 요소들에 접근할 때는 인덱스를 사용
    // p[0], p[1], ...
}
```

#### unordered_map<K,V>
```cpp
for (auto& p : m) { // map m에 auto&로 참조 접근
    // p.first는 해당 요소의 key값
    // p.second는 해당 요소의 value값
}
```

벡터는 인덱스로 접근, map에서 뱉어내는 pair는 `.first`, `.second`로 접근 가능!

<br>

## 자료구조별 요소

### 1. 요소 추가하기 (insert vs push_back)
| 자료구조 | 추가 함수 | 이유 |
|---|---|---|
| `vector` | `push_back` | 맨 뒤에 추가. 벡터에서 insert를 사용하려면 위치를 지정해줘야 함 |
| `unordered_set` | `insert`만 | 순서 개념 없음, 그냥 넣기만 함 |
| `unordered_map` | `m[key] = value` 또는 `insert` | 키로 접근하는 구조 |

#### 코드 예제
```cpp
vec.push_back(x);    // vector: 맨 뒤에 추가
s.insert(x);         // set: 중복 없이 추가
m[key]++;            // map : key가 없다면 자동으로 0부터 시작 
```

<br>

### 2. 기존 요소 찾기 - set

`s.find(key)`를 통해 key의 존재 여부를 찾음. key가 존재한다면 이터레이터 반환. 존재하지 않는다면 `s.end()`를 반환함.

```cpp
if(s.find("dog") != s.end()){
    // s라는 set 안에 dog라는 문자열이 존재한다면
}
```

<br>


## vector
일반 배열 및 스택으로 사용 가능

#### 벡터 nums 선언
```cpp
vector<int> nums = {1, 2, 3};
```

#### 요소 개수 반환
```cpp
nums.size();
```

#### nums가 비었다면 ture를 반환
```cpp
nums.empty();
```

#### 마지막 요소 확인
- 요소를 꺼내는 것이 아니라 요소의 값을 확인하는 용도
```cpp
nums.back();
```

####  가장 뒤의 요소 넣기
```cpp
nums.push_back(x);
```

####  가장 뒤의 요소 지우기
- 반환값 없음
- 필요하다면 `nums.back();`을 먼저 사용할 것
```cpp
nums.pop_back();
```

####  가장 앞의 요소 지우기
- 인덱스를 밀어야 하므로 속도가 느림
- 요소 개수가 많다면 queue로 분리할 것
```cpp
nums.erase(nums.begin());
```

#### begin() 및 end()
- `begin()`은 첫 원소의 위치
- `end()`는 마지막 원소 '다음'의 위치 (즉 해당 자리에는 실제 값이 없음)
- 따라서 배열의 생성에서 시작은 항상 포함되며 끝은 미포함된다
```cpp
vector<int> v = {1,2,3,4};
v.begin()   // 1의 위치
v.end()     // 4 바로 다음의 위치
```

#### 특정 값으로 채운 벡터 만들기
- vector<int> vec(n, value);에서 value는 넣고자하는 값, n은 해당 벡터에 value를 몇 개나 채울 것인지
- value 자리에 벡터를 채워 중첩 가능

```cpp
vector<int> vec(10, 0); // 0으로 10개를 채운 벡터
vector<vector<int>> vec(10, vector<int>(10, 0)); // [0, 0, .., 0]으로 10개를 채운 벡터
```


#### 구간으로 벡터 만들기
- 시작은 포함. 끝은 미포함
```cpp
vector<int> new_array(v.begin() + 1, v.begin() + 3); 
// {1,2,3,4}에서 {2, 3}을 가진 새 벡터 생성
```


<br>


## queue
- 가장 앞에서의 삭제가 빈번하다면 실행 시간을 위해 큐를 사용할 것
- `queue<int> q`로 선언
- 인덱스 접근, for문 순회 불가
- `size()`, `empty()` 등의 함수 사용 가능

#### 요소 넣기
- 선입선출이므로 요소는 뒤로 들어감
```cpp
q.push(x);
```

#### 요소 지우기
- 앞으로 삭제
- 반환값 없음
```cpp
q.pop();
```

#### 가장 앞 요소 확인
- 삽입 삭제와 별개 (배열 자체에는 변화 없음)
- 가장 앞의 값을 리턴함
```cpp
q.front();
```

#### 가장 뒤 요소 확인
```cpp
q.back();
```


<br>


## 우선순위 queue
- `#include <queue>`에 포함
- 가장 큰 값 혹은 가장 작은 값이 매번 달라진다면 우선순위 큐를 사용
- 일반 큐와 다르게 `front()`, `back()` 사용 불가
- 삭제 및 조회는 `top()`에서만 일어남
- 이외 일반 큐와 동일

### 선언
#### 일반 우선순위 큐
```cpp
priority_queue<int> q; // 현재 요소들 기준 가장 큰 값이 top
```

#### 최소 우선순위 큐
```cpp
priority_queue<int, vector<int>, greater<int>> mq; // 가장 작은 값이 top
```
- 첫 번째 int는 큐의 타입, 두 번째 벡터는 관습적 작성, 세 번째 greater<>는 오름차순
- 오름차순이므로 작은 값부터 top에 담기게 됨

### 삽입, 삭제, 조회
#### 요소 넣기
```cpp
q.push(x);
```

#### 요소 지우기
```cpp
q.pop(); // top의 요소가 삭제
```

#### top의 요소 확인
```cpp
q.top();
```


<br>


## BFS
- 출발점에서 목적지까지 최소 몇 번만에 갈 수 있는지를 구하는 알고리즘
- 최단 거리, 최소 횟수, 몇 번만에, 한 칸씩 이동 등등
- **BFS 문제에서 원본 크기의 거리 배열과 큐를 만들어 사용해야 한다는 것을 반드시 기억할 것!!**

### 1. 논리
1. 원본 크기의 거리 배열은 -1로 초기화
2. 출발점을 거리 배열에서 0으로 표기하고 큐에 넣기
3. 큐에서 기준점을 하나 꺼냄
4. 기준점에서 상하좌우 4칸을 살핌
5. 만약 다음 위치가 원본 배열 밖이거나, 원본 배열에서 막힌 길을 가지고 있거나, 거리 배열에 -1이 아닌 값이 있다면(이미 확인) 무시하고 진행
6. 거리를 '이전 거리 + 1'로 표기하고 큐에 해당 위치들을 넣음
7. 상하좌우를 살피는 게 끝났다면 다음 기준점을 큐에서 꺼냄
8. 큐가 비었다면 반복 종료
9. 만약 도착점의 거리 배열이 여전히 -1이라면 도달 불가

### 구현
- 원본 2차원 배열 maps 존재
- 원본과 같은 크기의 -1로 초기화된 거리 배열 존재
- x, y 좌표를 저장하기 위한 pair<int, int> 타입의 queue 존재
- maps의 값이 0이라면 길이 없음

```cpp
int n = maps.size();    // maps 내부 벡터 개수 
int m = maps[0].size(); // maps 내부 벡터 안의 원소 개수

vector<vector<int>> dist(n, vector<int>(m, -1));
queue<pair<int, int>> q;

q.push({0, 0}); // 시작점 큐에 넣기
dist[0][0] = 0; //출발칸을 개수에 포함한다면 0 대신 1을 사용할 것

vector<int> mx = {0, 0, 1, -1}; // x의 움직임 배열
vector<int> my = {1, -1, 0, 0};

while(q.empty() != true){
    pair<int, int> stand = q.front();
    q.pop();
    
    // pair이므로 first, second로 접근
    int x = stand.first;
    int y = stand.second;

    // 상하좌우 4번 반복
    for(int i = 0; i < 4; i++){
        int nx = x + mx[i];
        int ny = y + my[i];

        if(nx < 0 || ny < 0 || nx > n-1 || ny > m-1) continue;
        if(maps[nx][ny] == 0) continue;
        if(dist[nx][ny] != -1) continue;

        q.push({nx, ny});
        dist[nx][ny] = dist[x][y] + 1;
    }
}
```

- dist 거리 배열을 완성한 후 목적지가 되는 장소의 dist[_][_] 값을 반환하면 됨
- dist[_][_] 값이 -1일 때 도달 불가

### 주의
- 코드 내부의 x, y는 수학적의미의 x축, y축이 아님
- **dist[x][y]이므로 x가 배열 내부의 벡터, y가 벡터 내부의 요소를 뜻한다는 것을 잊지 말 것**


<br>


## algorithm

### 1. Min/Max
2가지 중에 더 작은/큰 값을 리턴
```cpp
min(10, 15);
```

### 2. sort
#### 벡터에서의 sort
시작/끝 위치(iterator) 두 개를 받아 그 구간을 오름차순 정렬.
```cpp
sort(v.begin(), v.end());  // 전체 정렬
sort(v.begin(), v.begin() + 3);  // 벡터의 일부만 정렬 (이 경우 3개의 원소)
```

#### 사용자 지정함수
- 두 개의 항목을 비교하고자 할 때
```cpp
bool comp(int a, int b){
    return a > b;  // 더 큰 쪽이 앞으로 올 때 true를 반환하도록 작성
}

sort(numbers.begin(), numbers.end(), comp);
```

#### 사용자 지정함수
- 두 개의 배열을 비교하고자 할 때
- 배열 내부에서 두 가지 이상의 비교 기준을 함께 사용하고자 할 때
- 필요하다면 if 문을 늘려 규칙 추가 가능
```cpp
bool comp(vector<int> a, vector<int> b){
    if(a[0] != b[0]) return a[0] > b[0]; // 첫 번째 원소 기준 클수록 앞으로
    return a[1] < b[1]; // 첫 번째 원소 같을 때, 두 번째 원소 기준 작을수록 앞으로
}

sort(numbers.begin(), numbers.end(), comp);
```

<br>

## 문자열
- 문자와 문자열을 구분. 작은 따옴표는 char, 큰 따옴표는 string
- `+`를 통해 문자열을 뒤로 덧붙일 수 있음

### 1. 길이
문자열 p의 길이
```cpp
p.length();
```

### 2. 서브 스트링
문자열 p의 서브 스트링 구하기. 인덱스 0에서부터 i만큼 잘라라
```cpp
p.substr(0,i);
```

### 3. 숫자 변환
#### 문자열 ↔ 숫자
숫자 → 문자열
```cpp
string str_a = to_string(a);
```

문자열→ 숫자
```cpp
int int_a = stoi(str_a); // string to int의 앞글자를 딴 함수명 : s to i
float float_a = stof(str_a);
```

#### 문자 ↔ 숫자
char 혹은 string의 한 글자를 숫자로 변환
```cpp
int int_a = char_a - '0';
int int_a = str_a[0] - '0';
```

### 4. 비교
- 자릿수가 큰 숫자를 비교할 때, int로 변환하면 오버플로우 위험이 있음. 
- 이런 경우 string 상태로 그대로 비교 연산자(>, <)를 쓰면 안전함 (단, 길이가 같을 때, 숫자 크기 비교와 결과가 같음)


<br>

## 헷갈리는 것들

### 1. 곱셈 기호 생략 불가

숫자와 변수를 곱할 때 `*`를 반드시 명시해야 함. 수학처럼 `2w`로 쓰면 컴파일 에러 발생

```cpp
2*w + 2*h + 4
```

### 2. int 사용 주의
10000이 넘는 숫자의 곱셈 등이 일어나려 할 경우, 모든 숫자를 int 대신 long long으로 통일할 것

```cpp
long long a = 10000, b = 10000;
long long c = a * b;
```


<br>
<br>
<br>


# SQL문을 활용한 코딩 테스트 연습

<br>

## 조건
`SELECT _ FROM`, `WHERE`, `AND`, `OR`, `BETWEEN _ AND _`, `LIKE '%abc%'`
- AND와 OR을 섞어 사용할 때 소괄호를 사용해 우선순위를 표시
- 한 번에 여러 개의 값을 묶을 때 소괄호 사용
- LIKE문의 문자열에 %는 해당자리에 추가 글자를 허용하겠다는 뜻

```sql
SELECT * FROM MEMBER
WHERE GENDER = 'W'
    AND (AGE = 20 OR AGE = 30)
    AND MEMBER_NAME IN ('철수', '영희')
    AND ACCESS_COUNT BETWEEN 10 AND 1000
    AND MEMBER_ID LIKE '%000'; // 멤버 ID가 000으로 끝나는 사람
```

### DISTINCT
- SELECT 바로 뒤에서 사용
- MEMBER에서 GENDER와 AGE를 추출한 뒤 GENDER와 AGE에 같은 데이터를 가진 완전히 중복된 행이 있다면 제거

```sql
SELECT DISTINCT GENDER, AGE
FROM MEMBER;
```


<br>


## NULL
`IS NULL`, `IS NOT NULL`, `IFNULL(col, '대체값')`
- IS NULL, IS NOT NULL은 WHERE문의 조건으로 사용
- IFNULL은 SELECT와 함께 사용. 사용자에게 보여지는 출력 결과를 대체함

### IS NULL 사용
```sql
WHERE AGE IS NULL
    AND MEMBER_NAME IS NOT NULL;
```

### IFNULL 사용
```sql
SELECT MEMBER_ID, IFNULL(GENDER, 'X') AS GENDER
FROM MEMBER;
```
- 멤버 ID와 성별을 가져오는데, 만약 성별이 NULL이라면 'X'로 대체하여 출력
- 이때 열의 이름이 IFNULL(GENDER, 'X')그대로 출력되므로 `AS`를 붙여 출력 열의 이름을 GENDER로 변경


<br>


## 날짜
`YEAR()`, `MONTH()`, `DAY()`, `DATE_FORMAT(col, '%Y-%m-%d')`
- 열의 타입이 DATE 또는 DATETIME일 때 사용 가능
- 날짜 포멧에 년도 `Y`는 반드시 대문자, 나머지는 소문자를 사용할 것
- '같다'를 표현할 때 '='을 하나만 쓸 것

```sql
SELECT DATE_FORMAT(DATE_OF_BIRTH, '%Y년 %m월 %d일') AS DATE_OF_BIRTH
FROM MEMBER
WHERE YEAR(DATE_OF_BIRTH) = 2000;
```


<br>


## 정렬
`ORDER BY col ASC/DESC`, `LIMIT`
- col를 기준으로 SELECT로 뽑아낸 행들을 정렬
- ASC는 오름차순. ORDER BY의 기본값이므로 생략 가능
- ASC와 DESC는 원하는 열 뒤에서 사용하며 암기할 것
- **ORDER BY에 여러 열을 쓰면 앞에 쓴 열이 1순위**
- LIMIT는 정렬 후 자르기이므로 ORDER BY 뒤에서 사용

```sql
SELECT * FROM MEMBER
ORDER BY MEMBER_ID DESC, AGE ASC
LIMIT 1; -- 가장 나이가 적은 사람 (나이가 같으면 ID가 큰 사람)
```


<br>


## JOIN
`JOIN ... ON`, `LEFT JOIN`
- MEMBER와 ORDERS 테이블이 있을 때 두 테이블을 합칠 수 있음
- MEMBER_ID를 기준으로 MEMBER와 ORDERS를 JOIN하면 JOIN된 테이블이 출력값이 됨 (여기서 선택적으로 출력 가능)

```sql
SELECT *
FROM ORDERS AS O
JOIN MEMBER AS M
    ON O.MEMBER_ID = M.ID AND ...
WHERE ...;
```

- 여러 테이블을 한거번에 JOIN 가능
- JOIN이므로 ON 조건에 맞는 데이터만이 추출
    - LEFT JOIN : FROM에 쓴 테이블을 기준으로 추출
    - RIGHT JOIN : JOIN 당하는 테이블을 기준으로 추출
- LEFT 혹은 RIGHT JOIN에서 없는 행은 NULL로 채워짐. 이를 이용해 IS NULL로 한쪽 테이블에만 있는 정보를 골라낼 수 있음

### 같은 테이블을 두 번 붙이는 경우
- **(부모-자식) (상사-직원)과 같은 관계가 한 테이블에 표시되어 있을 때**
- 하나를 부모 테이블 하나를 자식 테이블이라고 분리하여 생각
- 이때 같은 테이블을 두 번 붙이는 풀이가 필요하다



<br>


## 집계
`COUNT`, `SUM`, `MAX`, `MIN`, `AVG`, `ROUND`
- 하나의 열에서 행 전체의 값을 받아 하나의 값으로 계산함
- 성적의 개수, 총합, 최고, 최저, 평균, 반올림 등등
- NULL값은 집계에 포함되지 않는다

### 기본 집계
```sql
SELECT COUNT(MEMBER_ID)
FROM MEMBER;
```

### 중복을 제거한 집계
COUNT가 DISTINCT를 포함해 col 전체를 감싸도록 작성

```sql
SELECT COUNT(DISTINCT MEMBER_NAME)
FROM MEMBER;
```

### 전체 행 집계
NULL과 관계 없이 해당 테이블의 전체 행 개수를 세게 됨

```sql
SELECT COUNT(*)
FROM MEMBER;
```

### ROUND
- ROUND(값, 남길 소수 자릿수) 형태로 사용
- 주로 AVG로 구한 평균 값에서 소수점 자리수를 맞추는데 사용

```sql
SELECT ROUND(AVG(AGE), 0) AS AGE_AVG
FROM MEMBER;
```
- 소수점 없이 정수형으로 반올림한 평균값을 AGE_AVG라는 열 이름으로 출력


<br>


## 서브쿼리
- 괄호 안의 쿼리가 먼저 실행되어 결과가 나오고 그 결과를 바탕으로 메인 쿼리가 실행됨
- WHERE 등에서 사용
- 괄호 안에 SELECT 문을 하나 더 사용할 것

```sql
SELECT *
FROM PRODUCT
WHERE PRICE = (SELECT MAX(PRICE) FROM PRODUCT);
```
- PRODUCT 테이블에서 최고 가격을 가진 물건들의 정보만 출력하는 쿼리
- 최고 가격의 물건을 하나만 찾고자 한다면 `ORDER BY PRICE DESC LIMIT 1;` 로 풀 수 있음


<br>


## 묶기
`GROUP BY`, `HAVING`
- GROUP BY는 열을 지정하여 지정한 열의 값이 같은 행을 하나의 그룹으로 묶음
- GROUP BY를 쓰면 SELECT에는 GROUP BY를 한 기준 열과 집계함수를 사용한 결과만 사용할 수 있음
- **WHERE은 열 값에만 적용. 집계 함수의 결과를 필터링으로 걸고 싶다면 반드시 HAVING을 사용할 것**

### GROUP BY
- 성별에 따른 인원수 세기

```sql
SELECT GENDER, COUNT(*) AS COUNT
FROM MEMBER
GROUP BY GENDER
```

### HAVING
- 동명이인이 존재하는 이름만 찾기
- GROUP BY로 묶은 MEMBER_NAME에 대한 COUNT(*)

```sql
SELECT MEMBER_NAME
FROM MEMBER
GROUP BY MEMBER_NAME
HAVING COUNT(*) > 1;
```



---

조건 분기	CASE WHEN ... THEN ... ELSE ... END