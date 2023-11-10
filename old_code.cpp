//Создать массив указателей на слова в строке и вывести их отдельно каждое в строках
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>

void search_word_in_string();

int main()
{


}

void search_word_in_string(const char* string, int* counter, const char* words[])
{
	int length_word = 0;

	for (int i = 0; string[i] != '\0'; i++)
	{
		if (string[i] != ' ' && string[i] != ',' && string[i] != '.' && string[i] != '\0' && string[i] != '\n' and not(isalnum(string[i])))
		{
			if (length_word == 0)
			{
				words[(*counter)] = &string[i];
				(*counter)++;
			}
			length_word++;
		}
		else
		{
			length_word = 0;
		}

		while (isalnum(string[i]))
			i++;
	}

}