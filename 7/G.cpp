#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::string;
using std::vector;
typedef long long ll;


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int participants, foodPackages;
    cin >> participants >> foodPackages;

    std::map<int, int> foodTypes;
    for (int i = 0; i < foodPackages; i++) {
        int foodType;
        cin >> foodType;
        if (foodTypes.find(foodType) == foodTypes.end()) foodTypes[foodType] = 1;
        else foodTypes[foodType]++;
    }

    int days = 1;
    while (true) {
        int people = 0;
        for (auto &i : foodTypes) people += i.second/days;
        if (people < participants) {
            days--;
            break;
        }
        days++;
    }

    cout << days << '\n';
}