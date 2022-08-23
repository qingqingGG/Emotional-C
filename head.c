#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#define N sizeof(struct STUDENT)
#define M sizeof(struct REGISTRATION)
#include "head.h" 

struct STUDENT {           	//ѧ����Ϣ
	char number[12];       	//ѧ��
	char name[10];         	//����
	char profession[10];  	//רҵ��
	char sex[4];          	//�Ա�
	char nationality[10]; 	//����
	char telephone[13];  	//�ֻ�
	float Language;    	 	//���ĳɼ�
	float Math;             //��ѧ�ɼ�
	float English;          //Ӣ��ɼ�
	float total;            //�ܳɼ�
	float average;          //ƽ���ɼ�
	int x;
	struct STUDENT *next;   //ָ����
};

struct REGISTRATION {
	char name[12];           //�û���
	char code[20];           //����
	char telephone[14];      //��ϵ��ʽ
	int x;
	struct REGISTRATION *next;     //ָ����
};

void HideCursor() { //���ع��
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void color(short x) {
	if(x>=0&&x<=15) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	} else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	}
}

void toxy(int x, int y) { //������ƶ���X,Y���괦
	COORD pos = { x , y };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}

void menu() { //�˵�
	do {
		system("cls"); //����
		HideCursor(); //���ع��
		color(15);  //����һ���ÿ�����ɫ
		char t;
		toxy(35,7);
		printf("-------------ѧ����Ϣ����ϵͳ-------------\n");
		toxy(35,8);
		printf("|                                        |\n");
		toxy(35,9);
		printf("|                1.��Ϣ���              |\n");
		toxy(35,10);
		printf("|                2.�޸���Ϣ              |\n");
		toxy(35,11);
		printf("|                3.ɾ����Ϣ              |\n");
		toxy(35,12);
		printf("|                4.��Ϣ��ѯ              |\n");
		toxy(35,13);
		printf("|                5.��Ϣ����              |\n");
		toxy(35,14);
		printf("|                6.�˳����              |\n");
		toxy(35,15);
		printf("|                7.�л��˺�              |\n");
		toxy(35,16);
		printf("|                8.�ù���ģʽ��        |\n");
		toxy(35,17);
		printf("|                                        |\n");
		toxy(35,18);
		printf("------------------------------------------\n");
		toxy(35,19);
		printf("        ����������Ҫ���еĲ�����ţ�      \n");
		t=getch();  //�����Ժ���
		switch(t) {
			case '1':
				input_student();
				break;
			case '2':
				amend_student();
				break;
			case '3':
				del_student();
				break;
			case '4':
				find_student();
				break;
			case '5':
				print_student();
				break;
			case '6':
				over();
				break;
			case '7':
				land_interface();
				break;
			case '8':
				manager_code();
				break;
			default :
				break;
		}
	} while(1);
}

student ss() { //��ѧ����Ϣ�ļ��е����ݶ����������У�����ֵΪ��ͷ��ַ
	FILE *fp;    //�ļ�ָ��
	int n=0;
	student head=NULL;
	student p2,p,pr=NULL;
	fp=fopen("studentlist.txt","ab+");   //��ֻ���ķ�ʽ���ļ�
	if(fp==NULL) {
		printf("cannot open file\n");
	}
	while(!feof(fp)) {  //�ж��ļ�λ�ñ�־�Ƿ��ƶ����ļ�ĩβ
		n++;
		p=(student)malloc(N); //���ڴ�����һ�οռ�
		fread(p,N,1,fp);   //��fp��ָ����ļ��е����ݸ���p
		if(n==1) {
			head=p;
			p2=p;
		} else {   //��������
			pr=p2;
			p2->next=p;
			p2=p;
		}
	}
	if(pr!=NULL)
		pr->next=NULL;
	else
		head=NULL;
	fclose(fp);  //�ر��ļ�
	return head;  //����ͷָ��
}

registration cc() { //��ע����Ϣ�ļ��е����ݶ����������У�����ֵΪ��ͷ��ַ
	FILE *fp;    //�ļ�ָ��
	int n=0;
	registration head=NULL;
	registration p2,p,pr=NULL;
	fp=fopen("registration.txt","ab+");   //��ֻ���ķ�ʽ���ļ�
	if(fp==NULL) {
		printf("cannot open file\n");
	}
	while(!feof(fp)) {  //�ж��ļ�λ�ñ�־�Ƿ��ƶ����ļ�ĩβ
		n++;
		p=(registration)malloc(M); //���ڴ�����һ�οռ�
		fread(p,M,1,fp);   //��fp��ָ����ļ��е����ݸ���p
		if(n==1) {
			head=p;
			p2=p;
		} else {   //��������
			pr=p2;
			p2->next=p;
			p2=p;
		}
	}
	if(pr!=NULL)
		pr->next=NULL;
	else
		head=NULL;
	fclose(fp);  //�ر��ļ�
	return head;  //����ͷָ��
}

void input_student() { //ѧ����Ϣ¼��
	do {
		system("cls");
		color(10);
		char t;
		student p;
		p=(student)malloc(N);   //����ռ�
		//����ѧ����Ϣ
		printf("������ѧ��(С��12λ��)��\n");
		scanf("%s",p->number);
		getchar();
		printf("����������(С��8����)��\n");
		scanf("%s",p->name);
		getchar();
		printf("������רҵ��(С�ڵ���5����)��\n");
		scanf("%s",p->profession);
		getchar();
		printf("��������ϵ��ʽ(С�ڵ���13λ��)��\n");
		scanf("%s",p->telephone);
		getchar();
		printf("�����뼮��(С�ڵ���5����)��\n");
		scanf("%s",p->nationality);
		getchar();
		printf("�������Ա�(С��4λ��)��\n");
		scanf("%s",p->sex);
		getchar();
		printf("���������ĳɼ���\n");
		scanf("%f",&p->Language);
		getchar();
		printf("��������ѧ�ɼ���\n");
		scanf("%f",&p->Math);
		getchar();
		printf("������Ӣ��ɼ���\n");
		scanf("%f",&p->English);
		getchar();
		p->total=p->Language+p->English+p->Math;
		p->average=p->total/3;
		save_student(p);
		printf("���ڱ���....");
		Sleep(500);  //��ͣ0.5��
		system("cls");
		toxy(40,7);
		printf("-------------------------\n");
		toxy(40,8);
		printf("|                       |\n");
		toxy(40,9);
		printf("|        ����ɹ���     |\n");
		toxy(40,10);
		printf("| �Ƿ����¼��ѧ����Ϣ��|\n");
		toxy(40,11);
		printf("|     1.��      2.��    |\n");
		toxy(40,12);
		printf("|                       |\n");
		toxy(40,13);
		printf("-------------------------\n");
		while(1) { //������ѭ������Ч��ֹ������������
			t=getch();
			if(t=='1') break;
			else if(t=='2') menu();
		}
	} while(1);
}

void manager_code(){//����Ա��¼������֤ 
	system("cls");
	HideCursor();
	color(15);
	int i;
	char name[12],code[20];
	for(i=0;i<3;i++)
	{
		toxy(40,10);
		printf("-------��Ҫ��֤����Ա���------\n");
		toxy(40,11);
		printf("                               \n"); 
		toxy(40,12);
		printf("    ����Ա�˻�:                \n");
		toxy(40,13);
		printf("                               \n");
		toxy(40,14);
		printf("    ����Ա����:                \n");
		toxy(40,15);
		printf("                               \n"); 
		toxy(40,16);
		printf("-------------------------------\n");
		toxy(56,12); 
		gets(name);
		toxy(56,14);
		gets(code);
		system("cls");
		Sleep(500);
		toxy(40,15);
		printf("��֤��...");
		Sleep(500);
		system("cls");
		if(strcmp(name,"manager1")==0&&strcmp(code,"123456")==0)
		{
			toxy(40,14);
			printf("������ȷ�����ڽ������ģʽ...\n");
			toxy(40,15);
			printf("���Ե�..."); 
			Sleep(1000);
			manager();
		}
		else if(strcmp(name,"manager1")!=0&&strcmp(code,"123456")==0) 
		{
			toxy(40,14);
			printf("�û�����������������...\n");
			toxy(40,15);
			printf("�����������");
			getch(); 
		}
		else if(strcmp(name,"manager1")==0&&strcmp(code,"123456")!=0)
		{
			toxy(40,14);
			printf("�����������������...\n");
			toxy(40,15);
			printf("�����������");
			getch(); 
		}
		else
		{
			toxy(40,14);
			printf("���˻�δ��Ȩ������������...\n");
			toxy(40,15);
			printf("�����������");
			getch(); 
		} 	
	}
	system("cls");
	toxy(40,15);
	printf("����������̫�࣬�����ر�ϵͳ");
	Sleep(1000);
	exit(0); 	
} 

