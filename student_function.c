#include "student.h"

void SetPosition(int x, int y) {
	HANDLE hout;
	COORD cor;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cor.X = x;
	cor.Y = y;
	SetConsoleCursorPosition(hout, cor);
}
//隐藏光标
void Hide()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cor_info = { 1,0 };
	SetConsoleCursorInfo(hout, &cor_info);
}
//主菜单
int Menu() 
{
	int posy = 5;
	int option;		//保存用户输入的操作代码的变量
	int i, j;
	SetPosition(POS_X3, posy);
	printf("学生成绩管理系统\n"); //输入系统名字
	//输出系统名字和功能说明之间的两行短横线
	for (i = 0;i < 2;i++) {
		SetPosition(POS_X1, ++posy);
		for (j = 0;j < 55;j++) {
			printf("-");
		}
	}
	//输出系统支持的功能和对应的功能代码
	SetPosition(POS_X1, ++posy);
	printf("1. 输入学生信息");
	SetPosition(POS_X4, posy);
	printf("2. 增加学生信息");
	SetPosition(POS_X1, posy += 2);
	printf("3. 删除学生信息");
	SetPosition(POS_X4, posy);
	printf("4. 按学号查找记录");
	SetPosition(POS_X1, posy += 2);
	printf("5. 按姓名查找记录");
	SetPosition(POS_X4, posy);
	printf("6. 修改学生信息");
	SetPosition(POS_X1, posy += 2);
	printf("7. 计算学生成绩");
	SetPosition(POS_X4, posy);
	printf("8. 计算课程成绩");
	SetPosition(POS_X1, posy += 2);
	printf("9. 按学号排序");
	SetPosition(POS_X4, posy);
	printf("10. 按姓名排序");
	SetPosition(POS_X1, posy += 2);
	printf("11. 按总成绩降序排序");
	SetPosition(POS_X4, posy);
	printf("12. 按总成绩升序排序");
	SetPosition(POS_X1, posy += 2);
	printf("13. 学生成绩统计");
	SetPosition(POS_X4, posy);
	printf("14. 打印学生记录");
	SetPosition(POS_X1, posy += 2);
	printf("15. 学生记录存盘");
	SetPosition(POS_X4, posy);
	printf("16. 从磁盘读取学生记录");
	SetPosition(POS_X1, posy += 2);
	printf("0. 退出");
	//输出系统支持的功能与输入提示语之间的两行短横线
	for (i = 0;i < 2;i++) {
		SetPosition(POS_X1, ++posy);
		for (j = 0;j < 55;j++) {
			printf("-");
		}
	}
	//提示用户所要执行的功能代码
	SetPosition(POS_X1, ++posy);
	printf("请选择你想要进行的操作[0-16]: [    ]\b\b\b\b\b");
	scanf_s("%d", &option);
	return option;
}//可以使用easyx更改的.
//输入学生信息
void InputRecord(int* n, int* m, STU* stu, STU* head) 
{
	int i, j;
	int posy = 6;
	SetPosition(POS_X2, posy);
	printf("输入学生人数（n<%d）: ", STU_NUM);
	while (~scanf_s("%d", n)) {
		if (*n <= 50 && *n > 0) {
			break;
		}
		else if (*n == 0) {
			system("cls");
			SetPosition(POS_X2, posy);
			printf("没有信息吗???");
		}
		else if (*n < 0) {
			system("cls");
			SetPosition(POS_X2, posy);
			printf("你家负一个人");
		}
		else {
			system("cls");
			SetPosition(POS_X2, posy);
			printf("不是哥们,咱们班几个人");
		}
		SetPosition(POS_X2, posy + 1);
		system("pause");
		system("cls");
		SetPosition(POS_X2, posy);
		printf("输入学生人数(n<%d): ", STU_NUM);
	}
	SetPosition(POS_X2, posy += 2);
	printf("输入课程门数（m<%d）:", COURSE_NUM);
	while (~scanf_s("%d", m)) {
		if (*m <= 50 && *m > 0) {
			break;
		}
		else if (*m == 0) {
			system("cls");
			SetPosition(POS_X2, posy);
			printf("没有信息吗???");
		}
		else if (*m < 0) {
			system("cls");
			SetPosition(POS_X2, posy);
			printf("你们班负一个课程");
		}
		else {
			system("cls");
			SetPosition(POS_X2, posy);
			printf("不是哥们,咱们几个课程");
		}
		SetPosition(POS_X2, posy + 1);
		system("pause");
		system("cls");
		SetPosition(POS_X2, posy - 2);
		printf("输入学生人数(n<%d): %d", STU_NUM, *n);
		SetPosition(POS_X2, posy);
		printf("输入课程门数(m<%d): ", COURSE_NUM);
	}
	for (i = 0; i < 2; i++) {
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++) {
			printf("-");
		}
	}
	SetPosition(POS_X2, ++posy);
	printf("输入学生的学号、姓名和各门课程成绩：");
	for (i = 0; i < *n; i++) {
		SetPosition(POS_X2, ++posy);
		printf("输入第%d个学生信息：\t", i + 1);
		STU* temp = (STU*)malloc(sizeof(STU));
		if (temp == NULL) {
			printf("内存分配失败！\n");
			exit(1);
		}
		scanf_s("%ld %s", &temp->num, temp->name, (unsigned)_countof(temp->name));//指定大小防止溢出
		for (j = 0; j < *m; j++) {
			scanf_s("%f", &temp->score[j]);
		}
		if (stu == NULL)
		{
			stu = temp;
			head->prior = NULL;
			head->next = stu;
			stu->prior = head;
		}
		else
		{
			temp->prior = stu;
			stu->next = temp;
			temp->next = NULL;
			stu = temp;
		}
	}
	SetPosition(POS_X2, ++posy);
	printf("输入完毕!\n");
	system("pause");
}
//计算学生成绩
void CalculateScoreOfStudent(int n, int m, STU* stu) {
	int i, j;
	printf("每个学生各门课程的总分和平均分：\n");
	for (i = 0;i < n;i++) {
		stu[i].sum = 0;
		for (j = 0;j < m;j++) {
			stu[i].sum += stu[i].score[j];
		}
		stu[i].aver = stu[i].sum / m;
		printf("第%d个学生：总分=%.2f, 平均分=%.2f\n", i + 1, stu[i].sum, stu[i].aver);
	}
}
//计算课程成绩
void CalculateScoreOfCourse(int n, int m, STU stu[]) {
	int i, j;
	float sum[COURSE_NUM], aver[COURSE_NUM];
	int posy = 7;
	SetPosition(POS_X1, posy);
	printf("各门课程的总分和平均分的计算结果为：");
	for (j = 0;j < m;j++) {
		sum[j] = 0;
		for (i = 0;i < n;i++) {
			sum[j] += stu[i].score[j];
		}
		aver[j] = sum[j] / n;
		SetPosition(POS_X1, ++posy);
		printf("第%d个课程：总分=%.2f, 平均分=%.2f\n", j + 1, sum[j], aver[j]);
	}
}
//学生记录存盘
void WritetoFile(int n, int m, STU* head) {
	int i, j;
	// 定义文件指针
	FILE* fp;
	// 打开文件, 指定文件的处理方式为写入，并让指针指向文件
	if ((fopen_s(&fp, "D:\\IIITEM!\\student_management_system\\student.txt", "w")) != 0) {
		printf("打开文件失败\n");
		exit(0);
	}
	// 将文件按指定格式写入文件
	fprintf(fp, "%10d%10d\n", n, m);
	STU* current = head->next; // 跳过头节点
	while (current != NULL) {
		fprintf(fp, "%10ld%10s\n", current->num, current->name);
		for (j = 0; j < m; j++) {
			fprintf(fp, "%10.1f", current->score[j]);
		}
		fprintf(fp, "%10.1f%10.1f\n", current->sum, current->aver);
		current = current->next;
	}
	fclose(fp);
	// 提示用户存盘操作完毕
	printf("存盘完毕!\n");
}


