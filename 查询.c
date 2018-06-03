
#include "manager.h"
void chaxun() {
	while (1)
	{
	system("cls") ;
	char c;
	int b = 1, x = 38 , y = 4;

	system("cls") ;
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                           学生信息管理系统                                                 |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                     |     1.学生个人成绩查询   |                                           |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                           2.全员按各科排名                                                 |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                           3.全员总分/平均分排名                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                           4.返回                                                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                   ↑↓控制       ENTER  确认               |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	c = getch();
	while( c != 13) {
		if (c == 80 && b <= 4) {
			if(b == 4)
			b = 0;
			gotoxy(43, y);
    		puts("                             ");
    		gotoxy(43, y+1);
    		puts(" ");
    		gotoxy(70, y+1);
    		puts(" ");
    		gotoxy(43, y+2);
    		puts("                             ");
    		if(b == 0)
				y = 1;
    		gotoxy(43, y+3);
    		puts("============================");
    		gotoxy(43, y+4);
    		puts("|");
    		gotoxy(70, y+4);
    		puts("|");
    		gotoxy(43, y+5);
    		puts("============================");
			b++;
			y += 3;
			gotoxy(0,20);
		}
		if (c == 72 && b >= 1){
			if(b == 1)
				b = 5;
			gotoxy(43, y);
    		puts("                             ");
    		gotoxy(43, y+1);
    		puts(" ");
    		gotoxy(70, y+1);
    		puts(" ");
    		gotoxy(43, y+2);
    		puts("                             ");
    		if(b == 5)
				y = 16;
    		gotoxy(43, y-1);
    		puts("============================");
    		gotoxy(43, y-2);
    		puts("|");
    		gotoxy(70, y-2);
    		puts("|");
    		gotoxy(43, y-3);
    		puts("============================");
			b--;
			y -= 3;
			gotoxy(0,20);
		}
		c = getch();
	}
	if (b == 1) cha1();
	if (b == 2) chage();
	if (b == 3) sortsum();
	if (b == 4) return; 
	}
}


void  cha1() {
	struct lian  * prev = head, * current =  head->next;
	int y = 7;
	while(1) {
		system("cls") ;
		char c[31];
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		printf("     |                                           学生信息管理系统                                                 |\n");
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		printf("     |     请输入学生成绩：                                                                                       |\n");
		printf("     |                               姓名：                                                                       |\n");
		printf("     |                                      （输入录入成绩学生的姓名，回车停止）                                  |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                               平均：                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                               高数：                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                               离散：                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                               英语：                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                              C语言：                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                      ENTER  确认           |\n");
		printf("     --------------------------------------------------------------------------------------------------------------\n");
			if (current == NULL) {
			system("cls") ;
			gotoxy(38, y+3);
			puts("======================================");
    		gotoxy(38, y+4);
    		puts("|                                    |");
    		gotoxy(38, y+5);
    		puts("|                                    |");
    		gotoxy(51, y+5);
    		puts("没 有 数 据");
    		gotoxy(38, y+6);
    		puts("|                                    |");
    		gotoxy(50, y+6);
    		puts("(按任意键返回)") ;
    		gotoxy(38, y+7);
    		puts("======================================");
		getchar();
		return ;
		}
		gotoxy(44, 4);
		s_gets(c, 30);
		if ( c[0] == '\0' ) return ;

		while(current != NULL && strcmp(current->item.name,c) != 0) {
			current = current->next;
    	}
    	if (current == NULL) {
    		gotoxy(44, 5);
    		printf ("没有找到该同学，按任意键重新输入\t\n");
    		current =  head->next ;
    		getch(); 
    		continue ;
		}
		gotoxy(44, 7);
		printf("%.2f", current->item.avrg) ;
		gotoxy(44, 10);
		printf("%3d", current->item.math) ;
		gotoxy(44, 13);
		printf("%3d", current->item.lisan) ;
		gotoxy(44, 16);
		printf("%3d", current->item.english) ;
		gotoxy(44, 19);
		printf("%3d", current->item.c) ;

		getchar();




}
}

