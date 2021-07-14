#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int sz = s.size();
	string ans(sz, 'z');

	for (int i = 0; i < sz-2; ++i) {
		for (int j = i + 1; j < sz-1; ++j) {
			string tmp = s;			
			reverse(tmp.begin(), tmp.begin() + i+1);
			reverse(tmp.begin()+i+1, tmp.begin() + j+1);
			reverse(tmp.begin()+j+1, tmp.end());
			ans = min(ans, tmp);
		}
	}

	cout << ans << '\n';
    return 0;
}
