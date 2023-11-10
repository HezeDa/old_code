//Создать массив указателей на слова в строке и вывести их отдельно каждое в строках
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>

void test_search_word_in_string();
void search_word_in_string(const char* string, int* counter, const char* words[]);

int main()
{
	// Тестирование функции
	test_search_word_in_string();

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

void test_search_word_in_string()
{
	setlocale(LC_ALL, "Rus");

	// Тестовые данные
	char test_strings[5][81] = { "ass ass ass", "\n", "ass", "., ", "ass ass ass ass ass ass ass ass ass ass ass ass ass ass ass ass ass ass ass ass " };
	const char* words_in_string[40];
	int counter_words_in_string = 0;

	// Результат
	int counter[5] = { 3, 0, 1, 0, 20 };
	int is_ok = 1;
	char* pointer;

	for (int i = 0; i < 5; i++)
	{
		search_word_in_string(test_strings[i], &counter_words_in_string, words_in_string);
		if (counter_words_in_string != counter[i])
			is_ok = 0;
		if (counter[i] == 0)
			pointer = 0;
		else
			pointer = &test_strings[i][0];
		printf("Тест %d : адрес теста %p, ", i + 1, pointer);
		printf("адрес ожидаемый %p, количество слов: тестовые %d, ожидаемые %d\n", words_in_string[0], counter_words_in_string, counter[i]);
		counter_words_in_string = 0;
		words_in_string[0] = 0;
	}

	if (is_ok == 0)
		printf("Что-то пошло не так -_- \n");
	else
		printf("Функция работает исправно \n");
}