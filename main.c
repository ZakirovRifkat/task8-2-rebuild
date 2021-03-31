#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high, int *nswap, int *nif)
{

    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        *nif=*nif+1;
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            *nswap=*nswap+1;
        }
    }
    *nswap=*nswap+1;
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high, int *nswap, int *nif)
{

    if (low < high)
    {
        int pi = partition(array, low, high,&*nswap, &*nif);
        quickSort(array, low, pi - 1,&*nswap, &*nif);
        quickSort(array, pi + 1, high,&*nswap, &*nif);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}
int main()
 {
    setlocale(LC_ALL,"rus");
    int nswap=0,nif=0,*data,n;
    printf("Введите кол-во эллементов в массиве: ");
    scanf_s("%d", &n);
    data = (int*)malloc(n * sizeof(int));
    printf("Введите элеметнты массива: \n");
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &data[i]);
    }

    quickSort(data, 0, n - 1,&nswap,&nif);
    printf("Ваш сортированный массив:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d  ", data[i]);
    }
    printf("\n");
    printf("Кол-во перестановок: %d\n", nswap);
    printf("Кол-во сравнений: %d", nif);
    return 0;
}
