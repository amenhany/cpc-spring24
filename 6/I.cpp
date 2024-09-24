#include <iostream>
#include <stack>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int num, input, counter = 1;
    std::cin >> num >> input;
    std::stack<int> narrowRoad;
    narrowRoad.push(input);

    while (input !=0) {
        std::cin >> input;
        while (!narrowRoad.empty() && narrowRoad.top() == counter) {
            narrowRoad.pop();
            counter++;
        }
        if (input != counter) narrowRoad.push(input);
        else counter++;
    }

    if (counter == num+1) std::cout << "yes" << '\n';
    else std::cout << "no" << '\n';
}