void sortsum() {													///////冒泡排序链表
		struct lian  * current =  head->next;
		struct lian t;
		int ch = 1 , y=7;
		if ( current == NULL )
		{
			system("cls") ;
			gotoxy(38, y+3);
			puts("======================================");
    		gotoxy(38, y+4);
    		puts("|                                    |");
    		gotoxy(38, y+5);
    		puts("|                                    |");
    		gotoxy(51, y+5);
    		puts("没 有 数 据");
    		gotoxy(38, y+6);
    		puts("|                                    |");
    		gotoxy(50, y+6);
    		puts("(按任意键返回)") ;
    		gotoxy(38, y+7);
    		puts("======================================");
		getchar();
		return ;
		 }

		while (ch) {
			ch = 0;
			while (current->next != NULL) {
				if ( current->item.sum < current->next->item.sum)
				{
					t.item = current->item;
					current->item = current->next->item;
					current->next->item = t.item ;
					ch = 1;
				}
				current = current->next ;
			}
			current = head->next ;
		}
		bianli (head);
		cun();
}
void sorthigh() {													///////冒泡排序链表
		struct lian  * current =  head->next;
		struct lian t;
		int ch = 1 , y=7;
		if ( current == NULL )
		{
			system("cls") ;
			gotoxy(38, y+3);
			puts("======================================");
    		gotoxy(38, y+4);
    		puts("|                                    |");
    		gotoxy(38, y+5);
    		puts("|                                    |");
    		gotoxy(51, y+5);
    		puts("没 有 数 据");
    		gotoxy(38, y+6);
    		puts("|                                    |");
    		gotoxy(50, y+6);
    		puts("(按任意键返回)") ;
    		gotoxy(38, y+7);
    		puts("======================================");
		getchar();
		return ;
		 }

		while (ch) {
			ch = 0;
			while (current->next != NULL) {
				if ( current->item.math < current->next->item.math)
				{
					t.item = current->item;
					current->item = current->next->item;
					current->next->item = t.item ;
					ch = 1;
				}
				current = current->next ;

			}
			current = head->next ;

		}
		bianli (head);
		cun();
}
void sortlisan() {													///////冒泡排序链表
		struct lian  * current =  head->next;
		struct lian t;
		int ch = 1 , y=7;
		if ( current == NULL )
		{
			system("cls") ;
			gotoxy(38, y+3);
			puts("======================================");
    		gotoxy(38, y+4);
    		puts("|                                    |");
    		gotoxy(38, y+5);
    		puts("|                                    |");
    		gotoxy(51, y+5);
    		puts("没 有 数 据");
    		gotoxy(38, y+6);
    		puts("|                                    |");
    		gotoxy(50, y+6);
    		puts("(按任意键返回)") ;
    		gotoxy(38, y+7);
    		puts("======================================");
		getchar();
		return ;
		 }

		while (ch) {
			ch = 0;
			while (current->next != NULL) {
				if ( current->item.lisan < current->next->item.lisan)
				{
					t.item = current->item;
					current->item = current->next->item;
					current->next->item = t.item ;
					ch = 1;
				}
				current = current->next ;

			}
			current = head->next ;

		}
		bianli (head);
		cun();
}
void sortenglish() {													///////冒泡排序链表
		struct lian  * current =  head->next;
		struct lian t;
		int ch = 1 , y=7;
		if ( current == NULL )
		{
			system("cls") ;
			gotoxy(38, y+3);
			puts("======================================");
    		gotoxy(38, y+4);
    		puts("|                                    |");
    		gotoxy(38, y+5);
    		puts("|                                    |");
    		gotoxy(51, y+5);
    		puts("没 有 数 据");
    		gotoxy(38, y+6);
    		puts("|                                    |");
    		gotoxy(50, y+6);
    		puts("(按任意键返回)") ;
    		gotoxy(38, y+7);
    		puts("======================================");
		getchar();
		return ;
		 }

		while (ch) {
			ch = 0;
			while (current->next != NULL) {
				if ( current->item.english < current->next->item.english)
				{
					t.item = current->item;
					current->item = current->next->item;
					current->next->item = t.item ;
					ch = 1;
				}
				current = current->next ;

			}
			current = head->next ;

		}
		bianli (head);
		cun();
}
void sortc() {													///////冒泡排序链表
		struct lian  * current =  head->next;
		struct lian t;
		int ch = 1 , y=7;
		if ( current == NULL )
		{
			system("cls") ;
			gotoxy(38, y+3);
			puts("======================================");
    		gotoxy(38, y+4);
    		puts("|                                    |");
    		gotoxy(38, y+5);
    		puts("|                                    |");
    		gotoxy(51, y+5);
    		puts("没 有 数 据");
    		gotoxy(38, y+6);
    		puts("|                                    |");
    		gotoxy(50, y+6);
    		puts("(按任意键返回)") ;
    		gotoxy(38, y+7);
    		puts("======================================");
		getchar();
		return ;
		 }

		while (ch) {
			ch = 0;
			while (current->next != NULL) {
				if ( current->item.c < current->next->item.c)
				{
					t.item = current->item;
					current->item = current->next->item;
					current->next->item = t.item ;
					ch = 1;
				}
				current = current->next ;

			}
			current = head->next ;

		}
		bianli (head);
		cun();
}

void chage() {                                                  //////////////////////////各科成绩排序查询 

	while(1){
	char c;
	int b = 1, x = 38 , y = 4;
	system("cls") ;
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                           学生信息管理系统                                                 |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |       请选择排序科目:                                                                                      |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                     |         1.高数           |                                           |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                               2.离散                                                       |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                               3.英语                                                       |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                               4.C语言                                                      |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                               5.返回                                                       |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                   ↑↓控制       ENTER  确认               |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	c = getch();
	while( c != 13) {
		if (c == 80 && b <= 5) {
			if(b == 5)
				b = 0;
			gotoxy(43, y);
    		puts("                             ");
    		gotoxy(43, y+1);
    		puts(" ");
    		gotoxy(70, y+1);
    		puts(" ");
    		gotoxy(43, y+2);
    		puts("                             ");
    		if(b == 0)
				y = 1;
    		gotoxy(43, y+3);
    		puts("============================");
    		gotoxy(43, y+4);
    		puts("|");
    		gotoxy(70, y+4);
    		puts("|");
    		gotoxy(43, y+5);
    		puts("============================");
			b++;
			y += 3;
			gotoxy(0,20);
		}
		if (c == 72 && b >= 1){
			if(b == 1)
				b = 6;
			gotoxy(43, y);
    		puts("                             ");
    		gotoxy(43, y+1);
    		puts(" ");
    		gotoxy(70, y+1);
    		puts(" ");
    		gotoxy(43, y+2);
    		puts("                             ");
    		if(b == 6)
				y = 19;
    		gotoxy(43, y-1);
    		puts("============================");
    		gotoxy(43, y-2);
    		puts("|");
    		gotoxy(70, y-2);
    		puts("|");
    		gotoxy(43, y-3);
    		puts("============================");
			b--;
			y -= 3;
			gotoxy(0,20);
			} 
			c = getch(); 
			} 


	if (b == 1) sorthigh(); 
	if (b == 2) sortlisan();
	if (b == 3) sortenglish(); 
	if (b == 4) sortc();
	if (b == 5) return ;
	} 
	} 

