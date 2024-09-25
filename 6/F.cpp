#include <iostream>
#include <set>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n;
    std::cin >> n;

    std::multiset<int> st;
    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        st.insert(input);
    }

    if (!st.empty()) {
        int prev = *st.begin();
        for (auto &i : st) {
            if (i == prev) continue;
            else {
                st.erase(prev);
                prev = i;
            }
        }
    }

    std::cout << st.size() << '\n';
}