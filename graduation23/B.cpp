#include <iostream>
#include <vector>
#include <algorithm>


bool compare(std::pair<int, int> &p1, std::pair<int, int> &p2) {
    if (p1.first > p2.first) return 1;
    else if (p1.second < p2.second) return 1;
    else return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> ranking(n);
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            int input;
            std::cin >> input;
            sum += input;
        }

        ranking[i] = {sum, i+1};
    }

    sort(ranking.begin(), ranking.end(), compare);
    for (int i = 0; i < n; i++) {
        if (ranking[i].second == 1) std::cout << i+1 << '\n';
    }
}