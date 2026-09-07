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

## 자료구조별 접근/조작 방법

### 1. 순회할 때 나오는 타입 & 접근법
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

### 2. 요소 추가할 때 (insert vs push_back)
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

### 3. 요소 개수
set s의 요소 개수 구하기, 배열 nums의 요소 개수 구하기 등
```cpp
s.size()
nums.size();
```

<br>

### 4. 기존 요소 찾기
#### set의 경우

`s.find(key)`를 통해 key의 존재 여부를 찾음. key가 존재한다면 이터레이터 반환. 존재하지 않는다면 `s.end()`를 반환함.

```cpp
if(s.find("dog") != s.end()){
    // s라는 set 안에 dog라는 문자열이 존재한다면
}
```

<br>

## algorithm

### 1. Min/Max
2가지 중에 더 작은/큰 값을 리턴
```cpp
min(10, 15);
```

<br>

## 문자열

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
