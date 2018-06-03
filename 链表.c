
#include "manager.h"
struct lian * head = NULL ;                                        				  //学生头指针 ， 静态
struct telian * head2 = NULL , * laop = NULL;									  //老师头指针 
int ban = 0 ; 
lian * creat () {                                                    			  //创建学生 
	struct lian   * current =  NULL;
	current = (struct lian *)malloc(sizeof(struct lian));
	current->next = NULL;
	return current;
}

telian * creat2 () {                                                   			 //创建老师 
	struct telian   * current =  NULL;
	current = (struct telian *)malloc(sizeof(struct telian));
	current->next = NULL;
	return current;
}
//////////////////////////////////////////////////////////////////////////////////////
void addstu (struct lian * head) {                                   			 //添加学生信息

	char name[31];
	int n = 0 , shu = 0;
	FILE * fp; 
    struct lian  * prev = head, * current =  NULL , * new2 = head->next;
    while(prev->next != NULL) prev = prev->next;
    while(1) {
    new2 = head->next;
    system("cls") ;
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                           学生信息管理系统                                                 |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |     请输入学生信息：                                                                                       |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                               姓名：                                                                       |\n");
	printf("     |                                     （输入回车停止,最多30个字母,15个汉字）                                 |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                               性别：                                                                       |\n");
	printf("     |                                     （男/女）                                                              |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                               学号：                                                                       |\n");
	printf("     |                                     （输入8位学号）                                                        |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                               班级：                                                                       |\n");
	printf("     |                                     （正整数，输入错误则没有班级）                                         |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                            已经成功录入 0  名同学    ENTER  确认           |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	gotoxy(79, 22);
	printf("%d", n) ;

	if (ban != 0) 
	{
			gotoxy(44, 16);
			printf("%d", ban);

	}
		gotoxy(44, 7);
	s_gets(name, 30);
	if ( name[0] == '\0' ) break ;
	while(new2 != NULL && strcmp(new2->item.name,name) != 0) {
		new2 = new2->next;
    	}
    	if (new2 != NULL)   {
		gotoxy(44, 7);
    	printf("该同学已存在，无法录入");
        getch();
			continue ;

		}
	current = (struct lian *)malloc(sizeof(struct lian));
	prev->next = current;
	current->next = NULL;
	strcpy(current->item.name, name);
	gotoxy(44, 10);
	s_gets(current->item.sex, 3);
	gotoxy(44, 13);
	s_gets(current->item.number, 9);
	gotoxy(44, 16);
	if (ban == 0) 
	{
	scanf("%d", &current->item.ban);
	while(getchar() != '\n') ;
	}
	if (ban != 0)
	{
		current->item.ban = ban;
	}
	current->item.math = 0;
	current->item.english = 0;
	current->item.avrg = 0;
	current->item.c = 0;
	current->item.lisan = 0;
	current->item.sum = 0;
	strcpy(current->item.m,"0") ;
	prev = current;
	n++;
	}
	system("cls") ;
	gotoxy(44, 10);
	printf("成功录入%d名同学",n); 
	fp = fopen("shu.txt","r+");
	fscanf(fp,"%d",&shu);
	gotoxy(44, 11);
	printf(" 现共有%d名同学",shu+n) ;
	rewind(fp);
	fprintf(fp,"%d",n+shu);
	cun(); 
	fclose(fp);
	cun2();
	getch();
	return ;
}

//////////////////////////////////////////////////////////////////////////////////////
void addte (struct telian * head2) {                                    //添加老师信息

	char name[31];
	int n = 0 , shu = 0;
	FILE * fp; 
    struct telian  * prev = head2, * current =  NULL , * new2 = head2->next;
    while(prev->next != NULL) prev = prev->next;
    while(1) {
    new2 = head2->next;
    system("cls") ;
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                           学生信息管理系统                                                 |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |     请输入老师信息：                                                                                       |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                               姓名：                                                                       |\n");
	printf("     |                                     （输入回车停止,最多30个字母,15个汉字）                                 |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                               账号：                                                                       |\n");
	printf("     |                                     （最长20位）                                                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                               密码：                                                                       |\n");
	printf("     |                                     （最长20位）                                                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                           管理班级：                                                                       |\n");
	printf("     |                                     （正整数，输入0则管理所有班级）                                        |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                            已经成功录入 0  名老师    ENTER  确认           |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	gotoxy(79, 22);
	printf("%d", n) ;
	gotoxy(44, 7);
	s_gets(name, 30);
	if ( name[0] == '\0' ) break ;
	while(new2 != NULL && strcmp(new2->teitem.name,name) != 0) {
		new2 = new2->next;
    	}
    	if (new2 != NULL)   {
		gotoxy(44, 7);
    	printf("该老师已存在，无法录入");
        getch();
			continue ;

		}
	current = (struct telian *)malloc(sizeof(struct telian));
	prev->next = current;
	current->next = NULL;
	strcpy(current->teitem.name, name);
	gotoxy(44, 10);
	s_gets(current->teitem.z, 20);
	gotoxy(44, 13);
	s_gets(current->teitem.m, 20);
	gotoxy(44, 16);
	scanf("%d",&current->teitem.ban) ;
	while(getchar() != '\n') ; 
	prev = current;
	n++;
	}
	system("cls") ;
	gotoxy(44, 10);
	printf("成功录入%d名老师",n); 
	fp = fopen("laoshu.txt","r+");
	fscanf(fp,"%d",&shu);
	gotoxy(44, 11);
	printf(" 现共有%d名老师",shu+n) ;
	rewind(fp);
	fprintf(fp,"%d",n+shu);
	cun2(); 
	if(fp == NULL){
		
	} 
	fclose(fp);
	
	getch();
	return ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void addgra (struct lian * head) {                                                                             //添加学生成绩
	char name[31];
	int n = 0 ,key = 0;
    struct lian  * prev = head, * current = head->next;

    while(1) {
    	current = head->next ;
    system("cls") ;
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                           学生信息管理系统                                                 |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |     请输入学生成绩：                                                                                       |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                               姓名：                                                                       |\n");
	printf("     |                                     （输入录入成绩学生的姓名，回车停止）                                   |\n");
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
	printf("     |                                                            已经成功录入 0  名同学    ENTER  确认           |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");

		gotoxy(79, 22);
	    printf("%d", n) ;
		gotoxy(44, 7);
		s_gets(name, 30);
		if ( name[0] == '\0' ) break ;
		while(current != NULL && strcmp(current->item.name,name) != 0) {
			current = current->next;
    	}
		if (current == NULL)   {
		gotoxy(44, 7);
    	printf(" 无该同学，按任意键继续输入");
        getch();
			continue ;

		}
		gotoxy(44, 10);
		if (scanf("%3d" ,&current->item.math) == 0)  {
			current->item.math = 0;
			while (getchar() != '\n') ;
		}
		else
			while (getchar() != '\n') ;
		gotoxy(44, 13);
		if (scanf("%3d" ,&current->item.lisan) == 0)  {
			current->item.lisan = 0;
			while (getchar() != '\n') ;
		}
		else
			while (getchar() != '\n') ;
		gotoxy(44, 16);
		if (scanf("%3d" ,&current->item.english) == 0)  {
			current->item.english = 0;
			while (getchar() != '\n') ;
		}
		else
			while (getchar() != '\n') ;
		gotoxy(44, 19);
		if (scanf("%3d" ,&current->item.c) == 0)  {
			current->item.c = 0;
			while (getchar() != '\n') ;
		}
		else
			while (getchar() != '\n') ;
		current->item.sum = current->item.lisan + current->item.math + current->item.english +current->item.c ;
		current->item.avrg = (current->item.lisan + current->item.math + current->item.english +current->item.c) / 4.0;
	    n++;
	}
	system("cls") ;
	gotoxy(44, 10);
	printf("成功录入%d名同学",n);
	cun(); 
	getch();
	return ;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char * s_gets(char * st, int n) {
	char * ret_val;
	char * find ;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue ;
	}
	return ret_val ;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void bianli (struct lian * head)  {
	system("cls") ;
	int y = 7;                                                                //遍历学生输出
	struct lian  * prev = head, * current =  head->next;
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
	if (current != NULL && ban == 0) {
		printf("\t\t\t\t\t\t全体学生信息\n"); 
		printf("姓名                          性别           学号     班级  高数   离散   英语   C语言   平均    总分\n");
		while(current != NULL && ban == 0) {
			printf("%-30s %-2s         %8s     %2d   %3d    %3d    %3d    %3d     %.2f   %3d\n", current->item.name, current->item.sex, current->item.number,
				current->item.ban, current->item.math,current->item.lisan,current->item.english,current->item.c,current->item.avrg, current->item.sum);
			current = current->next;
		}
		getch();
		return ;
	}
	printf("\t\t\t\t\t%d 班 学 生 信 息\n\n", ban); 
	printf("姓名                          性别           学号      高数   离散   英语   C语言   平均    总分\n");
	while(current != NULL && ban != 0) {
		if (ban == current->item.ban) {
			printf("%-30s %-2s          %8s    %3d    %3d    %3d    %3d     %.2f   %3d\n", current->item.name, current->item.sex, current->item.number,
				current->item.math,current->item.lisan,current->item.english,current->item.c,current->item.avrg, current->item.sum);
		}
		current = current->next;
	}
	getch();
	system("cls");
	return;
}

////////////////////////////////////////////////////////////////////////////////////////////////
void bianli1 (struct telian * head2)  {
	system("cls") ;
	int y = 7;                                                                //遍历老师输出
	struct telian  * prev = head2, * current =  head2->next;
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
		getch();
		return ;
	}
	if (current != NULL) {
		printf("\t\t\t                姓名                账号                密码   管理班级 \n");
	} 
	while(current != NULL) {
	printf("\t\t\t%20s%20s%20s      %3d\n",current->teitem.name,current->teitem.z,current->teitem.m,current->teitem.ban);
	current = current->next;
	}
	getch();
	system("cls") ;
	return ;
}
//////////////////////////////////////////////////////////////////////////////////////
void cut (struct lian * head) {   
	FILE * fp;                                        							//删除学生
	struct lian  * prev = head, * current =  head;
	int shu = 0; 
	system("cls") ;
	char c[100];
	printf("请输入删除学生的名称：(输入回车停止)\n");
	while (s_gets(c, 30) != NULL && c[0] != '\0' )
	{
		while(current->next!= NULL && strcmp(current->next->item.name,c) != 0) {
			current = current->next;
    	}
    	if (current->next == NULL) {
    		printf ("没有找到该同学，请从新输入：（输入回车停止）\n");
    		current =  head ;
    		continue ;
		}
		if (ban == 0 || ban == current->next->item.ban)
    	{
		prev = current->next;
    	current->next = current->next->next;
    	current = head;
    	free(prev);
    	fp = fopen("shu.txt","r+");
		fscanf(fp,"%d",&shu);
		rewind(fp);
		fprintf(fp,"%d",shu-1);
    	printf("删除成功，还剩%d位同学，请输入下一位：(输入回车停止)\n",shu-1);
    	fclose(fp); 
  		  }
  		else 
  		 {
  		 	printf("%d %d",ban, current->item.ban);
  		 	printf("没有找到该同学，请从新输入：\n") ;
  		 	getchar();
		} 
  		
    
	}
	cun();
}
//////////////////////////////////////////////////////////////////////////////////////
void cut1 (struct telian * head2) {   
	FILE * fp;                                        							//删除老师 
	struct telian  * prev = head2, * current =  head2;
	int shu = 0; 
	system("cls") ;
	char c[100];
	printf("请输入删除老师的名称：(输入回车停止)\n");
	while (s_gets(c, 30) != NULL && c[0] != '\0' )
	{
		while(current->next != NULL && strcmp(current->next->teitem.name,c) != 0) {
			current = current->next;
    	}
    	if (current->next == NULL) {
    		printf ("没有找到该老师，请从新输入：（输入回车停止）\n");
    		current =  head2 ;
    		continue ;
		}
    	prev = current->next;
    	current->next = current->next->next;
    	current = head2 ;
    	free(prev);
    	fp = fopen("laoshu.txt","r+");
		fscanf(fp,"%d",&shu);
		rewind(fp);
		fprintf(fp,"%d",shu-1);
    	printf("删除成功，还剩%d位老师，请输入下一位：(输入回车停止)\n",shu-1);
    	fclose(fp); 
	}
	    	cun2(); 
}
	//////////////////////////////////////////////////////////////////////////////////////
