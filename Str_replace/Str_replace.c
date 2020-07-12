#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>

void swap(char* elem1, char* elem2);

char* Replace(char* str, char const* from, char const* to);

char* Input_for_str();
void Output_for_str(char* buffer);

int main()
{
    char* buffer = NULL, * from = NULL, * to = NULL;
    char* result = NULL;

    int check = 0;

    /*Input of data*/
    from = Input_for_str();
    to = Input_for_str();
    buffer = Input_for_str();

    result = Replace(buffer, from, to);

    /*Output of result*/
    Output_for_str(result);

    free(buffer);
    free(to);
    free(from);

    return 0;
}

void swap(char* elem1, char* elem2)
{
    char temp = 0;

    assert(elem1);
    assert(elem2);

    temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

char* Input_for_str()
{
    char* buffer = NULL;
    int size = 0, check = 0, i = 0;
    char elem = 0;

    check = scanf("%d%*c", &size);
    assert(check);

    buffer = (char*)calloc(size + 1, sizeof(char));
    assert(buffer);


    for (i = 0; i < size; ++i)
    {
        check = scanf("%c", &elem);
        assert(check);

        buffer[i] = elem;
    }
    buffer[size] = '\0';

    return buffer;
}

void Output_for_str(char* buffer)
{
    int i = 0;

    assert(buffer != NULL);

    for (i = 0; buffer[i] != '\0'; ++i)
    {
        printf("%c", buffer[i]);
    }
    printf("\n");
}

char* Replace(char* str, char const* from, char const* to)
{
    char* res = NULL, * str_ptr = NULL;
    int length = 0, counter = 0, res_size = 0;

    int from_size = strlen(from);
    int to_size = strlen(to);

    assert(str);
    assert(from);
    assert(to);

    /* counting num of word_from*/

    for (length = 0; str[length] != '\0'; ++length)
    {
        if (strstr(str + length, from) != NULL)
        {
            counter++;
            length += from_size - 1;
        }
    }

    res_size = length + abs(counter*(to_size - from_size)) + 1;

    res = (char*) calloc(res_size, sizeof(char));
    assert(res);

    length = 0;
    str_ptr = str;

    /*copy unchanged data from str to res*/
    /*replacing from and to*/

    while(*str_ptr != '\0')
    {
        if (strstr(str_ptr, from) == str_ptr)
        {
            strcpy(res + length, to);
            length += to_size;
            str_ptr += from_size;
        }
        else
        {
            res[length++] = *str_ptr++;
        }
    }
    res[length] = '\0';

    return res;
}

