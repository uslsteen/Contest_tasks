#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>

void swap(char* elem1, char* elem2);

char* Input_for_str();
void Output_for_str(char* buffer);

char* KMP_Search(char const* needle, int const* needle_lps, char const* haystack);
void Pat_preproc(char const* needle , int* needle_lps);

int main()
{
    char* haystack = NULL, *needle = NULL;

    int check = 0, needle_size = 0, haystack_size = 0;
    int* needle_lps = NULL;

    /*Input of data*/
    printf("Input haystack data:\n");
    haystack = Input_for_str(&haystack_size);

    printf("Input needle data:\n");
    needle = Input_for_str(&needle_size);

    /*create lps[] that will hold the longest prefix suffix*/
    needle_lps = (int*)calloc(needle_size, sizeof(needle_lps[0]));
    assert(needle_lps);

    /*Realize of algorithm*/
    KMP_Search(needle, needle_lps, haystack);

    free(haystack);
    free(needle);
    free(needle_lps);

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

char* Input_for_str(int* size)
{
    char* buffer = NULL;
    int check = 0, i = 0;
    char elem = 0;

    check = scanf("%d%*c", size);
    assert(check);

    buffer = (char*)calloc(*size + 1, sizeof(char));
    assert(buffer);

    for (i = 0; i < *size; ++i)
    {
        check = scanf("%c", &elem);
        assert(check);

        buffer[i] = elem;
    }
    buffer[*size] = '\0';

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

// C program for implementation of KMP pattern searching
// algorithm


void Pat_preproc(char const* needle , int* needle_lps)
{
    // length of the previous longest prefix suffix
    int lps_size = strlen(needle);
    int i = 1, j = 0;

    assert(needle);
    assert(needle_lps);

    needle_lps[0] = 0; // needle_lps[0] is always 0

    while (i < lps_size)
    {
        if (needle[i] == needle[j])
        {
            needle_lps[i] = j + 1;
            i++;
            j++;
        }
        else // if (needle[i] != needle[j])
        {
            if (j != 0)
            {
                j = needle_lps[j - 1];
            }
            else // if (len == 0)
            {
                needle_lps[i] = 0;
                i++;
            }
        }
    }
}

char* KMP_Search(char const* needle, int const* needle_lps, char const* haystack)
{
    int needle_size = strlen(needle);
    int haystack_size = strlen(haystack);
    int i = 0, j = 0;

    assert(needle);
    assert(needle_lps);
    assert(haystack);

    // Preprocess the pattern (calculate needle_lps[] array)
    Pat_preproc(needle, needle_lps);

    while (i < haystack_size) {
        if (toupper(needle[j]) == toupper(haystack[i]))
        {
            j++;
            i++;
        }

        if (j == needle_size)
        {
            printf("Found pattern at index %d\n", i - j);
            j = needle_lps[j - 1];
        }

            // mismatch after j matches
        else if ((i < haystack_size) && (toupper(needle[j]) != toupper(haystack[i])))
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = needle_lps[j - 1];
            else if (j == 0)
            {
                i = i + 1;

                if (i == haystack_size)
                {
                    printf("I can't find this pattern in the string!\n");
                }
            }
        }
    }
    return NULL;
}
