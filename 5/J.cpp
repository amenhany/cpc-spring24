#include <iostream>
#include <vector>
#include <algorithm>
 
typedef long long ll;
 
bool sortBySecond(std::pair<ll, ll> &p1, std::pair<ll, ll> &p2) {
    if (p1.second > p2.second) return 1;
    else return 0;
}
 
int main() {
    int t, nOfMonsters, genosPower;
    std::cin >> t;
    while (t--) {
        std::cin >> nOfMonsters >> genosPower;
        std::vector<std::pair<ll, ll>> monsters(nOfMonsters);
        for (int i = 0; i < nOfMonsters; i++) std::cin >> monsters[i].first;
        for (int i = 0; i < nOfMonsters; i++) std::cin >> monsters[i].second;
        std::sort(monsters.begin(), monsters.end(), sortBySecond);
 
        while (genosPower > 0 && monsters.size() > 0) {
            for (int i = 0; i < monsters.size(); i++) monsters[i].first -= genosPower;
            while (monsters.size() > 0) {
                if (monsters.back().first > 0) {
                    genosPower -= monsters.back().second;
                    break;
                }
                else if (monsters.size() > 0) monsters.pop_back();
                else break;
            }
        }
 
        if (genosPower > 0) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}