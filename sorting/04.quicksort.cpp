#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

template<typename T>
void PrintVec(const std::vector<T>& vec);

template<typename T>
void _Partition(std::vector<T>& vec, int& pivot, int from, int to)
{
    std::swap(vec[from], vec[pivot]);
    int low = from;
    int high = to + 1;
    while (true) {
        while (vec[++low] < vec[from]) {
            if (low == to) {
                break;
            }
        }
        while (vec[--high] > vec[from]) {
            if (high == from) {
                break;
            }
        }
        if (low >= high) {
            break;
        }
        std::swap(vec[low], vec[high]);
    }

    pivot = high; // Should not return low. Because at this moment, vec[high] is smaller than vec[from], it should be put in the low position.
    std::swap(vec[from], vec[pivot]);
}

template<typename T>
void _InternalSort(std::vector<T>& vec, int from, int to)
{
    if (from >= to) return;

    int pivot = (rand() % (from - to)) + from;
    _Partition(vec, pivot, from, to);
    _InternalSort(vec, from, pivot - 1);
    _InternalSort(vec, pivot + 1, to);
}

template<typename T>
void QuickSort(std::vector<T>& vec)
{
    _InternalSort(vec, 0, vec.size() - 1);
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

    for (int i = 0; i < 1000; ++i) {
        testA.push_back(rand() % 10000);
    }

    PrintVec(testA);

    QuickSort(testA);

    PrintVec(testA);
}

