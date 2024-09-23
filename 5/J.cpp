#include <iostream>
#include <vector>
#include <algorithm>
 
typedef long long ll;
 
int main() {
    int t, nOfMonsters, genosPower;
    std::cin >> t;
    while (t--) {
        std::cin >> nOfMonsters >> genosPower;
        std::vector<std::pair<ll, ll>> monsters(nOfMonsters);
        for (int i = 0; i < nOfMonsters; i++) std::cin >> monsters[i].second;
        for (int i = 0; i < nOfMonsters; i++) std::cin >> monsters[i].first;
        std::sort(monsters.begin(), monsters.end());
 
        while (genosPower > 0) {
            int temp = genosPower;
            bool done = true;
            for (int i = 0; i < monsters.size(); i++) {
                if (monsters[i].second > 0) {
                    monsters[i].second -= temp;
                    if (genosPower == temp) genosPower -= monsters[i].first;
                    done = false;
                } else continue;
            }
            if (done) break;
        }
 
        if (genosPower > 0) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}