#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <assert.h>

void Str_rev(char* buffer, char* needle, int needle_size);
char* Word_rev(char* string, int size);

void swap(char* str_input, char* str_find);

void Input(char* text, int size);
void Output(char* buffer, int size);

int main()
{
    char* needle = NULL;
    char* buffer = NULL;
    int needle_size = 0, buf_size = 0, i = 0, lenght = 0;

    scanf("%d%*c", &needle_size);

    needle = (char*)calloc(needle_size + 1, sizeof(needle[0]));
    assert(needle);

    Input(needle, needle_size + 1);

    scanf("%d%*c", &buf_size);

    buffer = (char*)calloc(buf_size + 1, sizeof(buffer[0]));
    assert(buffer);

    Input(buffer, buf_size + 1);

    Str_rev(buffer, needle, needle_size);

    Output(buffer, buf_size);

    free(buffer);
    free(needle);

    return 0;
}

void Str_rev(char* buffer, char* needle, int needle_size)
{
    int length = 0;
    char* str_ptr = NULL;

    assert(buffer);
    assert(needle);
    assert(needle_size > 0);

    while ((str_ptr = strstr(buffer + length, needle)) != NULL)
    {
        Word_rev(str_ptr, needle_size);
        length = (str_ptr - buffer + needle_size);
    }
}

char* Word_rev(char* string, int size)
{
    int i = 0;

    for (i = 0; i < size / 2; i++)
    {
        swap(string + i , string + size - i - 1);
    }

    return string;
}

void swap(char* str_input, char* str_find)
{
    char temp = 0;

    assert(str_input);
    assert(str_find);

    temp = *str_input;
    *str_input = *str_find;
    *str_find = temp;
}

void Input(char* buffer, int size)
{
    int i = 0;

    assert(buffer != NULL);
    assert(size != 0);

    for (i = 0; i < size - 1; i++)
    {
        scanf("%c", &buffer[i]);
    }

    buffer[size] = '\0';
}


void Output(char* buffer, int size)
{
    int i = 0;

    assert(buffer != NULL);
    assert(size != 0);

    for (i = 0; i < size; i++)
    {
        printf("%c", buffer[i]);
    }
    printf("\n");
}