//从磁盘中读取学生记录
int ReadfromFile(int* n, int* m, STU* head, int* first) {
	FILE* fp;
	int i, j;
	int posy = 8;
	SetPosition(POS_X1, posy);
	if ((fopen_s(&fp, "D:\\IIITEM!\\student_management_system\\student.txt", "r")) != 0) {
		printf("磁盘文件无法打开！");
		exit(0);
	}
	fscanf_s(fp, "%10d%10d", n, m);
	STU* current = head;
	for (i = 0; i < *n; i++) {
		STU* temp = (STU*)malloc(sizeof(STU));
		if (temp == NULL) {
			printf("内存分配失败！\n");
			exit(1);
		}
		fscanf_s(fp, "%10ld", &temp->num);
		fscanf_s(fp, "%10s", temp->name, (unsigned)sizeof(temp->name));
		for (j = 0; j < *m; j++) {
			fscanf_s(fp, "%10f", &temp->score[j]);
		}
		fscanf_s(fp, "%10f%10f", &temp->sum, &temp->aver);
		temp->next = NULL;
		temp->prior = current;
		current->next = temp;
		current = temp;
	}
	*first = 0;
	fclose(fp);
	printf("数据从磁盘读取完毕！");
	return 0;
}


//增加学生记录
void AppendRecord(int* n, int m, STU stu[])
{
	int i, j;
	int num_record;
	printf("请输入需要增加的数量：");
	scanf_s("%d", &num_record);
	while (*n + num_record > STU_NUM)
	{
		printf("数量太多，请重新输入：");
		scanf_s("%d", &num_record);
	}
	for (i = *n;i < *n + num_record;i++)
	{
		printf("输入第%d个学生信息（学号、姓名、%d个课程）\t", i + 1, m);
		scanf_s("%ld%s", &stu[i].num, stu[i].name, (unsigned)sizeof(stu[i].num) + (unsigned)sizeof(stu[i].name));
		for (j = 0;j < m;j++)
		{
			scanf_s("%f", &stu[i].score[j]);
		}
	}
	*n = *n + num_record;
	printf("添加完毕!\n");
	return;
}
//按学号找
void SearchByNumber(int n, int m, STU* stu) {
	long id;
	int i, j;
	printf("请输入你要查找的学生的学号：");
	scanf_s("%ld", &id);
	for (i = 0;i < n;i++) {
		if (stu[i].num == id) {
			printf("找到了，该学号对应的学生信息：\n");
			printf("%10ld%15s", stu[i].num, stu[i].name);
			for (j = 0;j < m;j++) {
				printf("%10.2f", stu[i].score[j]);
			}
			printf("%10.2f%10.2f", stu[i].sum, stu[i].aver);
			return;
		}
	}
	printf("未找到这个学号对应的学生记录");
	return;
}
//按姓名查找
void SearchByName(int n, int m, STU* stu) {
	int flag = 1;
	int i, j;
	int k = 0;
	char name[NAME_LEN];
	printf("请输入你要查找的学生的姓名：");
	scanf_s("%s", name, (unsigned)sizeof(name));
	for (i = 0;i < n;i++) {
		if (strcmp(stu[i].name, name) == 0) {
			printf("找到了，第%d学生信息为：\n", ++k);
			printf("%10ld%15s", stu[i].num, stu[i].name);
		}
		for (j = 0;j < m;j++) {
			printf("%10.2f", stu[i].score[j]);
		}
		printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);
		flag = 0;
	}
	if (flag) {
		printf("未找到这个姓名对应的学生记录\n");
	}
	return;
}
//删除学生记录
void DeleteRecord(int* n, int m, STU stu[]) {
	int i, j;
	long id;
	char ch;
	printf("请输入你要删除的学生信息对应的学号：");
	scanf_s("%ld", &id);
	for (i = 0;i < *n;i++) {
		if (stu[i].num == id) {
			printf("找到了该生学生信息\n");
			printf("%10ld%15s", stu[i].num, stu[i].name);
			for (j = 0;j < m;j++) {
				printf("%10.2f", stu[i].score[j]);
			}
			printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);
			printf("请确认是否需要删除该条记录？（Y/y或N/n）：");
			getchar();
			scanf_s("%c", &ch);
			if (ch == 'Y' || ch == 'y') {
				for (j = i;j < *n - 1;j++) {
					stu[j] = stu[j + 1];
				}
				(*n)--;
				printf("删除完毕\n");
				return;
			}
			else if (ch == 'N' || ch == 'n') {
				printf("找到了该学生记录，但不删除\n");
				return;
			}
			else {
				printf("输入出错!\n");
				return;
			}
		}
	}
	printf("未找到该生记录\n");
	return;
}
//修改学生操作
void ModifyRecord(int n, int m, STU* stu) {
	int i, j;
	long id;
	char ch;
	printf("请输入需要修改信息对应对应的学号：");
	scanf_s("%ld", &id);
	for (i = 0;i < n;i++) {
		if (stu[i].num == id) {
			printf("找到了该生学生信息\n");
			printf("%10ld%15s", stu[i].num, stu[i].name);
			for (j = 0;j < m;j++) {
				printf("%10.2f", stu[i].score[j]);
			}
			printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);
			printf("请确认是否需要修改？（Y/y或N/n）：");
			system("pause");
			scanf_s("%c", &ch);
			if (ch == 'Y' || ch == 'y') {
				printf("请输入要修改的学生信息：");
				scanf_s("%ld%s", &stu[i].num, stu[i].name, (unsigned)sizeof(stu[i].num) + (unsigned)sizeof(stu[i].name));
				stu[i].sum = 0;
				for (j = 0;j < m;j++) {
					scanf_s("%f", &stu[i].score[j]);
					stu[i].sum += stu[i].score[j];
				}
				stu[i].aver = stu[i].sum / m;
				printf("修改完毕\n");
				return;
			}
			else if (ch == 'N' || ch == 'n') {
				printf("找到了该学生记录，但不修改\n");
				return;
			}
			else {
				printf("输入出错!\n");
				return;
			}
		}
	}
	printf("未找到该生记录\n");
	return;
}
//输出学生记录
void PrintRecord(int n, int m, STU* stu) {
	int i, j;
	printf("学号\t\t姓名\t\t");
	for (j = 0;j < m;j++) {
		printf("课程%d\t\t", j + 1);
	}
	printf("总分\t\t平均分\n");
	for (i = 0;i < n;i++) {
		printf("%-16ld%-16s", stu[i].num, stu[i].name);
		for (j = 0;j < m;j++) {
			printf("%-16.1lf", stu[i].score[j]);
		}
		printf("%-16.1lf%-16.1lf\n", stu[i].sum, stu[i].aver);
	}
	return;
}

