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

### vector<T>
```cpp
for (const auto& p : v) {
    // p가 곧 원소
}
```

### vector<vector<T>>
```cpp
for (const auto& p : v) {
    // p는 벡터 안의 벡터를 반환. 해당 벡터 내의 요소들에 접근할 때는 인덱스를 사용
    // p[0], p[1], ...
}
```

### unordered_map<K,V>
```cpp
for (auto& p : m) { // map m에 auto&로 참조 접근
    // p.first는 해당 요소의 key값
    // p.second는 해당 요소의 value값
}
```

벡터는 인덱스로 접근, map에서 뱉어내는 pair는 `.first`, `.second`로 접근 가능!

<br>

## 자료구조별 요소

### 요소 추가하기 (insert vs push_back)
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

### 기존 요소 찾기 - set

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

사용자 지정함수
- 두 개의 항목을 비교하고자 할 때
```cpp
bool comp(int a, int b){
    return a > b;  // 더 큰 쪽이 앞으로 올 때 true를 반환하도록 작성
}

sort(numbers.begin(), numbers.end(), comp);
```

사용자 지정함수
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