void input_registration() { //ע���Ա¼��
	system("cls");
	color(10);
	char t;
	registration p;
	p=(registration)malloc(M);   //����ռ�
	//�����û�������Ϣ
	toxy(35,10);
	printf("------------------�û�ע��------------------");
	toxy(35,11);
	printf("|                                        |\n");
	toxy(35,12);
	printf("|   �������û���(С��6���ֻ�12���ַ�)��  |\n");
	toxy(35,13);
	printf("|                                        |\n");
	toxy(35,14);
	printf("|   ����������(С��20λ)��               |\n");
	toxy(35,15);
	printf("|                                        |\n");
	toxy(35,16);
	printf("|   ��������ϵ��ʽ(13λ)��               |\n");
	toxy(35,17);
	printf("|                                        |\n");
	toxy(35,18);
	printf("------------------------------------------\n");
	toxy(40,13);
	scanf("%s",p->name);
	getchar();
	toxy(40,15);
	scanf("%s",p->code);
	getchar();
	toxy(40,17);
	scanf("%s",p->telephone);
	getchar();
	save_registration(p);
	toxy(40,14);
	printf("���ڱ���....");
	Sleep(500);  //��ͣ0.5��
	system("cls");
	toxy(40,14);
	printf("�������ǰ����¼...");
	getch();
	land_interface();
}

void user_choice() { //�û�ģʽ
	do {
		system("cls");
		HideCursor();
		color(10);
		char t;
		toxy(40,9);
		printf("------------------------------------\n");
		toxy(40,10);
		printf("                                    \n");
		toxy(40,11);
		printf("       ��������Ҫ���еĲ����ǣ�     \n");
		toxy(40,12);
		printf("                                    \n");
		toxy(40,13);
		printf("      1.��¼    2.ע��    3.����    \n");
		toxy(40,14);
		printf("                                    \n");
		toxy(40,15);
		printf("------------------------------------\n");
		t=getch();
		switch(t) {
			case '1':
				land_interface();
				break;
			case '2':
				input_registration();
				break;
			case '3':
				homepage();
				break; 
			default:
				break;
		}
	} while(1);
}

void land_interface() { //��¼����
	do {
		color(10);
		char t;
		int n=0,num=0,i;
		registration head,p;
		char name[12],code[20];
		head=cc();
		for(i=0; i<5; i++) {//��for���������Ƶ�¼�������������������ʾ��¼�������� 
			p=head;
			system("cls");
			toxy(40,8);
			printf("-------------------------------\n");
			toxy(40,9);
			printf("|                             |\n");
			toxy(40,10);
			printf("|   �������û�����            |\n");
			toxy(40,11);
			printf("|                             |\n");
			toxy(40,12);
			printf("|   ���������룺              |\n");
			toxy(40,13);
			printf("|                             |\n");
			toxy(40,14);
			printf("-------------------------------\n");
			toxy(58,10);
			gets(name);
			toxy(56,12);
			gets(code);
			system("cls");
			Sleep(500);
			toxy(40,15);
			printf("��֤��...");
			Sleep(500);
			system("cls");
			if(p==NULL) {
				toxy(40,15);
				printf("δ����ע�ᣬ��ӭ��Ϊ��һλ�û�\n");
				toxy(40,16);
				printf("�������ǰ��ע��");
				getch();
				input_registration();
			}
			p=head;
			while(p!=NULL) {
				for(p=head; p!=NULL; p=p->next) {//�ж��Ƿ�����ƥ����û��� 
					if(strcmp(p->name,name)==0)
						n++;
				}
				p=head;
				for(p=head; p!=NULL; p=p->next) {
					if(strcmp(p->name,name)==0) {
						if(strcmp(p->code,code)==0) {
							toxy(40,15);
							printf("��¼�ɹ������Ե�...");
							Sleep(500);
							system("cls");
							menu();
						} else if(strcmp(p->code,code)!=0) {
							toxy(40,15);
							printf("������������µ�¼\n");
							toxy(40,16);
							printf("����������µ�¼");
							getch();
						}
					}
				}
				if(n==0)
				{
					toxy(40,15);
					printf("���˺�δע�ᣬ��ǰ��ע��\n");
					toxy(40,16);
					printf("�������ǰ��ע��");
					getch();
					input_registration();
				}
			}

		}
		system("cls");
		toxy(40,15);
		printf("������Ĵ���̫�࣬�����˳�ϵͳ...\n");
		Sleep(1000);
		exit(0);
	} while(1);
}

void homepage() { //��ҳ
	do {
		char t;
		system("cls");
		HideCursor(); 
		color(15);
		toxy(35,10);
		printf("--------------------------------------\n");
		toxy(35,11);
		printf("|                                    |\n");
		toxy(35,12);
		printf("|              1.�û�ģʽ            |\n");
		toxy(35,13);
		printf("|              2.������ģʽ          |\n");
		toxy(35,14);
		printf("|                                    |\n");
		toxy(35,15);
		printf("--------------------------------------\n");
		toxy(35,16);
		printf("     ����������Ҫ���еĲ�����ţ�     \n");
		t=getch();
		switch(t) {
			case '1':
				user_choice();
				break;
			case '2':
				manager_code();
				break;
			default:
				break;
		}
	} while(1);
}

void manager() { //������ģʽ
	do {
		char t;
		system("cls");
		HideCursor();
		color(15);
		toxy(35,10);
		printf("----------------������ģʽ----------------\n");
		toxy(35,11);
		printf("|                                        |\n");
		toxy(35,12);
		printf("|             1.�û���Ϣ����             |\n");
		toxy(35,13);
		printf("|             2.ɾ���û���Ϣ             |\n");
		toxy(35,14);
		printf("|             3.�޸��û���Ϣ             |\n");
		toxy(35,15);
		printf("|             4.������ҳ                 |\n");
		toxy(35,16);
		printf("|             5.����ѧ����Ϣ����ϵͳ     |\n");
		toxy(35,17);
		printf("|                                        |\n");
		toxy(35,18);
		printf("------------------------------------------\n");
		t=getch();
		switch(t) {
			case '1':
				print_member();
				break;
			case '2':
				del_member();
				break;
			case '3':
				amend_member();
				break;
			case '4':
				homepage();
				break;
			case '5':
				menu();
				break; 
			default:
				break;
		}
	} while(1);
}

