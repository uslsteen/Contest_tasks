#include "merge_sort.h"

//Merge-sortion algorithm

int main()
{
    int len = 0, check = 0, mode = 0;

    Start_working(&len, &mode);
//------------------------------------------------

    if (mode == INT)
    {
      int* buffer = (int*)calloc(len, sizeof(int));
      assert(buffer);

      Input(buffer, len, mode);

      Merge_sort(buffer, 0, len - 1);

      Output(buffer, len, mode);

      free(buffer);

    }
    else if (mode == STR)
    {
      char* buffer = (char*)calloc(len + 1, sizeof(int));
      assert(buffer);

      Input(buffer, len, mode);

      Merge_sort(buffer, 0, len - 1);

      Output(buffer, len, mode);

      free(buffer);
    }
    else
    {
      printf("Unidentified type of data in 'Start_working'!\n");
      abort();
    }

//------------------------------------------------

    return 0;
}
