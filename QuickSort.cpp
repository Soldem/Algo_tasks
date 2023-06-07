#include <iostream>

#define LIMIT 256

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

int partition(int* mas, int start, int end)
{
    int pivot = mas[end];

    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        if (mas[i] <= pivot)
        {
            swap(mas[i], mas[pIndex]);
            pIndex++;
        }
    }

    swap(mas[pIndex], mas[end]);

    return pIndex;
}

void quicksort(int* mas, int start, int end)
{
    if (start >= end) {
        return;
    }

    int pivot = partition(mas, start, end);

    quicksort(mas, start, pivot - 1);

    quicksort(mas, pivot + 1, end);
}

//
//// Функция для выполнения сортировки вставками для `arr[]`
//void insertSort(int* mas, int low, int n)
//{
//    for (int i = low + 1; i <= n; i++)
//    {
//        int value = mas[i];
//        int j = i;
//
//        while (j > low && mas[j - 1] > value)
//        {
//            mas[j] = mas[j - 1];
//            j--;
//        }
//        mas[j] = value;
//    }
//}
//
//int partition(int* mas, int low, int high)
//{
//    int pivot = mas[high];
//
//    int pIndex = low;
//
//    for (int i = low; i < high; i++)
//    {
//        if (mas[i] <= pivot)
//        {
//            swap(mas[i], mas[pIndex]);
//            pIndex++;
//        }
//    }
//    swap(mas[pIndex], mas[high]);
//
//    return pIndex;
//}
//
//
//void quicksort(int* mas, int low, int high)
//{
//    while (low < high)
//    {
//        if (high - low < LIMIT)
//        {
//            insertSort(mas, low, high);
//            break;
//        }
//        else {
//            int pivot = partition(mas, low, high);
//
//            if (pivot - low < high - pivot)
//            {
//                quicksort(mas, low, pivot - 1);
//                low = pivot + 1;
//            }
//            else {
//                quicksort(mas, pivot + 1, high);
//                high = pivot - 1;
//            }
//        }
//    }
//}

int main()
{
    int n;
    std::cin >> n;

    int* mas = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> mas[i];
    }

    quicksort(mas, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << "  ";
    }

    delete[] mas;
}









//#include <iostream>
//
//#define LIMIT 256
//
//void swap(int& a, int& b)
//{
//    int t = a;
//    a = b;
//    b = t;
//}
//
//int partition(int* mas, int start, int end)
//{
//    int pivot = mas[end];
//
//    int pIndex = start;
//
//    for (int i = start; i < end; i++)
//    {
//        if (mas[i] <= pivot)
//        {
//            swap(mas[i], mas[pIndex]);
//            pIndex++;
//        }
//    }
//
//    swap(mas[pIndex], mas[end]);
//
//    return pIndex;
//}
//
//void quicksort(int* mas, int start, int end)
//{
//    if (start >= end) {
//        return;
//    }
//
//    int pivot = partition(mas, start, end);
//
//    quicksort(mas, start, pivot - 1);
//
//    quicksort(mas, pivot + 1, end);
//}
//
////
////// Функция для выполнения сортировки вставками для `arr[]`
////void insertSort(int* mas, int low, int n)
////{
////    for (int i = low + 1; i <= n; i++)
////    {
////        int value = mas[i];
////        int j = i;
////
////        while (j > low && mas[j - 1] > value)
////        {
////            mas[j] = mas[j - 1];
////            j--;
////        }
////        mas[j] = value;
////    }
////}
////
////int partition(int* mas, int low, int high)
////{
////    int pivot = mas[high];
////
////    int pIndex = low;
////
////    for (int i = low; i < high; i++)
////    {
////        if (mas[i] <= pivot)
////        {
////            swap(mas[i], mas[pIndex]);
////            pIndex++;
////        }
////    }
////    swap(mas[pIndex], mas[high]);
////
////    return pIndex;
////}
////
////
////void quicksort(int* mas, int low, int high)
////{
////    while (low < high)
////    {
////        if (high - low < LIMIT)
////        {
////            insertSort(mas, low, high);
////            break;
////        }
////        else {
////            int pivot = partition(mas, low, high);
////
////            if (pivot - low < high - pivot)
////            {
////                quicksort(mas, low, pivot - 1);
////                low = pivot + 1;
////            }
////            else {
////                quicksort(mas, pivot + 1, high);
////                high = pivot - 1;
////            }
////        }
////    }
////}
//
//int main()
//{
//    int n;
//    std::cin >> n;
//
//    int* mas = new int[n];
//    for (int i = 0; i < n; i++)
//    {
//        std::cin >> mas[i];
//    }
//
//    quicksort(mas, 0, n - 1);
//
//    for (int i = 0; i < n; i++)
//    {
//        std::cout << mas[i] << "  ";
//    }
//
//    delete[] mas;
//}