void amend_member() { //�޸��û���Ϣ
	do {
		system("cls");
		color(10);
		registration head,p;
		int j=0,x;
		char ch,t;
		FILE *fp;  //�ļ�ָ��
		char name[12];   //����
		char code[20];  //���� 
		char telephone[14];   //�ֻ�����
		head=cc();
		p=head;
		while(p!=NULL) { //��ʼ��p->xΪ0
			p->x=0;
			p=p->next;
		}
		p=head;  //��p����ָ���ͷ
		printf("****************************�û���Ϣ****************************\n");
		printf("---------------------------------------------------------------\n");
		printf(" ���    �û���        ����                       ��ϵ��ʽ     \n");
		printf("---------------------------------------------------------------\n");
		if(head==NULL) {
			printf("��Ϣ������ʱû��ע����ϢŶ~^_^(�����������)");
			getch();
			manager();
		}
		while(p!=NULL) {
			j++;
			printf("%-4d      %-12s %-20s      %-14s\n",j,p->name,p->code,p->telephone);
			p->x=j;
			p=p->next;
		}
		while(1)
		{
			printf("��������Ҫ�޸ĵ��û���Ϣ���е���ţ�\n");
			scanf("%d",&x);
			getchar();
			if(x>j||x<=0) 
			{
				printf("�����������������!\n");
				Sleep(500);
			} 
			else 
			{
				break;
			}
		}
		p=head;   //��p����ָ���ͷ
		while(p!=NULL&&p->x!=x) { //���������ѯ���������Ľ��
			p=p->next;
		}
		if(p) { //���p��Ϊ��
			system("cls");
			//����Ҫ�޸ĵ���Ϣ
			toxy(40,11);
			printf("------������Ҫ�޸ĵ��û���Ϣ�����кţ�------\n");
			toxy(40,12);
			printf("|                                          |\n");
			toxy(40,13);
			printf("|                   1.����                 |\n");
			toxy(40,14);
			printf("|                   2.����                 |\n");
			toxy(40,15);
			printf("|                   3.��ϵ��ʽ             |\n");
			toxy(40,16);
			printf("|                                          |\n");
			toxy(40,17);
			printf("--------------------------------------------\n");
			t=getch();
			switch(t) {
				case '1':
					toxy(20,19);
					printf("����������(С��6���ֻ���12���ַ�)��\n");
					scanf("%s",p->name);
					getchar();
					break;
				case '2':
					toxy(20,19);
					printf("����������(С��20λ�ַ�)��\n");
					scanf("%s",p->code);
					getchar();
					break;
				case '3':
					toxy(20,19);
					printf("��������ϵ��ʽ(С�ڵ���13λ��)��\n");
					scanf("%s",p->telephone);
					getchar();
					break;
			}
		}
		color(7);
		system("cls");
		toxy(40,15);
		printf("��ת��...");
		Sleep(1000);
		system("cls");
		toxy(40,12);
		printf("-------------------------\n");
		toxy(40,13);
		printf("|                       |\n");
		toxy(40,14);
		printf("|     �Ƿ�ȷ���޸ģ�    |\n");
		toxy(40,15);
		printf("|    1.��       2.��    |\n");
		toxy(40,16);
		printf("|                       |\n");
		toxy(40,17);
		printf("-------------------------\n");
		while(1) { //������ѭ����ֹ������������
			t=getch();
			if(t=='1') {
				break;
			} else if(t=='2') {
				manager();
			}
		}
		system("cls");
		toxy(40,15);
		printf("�����޸ģ����Ժ�....\n");
		fp=fopen("registration.txt","wb");  //��ֻд�ķ�ʽ����Ϊstudentlist�Ķ������ļ����򿪵�ͬʱ����ļ��е�����
		if(fp==NULL) {
			printf("cannot open file\n");
		}
		if(fwrite(head,M,1,fp)!=1) { //��headд��fp��ָ����ļ���
			printf("write error!\n");
		}
		fclose(fp);  //�ر��ļ�
		if(head!=NULL) { //���head��Ϊ��
			p=head->next;   //��pָ��ڶ������
			fp=fopen("registration.txt","ab");  //��׷�ӵķ�ʽ���ļ�
			if(fp==NULL) {
				printf("cannot open file\n");
			}
			while(p!=NULL) {
				if(fwrite(p,M,1,fp)!=1) { //��pд��fp��ָ����ļ���
					printf("write error!\n");
				}
				p=p->next;
			}
			fclose(fp); //�ر��ļ�
		}
		Sleep(500);  //��ͣ0.5��
		system("cls");
		toxy(40,15);
		printf("�޸ĳɹ���\n");
		Sleep(500);
		system("cls");
		toxy(40,12);
		printf("-------------------------\n");
		toxy(40,13);
		printf("|                       |\n");
		toxy(40,14);
		printf("|     �Ƿ�����޸ģ�    |\n");
		toxy(40,15);
		printf("|    1.��       2.��    |\n");
		toxy(40,16);
		printf("|                       |\n");
		toxy(40,17);
		printf("-------------------------\n");
		while(1) { //������ѭ������Ч��ֹ������������
			t=getch();
			if(t=='1') break;
			else if(t=='2') manager();
		}
	} while(1);
}

void print_member() { //ע����Ϣ����
	system("cls");
	color(6);
	registration head,p;
	int j=0;
	char t;
	head=cc();
	printf("****************************�û���Ϣ****************************\n");
	printf("---------------------------------------------------------------\n");
	printf(" ���    �û���        ����                       ��ϵ��ʽ     \n");
	printf("---------------------------------------------------------------\n");
	if(head==NULL) {
		printf("��Ϣ������ʱû��ע����ϢŶ~^_^(�����������)");
		getch();
		manager();
	}
	p=head;
	while(p!=NULL) {
		j++;
		printf("%-4d      %-12s %-20s      %-14s\n",j,p->name,p->code,p->telephone);
		p=p->next;
	}
	Sleep(1000);
	printf("\n");
	printf("******����һ����Ҫ���еĲ����ǣ�******\n");
	printf("|                                    |\n");
	printf("|            1.����������            |\n");
	printf("|                                    |\n");
	printf("|            2.�޸��û���Ϣ          |\n");
	printf("|                                    |\n");
	printf("|            3.ɾ���û���Ϣ          |\n");
	printf("|                                    |\n");
	printf("--------------------------------------\n");
	printf("      ����������Ҫ���в��������      \n");
	t=getch();
	switch(t)
	{
		case '1':
			manager();
			break;
		case '2':
			amend_member();
			break;
		case '3':
			del_member();
	 } 
	Sleep(500);  //��ͣ0.5��
	system("cls");
	toxy(55,15);
	printf("���Ե�...\n");
	Sleep(500);  //��ͣ0.5��
	system("cls");
	toxy(55,15);
	printf("�����������!\n");
	getch();//�����Ժ���
}

void del_member() { //ɾ���û���Ϣ
	do {
		system("cls");
		color(9);
		FILE *fp;
		registration head,p,pre=NULL;
		int j=0,x;
		char t,c,ch;
		head=cc();  //���ú��������ر�ͷ��ַ
		p=head;
		while(p!=NULL) {
			p->x=0;
			p=p->next;
		}
		p=head;  //��p����ָ���ͷ
		printf("****************************�û���Ϣ****************************\n");
		printf("---------------------------------------------------------------\n");
		printf(" ���    �û���        ����                       ��ϵ��ʽ     \n");
		printf("---------------------------------------------------------------\n");
		if(head==NULL) {
			printf("��Ϣ������ʱû��ע����ϢŶ~^_^(�����������)");
			getch();
			manager();
		}
		while(p!=NULL) {
			j++;
			printf("%-4d      %-12s %-20s      %-14s\n",j,p->name,p->code,p->telephone);
			p->x=j;
			p=p->next;
		}

		while(1) {
			printf("��������Ҫɾ�����û�����ţ�\n");
			scanf("%d",&x);
			getchar();
			if(x>j||x==0) {
				printf("�����������������!\n");
				Sleep(500);
			} else {
				break;
			}
		}
		color(7);
		toxy(40,12);
		printf("-------------------------\n");
		toxy(40,13);
		printf("|                       |\n");
		toxy(40,14);
		printf("|     �Ƿ�ȷ��ɾ����    |\n");
		toxy(40,15);
		printf("|    1.��       2.��    |\n");
		toxy(40,16);
		printf("|                       |\n");
		toxy(40,17);
		printf("-------------------------\n");
		while(1) {
			t=getch();
			if(t=='1') {
				break;
			} else if(t=='2') {
				manager();
			}
		}
		p=head;
		while(p!=NULL&&p->x!=x) { //���������ѯ���������Ľ��
			pre=p;
			p=p->next;
		}
		if(p!=NULL) {
			if(pre==NULL) {
				head=head->next;
			} else {
				pre->next=p->next;
			}
		}
		free(p);
		fp=fopen("registration.txt","wb");//��ֻд�ķ�ʽ����Ϊstudentlist�Ķ������ļ����򿪵�ͬʱ����ļ��е�����
		if(fp==NULL) {
			printf("cannot open file\n");
		}
		if(fwrite(head,M,1,fp)!=1) {
			printf("write error!\n");
		}
		fclose(fp);
		if(head!=NULL) {
			p=head->next;
			fp=fopen("registration.txt","ab");
			if(fp==NULL) {
				printf("cannot open file\n");
			}
			while(p!=NULL) {
				if(fwrite(p,M,1,fp)!=1) {
					printf("write error!\n");
				}
				p=p->next;
			}
			fclose(fp);
		}
		system("cls");
		toxy(40,15);
		printf("����ɾ�������Ժ�....\n");
		Sleep(500);
		system("cls");
		toxy(40,12);
		printf("-------------------------\n");
		toxy(40,13);
		printf("|                       |\n");
		toxy(40,14);
		printf("|  ɾ���ɹ����Ƿ������ |\n");
		toxy(40,15);
		printf("|    1.��       2.��    |\n");
		toxy(40,16);
		printf("|                       |\n");
		toxy(40,17);
		printf("-------------------------\n");
		while(1) {
			c=getch();
			if(c=='1') {
				break;
			} else if(c=='2') {
				manager();
			}
		}
	} while(1);
}

