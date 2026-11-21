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
		cin >> N;

		vector<vector<int>> place(N, vector<int>(N, 0));

		vector<int> mx = { 0, 1, 0, -1 };
		vector<int> my = { 1, 0, -1, 0 };

		int m_index = 0;
		int x = 0;
		int y = 0;
		

		for (int num = 1; num <= N*N; num++) { //NxN 크기의 배열을 다 채워야 함
			place[x][y] = num;

			int nx = x + mx[m_index];
			int ny = y + my[m_index];

			// 막히는 경우
			if (nx < 0 || nx > N-1 || ny < 0 || ny > N-1 || place[nx][ny] != 0) { // (0 ~ N-1)까지가 배열 범위 + 이미 채워진 칸까지 벽으로 취급
				m_index = (m_index + 1) % 4; // 인덱스 갱신

				nx = x + mx[m_index];
				ny = y + my[m_index];
			}

			x = nx;
			y = ny;
		}


		// 출력 시작
		cout << '#' << test_case << '\n';

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << place[i][j] << ' ';
			}
			cout << '\n';
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

/*
1954. 달팽이 숫자
*/