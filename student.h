#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include <conio.h>

#define MAX_VAL 1000
#define STU_NUM 50
#define COURSE_NUM 10
#define NAME_LEN 10
#define POS_X1 35
#define POS_X2 40
#define POS_X3 50
#define POS_X4 65
#define POS_Y 3

typedef struct student
{
	long num;
	char name[NAME_LEN];
	float score[COURSE_NUM];
	float sum;
	float aver;
	struct student* Next;
}STU;

int Menu(void);
void SetPosition(int x, int y);
void InputRecord( int* n, int* m,STU stu[]);
void AppendRecord( int* n, int m, STU stu[]);
void DeleteRecord( int* n, int m, STU stu[]);
void SearchByNum( int n, int m, STU stu[]);
void SearchByName( int n, int m, STU stu[]);
void ModifyRecord( int n, int m, STU stu[]);
void CalculateScoreOfStudent( int n, int m, STU stu[]);
void CalculateScoreOfCourse( int n, int m, STU stu[]);
void SortByNumber(STU stu[], int n, int m);
void SortByName(STU stu[], int n, int m);
void SortByScore(STU stu[], int n, int m, int (*compare)(float a, float b));
int Ascending(float a, float b);
int Descending(float a, float b);
void StatisticAnalysis(int n, int m,STU stu[]);
void PrintRecord( int n, int m, STU stu[]);
void WritetoFile( int n, int m, STU stu[]);
int ReadfromFile( int* n, int* m, STU stu[],int *first);
void Hide();

