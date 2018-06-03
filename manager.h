#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
extern struct telian * laop ; 				// 老师状态记录 
extern struct lian * head ;                 // 头指针 学生 外部链接
extern struct telian * head2; 				// 头指针 老师 
extern int ban;					            // 班级记录 
struct tems {                               // 老师信息
	char name[100];							
	char z[21];
	char m[21];
	int ban;
};

typedef struct telian {						// 老师链表 
	struct tems teitem;
	struct telian * next;
}telian;

struct ms {                                 // 学生信息和成绩
	char name[100];
	char sex[10];
	char number[10];
	int lisan;
	int math;
	int english;
	int c;
	int sum;
	int ban;
	char m[10]; 
	float avrg;
};
typedef struct lian {                       // 链表
	struct ms item ;
	struct lian * next ;
} lian;

void zhujie(); 								// 主界面
void denglu1(); 							// 主界面 	 管理登录 
void denglu2(); 							// 主界面 	 老师登陆 
void denglu3(); 							// 主界面 	 学生登陆 
void denglu3_1(struct lian * current) ; 	// 主界面 	 学生登录界面 
void denglu1_1(); 							// 主界面 	 管理登录界面 
void denglu1_1_1(); 						// 主界面	 管理登录管理老师界面 
void gotoxy(int x, int y);					// 主界面	 移动光标函数
void xiu(struct lian * current)	;			// 主界面	 修改学生密码 
void xiu2() ;								// 主界面	 修改老师密码 

void jie2();								// 老师界面

char * s_gets(char * st, int n);			// 链表  	 输入处理函数
lian * creat ();                            // 链表  	 学生 创建带头结点 返回头指针
void cut (struct lian *);                   // 链表  	 删除同学 ，根据名字
void addstu (struct lian * head); 			// 链表 	 添加学生信息
void addgra (struct lian * head); 			// 链表 	 录入学生成绩
void bianli (struct lian * head);			// 链表 	 遍历输出信息 


telian * creat2 ();							// 链表  	 老师 创建带头结点 返回头指针
void addte (struct telian * head2);         // 链表  	 添加老师信息
void bianli1 (struct telian * head2);		// 链表  	 遍历输出老师信息
void cut1 (struct telian * head2) ;			// 链表  	 删除老师 



void chaxun(); 						        // 查询 	 查成绩主界面
void cha1();								// 查询 	 个人成绩
void cha2(struct lian * current); 			// 查询		 学生个人成绩 
void sortsum();								// 查询 	 冒泡链表排序总成绩 /平均分 
void chage();								// 查询 	 各科成绩 

void cun();                                 // 文件  	 保存同学 
void du();									// 文件  	 读取同学 
void cun2();								// 文件  	 存老师信息 
void du2();									// 文件 	 读取老师信息 

void jiami(char x[]);						// 主界面 	 加密 
void jiemi(char x[]);						// 主界面  	 解密 

