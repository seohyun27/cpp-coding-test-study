#include <iostream>
#include <vector>

using namespace std;

int main() {
	//scanf를 꺼서 cin을 빠르게 만드는 설정 두 개
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int N;
		cin >> N;

		vector<int> vec(N);

		for (int i = 0; i < N; i++) cin >> vec[i];

		long long sum = 0; // 팔고 남은 이익. 물건의 개수는 최대 1,000,000이므로 long long 사용할 것
		int cur_max = 0;
		for (int i = N-1; i >= 0; i--)	{	// 인덱스 범위는 0 ~ N-1까지 !!
			if (vec[i] < cur_max) sum += cur_max - vec[i];
			if (vec[i] > cur_max) cur_max = vec[i];
		}

		cout << '#' << tc + 1 << ' ' << sum << '\n';
	}
}

/*
백만장자 프로젝트

뒤에서부터 생각
2 2 2 5 3 4로 주어졌을 때
최대값 4보다 3이 작으므로 팔기
5는 4보다 크기 때문에 최대값 5로 수정
2는 5보다 작으니까 팔기
*/