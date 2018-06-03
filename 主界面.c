
#include "manager.h"
void jiami(char x[]) {
	for (int i = 0; i < strlen(x); i++) {
		x[i] = x[i] + 10 + i; 
	}
	
}
void jiemi(char x[]) {
	for (int i = 0; i < strlen(x); i++) {
		x[i] = x[i] - 10 - i; 
	}
	
}
void gotoxy(int x, int y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void zhujie() {
    char c;
	int b = 1, x = 38 , y = 7;
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                           学生信息管理系统                                                 |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |           请选择身份：                                                                                     |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                     |         1.管理员         |                                           |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                               2.老师                                                       |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                               3.学生                                                       |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                               4.退出程序                                                   |\n");
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
				y = 4;
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
			gotoxy(0,28);
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
			gotoxy(0,28);
		}
		c = getch();
	}
	if (b == 1) denglu1(); 
	if (b == 2) denglu2();
	if (b == 3) denglu3();
	if (b == 4) {
	gotoxy(0, 80);
	exit(0) ; 
	}
}

void denglu1() {  
	FILE * fp;
	int i, flag = 0;
	fp = fopen("管理员账号密码.txt", "r");
	char z[21], m[21], c, zd[21], md[21];
	while (1) {
	system("cls") ;
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                              学生信息管理系统                                              |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                管理员登录                                                  |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                      账号：                                                                |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                      密码：                                                                |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                   ENTER  确认              |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	gotoxy(50,10);
	for (i = 0; (c = getch())!= 13 && i <20 ; i++) {
		z[i] = c;
		printf("%c", c);
	}
	if (c == 13 && i == 0) {
		return ;
	}
	z[i] = '\0';
	gotoxy(50,13);
	for (i = 0; (c = getch())!= 13 && i <20 ; i++) {
	m[i] = c;
	printf("*");
	}
	m[i] = '\0';
	while (!feof(fp)){
		fscanf(fp,"%s %s", zd, md);
		jiemi(zd);
		jiemi(md); 
		if (strcmp(z, zd) == 0 && strcmp(m, md) == 0) {
			flag = 1;
			break ;
		}
	}
	if (flag == 1) {
	denglu1_1();
	ban = 0;
	}
	else {
		gotoxy(50,20);
		printf("账号或密码错误，按任意键继续");
		getch();
		rewind(fp);
		continue ; 
	}

	return ;

	}
} 

void denglu2() {
	int i, flag = 0;
	struct telian  * current =  head2->next;
	char z[21], m[21], c;
	while (1) {
	current =  head2->next;
	system("cls") ;
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                              学生信息管理系统                                              |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                老师登录                                                    |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                      账号：                                                                |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                      密码：                                                                |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                   ENTER  确认              |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	gotoxy(50,10);
	for (i = 0; (c = getch())!= 13 && i <20 ; i++) {
		z[i] = c;
		printf("%c", c);
	}
	if (c == 13 && i == 0) {
		return ;
	}
	z[i] = '\0';
	gotoxy(50,13);
	for (i = 0; (c = getch())!= 13 && i <20 ; i++) {
		m[i] = c;
		printf("*");
		}
	m[i] = '\0';
	while (current != NULL && strcmp(current->teitem.z,z) != 0) {
		current = current->next;
		}
	if (current == NULL) {
		gotoxy(50,20);
		printf("账号或密码错误，按任意键继续");
		getch();
		continue ; 
		}
	if (strcmp(current->teitem.m, m) == 0 ) {
		flag = 1;
		}
	if (flag == 1) {
	ban = current->teitem.ban; 
	laop = current ;
	jie2();
	}
	else {
		gotoxy(50,20);
		printf("账号或密码错误，按任意键继续");
		getch();
		continue ; 
	}

	return ;

}

}

