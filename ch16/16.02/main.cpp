#include <vector>
#include <iostream>
#include <numeric> // for std::accumulate
#include <functional> // for std::multiplies

template <typename T>
void printVector(const std::vector<T>& vec) {
    using namespace std;

    cout << "{ ";
    for (std::size_t i {0}; i < vec.size() - 1; i++) {
        cout << vec[i] << ", ";
    }
    cout << vec[vec.size() - 1] << " }\n";
}

std::vector<double> inputThreeNumbers() {
    using namespace std;
    std::vector<double> res (3);

    cout << "Input three numbers\n";
    cout << "First one: ";
    cin >> res[0];
    cout << "Second one: ";
    cin >> res[1];
    cout << "Third one: ";
    cin >> res[2];
    cout << endl;
    printVector(res);
    return res;
}

int main() {
    std::vector<int> vec {1, 4, 9, 16, 25};
    std::vector<double> temperatures (365);
    auto vecThree {inputThreeNumbers()};
    std::cout << "your vector is: ";
    printVector(vecThree);

    double sum = std::accumulate(vecThree.begin(), vecThree.end(), 0);
    std::cout << "sum = " << sum << std::endl;
    double product = std::accumulate(vecThree.begin(), vecThree.end(), 1, std::multiplies());
    std::cout << "product = " << product << std::endl;
    return 0;
}