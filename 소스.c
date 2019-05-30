#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define num 134//�ǹ� �� ����

struct building
{
	int buildingIndex;//�ǹ� ����
	char buildingNumber[7];//����+���ڸ�
	char buildingName[50];//�ѱ۸�
	char b_name[20];//�ǹ� �̸� �ӽ� ����
};
struct building Building[num];

void gotoxy(int x, int y)
{
	COORD Pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void LoadData()
{
	char* token;
	token = (char*)malloc(sizeof(Building));
	FILE* fp = fopen("BuildingName.txt", "r");

	for (int i = 0; i < num; i++)
	{
		fgets(Building[i].b_name, 50, fp);
		Building[i].buildingIndex = i;
	}

	for (int i = 0; i < num; i++)
	{
		token = strtok(Building[i].b_name, "/");
		strcpy(Building[i].buildingNumber, token);
		token = strtok(NULL, "\n");
		strcpy(Building[i].buildingName, token);
	}

	fclose(fp);
}

void DrawRectangle_Small()
{
	int c = 20, r = 7;//���簢���� ũ��
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (int i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	gotoxy(7, 3);
	printf("%c%c", a, b[3]);
	for (int i = 0; i < c - 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");

	for (int y = 4; y <= 10; y++)
	{
		gotoxy(7, y);
		printf("%c%c", a, b[2]);
	}
	gotoxy(7, 11); printf("%c%c", a, b[6]);

	for (int y = 4; y <= 11; y++)
	{
		gotoxy(26, y);
		printf("%c%c", a, b[2]);
	}

	gotoxy(8, 11);
	for (int i = 0; i < c - 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");

	gotoxy(32, 7);
	printf("-->");

	gotoxy(38, 3);
	printf("%c%c", a, b[3]);
	for (int i = 0; i < c - 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");

	for (int y = 4; y <= 10; y++)
	{
		gotoxy(38, y);
		printf("%c%c", a, b[2]);
	}
	gotoxy(38, 11); printf("%c%c", a, b[6]);

	for (int y = 4; y <= 10; y++)
	{
		gotoxy(57, y);
		printf("%c%c", a, b[2]);
	}
	gotoxy(57, 11); printf("%c%c", a, b[6]);

	gotoxy(39, 11);
	for (int i = 0; i < c - 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");

	gotoxy(13, 5);
	printf("<�����>");
	gotoxy(45, 5);
	printf("<������>");
}//���� �����1

void DrawRectangle_Big(int N)
{
	int c = 55, r = 30;//���簢���� ũ��
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (int i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	gotoxy(5, 15);
	printf("%c%c", a, b[3]);
	for (int i = 0; i < c - 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");

	for (int y = 16; y <= 40+N; y++)
	{
		gotoxy(5, y);
		printf("%c%c", a, b[2]);
	}

	for (int y = 16; y <= 40+N; y++)
	{
		gotoxy(59, y);
		printf("%c%c", a, b[2]);
	}

	gotoxy(5, 40+N);
	printf("%c%c", a, b[6]);
	for (int i = 0; i < c - 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");

}//���� �����2

void SearchData()
{
	char input[50] = { '\0' }, temp[50] = { '\0' };
	char name[20];
	int i, length, count = 0, count12 = 0;
	int n = 1;
	do
	{
		DrawRectangle_Small();
		DrawRectangle_Big(n);
		gotoxy(15, 16);

		printf("�ǹ� �̸��� �Է��ϼ���(ex : N14) : ");

		length = strlen(input);
		gotoxy(50 + length, 16);
		input[count] = getch();
		system("cls");
		gotoxy(50, 16);
		printf("%s", input);

		if (input[count] == 8)//�齺���̽� �Է� ��
		{
			printf("\b");
			fputs("  ", stdout);
			printf("\b");
			input[count - 1] = '\0';
			if (count > 0)
				count = count - 2;
			if (count = 0)
				input[0] = NULL;
			count = count - 1;
			length--;
		}

		if (input[count] == 13)//����Ű �Է� ��
		{
			strncpy(name, input, count);//�Է��� �ǹ����� name�� ����
			system("cls");
			DrawRectangle_Small();
			DrawRectangle_Big(n);
			gotoxy(20, 16);
			printf("�ǹ� �Է��� �Ϸ��մϴ�");
			gotoxy(15, 7);
			printf("%s", name);
			break;
		}

		printf("\n\n");
		for (int i = 0; i < num; i++)
		{
			if (input[count] >= 0 && input[count] <= 127)
			{
				if (input[count] == 'N')
					n = 11;
				else if (input[count] == 'E')
					n = 6;
				else if (input[count] == 'S')
					n = 41;
				strcpy(temp, Building[i].buildingNumber);
				if (strncmp(temp, input, count + 1) == 0)
				{
					printf("%30s\n", Building[i].buildingNumber);
				}
			}
			else if (input[count] == 8 || input[count] == 13)
				continue;
			else
			{
				n = 115;
				strcpy(temp, Building[i].buildingName);
				if (strncmp(temp, input, count + 1) == 0)
				{
					printf("%40s\n", Building[i].buildingName);
					n = n - 20;
				}
			}
		}
		count++;
	} while (1);

}
void main()
{
	system("mode con:cols=67");
	system("title �츮��07�� A+�� �츮��");
	system("color f0");

	LoadData();
	SearchData();
}