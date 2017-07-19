#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

template<typename T>
void Merge(std::vector<T>& vec, std::vector<T>&aux, int lo, int mid, int hi)
{
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; ++k) {
        aux[k] = vec[k];
    }

    for (int k = lo; k <= hi; ++k) {
        if (i > mid) {
            vec[k] = aux[j++];
        } else if (j > hi) {
            vec[k] = aux[i++];
        } else if (aux[j] < aux[i]) {
            vec[k] = aux[j++];
        } else {
            vec[k] = aux[i++];
        }
    }
}

template<typename T>
void Sort(std::vector<T>& vec, std::vector<T>& aux, int lo, int hi)
{
    if (lo >= hi) {
        return;
    }
    int mid = lo + (hi - lo) / 2;
    Sort(vec, aux, lo, mid);
    Sort(vec, aux, mid + 1, hi);
    Merge(vec, aux, lo, mid, hi);
}


template<typename T>
void MergeSort(std::vector<T>& vec)
{
    std::vector<T> aux(vec.size());
    Sort(vec, aux, 0, vec.size());
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
        testA.push_back(rand() % 1000);
    }

    PrintVec(testA);

    MergeSort(testA);

    PrintVec(testA);
}

