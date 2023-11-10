//Создать массив указателей на слова в строке и вывести их отдельно каждое в строках
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>

void search_word_in_string(const char* string, int* counter, const char* words[]);

int main()
{

	// Люблю писать на русском языке
	setlocale(LC_ALL, "Rus"); // Это для вывода слов
	SetConsoleCP(1251);          // С этой хренью начинает работать
	SetConsoleOutputCP(1251);    // русскоязычный ввод (надо будет погуглить)

	// Объявление переменных
	char string[81] = ""; // строка -_-
	const char* words[40]; // массив слов из строки
	int counter = 0; // счетчик слов в строке

	// Получить строку из консоли
	fgets(string, 81, stdin);

	// Вызов функции
	search_word_in_string(string, &counter, words);

	// Вывод слов
	for (int i = 0; i < counter; i++)
	{
		// Вывести слово
		while (*words[i] != '.' and *words[i] != ',' and *words[i] != ' ' and *words[i] != '\0')
		{
			printf("%c", *words[i]); // Вывести символ из слова
			words[i]++; // Перейти к следующему символу в слове
		}

		printf("\n"); // перейти к адресу следующего слова
	}

	if (counter == 0)
		printf("строка пустая -_-\n"); // вывод в случае того, если слов в строке нет

	return 0;

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