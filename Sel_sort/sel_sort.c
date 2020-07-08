#include <stdio.h>
#include <assert.h>
#include <malloc.h>

unsigned Min_element_pos(int* parr, unsigned len);
void Sel_step(int* arr, int i, int len);

void swap(int* num1, int* num2);

void Input(int* arr, int size);
void Output(int* arr, int size);


int main()
{
  int* buffer = NULL;
	int size = 0, pos = 0;

	scanf("%d", &size);

  buffer = (int*)calloc(size, sizeof(buffer[0]));
  assert(buffer);

	Input(buffer, size);


  for (pos = 0; pos < size; ++pos)
  {
	   Sel_step(buffer, pos, size);
  }

	Output(buffer, size);

	return 0;
}

unsigned Min_element_pos(int* parr, unsigned len)
{
	int minvalue = 0;
	unsigned i = 0, minpos = 0;

	assert(parr);
	assert(len > 0);

	minvalue = parr[0];
	minpos = 0;

	for (i = 1; i < len; ++i)
	{
		if (parr[i] < minvalue)
		{
			minpos = i;
			minvalue = parr[i];
		}
	}
	return minpos;
}

void Sel_step(int* arr, int i, int len)
{
	unsigned pos = Min_element_pos(arr + i, len - i) + i;

	assert(arr[pos] <= arr[i]);

	swap(arr + i, arr + pos);
}


void Input(int* arr, int size)
{
	int i = 0, elem = 0, check = 0;

	for (i = 0; i < size; i++)
	{
		check = scanf("%d", &elem);
    assert(check);

    arr[i] = elem;
	}
}

void Output(int* arr, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
