void Mainframe();
void exit();
void setErrorOne(int a,int b);
void SecFrame();
//������
typedef struct Linklist{
		char na[20];//�������
		char ph[20];//��ŵ绰����
		char ad[20];//��ŵ�ַ
		char em[20];
		struct Linklist *next;
}Linklist,*LNode;
Linklist *L,*s;
//һ�Ź��ܽ���
void find(Linklist *L){
	Linklist *p;
	p=L;
	char input[20],a;
	printf("\n\t��������Ҫ���ҵ�������");
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
		printf("\t����*������һ��\n\t");
		getchar();
		scanf("%c",&a);
		if(a=='*'){
			system("cls");
			Mainframe();
		}else{
			system("cls");
			printf("ERROR[001]:NULL POINT.Please input again.");
			printf("\n\t��������Ҫ���ҵ�������%s\n",input);
			goto loop;
		}
	}
}
//���Ź���ҳһ�Ź���
void insert(Linklist *L){
	char a;
	Linklist *p,*s;
	p=L;
	while(p->next){
		p=p->next;
	}
	s=(LNode)malloc(sizeof(Linklist));
	printf("\n\n\t������");
	scanf("%s",s->na);
	printf("\t�ƶ����룺");
	scanf("%s",s->ph);
	printf("\t��ַ��");
	scanf("%s",s->ad);
	printf("\t���䣺");
	scanf("%s",s->em);
	s->next=NULL;
	p->next=s;
	system("cls");
loop:
	printf("\n\n\n\t����ɹ�\n");
	printf("\t����*������һ��\n\t");
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
//���Ź���ҳ���Ź���
void del(Linklist *L){
	Linklist *p,*q;
	p=L;
	int i;
	char n[20],a;
	printf("\n\n\t��Ҫɾ����������");
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
		printf("\n\tɾ���ɹ�");
	}
	printf("\n\t����*������һ��\n\t");
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
//���Ź���ҳ���Ź���
void update(Linklist *L){
	Linklist *p;
	p=L;
	char n[20],a;
	getchar();
	printf("\n\n\t��Ҫ�޸����������");
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
		printf("\t������");
		scanf("%s",p->na);
		printf("\t�ƶ����룺");
		scanf("%s",p->ph);
		printf("\t��ַ��");
		scanf("%s",p->ad);
		printf("\t���䣺");
		scanf("%s",p->em);
		system("cls");
loop:
		printf("\n\n\t�޸ĳɹ�\n");
	}
	printf("\t����*������һ��\n\t");
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
//���Ź���ҳ��
void SecFrame(){
	int a;
	printf("\n\n\t******************************************************************\n");
	printf("\t*                     ͨѶ¼����ϵͳ                             *\n");
	printf("\t******************************************************************\n\n\n");
	printf("\t******************************************************************\n");
	printf("\t*       �������������ִ�в���                                   *\n");
	printf("\t*       1.�½���ϵ��                                             *\n");
	printf("\t*       2.ɾ����ϵ��                                             *\n");
	printf("\t*       3.�޸���ϵ����Ϣ                                         *\n");
	printf("\t*       4.������ҳ                                               *\n");
	printf("\t******************************************************************\n");
	printf("\t��������ѡ�����ţ�");
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
//���Ź���ҳ��
//�����������ֵ
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
	printf("\t����*������һ��");
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
����˵��һ���������Ų����ڣ����������롣
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
����˵������
*/
void showError(){
	char temp;
	printf("\n\n\t����Ϊϵͳ����˵����\n");
	printf("\tERROR[001]:NULL POINT.Please input again.\n\t����һ���������Ų����ڣ����������롣\n\n");
	printf("\tERROR[002]:INVALID CHARACTERS.Please input again.\n\t���������Ч�ַ������������롣\n\n");
	printf("\tError[003]:CAN'T OPEN FILE.(file name)\n\t���������޷����ļ�(�ļ���)\n\n");
	printf("\tERROR[004]:CAN NOT FIND.Please input again.\n\t�����ģ��޷��ҵ���Ŀ�꣬����������\n\n");
	printf("\t����*������ҳ\n\t");
	
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
ϵͳ�˳�����
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
	printf("\n\n\t���ڴ�������Ϣ");
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
	printf("\tУ��ֵ��%d\n",i);
	fprintf(wna,"%s",allname);
	fprintf(wph,"%s",allphone);
	fprintf(wmo,"%s",alladdress);
	fprintf(wem,"%s",allemail);
	fclose(wna);
	fclose(wph);
	fclose(wmo);
	fclose(wem);
	printf("\n\n\t�������\n\n");
	Sleep(1000);
	//system("color f0");
	system("cls");
	printf("\n\n\t��л����ʹ�ã��ټ���\n\n");
	getchar();
}
/*
���ں���
*/
void about(){
	char temp;
	printf("\n\n\tProgrammer:baogang Song\n\tTime:2018/12/27\n\tData:0.0.3\n");
	printf("\t����*������ҳ\n\t");
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
�û�ѡ����ת����
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
	printf("\t*                     ��ӭʹ��ͨѶ¼����ϵͳ                     *\n");
	printf("\t******************************************************************\n\n\n");
}
/*
������
*/
void Mainframe(){
	int chose;//�û�ѡ�����ʱ�õı���
	printf("\n\n\n\n\t******************************************************************\n");
	printf("\t*                     ͨѶ¼����ϵͳ                             *\n");
	printf("\t******************************************************************\n\n");
	printf("\t******************************************************************\n");
	printf("\t*       �������������ִ�в���                                   *\n");
	printf("\t*       1.��ѯ��ϵ��                                             *\n");
	printf("\t*       2.��Ϣά��                                               *\n");
	printf("\t*       3.�鿴ȫ����ϵ��                                         *\n");
	printf("\t*       4.����                                                   *\n");
	printf("\t*       5.����˵��                                               *\n");
	printf("\t*       6.���沢�˳�                                             *\n");
	printf("\t*          �벻Ҫʹ�ùرռ��˳���������޷���������            *\n");
	printf("\t******************************************************************\n");
	printf("\t��������ѡ�����ţ�");
	scanf("%d",&chose);
	printf("%d",chose);
	setErrorOne(chose,0);
	Chose(chose);
}