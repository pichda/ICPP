#include <string>
#include <iostream>
#include "IComparable.h"
#include <random>
#include "MyTime.h"


// jednoduchy bubblesort
void SortArray(IComparable** arr, int arrSize) {
    for (int i = 0; i < arrSize - 1; i++)
    {
        for (int j = 0; j < arrSize - i - 1; j++)
        {
            if (arr[j + 1]->CompareTo(arr[j]) == -1)  // levy objekt < pravy objekt � vrac� -1 
            {
                IComparable* tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(int argc, char** argv) {

    int const MY_ARRAY_SIZE = 10;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0, 23);
    std::uniform_real_distribution<double> dist_minutes(0, 59);

    MyTime** myArr = new MyTime*[MY_ARRAY_SIZE];

    for (int i = 0; i < MY_ARRAY_SIZE; i++)
    {
        MyTime* t = new MyTime(dist(mt), dist_minutes(mt), dist_minutes(mt));
        myArr[i] = t;
    }

    std::cout << "Unsorted array \n";
    for (int i = 0; i < MY_ARRAY_SIZE; i++)
    {
        std::cout << myArr[i]->ToString() << "\n";
    }

    //reinterpret_cast<IComparable**>(myArr)
    SortArray((IComparable**)myArr,MY_ARRAY_SIZE);
    std::cout << "\nSorted array \n";
    for (int i = 0; i < MY_ARRAY_SIZE; i++)
    {
        std::cout << myArr[i]->ToString() << "\n";
    }

    delete[]myArr;

}