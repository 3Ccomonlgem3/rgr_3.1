#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#define pi acos(-1);
int main(void)
{
	system("chcp 1251>nul");

	double r, L, U, f, Xl,e,si;
	double E[16], I[16];
	int a, b, c;
	double rezistor[16];
	double minRezistor;
	int countRezistor = 0;
	int lenghtR = 0;
	int menu;
	int menuI = 0;
	printf("РГР, задание_3, вариант 14\n");
	printf("------------------------------------------------------------\n");
		do
		{
			/*system("cls");*/
			printf("1 - Ввод данных \n");
			printf("2 - Вывод данных \n");
			printf("3 - Произвести расчеты \n");
			printf("4 - выход \n");
			printf("=====================================================================\n");
			scanf("%d", &menu);
			switch (menu)
			{
			case 1:
				printf("Введите количество значений активного сопротивления от 1 до 15 :\n");
					if (scanf("%d", &lenghtR) != 1 || lenghtR < 1 || lenghtR>15)
					{
						
						printf("Некоректный ввод, выберите пункт из меню...\n");
						continue;
					}
				// значений активного сопротивления добовляем в массив
				for (int i = 1; i <= lenghtR; i++)
				{
					printf("Введите R%d=", i);
					if (scanf("%lf", &rezistor[i]) != 1 || rezistor[i] < 0)
					{
						
						printf("Некоректный ввод...\n");
						continue;
					}
				}
				// находим минимальное сопротивление
				minRezistor = rezistor[1];
				for (int i = 2; i <= lenghtR; i++)
				{
					if (minRezistor > rezistor[i]) { minRezistor = rezistor[i]; }
				}
				// находим колличество минимальных сопротивлений
				for (int i = 1; i <= lenghtR; i++)
				{
					if (minRezistor == rezistor[i]) { countRezistor++; }
				}

				printf("Колличество минимальных значений сопротивления = %d\n", countRezistor);

				printf("Введите целую часть 'a' и дробную часть 'b' для значения индуктивности L\n от 0 до 100\n");
				printf("  a = ");
				if (scanf("%d", &a) != 1 || a < 0 || a > 100)  //scanf возвращает 1 или 0, 1 если полученны корректные данные, 0 если полученны не корректные данные
				{
					
					printf("\t\tНекорректные данные!\n");
					continue;
				}
				printf("  b = ");
				if (scanf("%d", &b) != 1 || b < 0 || b > 100)
				{
				
					printf("\t\tНекорректные данные!\n");
					continue;
				}
				if (a == 0 && b == 0) {
					
					printf("\t\tНекорректные данные!\n");
					continue;
				}
				printf("------------------------------------------------------------\n");
				//индуктивность l
				printf("Введите индуктивность L = ");
				if (scanf("%lf", &L) != 1 || L < 0)
				{
					
					printf("\t\tНекорректные данные!\n");
					continue;
				}
				//напряжение u
				printf("Введите напряжение U = ");
				if (scanf("%lf", &U) != 1 || U < 0)
				{
					
					printf("\t\tНекорректные данные!\n");
					continue;
				}
				//частота f
				printf("Введите частоту f = ");
				if (scanf("%lf", &f) != 1 || f < 0)
				{
					
					printf("\t\tНекорректные данные!\n");
					continue;
				}
				menuI = 1;
				break;
			case 2:
				if (menuI == 0)
				{
					printf("Первым делом введи данные, потом вывод...\n");
					break;
				}
				else
				{
					printf(" L = %0*.*lf\n U = %5.*lf\n f = %.1lf\n", a + b + 1, b, L, 7 - 5 - 1, U, f);
					printf("Колличество минимальных значений сопротивления = %d\n", countRezistor);
				}
				break;
				menuI = 2;
			case 3:
				if (menuI == 0)
				{
					printf("Первым делом введи данные, потом проверь их в выводе, а потом расчитывай...\n");
					break;
				}
				else
				{
					printf("Реактивное значение катушки 'Xl' вычисляется по формуле:\n  Xl=2пfL\n");
					Xl = f * L * 2 * pi;
					printf("  Xl = %lf\n", Xl);
					for (int i = 1; i <= lenghtR; i++)
					{
						printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

						r = rezistor[i];
						printf("\t\tРасчет N%d для активного сопротивления r = % .1lf\n\n", i, r);

						printf("Сила тока 'I' в цепи вычисляется по формуле:\n  I = U/(r^2+Xl^2)^1/2\n");
						I[i] = U / sqrt(r * r + Xl * Xl);
						si = I[i];
						printf("  I = %7.3lf\n", I[i]);

						printf("ЭДС самоиндукции 'E' вычисляется по формуле:\n  |E|=|Ul|=|I*Xl|\n");
						E[i] = fabs(I[i] * Xl);
						e = E[i];
						printf("  |E| = %.3lf\n", E[i]);

					}
					printf("------------------------------------------------------------\n");
					printf("┌───────────┬───────────┬───────────┐\n");
					printf("│     E     │     I     │     r     │\n");
					printf("├───────────┼───────────┼───────────┤\n");
					printf("│|E| = %.3lf│I = %7.3lf │r = %.1lf  │\n", e,si, r);
					printf("└───────────┴───────────┴───────────┘\n");
					printf("Колличество минимальных значений сопротивления = %d\n", countRezistor);
					menuI = 2;
					system("pause");
				}
				menuI = 3;
				break; 
			case 4:
				printf("ну и прощай...\n");
				break;
			default:
				printf("выбери другое!\n");
			}
			if (menu != 4) {
				printf("\nНажмите Enter...\n");
				getchar();
				getchar();
			}
		} while (menu != 4);
		return 0;
		
	system("pause");

	return 0;
}