void denglu3() {
	char c[30], m[30],l;
	struct lian * current ;
	int i = 0;
	while (1) {
	current =  head->next;
	system("cls") ;
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                              学生信息管理系统                                              |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                学生登录                                                    |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                      账号：                                                                |\n");
	printf("     |                                            （姓名）                                                        |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                      密码：                                                                |\n");
	printf("     |                                            （初次登录默认为0，进入后请修改密码）                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                   ENTER  确认              |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	gotoxy(50,10);
	s_gets(c, 30);
	if ( c[0] == '\0' ) break ;
			while(current != NULL && strcmp(current->item.name,c) != 0) {
		current = current->next;
    	}
    	if (current == NULL)   {
		gotoxy(50,10);
    	printf("该同学不存在");
       	getch();
		continue ;

		}
		gotoxy(50,13);
		for ( i = 0; (l = getch()) != 13 && i < 20 ; i++) {
		m[i] = l;
		printf("*");
		}
		m[i] = '\0';
		if (strcmp(current->item.m,m) == 0) {
			ban = current->item.ban;
			denglu3_1(current);
			return ;
		} 
		gotoxy(50,20);
		printf("账号或密码错误，按任意键继续");
		getch();
	}
}

void denglu1_1() {
	while (1) {
	system("cls") ;
	    char c;
	int b = 1, x = 38 , y = 7;
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                           学生信息管理系统                                                 |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |           请选择：                                                                                         |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                     |      1.管理老师信息      |                                           |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                            2.管理学生信息                                                  |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                            3.返回                                                          |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
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
		if (c == 80 && b <= 3) {
			if(b == 3)
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
				y = 4;
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
				b = 4;
			gotoxy(43, y);
    		puts("                             ");
    		gotoxy(43, y+1);
    		puts(" ");
    		gotoxy(70, y+1);
    		puts(" ");
    		gotoxy(43, y+2);
    		puts("                             ");
    		if(b == 4)
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
			if (b == 1) denglu1_1_1(); 
			if (b == 2) jie2();
			if (b == 3) return ; 
		}
		} 
		
		
void denglu1_1_1() {
	while(1) {

	system("cls") ;
	char c;
	int b = 1, x = 38 , y = 4;
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                           学生信息管理系统                                                 |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                     |        1.老师目录        |                                           |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                              2.添加老师                                                    |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                              3.删除老师                                                    |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                              4.修改老师密码                                                |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                              5.返回                                                        |\n");
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
	if (b == 1) {

		bianli1 (head2); 


	}
	if (b == 2) {
		system("cls") ;
		addte (head2);
	}
	if (b == 3) cut1 (head2);
	if (b == 4) xiu2();
	if (b == 5) return ;
}
}

void denglu3_1(struct lian * current) {
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
	printf("     |                                           2.全班按各科排名                                                 |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                           3.全班总分/平均分排名                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                           4.修改我的密码                                                   |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                           5.返回                                                           |\n");
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
	if (b == 1) cha2(current);
	if (b == 2) chage();
	if (b == 3) sortsum();
	if (b == 4) xiu(current);
	if (b == 5) {
	ban = 0;
	return; 
	}
}}
////////////////////														学生成绩查询 
void cha2(struct lian * current) {
		system("cls") ;
		char c[31];
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		printf("     |                                           学生信息管理系统                                                 |\n");
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		printf("     |                                                                                                            |\n");
		printf("     |                               姓名：                                                                       |\n");
		printf("     |                                                                                                            |\n");
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
		printf("     |                               总分：                                                 ENTER  确认           |\n");
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		gotoxy(44, 4);
		printf("%s", current->item.name);
		gotoxy(44, 7);
		printf("%.2f", current->item.avrg);
		gotoxy(44, 10);
		printf("%d", current->item.math);
		gotoxy(44, 13);
		printf("%d", current->item.lisan);
		gotoxy(44, 16);
		printf("%d", current->item.english);
		gotoxy(44, 19);
		printf("%d", current->item.c);
		gotoxy(44, 22);
		printf("%d", current->item.sum);
		getch();

} 
/////////////////////////////////////////////// 														修改密码 
void xiu(struct lian * current) {
		struct lian * xian = head;
		while(1) {
		system("cls") ;
		char c[31],b[31], n[31];
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		printf("     |                                           学生信息管理系统                                                 |\n");
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                       姓名（账号）：                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                            新密码 ：                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                          再次输入 ：                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                      ENTER  确认           |\n");
		printf("     --------------------------------------------------------------------------------------------------------------\n");

		if (ban == 0 || laop != NULL) 
		{
			gotoxy(50,7);
			s_gets(c, 30);
			if (c[0] == '\0') return ;
			while(xian->next != NULL && strcmp(xian->next->item.name,c) != 0) {
			xian = xian->next;
    		}
			if (xian->next == NULL) {
			gotoxy(44, 7); 
    		printf ("没有找到该同学，请从新输入：（直接按回车返回）\n");
    		getch();
    		xian =  head ;
    		continue ;
			}
    		
			gotoxy(50,10);
			s_gets(c, 30);
	 		gotoxy(50,13);
			s_gets(b, 30);
			if (strcmp(c,b) == 0) {
			strcpy(xian->next->item.m,c);
			cun(); 
			gotoxy(50,16);
			printf("修改成功\n");
			gotoxy(50,16);
			printf("新密码为%s",xian->next->item.m) ; 
			getch();
			return ;
			}
		}
			
		else {
		gotoxy(50,7);
		printf("%s", current->item.name);
		gotoxy(50,10);
		s_gets(c, 30);
	 	gotoxy(50,13);
		s_gets(b, 30);
		if (strcmp(c,b) == 0) {
			strcpy(current->item.m,c);
			cun(); 
			gotoxy(50,16);
			printf("修改成功\n");
			gotoxy(50,17);
			printf("新密码为%s",current->item.m) ; 
			getch();
			return ;
		}
	}
}}

void xiu2() {
		
		char c[31], b[31], l;
		while(1) {
		system("cls") ;
		struct telian * xian = head2;
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		printf("     |                                           学生信息管理系统                                                 |\n");
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                              账号 ：                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                            新密码 ：                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                          再次输入 ：                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                      ENTER  确认           |\n");
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		if (ban == 0 && laop == NULL) {
			gotoxy(44, 7);
			s_gets(c, 30);
			if (c[0] == '\0') return ;
			while(xian->next != NULL && strcmp(xian->next->teitem.z,c) != 0) {
			xian = xian->next;
    		}
			if (xian->next == NULL) {
			gotoxy(44, 7);
    		printf ("没有找到该老师，请从新输入：（直接按回车返回）\n");
    		getch();
    		xian =  head2 ;
    		continue ;
			}
			gotoxy(44,10);
			s_gets(c, 30);
	 		gotoxy(44,13);
			s_gets(b, 30);
			if (strcmp(c,b) == 0) {
				strcpy(xian->next->teitem.m,c);
				gotoxy(44,16);
				printf("\t修改成功\n");
				gotoxy(44,17);
				printf("新密码为%s",xian->next->teitem.m) ; 
				getch();
				cun2() ; 
				return ; 
			}
		}
		else {

		gotoxy(44, 7);
		printf("%s", laop->teitem.z);
		gotoxy(44,10);
		s_gets(c, 30);
	 	gotoxy(44,13);
		s_gets(b, 30);
		if (strcmp(c,b) == 0) {
			strcpy(laop->teitem.m,c);
			gotoxy(44,16);
			printf("\t修改成功\n");
			gotoxy(44,17);
			printf("新密码为%s",laop->teitem.m) ; 
			getch();
			cun2() ; 
			return ; 
		}
	}
}
}
