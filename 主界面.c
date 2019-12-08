
#include "manager.h"
void jiami(char x[]) {
	for (int i = 0; i < strlen(x); i++) {
		x[i] = x[i] + 10 + i;
		int a = 1;
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
	printf("     |                                           ѧ����Ϣ����ϵͳ                                                 |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |           ��ѡ����ݣ�                                                                                     |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                     |         1.����Ա         |                                           |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                               2.��ʦ                                                       |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                               3.ѧ��                                                       |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                               4.�˳�����                                                   |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                   ��������       ENTER  ȷ��               |\n");
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
	fp = fopen("����Ա�˺�����.txt", "r");
	char z[21], m[21], c, zd[21], md[21];
	while (1) {
	system("cls") ;
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                              ѧ����Ϣ����ϵͳ                                              |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                ����Ա��¼                                                  |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                      �˺ţ�                                                                |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                      ���룺                                                                |\n");
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
	printf("     |                                                                                   ENTER  ȷ��              |\n");
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
		printf("�˺Ż�������󣬰����������");
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
	printf("     |                                              ѧ����Ϣ����ϵͳ                                              |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                ��ʦ��¼                                                    |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                      �˺ţ�                                                                |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                      ���룺                                                                |\n");
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
	printf("     |                                                                                   ENTER  ȷ��              |\n");
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
		printf("�˺Ż�������󣬰����������");
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
		printf("�˺Ż�������󣬰����������");
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
	printf("     |                                              ѧ����Ϣ����ϵͳ                                              |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                ѧ����¼                                                    |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                      �˺ţ�                                                                |\n");
	printf("     |                                            ��������                                                        |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                      ���룺                                                                |\n");
	printf("     |                                            �����ε�¼Ĭ��Ϊ0����������޸����룩                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                   ENTER  ȷ��              |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	gotoxy(50,10);
	s_gets(c, 30);
	if ( c[0] == '\0' ) break ;
			while(current != NULL && strcmp(current->item.name,c) != 0) {
		current = current->next;
    	}
    	if (current == NULL)   {
		gotoxy(50,10);
    	printf("��ͬѧ������");
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
		printf("�˺Ż�������󣬰����������");
		getch();
	}
}

void denglu1_1() {
	while (1) {
	system("cls") ;
	    char c;
	int b = 1, x = 38 , y = 7;
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                           ѧ����Ϣ����ϵͳ                                                 |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |           ��ѡ��                                                                                         |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                     |      1.������ʦ��Ϣ      |                                           |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                            2.����ѧ����Ϣ                                                  |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                            3.����                                                          |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                   ��������       ENTER  ȷ��               |\n");
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
	printf("     |                                           ѧ����Ϣ����ϵͳ                                                 |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                     |        1.��ʦĿ¼        |                                           |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                              2.�����ʦ                                                    |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                              3.ɾ����ʦ                                                    |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                              4.�޸���ʦ����                                                |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                              5.����                                                        |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
    printf("     |                                                                                                            |\n");
	printf("     |                                                                   ��������       ENTER  ȷ��               |\n");
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
	printf("     |                                           ѧ����Ϣ����ϵͳ                                                 |\n");
	printf("     --------------------------------------------------------------------------------------------------------------\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                     |     1.ѧ�����˳ɼ���ѯ   |                                           |\n");
	printf("     |                                     ============================                                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                           2.ȫ�ఴ��������                                                 |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                           3.ȫ���ܷ�/ƽ��������                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                           4.�޸��ҵ�����                                                   |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                           5.����                                                           |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                                                            |\n");
	printf("     |                                                                   ��������       ENTER  ȷ��               |\n");
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
////////////////////														ѧ���ɼ���ѯ 
void cha2(struct lian * current) {
		system("cls") ;
		char c[31];
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		printf("     |                                           ѧ����Ϣ����ϵͳ                                                 |\n");
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		printf("     |                                                                                                            |\n");
		printf("     |                               ������                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                               ƽ����                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                               ������                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                               ��ɢ��                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                               Ӣ�                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                              C���ԣ�                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                               �ܷ֣�                                                 ENTER  ȷ��           |\n");
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
/////////////////////////////////////////////// 														�޸����� 
void xiu(struct lian * current) {
		struct lian * xian = head;
		while(1) {
		system("cls") ;
		char c[31],b[31], n[31];
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		printf("     |                                           ѧ����Ϣ����ϵͳ                                                 |\n");
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                       �������˺ţ���                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                            ������ ��                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                          �ٴ����� ��                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                      ENTER  ȷ��           |\n");
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
    		printf ("û���ҵ���ͬѧ����������룺��ֱ�Ӱ��س����أ�\n");
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
			printf("�޸ĳɹ�\n");
			gotoxy(50,16);
			printf("������Ϊ%s",xian->next->item.m) ; 
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
			printf("�޸ĳɹ�\n");
			gotoxy(50,17);
			printf("������Ϊ%s",current->item.m) ; 
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
		printf("     |                                           ѧ����Ϣ����ϵͳ                                                 |\n");
		printf("     --------------------------------------------------------------------------------------------------------------\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                              �˺� ��                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                            ������ ��                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                          �ٴ����� ��                                                                       |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                                            |\n");
		printf("     |                                                                                      ENTER  ȷ��           |\n");
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
    		printf ("û���ҵ�����ʦ����������룺��ֱ�Ӱ��س����أ�\n");
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
				printf("\t�޸ĳɹ�\n");
				gotoxy(44,17);
				printf("������Ϊ%s",xian->next->teitem.m) ; 
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
			printf("\t�޸ĳɹ�\n");
			gotoxy(44,17);
			printf("������Ϊ%s",laop->teitem.m) ; 
			getch();
			cun2() ; 
			return ; 
		}
	}
}
}
