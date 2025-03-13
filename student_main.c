//测试unicode
//测试远程拉取请求

#include "student.h"

int main()
{
	int n = 0;
	int m = 0;
	int i, j;
	char ch, c;
	int first = 1;//标记系统中是否有学生成绩信息
	STU stu[STU_NUM];

	system("mode con cols = 130 lines = 60");
	system("color 0E");
	while (1)
	{
		system("cls");
		ch = Menu();
		switch (ch)
		{
		case 1:
			system("cls");
			InputRecord(&n, &m, stu);
			first = 0;
			system("pause");
			break;
		case 2:
			system("cls");
			if (first) {
				printf("系统中尚无学生成绩信息，请先输入\n");
				system("pause");
				break;
			}
			AppendRecord(&n, m, stu);
			system("pause");
			break;
		case 3:
			system("cls");
			if (first) {
				printf("系统中尚无学生成绩信息，请先输入\n");
				system("pause");
				break;
			}
			DeleteRecord(&n, m, stu);
			system("pause");
			break;
		case 4:
			system("cls");
			if (first) {
				printf("系统中尚无学生成绩信息，请先输入\n");
				system("pause");
				break;
			}
			SearchByNumber(n, m, stu);
			system("pause");
			break;
		case 5:
			system("cls");
			if (first) {
				printf("系统中尚无学生成绩信息，请先输入\n");
				system("pause");
				break;
			}
			SearchByName(n, m, stu);
			system("pause");
			break;
		case 6:
			system("cls");
			if (first) {
				printf("系统中尚无学生成绩信息，请先输入\n");
				system("pause");
				break;
			}
			ModifyRecord(n, m, stu);
			system("pause");
			break;
		case 7:
			system("cls");
			if (first) {
				printf("系统中尚无学生成绩信息，请先输入!\n");
				system("pause");
				break;
			}
			CalculateScoreOfStudent(n, m, stu);
			system("pause");
			break;
		case 8:
			system("cls");
			if (first) {
				SetPosition(POS_X3, POS_Y);
				printf("系统中尚无学生成绩信息，请先输入!\n");
				system("pause");
				break;
			}
			CalculateScoreOfCourse(n, m, stu);
			system("pause");
			break;
		case 9:
 			system("cls");
			if(first)
			{
				SetPosition(POS_X3,POS_Y);
				printf("系统中尚无学生成绩信息，请先输入！\n");
				_getch();
				break;
			}
			SortbyNum(n, m, stu);
			_getch();
			break;
		case 10:
		system("cls");
			if(first)
			{
				SetPosition(POS_X3,POS_Y);
				printf("系统中尚无学生成绩信息，请先输入！\n");
				_getch();
				break;
			}
			SortbyScore(n, m, stu);
			_getch();
			break;
		case 11:
			system("cls");
			if(first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("系统中尚无学生成绩信息，请先输入！\n");
				_getch();
				break;
			}
			SortbyScore(n, m, stu, Descending);
			_getch();
			break;
		case 12:
			system("cls");
			if(first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("系统中尚无学生成绩信息，请先输入！\n");
				_getch();
				break;
			}
			SortbyScore(n, m, stu, Ascending);
			_getch();
			break;
		case 13:
			system("cls");
			if(first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("系统中尚无学生成绩信息，请先输入!\n");
				_getch();
				break;
			}
			StatisticAnalysis(n, m, stu);
			_getch();
			break;
		case 14:
			system("cls");
			if (first) {
				printf("系统中尚无学生成绩信息，请先输入!\n");
				system("pause");
				break;
			}
			PrintRecord(n, m, stu);
			system("pause");
			break;
		case 15:
			system("cls");
			if (first) {
				SetPosition(POS_X3, POS_Y);
				printf("系统中尚无学生成绩信息，请先输入!\n");
				system("pause");
				break;
			}
			WritetoFile(n, m, stu);
			system("pause");
			break;
		case 16:
			system("cls");
			if (ReadfromFile(&n, &m, stu, &first) || first) {
				SetPosition(POS_X1, 10);
				printf("尚未输入学生信息或文件打开失败，请先检查\n");
				system("pause");
				break;
			}
			system("pause");
			break;
		case 0:
			system("cls");
			printf("推出系统！\n");
			exit(0);
		default:
			system("cls");
			printf("输入出错，请重新选择操作！\n");
			system("pause");
			break;
		}
	}
	return 0;
}