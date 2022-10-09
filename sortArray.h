#ifndef SORTARRAY_H
#define SORTARRAY_H
#include <QVector>
#include <algorithm>
void doiCho(QString *a, QString *b) {
    QString t = *a;
    *a = *b;
    *b = t;
}
// option = 1 tu be den lon, = 0 tu lon den be
int partition(QVector<QVector<QString>> &arr, int start, int end, int option)
{

    long long int pivot = arr[start][0].toLongLong(); // phan tu dau tien

    int count = 0;
    if (option == 1)
    {
        for (int i = start + 1; i <= end; i++) {
            if (arr[i][0].toLongLong() <= pivot)
                count++;
        }
    }
    else {
        for (int i = start + 1; i <= end; i++) {
            if (arr[i][0].toLongLong() >= pivot)
                count++;
        }
    }
    int pivotIndex = start + count;
    //    doiCho(&arr[pivotIndex][0], &arr[start][0]);
    for (int i = 0; i < arr[i].size(); i++)
    {
        doiCho(&arr[pivotIndex][i], &arr[start][i]);
    }

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        if (option == 1)
        {
            while (arr[i][0].toLongLong() <= pivot) {
                i++;
            }

            while (arr[j][0].toLongLong() > pivot) {
                j--;
            }
        }
        else {
            while (arr[i][0].toLongLong() >= pivot) {
                i++;
            }

            while (arr[j][0].toLongLong() < pivot) {
                j--;
            }
        }
        if (i < pivotIndex && j > pivotIndex) {
            int index1 = i++;
            int index2 = j--;
            // doiCho(&arr[index1][0],&arr[index2][0]);
            for (int i = 0; i < arr[i].size(); i++)
            {
                doiCho(&arr[index1][i], &arr[index2][i]);
            }
        }
    }

    return pivotIndex;
}
void quickSort(QVector<QVector <QString>> &arr, int start, int end, int option)
{
    // base case
    if (start >= end)
        return;
    // partitioning the array
    int p = partition(arr, start, end, option);

    // Sorting the left part
    quickSort(arr, start, p - 1, option);

    // Sorting the right part
    quickSort(arr, p + 1, end, option);

}
#endif // SORTARRAY_H