void amend_student() { //�޸�ѧ����Ϣ
	do {
		system("cls");
		color(10);
		student head,p;
		int j=0,x;
		char ch,t;
		FILE *fp;  //�ļ�ָ��
		char _name[10];
		char number[12];  //ѧ�� 
		char name[10];   //����
		char profession[10];  //רҵ��
		char telephone[13];   //�ֻ�����
		char nationality[10]; //����
		char sex[4];    //�Ա�
		float Language;    	 	//���ĳɼ�
		float Math;             //��ѧ�ɼ�
		float English;          //Ӣ��ɼ�
		head=ss();
		p=head;

		printf("��������Ҫ�޸ĵ�ѧ��������\n");
		gets(_name);
		while(p!=NULL) { //��ʼ��p->xΪ0
			p->x=0;
			p=p->next;
		}
		p=head;  //��p����ָ���ͷ
		printf("*******************************************************ѧ����Ϣ*******************************************************\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf(" ���   ѧ��         ����     �Ա�    רҵ     ����         ��ϵ��ʽ      ����     ��ѧ     Ӣ��    �ܳɼ�   ƽ���ɼ� \n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		while(p!=NULL) {
			if(p!=NULL&&strcmp(p->name,_name)==0) {
				j++;
				printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-4.2f     %-4.2f   %-4.2f   %-4.2f    %-4.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
				p->x=j;  //�����ϲ�ѯ��׼�Ľ����
			}
			p=p->next;
		}
		if(j==0) {        //���j=0����û�н���ǰ�������ѭ����Ҳ����û���ҵ���Ӧ����Ϣ
			printf("û���ҵ���Ӧ����Ϣ��\n(��0���أ���1��������)");
			while(1) {      //��ѭ����Ϊ�˷�ֹ��0��1��������������
				ch=getch();
				if(ch=='0') {
					menu();
					break;
				} else if(ch=='1') {
					break;
				}
			}
			if(ch=='1')   //��������ch����1�����������ѭ��
				continue;
		}
		while(1) {
			printf("��������Ҫ�޸ĵ�ѧ����Ϣ���е���ţ�\n");
			scanf("%d",&x);
			getchar();
			if(x>j||x==0) {
				printf("�����������������!\n");
				Sleep(500);
			} else {
				break;
			}
		}
		p=head;   //��p����ָ���ͷ
		while(p!=NULL&&p->x!=x) { //���������ѯ���������Ľ��
			p=p->next;
		}
		if(p) { //���p��Ϊ��
			system("cls");
			//����Ҫ�޸ĵ���Ϣ
			toxy(40,7);
			printf("������Ҫ�޸ĵ�ѧ����Ϣ�����кţ�\n");
			toxy(40,8);
			printf("|           1.ѧ��             |\n");
			toxy(40,9);
			printf("|           2.����             |\n");
			toxy(40,10);
			printf("|           3.רҵ��           |\n");
			toxy(40,11);
			printf("|           4.��ϵ��ʽ         |\n");
			toxy(40,12);
			printf("|           5.����             |\n");
			toxy(40,13);
			printf("|           6.�Ա�             |\n");
			toxy(40,14);
			printf("|           7.���ĳɼ�         |\n");
			toxy(40,15);
			printf("|           8.��ѧ�ɼ�         |\n");
			toxy(40,16);
			printf("|           9.Ӣ��ɼ�         |\n");
			toxy(40,17);
			printf("--------------------------------\n");
			t=getch();
			switch(t) {
				case '1':
					toxy(20,19);
					printf("������ѧ��(С��12λ��)��\n");
					scanf("%s",p->number);
					getchar();
					break;
				case '2':
					toxy(20,19);
					printf("����������(С�ڵ���5����)��\n");
					scanf("%s",p->name);
					getchar();
					break;
				case '3':
					toxy(20,19);
					printf("������רҵ��(С�ڵ���5����)��\n");
					scanf("%s",p->profession);
					getchar();
					break;
				case '4':
					toxy(20,19);
					printf("��������ϵ��ʽ(С�ڵ���13λ��)��\n");
					scanf("%s",p->telephone);
					getchar();
					break;
				case '5':
					toxy(20,19);
					printf("�����뼮��(С��5����)��\n");
					scanf("%s",p->nationality);
					getchar();
					break;
				case '6':
					toxy(20,19);
					printf("�������Ա�(С�ڵ���4����)��\n");
					scanf("%s",p->sex);
					getchar();
					break;
				case '7':
					toxy(20,19);
					printf("���������ĳɼ���\n");
					scanf("%f",&p->Language);
					getchar();
					break;
				case '8':
					toxy(20,19);
					printf("��������ѧ�ɼ���\n");
					scanf("%f",&p->Math);
					getchar();
					break;
				case '9':
					toxy(20,19);
					printf("������Ӣ��ɼ���\n");
					scanf("%f",&p->English);
					getchar();
					break;
			}
		}
		color(7);
		system("cls");
		printf("��ת��...");
		Sleep(1500);
		system("cls");
		toxy(40,12);
		printf("-------------------------\n");
		toxy(40,13);
		printf("|                       |\n");
		toxy(40,14);
		printf("|     �Ƿ�ȷ���޸ģ�    |\n");
		toxy(40,15);
		printf("|    1.��       2.��    |\n");
		toxy(40,16);
		printf("|                       |\n");
		toxy(40,17);
		printf("-------------------------\n");
		while(1) { //������ѭ����ֹ������������
			t=getch();
			if(t=='1') {
				break;
			} else if(t=='2') {
				menu();
			}
		}
		system("cls");
		printf("�����޸ģ����Ժ�....\n");
		fp=fopen("studentlist","wb");  //��ֻд�ķ�ʽ����Ϊstudentlist�Ķ������ļ����򿪵�ͬʱ����ļ��е�����
		if(fp==NULL) {
			printf("cannot open file\n");
		}
		if(fwrite(head,N,1,fp)!=1) { //��headд��fp��ָ����ļ���
			printf("write error!\n");
		}
		fclose(fp);  //�ر��ļ�
		if(head!=NULL) { //���head��Ϊ��
			p=head->next;   //��pָ��ڶ������
			fp=fopen("studentlist","ab");  //��׷�ӵķ�ʽ���ļ�
			if(fp==NULL) {
				printf("cannot open file\n");
			}
			while(p!=NULL) {
				if(fwrite(p,N,1,fp)!=1) { //��pд��fp��ָ����ļ���
					printf("write error!\n");
				}
				p=p->next;
			}
			fclose(fp); //�ر��ļ�
		}
		Sleep(500);  //��ͣ0.5��
		system("cls");
		printf("�޸ĳɹ���\n");
		Sleep(500);
		system("cls");
		printf("-------------------------\n");
		printf("|                       |\n");
		printf("|     �Ƿ�����޸ģ�    |\n");
		printf("|    1.��       2.��    |\n");
		printf("|                       |\n");
		printf("-------------------------\n");
		while(1) { //������ѭ������Ч��ֹ������������
			t=getch();
			if(t=='1') break;
			else if(t=='2') menu();
		}
	} while(1);
}

void del_student() { //ɾ��ѧ����Ϣ
	do {
		system("cls");
		color(9);
		FILE *fp;
		student head,p,pre=NULL;
		int j=0,x;
		char name[10];
		char t,c,ch;
		head=ss();  //���ú��������ر�ͷ��ַ
		printf("��������Ҫɾ����ѧ��������\n");
		scanf("%s",name);
		p=head;
		while(p!=NULL) {
			p->x=0;
			p=p->next;
		}
		p=head;
		printf("*******************************************************ѧ����Ϣ*******************************************************\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf(" ���   ѧ��         ����     �Ա�    רҵ     ����         ��ϵ��ʽ      ����     ��ѧ     Ӣ��    �ܳɼ�   ƽ���ɼ� \n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		while(p!=NULL) {
			if(p!=NULL&&strcmp(p->name,name)==0) {
				j++;
				printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-4.2f     %-4.2f   %-4.2f   %-4.2f    %-4.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
				p->x=j;
			}
			p=p->next;
		}
		if(j==0) {        //���j=0����û�н���ǰ�������ѭ����Ҳ����û���ҵ���Ӧ����Ϣ
			printf("û���ҵ���Ӧ����Ϣ��\n(��0���أ���1��������)");
			while(1) {      //��ѭ����Ϊ�˷�ֹ��0��1��������������
				ch=getch();
				if(ch=='0') {
					menu();
					break;
				} else if(ch=='1') {
					break;
				}
			}
			if(ch=='1')   //��������ch����1�����������ѭ��
				continue;
		}
		while(1) {
			printf("��������Ҫɾ����ѧ������ţ�\n");
			scanf("%d",&x);
			getchar();
			if(x>j||x==0) {
				printf("�����������������!\n");
				Sleep(500);
			} else {
				break;
			}
		}
		color(7);
		toxy(40,12);
		printf("-------------------------\n");
		toxy(40,13);
		printf("|                       |\n");
		toxy(40,14);
		printf("|     �Ƿ�ȷ��ɾ����    |\n");
		toxy(40,15);
		printf("|    1.��       2.��    |\n");
		toxy(40,16);
		printf("|                       |\n");
		toxy(40,17);
		printf("-------------------------\n");
		while(1) {
			t=getch();
			if(t=='1') {
				break;
			} else if(t=='2') {
				menu();
			}
		}
		p=head;
		while(p!=NULL&&p->x!=x) {
			pre=p;
			p=p->next;
		}
		if(p!=NULL) {
			if(pre==NULL) {
				head=head->next;
			} else {
				pre->next=p->next;
			}
		}
		free(p);
		fp=fopen("studentlist","wb");
		if(fp==NULL) {
			printf("cannot open file\n");
		}
		if(fwrite(head,N,1,fp)!=1) {
			printf("write error!\n");
		}
		fclose(fp);
		if(head!=NULL) {
			p=head->next;
			fp=fopen("studentlist","ab");
			if(fp==NULL) {
				printf("cannot open file\n");
			}
			while(p!=NULL) {
				if(fwrite(p,N,1,fp)!=1) {
					printf("write error!\n");
				}
				p=p->next;
			}
			fclose(fp);
		}
		system("cls");
		printf("����ɾ�������Ժ�....\n");
		Sleep(500);
		system("cls");
		toxy(40,12);
		printf("-------------------------\n");
		toxy(40,13);
		printf("|                       |\n");
		toxy(40,14);
		printf("|  ɾ���ɹ����Ƿ������ |\n");
		toxy(40,15);
		printf("|    1.��       2.��    |\n");
		toxy(40,16);
		printf("|                       |\n");
		toxy(40,17);
		printf("-------------------------\n");
		while(1) {
			c=getch();
			if(c=='1') {
				break;
			} else if(c=='2') {
				menu();
			}
		}
	} while(1);
}

void print_student() { //ѧ����Ϣ����
	system("cls");
	color(6);
	student head,p;
	int j=0;
	char t;
	head=ss();
	printf("*******************************************************ѧ����Ϣ*******************************************************\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf(" ���   ѧ��         ����     �Ա�    רҵ     ����         ��ϵ��ʽ      ����     ��ѧ     Ӣ��    �ܳɼ�   ƽ���ɼ� \n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	if(head==NULL) {
		printf("��Ϣ������ʱû��ѧ����ϢŶ~�Ͽ�ȥ��Ӽ�����^_^(�����������)");
		getch();
		menu();
	}
	p=head;
	while(p!=NULL) {
		j++;
		printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-5.2f     %-5.2f   %-5.2f   %-5.2f    %-5.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
		p=p->next;
	}

	j=0;
	printf("\n");
	printf("        -------����Ҫ���е���һ���Ĳ����ǣ�-------\n");
	printf("        |         1.��ǳɼ��в������ѧ��       |\n");;
	printf("        |         2.��ѧ���ɼ���������           |\n");
	printf("        |         3.�鿴��߷ֺ���ͷ�           |\n");
	printf("        |         4.�������˵�                   |\n");
	printf("        ------------------------------------------\n");
	t=getch();
	Sleep(500);  //��ͣ0.5��
	system("cls");
	switch(t) {
		case '1':
			p=head;
			printf("*******************************************************ѧ����Ϣ*******************************************************\n");
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			printf(" ���   ѧ��         ����     �Ա�    רҵ     ����         ��ϵ��ʽ      ����     ��ѧ     Ӣ��    �ܳɼ�   ƽ���ɼ� \n");
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			while(p!=NULL) {
				j++;
				if((p->Language)<60||(p->English)<60||(p->Math)<60) {
					color(4);
					printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-5.2f     %-5.2f   %-5.2f   %-5.2f    %-5.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
				} else {
					color(6);
					printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-5.2f     %-5.2f   %-5.2f   %-5.2f    %-5.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
				}
				p=p->next;
			}
			color(6);
			printf("\n");
			printf("�������������һ������!\n");
			getch();
			printf("\n");
			printf("      -----����һ���Ĳ����ǣ�-----\n");
			printf("      |     1.���سɼ��б�       |\n");
			printf("      |     2.�Գɼ���������     |\n");
			printf("      |     3.�������˵�         |\n");
			printf("      ----------------------------\n");
			t=getch();
			switch(t) {
				case '1':
					print_student();
					break;
				case '2':
					p=head;
					rank_student(p);
					break;
				case '3':
					break;
			}

		case '2':
			p=head;
			rank_student(p);
			break;
		case '3':
			p=head;
			max_min(p);
			break;
		case '4':
			break;
	}
	Sleep(500);  //��ͣ0.5��
	system("cls");
	toxy(55,15);
	printf("���Ե�...\n");
	Sleep(500);  //��ͣ0.5��
	system("cls");
	toxy(55,15);
	printf("�����������!\n");
	getch();//�����Ժ���
}

void rank_student(student head) { //ѧ���ɼ�����
	color(6);
	do {
		system("cls");
		Sleep(500);
		student flag = NULL, j = NULL, t = NULL;
		student q = head, h = head;
		char v,m;
		int g=0;
		toxy(40,8);
		printf("����ѡ����Ҫ�����ѡ�\n");
		toxy(40,9);
		printf("|  --  1.���ĳɼ�  --  |\n");
		toxy(40,10);
		printf("|  --  2.��ѧ�ɼ�  --  |\n");
		toxy(40,11);
		printf("|  --  3.Ӣ��ɼ�  --  |\n");
		toxy(40,12);
		printf("|  --  4.�ܳɼ�    --  |\n");
		toxy(40,13);
		printf("|  --  5.ƽ���ɼ�  --  |\n");
		toxy(40,14);
		printf("------------------------\n");
		toxy(40,15);
		printf("\n");
		toxy(40,16);
		printf("��������Ҫѡ������^-^\n");
		v=getch();
		Sleep(500);  //��ͣ0.5��
		system("cls");
		if(q!=NULL) {
			switch(v) {
				case '1':
					print_rank();
					m=getch();
					switch(m) {
						case '1'://��������
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//����ָ��
									if (j->next->Language > j->next->next->Language) {
										student p1 = j->next;
										student p2 = j->next->next;
										p1->next = p2->next;
										j->next = p2;
										p2->next = p1;
										flag = j->next->next;
									}
									j = j->next;
								}
							} while (flag != NULL);
							// ����ͷ�ڵ�, ���ҽ�ͷ�ڵ���뵽���ʵ�λ��(һ�β���)

							head = head->next;
							//Node q = head->next;
							while (q->next != NULL) {
								if (q->next->Language > h->Language) {
									h->next = q->next;
									q->next = h;
									break;
								}
								q = q->next;
							}
							break;

						case '2'://���Ľ���
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//����ָ��
									if (j->next->Language < j->next->next->Language) {
										student p1 = j->next;
										student p2 = j->next->next;
										p1->next = p2->next;
										j->next = p2;
										p2->next = p1;
										flag = j->next->next;
									}
									j = j->next;
								}
							} while (flag != NULL);
							// ����ͷ�ڵ�, ���ҽ�ͷ�ڵ���뵽���ʵ�λ��(һ�β���)

							head = head->next;
							//Node q = head->next;
							while (q->next != NULL) {
								if (q->next->Language < h->Language) {
									h->next = q->next;
									q->next = h;
									break;
								}
								q = q->next;
							}
							break;
					}
					break;

				case '2':
					print_rank();
					m=getch();
					switch(m) {
						case '1'://��ѧ����
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//����ָ��
									if (j->next->Math > j->next->next->Math) {
										student p1 = j->next;
										student p2 = j->next->next;
										p1->next = p2->next;
										j->next = p2;
										p2->next = p1;
										flag = j->next->next;
									}
									j = j->next;
								}
							} while (flag != NULL);
							// ����ͷ�ڵ�, ���ҽ�ͷ�ڵ���뵽���ʵ�λ��(һ�β���)

							head = head->next;
							//Node q = head->next;
							while (q->next != NULL) {
								if (q->next->Math > h->Math) {
									h->next = q->next;
									q->next = h;
									break;
								}
								q = q->next;
							}
							break;

						case '2'://��ѧ����
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//����ָ��
									if (j->next->Math < j->next->next->Math) {
										student p1 = j->next;
										student p2 = j->next->next;
										p1->next = p2->next;
										j->next = p2;
										p2->next = p1;
										flag = j->next->next;
									}
									j = j->next;
								}
							} while (flag != NULL);
							// ����ͷ�ڵ�, ���ҽ�ͷ�ڵ���뵽���ʵ�λ��(һ�β���)

							head = head->next;
							//Node q = head->next;
							while (q->next != NULL) {
								if (q->next->Math < h->Math) {
									h->next = q->next;
									q->next = h;
									break;
								}
								q = q->next;
							}
							break;
					}
					break;

				case '3':
					print_rank();
					m=getch();
					switch(m) {
						case '1'://Ӣ������
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//����ָ��
									if (j->next->English > j->next->next->English) {
										student p1 = j->next;
										student p2 = j->next->next;
										p1->next = p2->next;
										j->next = p2;
										p2->next = p1;
										flag = j->next->next;
									}
									j = j->next;
								}
							} while (flag != NULL);
							// ����ͷ�ڵ�, ���ҽ�ͷ�ڵ���뵽���ʵ�λ��(һ�β���)

							head = head->next;
							//Node q = head->next;
							while (q->next != NULL) {
								if (q->next->English > h->English) {
									h->next = q->next;
									q->next = h;
									break;
								}
								q = q->next;
							}
							break;

						case '2'://Ӣ�ｵ��
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//����ָ��
									if (j->next->English < j->next->next->English) {
										student p1 = j->next;
										student p2 = j->next->next;
										p1->next = p2->next;
										j->next = p2;
										p2->next = p1;
										flag = j->next->next;
									}
									j = j->next;
								}
							} while (flag != NULL);
							// ����ͷ�ڵ�, ���ҽ�ͷ�ڵ���뵽���ʵ�λ��(һ�β���)

							head = head->next;
							//Node q = head->next;
							while (q->next != NULL) {
								if (q->next->English < h->English) {
									h->next = q->next;
									q->next = h;
									break;
								}
								q = q->next;
							}
							break;
					}
					break;

				case '4':
					print_rank();
					m=getch();
					switch(m) {
						case '1'://�ܳɼ�����
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//����ָ��
									if (j->next->total > j->next->next->total) {
										student p1 = j->next;
										student p2 = j->next->next;
										p1->next = p2->next;
										j->next = p2;
										p2->next = p1;
										flag = j->next->next;
									}
									j = j->next;
								}
							} while (flag != NULL);
							// ����ͷ�ڵ�, ���ҽ�ͷ�ڵ���뵽���ʵ�λ��(һ�β���)

							head = head->next;
							//Node q = head->next;
							while (q->next != NULL) {
								if (q->next->total > h->total) {
									h->next = q->next;
									q->next = h;
									break;
								}
								q = q->next;
							}
							break;

						case '2'://�ܳɼ�����
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//����ָ��
									if (j->next->total < j->next->next->total) {
										student p1 = j->next;
										student p2 = j->next->next;
										p1->next = p2->next;
										j->next = p2;
										p2->next = p1;
										flag = j->next->next;
									}
									j = j->next;
								}
							} while (flag != NULL);
							// ����ͷ�ڵ�, ���ҽ�ͷ�ڵ���뵽���ʵ�λ��(һ�β���)

							head = head->next;
							//Node q = head->next;
							while (q->next != NULL) {
								if (q->next->total < h->total) {
									h->next = q->next;
									q->next = h;
									break;
								}
								q = q->next;
							}
							break;
					}
					break;

				case '5':
					print_rank();
					m=getch();
					switch(m) {
						case '1'://ƽ���ɼ�����
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//����ָ��
									if (j->next->average > j->next->next->average) {
										student p1 = j->next;
										student p2 = j->next->next;
										p1->next = p2->next;
										j->next = p2;
										p2->next = p1;
										flag = j->next->next;
									}
									j = j->next;
								}
							} while (flag != NULL);
							// ����ͷ�ڵ�, ���ҽ�ͷ�ڵ���뵽���ʵ�λ��(һ�β���)

							head = head->next;
							//Node q = head->next;
							while (q->next != NULL) {
								if (q->next->average > h->average) {
									h->next = q->next;
									q->next = h;
									break;
								}
								q = q->next;
							}
							break;

						case '2'://ƽ���ɼ�����
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//����ָ��
									if (j->next->average < j->next->next->average) {
										student p1 = j->next;
										student p2 = j->next->next;
										p1->next = p2->next;
										j->next = p2;
										p2->next = p1;
										flag = j->next->next;
									}
									j = j->next;
								}
							} while (flag != NULL);
							// ����ͷ�ڵ�, ���ҽ�ͷ�ڵ���뵽���ʵ�λ��(һ�β���)

							head = head->next;
							//Node q = head->next;
							while (q->next != NULL) {
								if (q->next->average < h->average) {
									h->next = q->next;
									q->next = h;
									break;
								}
								q = q->next;
							}
							break;
					}
					break;
			}
		} else {
			printf("��Ϣ������ʱû��ѧ����ϢŶ~�Ͽ�ȥ��Ӽ�����^_^(�����������)");
			getch();
			menu();
		}
		Sleep(500);  //��ͣ0.5��
		system("cls");
		printf("���������Եȣ�\n");
		Sleep(500);
		system("cls");
		q=head;
		printf("*******************************************************ѧ����Ϣ*******************************************************\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf(" ���   ѧ��         ����     �Ա�    רҵ     ����         ��ϵ��ʽ      ����     ��ѧ     Ӣ��    �ܳɼ�   ƽ���ɼ� \n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		while(q!=NULL) {
			g++;
			printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-5.2f     %-5.2f   %-5.2f   %-5.2f    %-5.2f\n",g,q->number,q->name,q->sex,q->profession,q->nationality,q->telephone,q->Language,q->Math,q->English,q->total,q->average);
			q=q->next;
		}
		printf("\n");
		printf("-------------------------\n");
		printf("|                       |\n");
		printf("|    ��һ���Ĳ����ǣ�   |\n");
		printf("|    1.����ѧ���ɼ���   |\n");
		printf("|    2.�������˵�       |\n");
		printf("|                       |\n");
		printf("-------------------------\n");
		while(1) { //������ѭ������Ч��ֹ������������
			v=getch();
			if(v=='1')
				print_student();
			else if(v=='2') menu();
		}
	} while(1);
}

