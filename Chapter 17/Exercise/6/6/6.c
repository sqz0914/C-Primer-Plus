#include <stdio.h>
#include <windows.h>
int Seek_int(int Table[], int max, int Seek);
int main(void)
{
	int Table[10] = { 1, 3, 5, 6, 9, 13, 19, 21, 34, 45 };
	int num;

	for (num = 0; num < 100; num++)
	{
		if (Seek_int(Table, 10, num))
			printf("%d found!\n", num);
		else
			printf("%d not found!\n", num);
	}
	system("PAUSE");

	return 0;
}

int Seek_int(int Table[], int max, int Seek)
{
	int min = 0 , half;
	while (1)
	{
		half = (min + max) / 2;
		if (Seek < Table[half])
			max = half - 1;
		else if (Seek >Table[half])
			min = half + 1;
		else
			return 1;

		if (min == max - 1)
		{
			if (Seek == Table[min] || Seek == Table[max])
				return 1;
			else
				return 0;
		}
	}
}