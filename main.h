void Mainframe();
void exit();
void setErrorOne(int a,int b);
void SecFrame();
//链表定义
typedef struct Linklist{
		char na[20];//存放名字
		char ph[20];//存放电话号码
		char ad[20];//存放地址
		char em[20];
		struct Linklist *next;
}Linklist,*LNode;
Linklist *L,*s;
//一号功能界面
void find(Linklist *L){
	Linklist *p;
	p=L;
	char input[20],a;
	printf("\n\t请输入您要查找的姓名：");
	scanf("%s",&input);
loop:
	while(p){
		if(strcmp(p->na,input)==0){
			printf("\tname:%s phone:%s address:%s E-mail:%s\n",p->na,p->ph,p->ad,p->em);
			break;
		}
		p=p->next;
	}
	if(p==NULL){
		system("cls");
		printf("ERROR[004]:CAN NOT FIND.Please input again.");
		find(L);
	}else{
		printf("\t输入*返回上一层\n\t");
		getchar();
		scanf("%c",&a);
		if(a=='*'){
			system("cls");
			Mainframe();
		}else{
			system("cls");
			printf("ERROR[001]:NULL POINT.Please input again.");
			printf("\n\t请输入您要查找的姓名：%s\n",input);
			goto loop;
		}
	}
}
//二号功能页一号功能
void insert(Linklist *L){
	char a;
	Linklist *p,*s;
	p=L;
	while(p->next){
		p=p->next;
	}
	s=(LNode)malloc(sizeof(Linklist));
	printf("\n\n\t姓名：");
	scanf("%s",s->na);
	printf("\t移动号码：");
	scanf("%s",s->ph);
	printf("\t地址：");
	scanf("%s",s->ad);
	printf("\t邮箱：");
	scanf("%s",s->em);
	s->next=NULL;
	p->next=s;
	system("cls");
loop:
	printf("\n\n\n\t插入成功\n");
	printf("\t输入*返回上一层\n\t");
	getchar();
	scanf("%c",&a);
	if(a=='*'){
		system("cls");
		SecFrame();
	}else{
		system("cls");
		printf("ERROR[001]:NULL POINT.Please input again.");
		goto loop;
	}
}
//二号功能页二号功能
void del(Linklist *L){
	Linklist *p,*q;
	p=L;
	int i;
	char n[20],a;
	printf("\n\n\t需要删除项姓名：");
	scanf("%s",&n);
	while(p){
		if(strcmp(n,p->na)==0){
			break;
		}
		p=p->next;
		i++;
	}
	p=L;
	for(int j=0;j<i;j++){
		p=p->next;
	}
	if(p==NULL){
		system("cls");
		printf("ERROR[004]:CAN NOT FIND.Please input again.");
		del(L);
	}
	else{
		q=p->next;
		p->next=q->next;
		free(q);
		system("cls");
loop:
		printf("\n\t删除成功");
	}
	printf("\n\t输入*返回上一层\n\t");
	getchar();
	scanf("%c",&a);
	if(a=='*'){
		system("cls");
		SecFrame();
	}else{
		system("cls");
		printf("ERROR[001]:NULL POINT.Please input again.");
		goto loop;
	}
}
//二号功能页三号功能
void update(Linklist *L){
	Linklist *p;
	p=L;
	char n[20],a;
	getchar();
	printf("\n\n\t需要修改项的姓名：");
	scanf("%s",&n);
	while(p){
		if(strcmp(n,p->na)==0){
			break;
		}
		p=p->next;
	}
	if(p==NULL){
		system("cls");
		printf("ERROR[004]:CAN NOT FIND.Please input again.");
		update(L);
	}
	else{
		printf("\t姓名：");
		scanf("%s",p->na);
		printf("\t移动号码：");
		scanf("%s",p->ph);
		printf("\t地址：");
		scanf("%s",p->ad);
		printf("\t邮箱：");
		scanf("%s",p->em);
		system("cls");
loop:
		printf("\n\n\t修改成功\n");
	}
	printf("\t输入*返回上一层\n\t");
	getchar();
	scanf("%c",&a);
	if(a=='*'){
		system("cls");
		SecFrame();
	}else{
		system("cls");
		printf("ERROR[001]:NULL POINT.Please input again.");
		goto loop;
	}
}
//二号功能页面
void SecFrame(){
	int a;
	printf("\n\n\t******************************************************************\n");
	printf("\t*                     通讯录管理系统                             *\n");
	printf("\t******************************************************************\n\n\n");
	printf("\t******************************************************************\n");
	printf("\t*       请输入以下序号执行操作                                   *\n");
	printf("\t*       1.新建联系人                                             *\n");
	printf("\t*       2.删除联系人                                             *\n");
	printf("\t*       3.修改联系人信息                                         *\n");
	printf("\t*       4.返回首页                                               *\n");
	printf("\t******************************************************************\n");
	printf("\t请输入您选择的序号：");
	scanf("%d",&a);
	setErrorOne(a,1);
	switch(a){
	case 1:
		system("cls");
		insert(L);
		break;
	case 2:
		system("cls");
		del(L);
		break;
	case 3:
		system("cls");
		update(L);
		break;
	case 4:
		system("cls");
		Mainframe();
		break;
	}

}
//三号功能页面
//输出链表所有值
void output(Linklist *L){
	Linklist *p;
	char a;
	getchar();
	p=L->next;
	printf("\n\n");
	while(p){
		printf("\tname:%s phone:%s address:%s E-mail:%s\n",p->na,p->ph,p->ad,p->em);
		p=p->next;
	}
	printf("\t输入*返回上一层");
	scanf("%c",&a);
	if(a=='*'){
		system("cls");
		Mainframe();
	}else{
		system("cls");
		printf("ERROR[001]:NULL POINT.Please input again.");
		SecFrame();
	}
}
/*
错误说明一：输入的序号不存在，请重新输入。
*/
void setErrorOne(int a,int b){
	if(b==0){	
		if(a>6||a<1){
			system("cls");
			printf("ERROR[001]:NULL POINT.Please input again.");
			Mainframe();
		}
	}
	if(b==1){	
		if(a>4||a<1){
			system("cls");
			printf("ERROR[001]:NULL POINT.Please input again.");
			SecFrame();
		}
	}
}
/*
错误说明函数
*/
void showError(){
	char temp;
	printf("\n\n\t以下为系统报错说明：\n");
	printf("\tERROR[001]:NULL POINT.Please input again.\n\t错误一：输入的序号不存在，请重新输入。\n\n");
	printf("\tERROR[002]:INVALID CHARACTERS.Please input again.\n\t错误二：无效字符，请重新输入。\n\n");
	printf("\tError[003]:CAN'T OPEN FILE.(file name)\n\t错误三：无法打开文件(文件名)\n\n");
	printf("\tERROR[004]:CAN NOT FIND.Please input again.\n\t错误四：无法找到该目标，请重新输入\n\n");
	printf("\t输入*返回首页\n\t");
	
	getchar();
	scanf("%c",&temp);
	if(temp=='*'){
		system("cls");
		Mainframe();
	}else{
		system("cls");
		printf("ERROR[002]:INVALID CHARACTERS.Please input again.");
		showError();
	}
}
/*
系统退出函数
*/
void exit(Linklist *L){
	//system("color 0A");
	system("cls");
	int i=0;
	Linklist *p;
	char allname[2000],allphone[2000],alladdress[2000],allemail[2000],temp[2]="*",loop[50];
	FILE *wna=fopen("name.txt","w");
	FILE *wph=fopen("phone.txt","w");
	FILE *wmo=fopen("address.txt","w");
	FILE *wem=fopen("email.txt","w");
	strcpy(allname,temp);
	strcpy(allphone,temp);
	strcpy(alladdress,temp);
	strcpy(allemail,temp);
	p=L->next;
	printf("\n\n\t正在储存变更信息");
	while(p){
		strcpy(loop,p->na);
		strcat(loop,temp);
		strcat(allname,loop);
		strcpy(loop,p->ph);
		strcat(loop,temp);
		strcat(allphone,loop);
		strcpy(loop,p->ad);
		strcat(loop,temp);
		strcat(alladdress,loop);
		strcpy(loop,p->em);
		strcat(loop,temp);
		strcat(allemail,loop);
		p=p->next;
		printf(".");
		Sleep(100);
		i++;
	}
	printf("\n\tOpen .txt and save.\n");
	printf("\t%s\n",allname);
	Sleep(100);
	printf("\t%s\n",allphone);
	Sleep(100);
	printf("\t%s\n",alladdress);
	Sleep(100);
	printf("\t%s\n",allemail);
	Sleep(100);
	printf("\t校验值：%d\n",i);
	fprintf(wna,"%s",allname);
	fprintf(wph,"%s",allphone);
	fprintf(wmo,"%s",alladdress);
	fprintf(wem,"%s",allemail);
	fclose(wna);
	fclose(wph);
	fclose(wmo);
	fclose(wem);
	printf("\n\n\t储存完成\n\n");
	Sleep(1000);
	//system("color f0");
	system("cls");
	printf("\n\n\t感谢您的使用，再见！\n\n");
	getchar();
}
/*
关于函数
*/
void about(){
	char temp;
	printf("\n\n\tProgrammer:baogang Song\n\tTime:2018/12/27\n\tData:0.0.3\n");
	printf("\t输入*返回首页\n\t");
	getchar();
	scanf("%c",&temp);
	if(temp=='*'){
		system("cls");
		Mainframe();
	}else{
		system("cls");
		printf("ERROR[002]:INVALID CHARACTERS.Please input again.");
		about();
	}
}
/*
用户选择跳转函数
*/
void Chose(int a){
	switch(a){
	case 1:
		system("cls");
		find(L);
		break;
	case 2:
		system("cls");
		SecFrame();
		break;
	case 3:
		system("cls");
		output(L);
		break;
	case 4:
		system("cls");
		about();
		break;
	case 5:
		system("cls");
		showError();
		break;
	case 6:
		exit(L);
		break;
	}
}
void welcome(){
	//system("color f1");
	printf("\n\n\n\n\n\n\n\n\n\n\t******************************************************************\n");
	printf("\t*                     欢迎使用通讯录管理系统                     *\n");
	printf("\t******************************************************************\n\n\n");
}
/*
主界面
*/
void Mainframe(){
	int chose;//用户选择序号时用的变量
	printf("\n\n\n\n\t******************************************************************\n");
	printf("\t*                     通讯录管理系统                             *\n");
	printf("\t******************************************************************\n\n");
	printf("\t******************************************************************\n");
	printf("\t*       请输入以下序号执行操作                                   *\n");
	printf("\t*       1.查询联系人                                             *\n");
	printf("\t*       2.信息维护                                               *\n");
	printf("\t*       3.查看全部联系人                                         *\n");
	printf("\t*       4.关于                                                   *\n");
	printf("\t*       5.错误说明                                               *\n");
	printf("\t*       6.储存并退出                                             *\n");
	printf("\t*          请不要使用关闭键退出程序否则将无法保存数据            *\n");
	printf("\t******************************************************************\n");
	printf("\t请输入您选择的序号：");
	scanf("%d",&chose);
	printf("%d",chose);
	setErrorOne(chose,0);
	Chose(chose);
}