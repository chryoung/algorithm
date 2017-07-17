#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

template<typename T>
void InsertSort(std::vector<T>& vec)
{
    int minIndex = 0;
    // i stands for number of sorted elments.
    for (int i = 0; i < vec.size() - 1; ++i) {
        int j = i + 1;
        for (int scanIndex = 0; scanIndex < j; ++scanIndex) {
            if (vec[scanIndex] > vec[j]) {
                T hold = vec[j];
                int moveIndex = j;
                for (; moveIndex > scanIndex; --moveIndex) {
                    vec[moveIndex] = vec[moveIndex - 1];
                }
                vec[moveIndex] = hold;
                break;
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

    InsertSort(testA);

    PrintVec(testA);
}

