#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void Input(int* arr, int len);
void Output(int* arr, int len);

void Insertion_sort(int* arr, int len);
int Move_right(int* arr, int key, int last);

int main()
{
    int* buffer = NULL;
    int len = 0, check = 0;

    check = scanf("%d", &len);
    assert(check == 1);

    buffer = (int*)calloc(len, sizeof(buffer[0]));
    assert(buffer);

    Input(buffer, len);

    Insertion_sort(buffer, len);

    Output(buffer, len);

    return 0;
}


void Input(int* arr, int len)
{
    int i = 0, check = 0, num = 0;

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

    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Insertion_sort(int* arr, int len)
{
    int i = 0, pos = 0, key = 0;

    for(int i = 0; i < len; ++i)
    {
        key = arr[i];
        pos = Move_right(arr, key, i);
        arr[pos] = key;
    }
}

int Move_right(int* arr, int key, int last)
{
    int i = 0;

    for (i = last - 1; i >=0; i--)
    {
        if (arr[i] <= key)
            break;

        arr[i + 1] = arr[i];
    }

    return i+1;
}