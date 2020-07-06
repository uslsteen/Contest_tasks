#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#pragma warning (disable : 4996)

void Init(int* arr, int len);
int Majority_Element(const int* parr, int len);

int main()
{
	int* arr = NULL;
	int len = 0, check = 0, res = 0;

	check = scanf("%d", &len);
	assert(check);

	arr = (int*)calloc(len, sizeof(int));
	assert(arr);
	
	Init(arr, len);
	res = Majority_Element(arr, len);

	printf("%d", res);

	return 0;
}

int Majority_Element(const int* parr, int len)
{
	int counter = 0, maj_elem = 0, i = 0;

	for (i = 0; i < len; i++)
	{
		if (counter == 0)
		{
			maj_elem = parr[i];
		}

		if (parr[i] == maj_elem)
		{
			counter++;
		}
		else
			counter--;
	}

	counter = 0;

	for (i = 0; i < len; i++)
	{
		if (parr[i] == maj_elem)
		{
			counter++;
		}
	}

	if (counter > len / 2)
	{
		return maj_elem;
	}
	else
		return -1;
}


void Init(int* arr, int len)
{
	int i = 0, num = 0;

	for (i = 0; i < len; i++)
	{
		scanf("%d", &num);
		arr[i] = num; 
	}
}