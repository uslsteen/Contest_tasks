#ifndef __MERGE_SORT__
#define __MERGE_SORT__

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <iostream>
#include <string.h>

enum type
{
  INT = 0, STR = 1
};

  void Start_working(int* len, int* mode)
  {
    int check = 0;
    char name_of_type[5] = {0};

    printf("Please, select type of your data:\n");
    printf("int || str\n");

    scanf("%s", name_of_type);

    if (strcmp(name_of_type, "str") == 0)
    {
      *mode = STR;
    }
    else if (strcmp(name_of_type, "int") == 0)
    {
      *mode = INT;
    }
    else
    {
      printf("Unidentified type of data!\n");
      abort();
    }

    printf("Input size of your buffer:\n");
    check = scanf("%d", len);
    assert(check == 1);

  }

  template <typename Elem_t>
  void Input(Elem_t* arr, int len, int mode)
  {
    int i = 0, check = 0, elem = 0;

    printf("Input your data:\n");

    if (mode == STR)
    {
      scanf("%s", arr);
    }
    else if (mode == INT)
    {
      for (i = 0; i < len; i++)
      {
          check = scanf("%d", &elem);
          assert(check);

          arr[i] = elem;
      }
    }
    else
    {
      printf("Unidentified type of data in input!\n");
      abort();
    }
  }


  template <typename Elem_t>
  void Output(Elem_t* arr, int len, int mode)
  {
      int i = 0;

      assert(arr != NULL);
      assert(len >= 0);

      printf("Let's check result!\n");

      if (mode == INT)
      {
        for (i = 0; i < len; i++)
            printf("%d ", arr[i]);
      }
      else
      if (mode == STR)
      {
        printf("%s\n", arr);
      }
      else
      {
        printf("Unidentified type of data in 'output'!\n");
        abort();
      }
  }


  template <typename Elem_t>
  void swap(Elem_t* x, Elem_t* y)
  {
    int temp = 0;

    temp = *x;
    *x = *y;
    *y = temp;
  }


  template <typename Elem_t>
  void Merge(Elem_t* arr, int l, int m, int r)
  {
      int i = 0, j = 0, k = 0;
      int size_l = m - l + 1;
      int size_r = r - m;

      /* create temp buffers */

      Elem_t* temp_L = NULL, * temp_R = NULL;

      temp_L = (Elem_t*)calloc(size_l, sizeof(temp_L[0]));
      assert(temp_L);

      temp_R = (Elem_t*)calloc(size_r, sizeof(temp_R[0]));
      assert(temp_R);

      /* Copy data to temp buffers temp_L[size_l] and temp_R[size_r] */
      for (i = 0; i < size_l; i++)
          temp_L[i] = arr[l + i];

      for (j = 0; j < size_r; j++)
          temp_R[j] = arr[m + 1 + j];

      /* Merge the temp arrays back into arr[l..r]*/

      i = 0; // Initial index of first temp_buf
      j = 0; // Initial index of second temp_buf
      k = l; // Initial index of merged buffer
      while (i < size_l && j < size_r)
      {
          if (temp_L[i] <= temp_R[j])
          {
              arr[k] = temp_L[i];
              i++;
          }
          else
          {
              arr[k] = temp_R[j];
              j++;
          }

          k++;
      }

      /* Copy the remaining elements of temp_L[], if there are any */
      while (i < size_l)
      {
          arr[k] = temp_L[i];
          i++;
          k++;
      }

      /* Copy the remaining elements of temp_R[], if there are any */
      while (j < size_r)
      {
          arr[k] = temp_R[j];
          j++;
          k++;
      }

      free(temp_L);
      free(temp_R);
  }

  template <typename Elem_t>
  void Merge_sort(Elem_t* arr, int l, int r)
  {
    int m = (l + r)/2;

    if (l >= r)
      return;

    Merge_sort(arr, l, m);
    Merge_sort(arr, m + 1, r);

    Merge(arr, l, m, r);
  }

#endif //__MERGE_SORT__
