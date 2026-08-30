# cpp-coding-test-study
C++을 활용한 코딩 테스트 연습


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




## for문
### 참조 접근
```cpp
for (auto& p : m) { // map m에 auto&로 참조 접근
    // p.first는 해당 요소의 key값
    // p.second는 해당 요소의 value값

```



## 배열
### 요소 개수
set s의 요소 개수 구하기, 배열 nums의 요소 개수 구하기 등
```cpp
s.size()
nums.size();
```



## algorithm
### Min/Max
2가지 중에 더 작은/큰 값을 리턴
```cpp
min(10, 15);
```


## 문자열
### 길이
문자열 p의 길이
```cpp
p.length();
```

### 서브 스트링
문자열 p의 서브 스트링 구하기. 인덱스 0에서부터 i만큼 잘라라
```cpp
p.substr(0,i);
```