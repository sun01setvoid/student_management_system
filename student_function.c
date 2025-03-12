#include "student.h"

//设置光标位置
void GotoXY(int x, int y) {
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
int Menu() {
	int posy = 5;
	int option;		//保存用户输入的操作代码的变量
	int i, j;
	SetPosition(POS_X3, posy);
	printf("学生成绩管理系统\n"); //输入系统名字
	//输出系统名字和功能说明之间的两行短横线
	for (int i =0 ;i < 2;i++) {
		SetPosition(POS_X1, ++posy);
		for (int j = 0;j < 55;j++) {
			printf("-");
		}
	}
	//输出系统支持的功能和对应的功能代码
	SetPosition(POS_X1, ++posy);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy+=2);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy += 2);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy += 2);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy += 2);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy += 2);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy += 2);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy += 2);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy += 2);
	printf("");
	//输出系统支持的功能与输入提示语之间的两行短横线
	for (int i = 0;i < 2;i++) {
		SetPosition(POS_X1, ++posy);
		for (int j = 0;j < 55;j++) {
			printf("-");
		}
	}
	//提示用户所要执行的功能代码
	printf("");
	scanf("%d", &option);
	return option;
}
//输入学生信息
void InputRecord(STU* stu,int *n,int*m) {

}

