#include <iostream> // IO 선언

using namespace std; // 네임 스페이스 선언

int main() {
	int T;
	cin >> T; // 테스트 케이스 개수

	for (int i = 0; i < T; i++) {
		int sum = 0;

		for (int j = 0; j < 10; j++) {
			int num;
			cin >> num;
		
			if (num % 2 != 0) sum += num;
		}

		cout << '#' << i+1 << " " << sum << "\n";
	}

	return 0;
}