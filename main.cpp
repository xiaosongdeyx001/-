
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include"main.h"
void main(){
	system("title 通讯录管理系统");
	//system("color 0A");
	//system("VER");
	//system("VOL");
	system("date /t & time /t")
	printf("\tTime:2018/12/15\n");
	char name[50][20],phone[50][20],address[50][20],email[50][20];//拆分数组定义
	char allname[2000],allphone[2000],alladdress[2000],allemail[2000];//获取数组定义
	printf("\tLoading");
	for(int q=0;q<=7;q++){
		Sleep(100);
		printf(" .");
	}
	printf("\n");
	//读取姓名存储文件
	FILE *fr=fopen("name.txt","r");
	if(fr==NULL){
		printf("Error[003]:CAN'T OPEN FILE.(name.txt)");
	}else{
		fscanf(fr,"%s",allname);
	}
	fclose(fr);
	printf("\t%s\n\t",allname);
	//解析姓名字符串
	for(int i=0, j=0, k=0;allname[i]!='\0';i++){
		if(i==0)i++;
		if(allname[i]=='*'){
			name[j][k]='\0';
			printf(" *");
			Sleep(100);
			j++;
			k=0;
			continue;
		}
		name[j][k]=allname[i];	
		k++;
	}
	printf("\n");
	for(int x=0;x<j;x++){
		Sleep(100);
		printf("\t%s\n",name[x]);
	}
	Sleep(1500);
	printf("\tReady name.txt\n");
	//读取移动电话存储文件
	fr=fopen("phone.txt","r");
	if(fr==NULL){
		printf("Error[003]:CAN'T OPEN FILE.(phone.txt)");
	}else{
		fscanf(fr,"%s",allphone);
	}
	fclose(fr);
	printf("\t%s\n\t",allphone);
	//解析移动电话字符串
	for(i=0,j=0,k=0;allphone[i]!='\0';i++){
		if(i==0)i++;
		if(allphone[i]=='*'){
			phone[j][k]='\0';
			printf(" *");
			Sleep(100);
			j++;
			k=0;
			continue;
		}
		phone[j][k]=allphone[i];	
		k++;
	}
	printf("\n");
	for(x=0;x<j;x++){
		Sleep(100);
		printf("\t%s\n",phone[x]);
	}
	Sleep(1500);
	printf("\tReady phone.txt\n");
	//读取地址字符串 
	fr=fopen("address.txt","r");
	if(fr==NULL){
		printf("Error[003]:CAN'T OPEN FILE.(address.txt)");
	}else{
		fscanf(fr,"%s",alladdress);
	}
	fclose(fr);
	printf("\t%s\n\t",alladdress);
	//解析地址字符串 
	for(i=0,j=0,k=0;alladdress[i]!='\0';i++){
		if(i==0)i++;
		if(alladdress[i]=='*'){
			address[j][k]='\0';
			printf(" *");
			Sleep(100);
			j++;
			k=0;
			continue;
		}
		address[j][k]=alladdress[i];	
		k++;
	}
	printf("\n");
	for(x=0;x<j;x++){
		Sleep(100);
		printf("\t%s\n",address[x]);
	}
	Sleep(1500);
	printf("\tReady address.txt\n");
	//读取邮箱存储文件
	fr=fopen("email.txt","r");
	if(fr==NULL){
		printf("Error[003]:CAN'T OPEN FILE.(email.txt)");
	}else{
		fscanf(fr,"%s",allemail);
	}
	fclose(fr);
	printf("\t%s\n\t",allemail);
	//解析邮箱字符串
	for(i=0,j=0,k=0;allemail[i]!='\0';i++){
		if(i==0)i++;
		if(allemail[i]=='*'){
			email[j][k]='\0';
			printf(" *");
			Sleep(100);
			j++;
			k=0;
			continue;
		}
		email[j][k]=allemail[i];	
		k++;
	}
	printf("\n");
	for(x=0;x<j;x++){
		Sleep(100);
		printf("\t%s\n",email[x]);
	}
	Sleep(1500);
	printf("\tReady email.txt\n");
	Sleep(1500);
	printf("\tReady to create a link list");
	for(q=0;q<=7;q++){
		Sleep(500);
		printf(" .");
	}
	printf("\n");
	printf("\t校验值：%d\n",j);
	//链表赋值新建
	L=(LNode)malloc(sizeof(Linklist));
	L->next=NULL;
	for(x=0;x<j;x++){
		s=(LNode)malloc(sizeof(Linklist));
		strcpy(s->na,name[x]);
		strcpy(s->ph,phone[x]);
		strcpy(s->ad,address[x]);  
		strcpy(s->em,email[x]);
		s->next=L->next;
		L->next=s;
		printf("\t%s:%s %s %s %s %s\n",&s,s->na,s->ph,s->ad,s->em,&s->next);
		Sleep(100);
	}
	printf("\tCreate link list succes\n");
	Sleep(1000);
	printf("\tPlease wait");
	for(q=0;q<=7;q++){
		Sleep(500);
		printf(" .");
	}
	printf("\n");
	Sleep(1500);
	system("cls");
	welcome();
	Sleep(2000);
	system("cls");
	//开启主界面
	Mainframe();
}
