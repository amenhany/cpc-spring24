#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> v(n, 0);

    std::vector<int>::iterator it;
    it = v.begin();
    for (int i = 1; i <= n; i++) {
        if (s[i-1] == 'R') it++;
        it = v.insert(it, i);
    }

    for (int i = 0; i <= n; i++) std::cout << v[i] << ' ';
}