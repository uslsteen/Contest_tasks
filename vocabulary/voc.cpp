#include "voc.h"



void Input(const char* in, const char* type, char* text)
{
	int result_of_input = 0;

	assert(in != NULL);
	assert(type != NULL);
	assert(text != NULL);

	printf(in);

	if ((result_of_input = scanf(type, text)) != 1)
	{
		printf("Error in input name of file!\n");
		assert(result_of_input != 1);
	}
}


char* Create_Buffer(const char* name_of_file, size_t* file_size)
{
	assert(name_of_file != NULL);

	FILE* file = fopen(name_of_file, "rb");

	if (file == NULL)
	{
		printf("Error\n");
		return NULL;
	}

	int num_of_symb = Lenght_Of_File(file);

	if (num_of_symb == 0)
	{
		printf("Error with counting symbols\n");
		return NULL;
	}

	char* buf = (char*)calloc(num_of_symb + 1, sizeof(buf[0]));
	assert(buf);

	int reading_size = fread(buf, sizeof(buf[0]), num_of_symb, file);

	*file_size = reading_size;
	fclose(file);

	return buf;
}


int Lenght_Of_File(FILE* file)
{
	assert(file != NULL);

	fseek(file, 0, SEEK_END);

	int lenght = ftell(file);

	if (lenght <= 0)
	{
		printf("Error with fseek fucntion\n");
		return 0;
	}

	rewind(file);

	return lenght;
}


Lines* Create_Ptr_Buf(char* buf, size_t buf_size, size_t* str_cnt, char end_value)
{
	assert(buf != NULL);
	assert(buf_size != 0);
	assert(str_cnt != NULL);

	int num_of_strs = String_Counter(buf, buf_size, end_value);
	int real_str = 0;

	Lines* ptrs_buffer = (Lines*)calloc(num_of_strs, sizeof(ptrs_buffer[0]));
	assert(ptrs_buffer != NULL);

	char* s = (char*)memchr(buf, end_value, buf_size);

	char* prev = buf;
	char prevch = 0, pre_prevch = 0;

	if (s != buf && s != NULL)
	{
		prevch = *(s - 1);
	}

	if (s != buf + 1 && s != NULL)
	{
		prevch = *(s - 2);
	}

	while (s != NULL)
	{
		ptrs_buffer[real_str].line_ptr = prev;
		ptrs_buffer[real_str++].len = s - prev + 1;

		if ((prevch == '\n' || prevch == '\r') && pre_prevch == '\n')
		{
			real_str--;
		}

		prev = s + 1;

		s = (char*)memchr(s + 1, end_value, buf_size - (s - buf) - 1);

		if (s != NULL)
		{
			prevch = *(s - 1);
			pre_prevch = *(s - 2);
		}
	}

	s = (char*)memchr(prev, 0, buf_size - (s - buf) - 1);

	if (*(s - 1) != '\n')
	{
		ptrs_buffer[real_str].line_ptr = prev;
		ptrs_buffer[real_str++].len = s - prev + 1;
	}

	*str_cnt = real_str;
	return ptrs_buffer;
}



int String_Counter(const char* buffer, size_t buffer_size, char symbol)
{
	assert(buffer != NULL);
	assert(buffer_size != 0);

	int str_counter = 0;

	char* s_ptr = (char*)memchr(buffer, symbol, buffer_size);
	while (s_ptr != NULL)
	{
		str_counter++;
		s_ptr = (char*)memchr(s_ptr + 1, symbol, buffer_size - (s_ptr - buffer) - 1);
	}

	if (buffer[buffer_size - 1] != symbol)
	{
		str_counter++;
	}

	return str_counter;
}


int Searching(char* buffer, char* needle)
{
	assert(buffer != NULL);
	assert(needle);

	char* temp = NULL;
	int counter = 0;

	
	temp = buffer;

	while ((temp = strstr(temp, needle)) != NULL)
	{
		counter++;
		temp++;
	}

	return counter;
}


void Start_Working(const char* name_in1_file,const char* name_in2_file, const char* name_out_file)
{
	char* buffer1 = NULL, * buffer2 = NULL;
	char needle[MAX_NAME] = { {0} };

	size_t file_size1 = 0, file_size2 = 0;
	size_t num_of_strs2 = 0;

	int counter = 0, index = 0, check = 0;
	size_t i = 0;

	struct listnode* HASHTABLE[HASHTAB_SIZE];

	Hashtab_Init(HASHTABLE);

	assert(name_in1_file);
	assert(name_in2_file);
	assert(name_out_file);

	buffer1 = Create_Buffer(name_in1_file, &file_size1);
	assert(buffer1);

	buffer2 = Create_Buffer(name_in2_file, &file_size2);
	assert(buffer2);

	Lines* text2 = Create_Ptr_Buf(buffer2, file_size2, &num_of_strs2, '\n');
	assert(text2);

	for (i = 0; i < num_of_strs2; i++)
	{

		if ((check = sscanf(text2[i].line_ptr, "%s", needle)) != 1)
		{
			printf("Error in scanf from text2!\n");
			return;
		}

		counter = Searching(buffer1, needle);

		index = Hashtab_Push(HASHTABLE, needle, counter, text2[i].len);
		Put_Table_Into_File(HASHTABLE, name_out_file, index);

		Hashtable_Delete(HASHTABLE, needle, text2[i].len);
	}

	free(text2);
	free(buffer1);
	free(buffer2);

}


int Hashtab_Hash(char* key, int length_of_key)
{
	int h = 0;
	char* p = NULL;

	assert(key != NULL);

	for (p = key; p - key + 1 != length_of_key; p++)
	{
		h = h * HASHTAB_MUL + (int)* p;
	}

	return (h % HASHTAB_SIZE);
}


void Hashtab_Init(struct listnode** hashtable)
{
	for (int i = 0; i < HASHTAB_SIZE; i++)
	{
		hashtable[i] = NULL;
	}
}


int Hashtab_Push(struct listnode** hashtab, char* key, int value, int length_of_key)
{
	struct listnode* new_node;

	assert(hashtab != NULL);
	assert(key != NULL);

	int index = Hashtab_Hash(key, length_of_key);


	new_node = (struct listnode*) calloc(1, sizeof(struct listnode));

	if (new_node != NULL)
	{
		new_node->next = hashtab[index];
		hashtab[index] = new_node;

		new_node->key = key;
		new_node->value = value;
	}

	return index;
}


void Put_Table_Into_File(struct listnode** hashtab, const char* name_file_out, int index)
{
	FILE* out = fopen(name_file_out, "ab");

	assert(hashtab);

	if (out == NULL)
	{
		printf("error with file opening!\n");
		return;
	}


	fprintf(out, "word(keys): %s	|	 hash: %d		|	 amount in text:%d%c", hashtab[index]->key, index, hashtab[index]->value, '\n');

	fclose(out);
}



void Hashtable_Delete(struct listnode** hashtab, char* key, int length_of_key)
{
	int index = 0;
	struct listnode* p, * prev = NULL;

	assert(hashtab);
	assert(key);

	index = Hashtab_Hash(key, length_of_key);

	for (p = hashtab[index]; p != NULL; p = p->next) 
	{
		if (strcmp(p->key, key) == 0)
		{
			if (prev == NULL)
			{
				hashtab[index] = p->next;
			}
			else
				{
					prev->next = p->next;
					free(p);
					return;
				}
		}

		prev = p;
	}
}