void print_rank() { //����������
	toxy(40,10);
	printf("��������Ҫ�Դ˳ɼ������������л��ǽ������У�\n");
	toxy(40,11);
	printf("|                                          |\n");
	toxy(40,12);
	printf("|        ****       1.����       ****      |\n");
	toxy(40,13);
	printf("|        ****       2.����       ****      |\n");
	toxy(40,14);
	printf("|                                          |\n");
	toxy(40,15);
	printf("--------------------------------------------\n");
}

void max_min(student head) { //�����߷ֺ���ͷ��Լ������Ϣ
	color(6);
	student p=head;
	char t,m;
	float max,min;
	printf("\n");
	printf("-----------------------------------\n");
	printf("|                                 |\n");
	printf("|     1.�鿴������߷ֺ���ͷ�    |\n");
	printf("|     2.�鿴��ѧ��߷ֺ���ͷ�    |\n");
	printf("|     3.�鿴Ӣ����߷ֺ���ͷ�    |\n");
	printf("|     4.�鿴�ܷ���߷ֺ���ͷ�    |\n");
	printf("|     5.�鿴ƽ������߷ֺ���ͷ�  |\n");
	printf("|                                 |\n");
	printf("-----------------------------------\n");
	t=getch();
	switch(t) {
		case '1':
			system("cls");
			Sleep(500);
			p=head;
			max = p->Language;
			min = p->Language;
			while(p->next!=NULL) {
				if(max < p->next->Language)
					max = p->next->Language;
				else if(min > p->next->Language)
					min = p->next->Language;
				p = p->next;
			}
			printf("������߷�Ϊ��%5.2f\t��ͷ�Ϊ��%5.2f\n",max,min);
			printf("\n\n\n");
			p=head;
			do {
				if(max==p->Language) {
					printf("������߷�ͬѧ�Ļ�����Ϣ�ǣ�\n");
					printf("ѧ�ţ�%s\t������%s\tרҵ��%s\t���ĵ÷֣�%5.2f\n",p->number,p->name,p->profession,p->Language);
				}
				p=p->next;
			} while(p!=NULL);
			printf("\n\n\n");
			p=head;
			do {
				if(min==p->Language) {
					printf("������ͷ�ͬѧ�Ļ�����Ϣ�ǣ�\n");
					printf("ѧ�ţ�%s\t������%s\tרҵ��%s\t���ĵ÷֣�%5.2f\n",p->number,p->name,p->profession,p->Language);
				}
				p=p->next;
			} while(p!=NULL);
			break;
		case '2':
			system("cls");
			Sleep(500);
			p=head;
			max = p->Math,min = p->Math;
			while(p->next!=NULL) {
				if(max<p->next->Math)
					max=p->next->Math;
				if(min>p->next->Math)
					min=p->next->Math;
				p=p->next;
			}
			printf("��ѧ��߷�Ϊ��%5.2f\t��ͷ�Ϊ��%5.2f\n",max,min);
			printf("\n\n\n");
			p=head;
			do {
				if(max==p->Math) {
					printf("��ѧ��߷�ͬѧ�Ļ�����Ϣ�ǣ�\n");
					printf("ѧ�ţ�%s\t������%s\tרҵ��%s\t��ѧ�÷֣�%5.2f\n",p->number,p->name,p->profession,p->Math);
				}
				p=p->next;
			} while(p!=NULL);
			printf("\n\n\n");
			p=head;
			do {
				if(min==p->Math) {
					printf("��ѧ��ͷ�ͬѧ�Ļ�����Ϣ�ǣ�\n");
					printf("ѧ�ţ�%s\t������%s\tרҵ��%s\t��ѧ�÷֣�%5.2f\n",p->number,p->name,p->profession,p->Math);
				}
				p=p->next;
			} while(p!=NULL);
			break;
		case '3':
			system("cls");
			Sleep(500);
			p=head;
			max=p->English,min=p->English;
			while(p->next!=NULL) {
				if(max<p->next->English)
					max=p->next->English;
				if(min>p->next->English)
					min=p->next->English;
				p=p->next;
			}
			printf("Ӣ����߷�Ϊ��%5.2f\t��ͷ�Ϊ��%5.2f\n",max,min);
			printf("\n\n\n");
			p=head;
			do {
				if(max==p->English) {
					printf("Ӣ����߷�ͬѧ�Ļ�����Ϣ�ǣ�\n");
					printf("ѧ�ţ�%s\t������%s\tרҵ��%s\tӢ��÷֣�%5.2f\n",p->number,p->name,p->profession,p->English);
				}
				p=p->next;
			} while(p!=NULL);
			printf("\n\n\n");
			p=head;
			do {
				if(min==p->English) {
					printf("Ӣ����ͷ�ͬѧ�Ļ�����Ϣ�ǣ�\n");
					printf("ѧ�ţ�%s\t������%s\tרҵ��%s\tӢ��÷֣�%5.2f\n",p->number,p->name,p->profession,p->English);
				}
				p=p->next;
			} while(p!=NULL);
			break;
		case '4':
			system("cls");
			Sleep(500);
			p=head;
			max=p->total,min=p->total;
			while(p->next!=NULL) {
				if(max<p->next->total)
					max=p->next->total;
				if(min>p->next->total)
					min=p->next->total;
				p=p->next;
			}
			printf("�ܷ���߷�Ϊ��%5.2f\t��ͷ�Ϊ��%5.2f\n",max,min);
			printf("\n\n\n");
			p=head;
			do {
				if(max==p->total) {
					printf("�ܷ���߷�ͬѧ�Ļ�����Ϣ�ǣ�\n");
					printf("ѧ�ţ�%s\t������%s\tרҵ��%s\t�ֵܷ÷֣�%5.2f\n",p->number,p->name,p->profession,p->total);
				}
				p=p->next;
			} while(p!=NULL);
			printf("\n\n\n");
			p=head;
			do {
				if(min==p->total) {
					printf("�ܷ���ͷ�ͬѧ�Ļ�����Ϣ�ǣ�\n");
					printf("ѧ�ţ�%s\t������%s\tרҵ��%s\t�ֵܷ÷֣�%5.2f\n",p->number,p->name,p->profession,p->total);
				}
				p=p->next;
			} while(p!=NULL);
			break;
		case '5':
			system("cls");
			Sleep(500);
			p=head;
			max=p->average,min=p->average;
			while(p->next!=NULL) {
				if(max<p->next->average)
					max=p->next->average;
				if(min>p->next->average)
					min=p->next->average;
				p=p->next;
			}
			printf("ƽ������߷�Ϊ��%f\t��ͷ�Ϊ��%f\n",max,min);
			printf("\n\n\n");
			p=head;
			do {
				if(max==p->average) {
					printf("ƽ������߷�ͬѧ�Ļ�����Ϣ�ǣ�\n");
					printf("ѧ�ţ�%s\t������%s\tרҵ��%s\tƽ���֣�%f\n",p->number,p->name,p->profession,p->average);
				}
				p=p->next;
			} while(p!=NULL);
			printf("\n\n\n");
			p=head;
			do {
				if(min==p->average) {
					printf("ƽ������ͷ�ͬѧ�Ļ�����Ϣ�ǣ�\n");
					printf("ѧ�ţ�%s\t������%s\tרҵ��%s\tƽ���֣�%f\n",p->number,p->name,p->profession,p->average);
				}
				p=p->next;
			} while(p!=NULL);
			break;
	}
	printf("\n");
	printf("-------------------------\n");
	printf("|                       |\n");
	printf("|    ��һ���Ĳ����ǣ�   |\n");
	printf("|    1.����ѧ���ɼ���   |\n");
	printf("|    2.�������˵�       |\n");
	printf("|                       |\n");
	printf("-------------------------\n");
	while(1) { //������ѭ������Ч��ֹ������������
		m=getch();
		if(m=='1')
			print_student();
		else if(m=='2') menu();
	}
}

