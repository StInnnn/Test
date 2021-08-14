#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <locale.h>

	int main(void) {
		setlocale(LC_ALL,"rus");
		int n; //число будущих массивов
		int m; //длина массива
		printf_s("\n Введите натуральное число n: ");
		scanf_s("%d", &n);
		int** lesenka = NULL;
		int* dlinales = NULL;
		lesenka = (int**)calloc(n, sizeof(int*));
		dlinales = (int*)calloc(n, sizeof(int)); // для хранения размера строк

		if (lesenka == NULL || dlinales == NULL) {
			printf_s("\n Out of memory. Error. Press any key to exit: ");
			system("pause>nul");
			exit(1); // аварийный выход из программы
		}

		int a = 3; //длина ступеньки
		
		for (int i = 0; i < n; ++i) {
			m = a++; 
			
			dlinales[i] = m;
			lesenka[i] = (int*)calloc(m, sizeof(int));
			if (lesenka[i] == NULL) {
				lesenka = NULL;
				printf_s("\n Press any key to exit: ");
				system("pause>nul");
				exit(2);
			}
		}
		srand((unsigned)123);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < dlinales[i]; ++j) {
				lesenka[i][j] = rand()%50; 
			}
		}
		for (int i = 0; i < n; i++)
		{
			
			if ((i+1) % 2 != 0) //нечетный-убывание, четный- возрастание
			{
				for (int o = 0; o < dlinales[i] - 1; o++)
					for (int j = 0; j < dlinales[i] - 1; j++)
					{
						int tmp;
						if (lesenka[i][j] < lesenka[i][j + 1])
						{
							tmp = lesenka[i][j];
							lesenka[i][j] = lesenka[i][j + 1];
							lesenka[i][j + 1] = tmp;
						}
					}
			}
			else {
				for (int o = 0; o < dlinales[i] - 1; o++)
					for (int j = 0; j < dlinales[i] - 1; j++)
					{
						int tmp;
						if (lesenka[i][j] > lesenka[i][j + 1])
						{
							tmp = lesenka[i][j];
							lesenka[i][j] = lesenka[i][j + 1];
							lesenka[i][j + 1] = tmp;
						}
					}
			}
			}
	
		printf_s("\n Итог:\n\n");
		
		for (int i = 0, k = 0; i < n; ++i) {
			printf_s("%4i)", ++k);
			for (int j = 0; j < dlinales[i]; ++j) {
				printf_s("%4li", *(lesenka[i] + j));
			}
			printf_s("\n");
		}
		
		free(dlinales);	
		for (int i = 0; i < n; ++i) {
			free(lesenka[i]);
		}
		free(lesenka);
		printf_s("\n\n Press any key to exit: ");
		return(0);
		
	}


