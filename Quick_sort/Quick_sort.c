#include <stdio.h>
#include <assert.h>
#include <malloc.h>

void Quick_sort(int *arr, unsigned low, unsigned high);
unsigned Partition(int* arr, unsigned low, unsigned high);

void Input(int* arr, int len);
void Output(int* arr, int len);

void swap(int* x, int* y);

int main()
{
    int* buffer = NULL;
    int len = 0, check = 0;

    printf("Input size of your buffer:\n");
    check = scanf("%d", &len);
    assert(check == 1);

    buffer = (int*)calloc(len, sizeof(buffer[0]));
    assert(buffer);

    Input(buffer, len);

    Quick_sort(buffer, 0, len - 1);

    Output(buffer, len);

    free(buffer);
    return 0;
}


void Input(int* arr, int len)
{
    int i = 0, check = 0, num = 0;

    printf("Input your data:\n");

    for (i = 0; i < len; i++)
    {
        check = scanf("%d", &num);
        assert(check);
        arr[i] = num;
    }
}

void Output(int* arr, int len)
{
    int i = 0;

    assert(arr != NULL);
    assert(len >= 0);

    printf("RESULT!\n");

    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Quick_sort(int* arr, unsigned low, unsigned high)
{
    if (low >= high)
        return;

    unsigned pos = Partition(arr, low, high);

    if (pos > low)
    {
        Quick_sort(arr, low, pos - 1);
    }
    Quick_sort(arr, pos + 1, high);
}


unsigned Partition(int* arr, unsigned low, unsigned high)
{
    unsigned pivot = low, begin = low, end = high;

    while (begin < end)
    {
        while ((arr[begin] <= arr[pivot]) && (begin <= high))
            begin++;

        while ((arr[end] > arr[pivot]) && (end >= low))
            end--;

        if (begin < end)
            swap(arr + begin, arr + end);
    }

    swap(arr + end, arr + pivot);

    return end;
}

void swap(int* x, int* y)
{
    int temp = 0;

    temp = *x;
    *x = *y;
    *y = temp;
}

