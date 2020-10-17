//#ifndef __VOC_H__
//#define __VOC_H__
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>

#pragma warning (disable: 4996 4090)

typedef struct
{
	char* line_ptr;
	size_t len;
} Lines;


struct listnode
{
	char* key;
	int value;

	struct listnode* next;
};

const int HASHTAB_SIZE = 71;
const int HASHTAB_MUL = 31;
const int MAX_NAME = 30;


//working with strings functions__________________________________________________________________

void Input(const char* in, const char* type, char* text);

char* Create_Buffer(const char* name_of_file, size_t* file_size);

int Lenght_Of_File(FILE* file);

int String_Counter(const char* buffer, size_t buffer_size, char symbol);

Lines* Create_Ptr_Buf(const char* buffer, size_t buffer_size, size_t* counter_of_strs, char symbol);

int Searching(char* buffer, char* needle);

//______________________________________________________________________________________________

//Hashtable functions___________________________________________________________________________

int Hashtab_Hash(char* key, int length_of_key);

void Hashtab_Init(struct listnode** hashtable);

int Hashtab_Push(struct listnode** hashtable, char* key, int value, int lenght_of_key);

void Hashtable_Delete(struct listnode** hashtable, char* key, int length_of_key);

//________________________________________________________________________________________________


//others__________________________________________________________________________________________

void Start_Working(const char* name_in1_file, const char* name_in2_file, const char* name_file_out);

void Put_Table_Into_File(struct listnode** hashtable, const char* name_file_out, int index);
//________________________________________________________________________________________________

//#endif 
