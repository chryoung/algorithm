#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

template<typename T>
void BubbleSort(std::vector<T>& vec)
{
    for (int i = vec.size() - 1; i > 0; --i) {
        for (int j = i - 1; j >= -1; --j) {
            if (vec[j] > vec[i]) {
                std::swap(vec[j], vec[i]);
            }
        }
    }
}

template<typename T>
void PrintVec(const std::vector<T>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }

    std::cout << "\b\n";
}

int main (void)
{
    using namespace std;

    srand(time(0));
    vector<int> testA;

    for (int i = 0; i < 10; ++i) {
        testA.push_back(rand() % 100);
    }

    PrintVec(testA);

    BubbleSort(testA);

    PrintVec(testA);
}

