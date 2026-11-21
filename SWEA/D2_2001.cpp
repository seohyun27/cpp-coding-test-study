#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int M;
		cin >> N;
		cin >> M;

		vector<vector<int>> place(N, vector<int>(N)); //N 개의 칸을 'N개의 칸으로 채운 벡터'로 채울 것

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> place[i][j];
			}
		}

		int max_sum = 0;

		for (int i = 0; i <= N-M; i++) { // (N-M, N-M)까지 1번 꼭짓점이 될 수 있음
			for (int j = 0; j <= N-M; j++) {
				// 여기를 1번 꼭지점으로 두고 M 영역만큼 구하기
				int sum = 0;

				for (int x = 0; x < M; x++) {
					for (int y = 0; y < M; y++) {
						sum += place[i+x][j+y];
					}
				}

				if (max_sum < sum) max_sum = sum;
			}
		}

		cout << '#' << test_case << ' ' << max_sum << '\n';
	}

	return 0;
}


/*
파리퇴치 문제

N=6, M=3라면
파리채의 왼쪽 상단이 될 수 있는 영역은 아래와 같음
 1 2 3 4 (5 6)
 1 2 3 4 (5 6)
 1 2 3 4 (5 6)
 1 2 3 4 (5 6)
(1 2 3 4  5 6)
(1 2 3 4  5 6)

인덱스 (3,3)까지 포함되어야 함

파리채로 때리는 영역
옆으로는 0부터 N-M까지 M만큼
아래로도 0부터 N-M까지 M만큼
*/