//按照学号对学生记录进行排序（升序）
void SortbyNum(int n, int m,STU* stu)
{
	int i,j;
	int k;
	STU temp;

	for(i = 0;i < n;i++)
	{
		k = i;
		for(j = i + 1;j < n;j++)
		{
			if(stu[j].num < stu[k].num)
			k = j;
		}
		if(k != i)
		{
			temp = stu[k];
			stu[k] = stu[i];
			stu[i] = temp;
		}
	}
	printf("按照学号从小到大对学生记录进行排序");
}

//按照总成绩进行排序
void SortbyScore(int n, int m, STU* stu)
{
	int i, j;
	int k;
	STU temp;

	for(i = 0;i < n;i++)
	{
		k = i;
		for(j = i + 1;i < n;j++)
		{
			if(stu[j].sum < stu[k].sum)
			k = j;
		}
		if(k != i)
		{
			temp = stu[k];
			stu[k] = stu[i];
			stu[i] = temp;
		}
		printf("按总分对学生记录升序排序完毕");
	}
}

//规定降序排序规则
int Descending(float a, float b)
{
	return a > b;
}

//规定升序排序规则
int Ascending(float a, float b)
{
	return a < b;
}

//按照学生成绩总分对所有学生记录进行升序或降序排序
void SortByScore(int n, int m, STU* stu,int(* compare)(float a, float b))
{
	int i, j;
	int k;
	STU temp;

	for(i = 0;i < n;i++)
	{
		k = i;
		for(j = i + 1;j < n;j++)
		{
			if((*compare)(stu[j].sum, stu[k].sum))
			{
				k = j;
			}
		}
		if(k != i)
		{
			temp = stu[k];
			stu[k] = stu[i];
			stu[i] = temp;
		}
	}
	printf("按照学生成绩总分对学生记录排序完毕");
}

//统计并输出各个分数段学生人数及占比
void StatisticAnalysis(int n, int m, STU* stu)
{
	int i, j, t[6];

	for(j = 0;j < m;j++)
	{
		printf("\n课程%d成绩统计结果为： \n",j + 1);
		printf("分数段\t人数\t占比\n");
	}

	memset(t, 0, sizeof(t));
	for(i = 0;i < n;i++)
	{
		if (stu[i].score[j] >= 0 && stu[i].score[j] < 60)
			t[0]++;
		else if(stu[i].score[j] < 70)
		t[1]++;
		else if(stu[i].score[j] < 80)
		t[2]++;
		else if(stu[i].score[j] < 90)
		t[3]++;
		else if(stu[i].score[j] < 100)
		t[4]++;
		else if(stu[i].score[j] == 100)
		t[5]++;
	}

	for(i = 0;i < 6;i++)
	{
		if(i == 0)
		printf("<60\t%d\t%.2f%%\n",t[i], (float)t[i]/n * 100);
		else if(i == 5)
		printf("100\t%d\t%.2f%%\n",t[i], (float)t[i]/n * 100);
		else
		printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i]/n * 100);
	}
}