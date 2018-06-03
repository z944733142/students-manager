
#include "manager.h"
void cun() {
	struct lian * current =  head->next;
	FILE * fp;
	fp = fopen("lian.txt","w");
	if (fp == NULL) {

	}
	while (current != NULL) {
		fwrite(current,sizeof(struct ms),1,fp);
		current = current->next;
	} 

	fclose(fp);
}

void cun2() {
	struct telian * current =  head2->next;
	FILE * fp;
	fp = fopen("laolian.txt","w");
	if (fp == NULL) {

	}
	while (current != NULL) {
		fwrite(current,sizeof(struct tems),1,fp);
		current = current->next;
	} 

	fclose(fp);
}


void du() {
	struct lian  * prev = head, * current =  NULL;
	int shu = 0;
	FILE * fp;
	fp = fopen("shu.txt","r");
		if (fp == NULL) {
		
	}
	fscanf(fp,"%d",&shu);
	fclose(fp);
	fp = fopen("lian.txt","r");
	
	if (fp == NULL) {
		
	}
	while(shu--){
		current = (struct lian *)malloc(sizeof(struct lian));
	    fread(current,sizeof(struct ms),1,fp);
	    prev->next = current;
	    current->next = NULL;
	    prev = current;

	
	}
	fclose(fp);
}

void du2() {
	struct telian  * prev = head2, * current =  NULL;
	int shu = 0;
	FILE * fp;
	fp = fopen("laoshu.txt","r");
		if (fp == NULL) {
		
	}
	fscanf(fp,"%d",&shu);
	fclose(fp);
	fp = fopen("laolian.txt","r");
	
	if (fp == NULL) {
		
	}
	while(shu--){
		current = (struct telian *)malloc(sizeof(struct telian));
	    fread(current,sizeof(struct tems),1,fp);
	    prev->next = current;
	    current->next = NULL;
	    prev = current;

	
	}
	fclose(fp);
}

