#include "reverse.h"
#include <string.h>
#include <stdlib.h>

char* strrev(const char* string) 
{
    int length = strlen(string);
    char* temp = (char*)malloc(sizeof(char) * (length + 1)); // +1 for null terminator
    for (int i = 0; i < length; i++) {
	temp[(length - 1) - i] = string[i];
    }
    temp[length] = '\0';
    return temp;
}