void find_student() { //��ѯѧ����Ϣ
	do {
		system("cls"); //����
		color(8);
		char t;
		toxy(40,8);
		printf("----------ѧ����Ϣ��ѯ---------\n");
		toxy(40,9);
		printf("|         1.������ѯ          |\n");
		toxy(40,10);
		printf("|         2.רҵ��ѯ          |\n");
		toxy(40,11);
		printf("|         3.ѧ�Ų�ѯ          |\n");
		toxy(40,12);
		printf("|         4.�����ѯ          |\n");
		toxy(40,13);
		printf("|         5.ģ����ѯ          |\n");
		toxy(40,14);
		printf("---------��0�������˵�---------\n");
		t=getch();
		switch(t) {
			case '0':
				menu();
				break;
			case '1':
				find_name_student();
				break;
			case '2':
				find_profession_student();
				break;
			case '3':
				find_number_student();
				break;
			case '4':
				find_nationality_student();
				break;
			case '5':
				fuzzy_search();
				break;
			default :
				break;
		}
	} while(1);
}

void find_name_student() { //��������ѯ
	system("cls");
	student head,p;
	int j=0;
	head=ss();
	char name[10];
	printf("��������Ҫ��ѯѧ����������\n");
	gets(name);
	printf("���ڲ�ѯ....\n");
	Sleep(500);
	p=head;
	printf("*******************************************************ѧ����Ϣ*******************************************************\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf(" ���   ѧ��         ����     �Ա�    רҵ     ����         ��ϵ��ʽ      ����     ��ѧ     Ӣ��    �ܳɼ�   ƽ���ɼ� \n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	while(p!=NULL) {
		if(p!=NULL&&strcmp(p->name,name)==0) {
			j++;
			printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-4.2f     %-4.2f   %-4.2f   %-4.2f    %-4.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
		}
		p=p->next;
	}
	printf("����������أ�\n");
	getch();
	find_student();
}

void find_profession_student() { //��רҵ����ѯ
	system("cls");
	color(8);
	student head,p;
	int j=0;
	head=ss();
	char profession[10];
	printf("��������Ҫ��ѯѧ��������\n");
	gets(profession);
	printf("���ڲ�ѯ....\n");
	Sleep(500);
	p=head;
	printf("*******************************************************ѧ����Ϣ*******************************************************\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf(" ���   ѧ��         ����     �Ա�    רҵ     ����         ��ϵ��ʽ      ����     ��ѧ     Ӣ��    �ܳɼ�   ƽ���ɼ� \n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	while(p!=NULL) {
		if(p!=NULL&&strcmp(p->profession,profession)==0) {
			j++;
			printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-4.2f     %-4.2f   %-4.2f   %-4.2f    %-4.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
		}
		p=p->next;
	}
	printf("����������أ�\n");
	getch();
	find_student();
}

void find_number_student() { //��ѧ�Ų�ѯ
	system("cls");
	color(8);
	student head,p;
	int j=0;
	head=ss();
	char number[10];
	printf("��������Ҫ��ѯѧ��ѧ�ţ�\n");
	gets(number);
	printf("���ڲ�ѯ....\n");
	p=head;
	printf("*******************************************************ѧ����Ϣ*******************************************************\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf(" ���   ѧ��         ����     �Ա�    רҵ     ����         ��ϵ��ʽ      ����     ��ѧ     Ӣ��    �ܳɼ�   ƽ���ɼ� \n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	while(p!=NULL) {
		if(p!=NULL&&strcmp(p->number,number)==0) {
			j++;
			printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-4.2f     %-4.2f   %-4.2f   %-4.2f    %-4.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
		}
		p=p->next;
	}
	printf("����������أ�\n");
	getch();
	find_student();
}

void find_nationality_student() { //�������ѯ
	system("cls");
	color(8);
	student head,p;
	int j=0;
	head=ss();
	char nationality[10];
	printf("��������Ҫ��ѯ��ѧ�����᣺\n");
	gets(nationality);
	printf("���ڲ�ѯ....\n");
	Sleep(500);
	p=head;
	printf("*******************************************************ѧ����Ϣ*******************************************************\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf(" ���   ѧ��         ����     �Ա�    רҵ     ����         ��ϵ��ʽ      ����     ��ѧ     Ӣ��    �ܳɼ�   ƽ���ɼ� \n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	while(p!=NULL) {
		if(p!=NULL&&strcmp(p->nationality,nationality)==0) {
			j++;
			printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-4.2f     %-4.2f   %-4.2f   %-4.2f    %-4.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
		}
		p=p->next;
	}
	printf("����������أ�\n");
	getch();
	find_student();
}

void fuzzy_search() { //ģ����ѯ
	system("cls");
	color(8);
	student head,p;
	int j=0;
	head=ss();
	char information[10];
	printf("��������Ҫ��ѯѧ������Ϣ��\n");
	gets(information);
	printf("���ڲ�ѯ....\n");
	Sleep(500);
	p=head;
	printf("*******************************************************ѧ����Ϣ*******************************************************\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf(" ���   ѧ��         ����     �Ա�    רҵ     ����         ��ϵ��ʽ      ����     ��ѧ     Ӣ��    �ܳɼ�   ƽ���ɼ� \n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	while(p!=NULL) {
		if(p!=NULL&&(strcmp(p->name,information)==0||strcmp(p->profession,information)==0||strcmp(p->number,information)==0||strcmp(p->nationality,information)==0)||strcmp(p->sex,information)==0||strcmp(p->telephone,information)==0) {
			j++;
			printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-4.2f     %-4.2f   %-4.2f   %-4.2f    %-4.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
		}
		p=p->next;
	}
	printf("����������أ�\n");
	getch();
	find_student();
}

void save_student(student p) { //��ѧ����Ϣp������д���ļ�
	FILE *fp;  //�ļ�ָ��
	fp=fopen("studentlist.txt","ab");  //��׷�ӵķ�ʽ������Ϊstudentlist�Ķ������ļ�
	if(fp==NULL) {
		printf("cannot open file!\n");
	}
	if(fwrite(p,N,1,fp)!=1) { //��p��ָ���һ�δ�СΪN�����ݴ���fp��ָ����ļ���
		printf("write error!\n");
	}
	fclose(fp);  //�ر��ļ�
}

void save_registration(registration p) { //��ע��p������д���ļ�
	FILE *fp;  //�ļ�ָ��
	fp=fopen("registration.txt","ab");  //��׷�ӵķ�ʽ������Ϊstudentlist�Ķ������ļ�
	if(fp==NULL) {
		printf("cannot open file!\n");
	}
	if(fwrite(p,M,1,fp)!=1) { //��p��ָ���һ�δ�СΪM�����ݴ���fp��ָ����ļ���
		printf("write error!\n");
	}
	fclose(fp);  //�ر��ļ�
}

void over() {  //�˳����
	system("cls");
	char t;
	toxy(40,12);
	printf("-----------------------\n");
	toxy(40,13);
	printf("|                     |\n");
	toxy(40,14);
	printf("|   ��ȷ��Ҫ�˳���  |\n");
	toxy(40,15);
	printf("|   1.ȷ��   2.ȡ��   |\n");
	toxy(40,16);
	printf("|                     |\n");
	toxy(40,17);
	printf("-----------------------\n");
	while(1) {
		t=getch();     //����t
		switch(t) {
			case '1':
				system("cls");
				color(6);
				toxy(45,15);
				printf("���ڰ�ȫ�˳�....\n");
				Sleep(1000);   //��ͣ1��
				system("cls");
				color(8);
				toxy(45,14);
				printf("�Ѱ�ȫ�˳����!\n");
				toxy(45,15);
				printf("ллʹ�ã�\n");
				toxy(45,16);
				printf("by-by^_^\n");
				exit(0);
				break; //��ֹ����
			case '2':
				menu();
				break;
			default :
				break;
		}
	}
}

