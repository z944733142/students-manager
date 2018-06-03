#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

extern struct lian * head ;                 // 头指针，外部链接


struct ms {                                 // 学生信息和成绩
	char name[100];
	char sex[10];
	char number[10];
	int lisan;
	int math;
	int english;
	int c;
	int sum;
	float avrg;
};
typedef struct lian {                       // 链表
	struct ms item ;
	struct lian * next ;
} lian;
void zhujie(); 								// 主界面函数
char * s_gets(char * st, int n);			// 输入处理函数
void jie2();								// 老师界面
void gotoxy(int x, int y);					// 移动光标函数

lian * creat ();                            // 链表   创建 带头结点 返回头指针
void cut (struct lian *);                   // 链表   删除同学 ，根据名字
void addstu (struct lian * head); 			// 链表   添加学生信息
void addgra (struct lian * head); 			// 链表   录入学生成绩
void bianli (struct lian * head);			// 链表   遍历输出信息
void pai() ;								// 链表   冒泡排序链

void chaxun(); 						    // 查询   查成绩主界面
void cha1();								// 查询   个人成绩

void cun();                               // 文件   保存
void du();
