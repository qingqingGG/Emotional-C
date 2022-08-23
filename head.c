#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#define N sizeof(struct STUDENT)
#define M sizeof(struct REGISTRATION)
#include "head.h" 

struct STUDENT {           	//学生信息
	char number[12];       	//学号
	char name[10];         	//姓名
	char profession[10];  	//专业名
	char sex[4];          	//性别
	char nationality[10]; 	//籍贯
	char telephone[13];  	//手机
	float Language;    	 	//语文成绩
	float Math;             //数学成绩
	float English;          //英语成绩
	float total;            //总成绩
	float average;          //平均成绩
	int x;
	struct STUDENT *next;   //指针域
};

struct REGISTRATION {
	char name[12];           //用户名
	char code[20];           //密码
	char telephone[14];      //联系方式
	int x;
	struct REGISTRATION *next;     //指针域
};

void HideCursor() { //隐藏光标
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

void toxy(int x, int y) { //将光标移动到X,Y坐标处
	COORD pos = { x , y };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}

void menu() { //菜单
	do {
		system("cls"); //清屏
		HideCursor(); //隐藏光标
		color(15);  //设置一个好看的颜色
		char t;
		toxy(35,7);
		printf("-------------学生信息管理系统-------------\n");
		toxy(35,8);
		printf("|                                        |\n");
		toxy(35,9);
		printf("|                1.信息入库              |\n");
		toxy(35,10);
		printf("|                2.修改信息              |\n");
		toxy(35,11);
		printf("|                3.删除信息              |\n");
		toxy(35,12);
		printf("|                4.信息查询              |\n");
		toxy(35,13);
		printf("|                5.信息总览              |\n");
		toxy(35,14);
		printf("|                6.退出软件              |\n");
		toxy(35,15);
		printf("|                7.切换账号              |\n");
		toxy(35,16);
		printf("|                8.用管理模式打开        |\n");
		toxy(35,17);
		printf("|                                        |\n");
		toxy(35,18);
		printf("------------------------------------------\n");
		toxy(35,19);
		printf("        请输入你需要进行的操作序号！      \n");
		t=getch();  //不回显函数
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

student ss() { //将学生信息文件中的内容读出到链表中，返回值为表头地址
	FILE *fp;    //文件指针
	int n=0;
	student head=NULL;
	student p2,p,pr=NULL;
	fp=fopen("studentlist.txt","ab+");   //以只读的方式打开文件
	if(fp==NULL) {
		printf("cannot open file\n");
	}
	while(!feof(fp)) {  //判断文件位置标志是否移动到文件末尾
		n++;
		p=(student)malloc(N); //向内存申请一段空间
		fread(p,N,1,fp);   //将fp所指向的文件中的内容赋给p
		if(n==1) {
			head=p;
			p2=p;
		} else {   //创建链表
			pr=p2;
			p2->next=p;
			p2=p;
		}
	}
	if(pr!=NULL)
		pr->next=NULL;
	else
		head=NULL;
	fclose(fp);  //关闭文件
	return head;  //返回头指针
}

registration cc() { //将注册信息文件中的内容读出到链表中，返回值为表头地址
	FILE *fp;    //文件指针
	int n=0;
	registration head=NULL;
	registration p2,p,pr=NULL;
	fp=fopen("registration.txt","ab+");   //以只读的方式打开文件
	if(fp==NULL) {
		printf("cannot open file\n");
	}
	while(!feof(fp)) {  //判断文件位置标志是否移动到文件末尾
		n++;
		p=(registration)malloc(M); //向内存申请一段空间
		fread(p,M,1,fp);   //将fp所指向的文件中的内容赋给p
		if(n==1) {
			head=p;
			p2=p;
		} else {   //创建链表
			pr=p2;
			p2->next=p;
			p2=p;
		}
	}
	if(pr!=NULL)
		pr->next=NULL;
	else
		head=NULL;
	fclose(fp);  //关闭文件
	return head;  //返回头指针
}

void input_student() { //学生信息录入
	do {
		system("cls");
		color(10);
		char t;
		student p;
		p=(student)malloc(N);   //申请空间
		//输入学生信息
		printf("请输入学号(小于12位数)：\n");
		scanf("%s",p->number);
		getchar();
		printf("请输入姓名(小于8个字)：\n");
		scanf("%s",p->name);
		getchar();
		printf("请输入专业名(小于等于5个字)：\n");
		scanf("%s",p->profession);
		getchar();
		printf("请输入联系方式(小于等于13位数)：\n");
		scanf("%s",p->telephone);
		getchar();
		printf("请输入籍贯(小于等于5个字)：\n");
		scanf("%s",p->nationality);
		getchar();
		printf("请输入性别(小于4位数)：\n");
		scanf("%s",p->sex);
		getchar();
		printf("请输入语文成绩：\n");
		scanf("%f",&p->Language);
		getchar();
		printf("请输入数学成绩：\n");
		scanf("%f",&p->Math);
		getchar();
		printf("请输入英语成绩：\n");
		scanf("%f",&p->English);
		getchar();
		p->total=p->Language+p->English+p->Math;
		p->average=p->total/3;
		save_student(p);
		printf("正在保存....");
		Sleep(500);  //暂停0.5秒
		system("cls");
		toxy(40,7);
		printf("-------------------------\n");
		toxy(40,8);
		printf("|                       |\n");
		toxy(40,9);
		printf("|        保存成功！     |\n");
		toxy(40,10);
		printf("| 是否继续录入学生信息？|\n");
		toxy(40,11);
		printf("|     1.是      2.否    |\n");
		toxy(40,12);
		printf("|                       |\n");
		toxy(40,13);
		printf("-------------------------\n");
		while(1) { //利用死循环可有效防止其他按键干扰
			t=getch();
			if(t=='1') break;
			else if(t=='2') menu();
		}
	} while(1);
}

void manager_code(){//管理员登录密码验证 
	system("cls");
	HideCursor();
	color(15);
	int i;
	char name[12],code[20];
	for(i=0;i<3;i++)
	{
		toxy(40,10);
		printf("-------需要验证管理员身份------\n");
		toxy(40,11);
		printf("                               \n"); 
		toxy(40,12);
		printf("    管理员账户:                \n");
		toxy(40,13);
		printf("                               \n");
		toxy(40,14);
		printf("    管理员密码:                \n");
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
		printf("验证中...");
		Sleep(500);
		system("cls");
		if(strcmp(name,"manager1")==0&&strcmp(code,"123456")==0)
		{
			toxy(40,14);
			printf("密码正确，正在进入管理模式...\n");
			toxy(40,15);
			printf("请稍等..."); 
			Sleep(1000);
			manager();
		}
		else if(strcmp(name,"manager1")!=0&&strcmp(code,"123456")==0) 
		{
			toxy(40,14);
			printf("用户名错误，请重新输入...\n");
			toxy(40,15);
			printf("按任意键返回");
			getch(); 
		}
		else if(strcmp(name,"manager1")==0&&strcmp(code,"123456")!=0)
		{
			toxy(40,14);
			printf("密码错误，请重新输入...\n");
			toxy(40,15);
			printf("按任意键返回");
			getch(); 
		}
		else
		{
			toxy(40,14);
			printf("该账户未授权，请重新输入...\n");
			toxy(40,15);
			printf("按任意键返回");
			getch(); 
		} 	
	}
	system("cls");
	toxy(40,15);
	printf("密码错误次数太多，即将关闭系统");
	Sleep(1000);
	exit(0); 	
} 

void input_registration() { //注册成员录入
	system("cls");
	color(10);
	char t;
	registration p;
	p=(registration)malloc(M);   //申请空间
	//输入用户密码信息
	toxy(35,10);
	printf("------------------用户注册------------------");
	toxy(35,11);
	printf("|                                        |\n");
	toxy(35,12);
	printf("|   请输入用户名(小于6个字或12个字符)：  |\n");
	toxy(35,13);
	printf("|                                        |\n");
	toxy(35,14);
	printf("|   请输入密码(小于20位)：               |\n");
	toxy(35,15);
	printf("|                                        |\n");
	toxy(35,16);
	printf("|   请输入联系方式(13位)：               |\n");
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
	printf("正在保存....");
	Sleep(500);  //暂停0.5秒
	system("cls");
	toxy(40,14);
	printf("按任意键前往登录...");
	getch();
	land_interface();
}

void user_choice() { //用户模式
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
		printf("       请问您需要进行的操作是：     \n");
		toxy(40,12);
		printf("                                    \n");
		toxy(40,13);
		printf("      1.登录    2.注册    3.返回    \n");
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

void land_interface() { //登录界面
	do {
		color(10);
		char t;
		int n=0,num=0,i;
		registration head,p;
		char name[12],code[20];
		head=cc();
		for(i=0; i<5; i++) {//用for函数来控制登录次数，如果超过次数显示登录次数过多 
			p=head;
			system("cls");
			toxy(40,8);
			printf("-------------------------------\n");
			toxy(40,9);
			printf("|                             |\n");
			toxy(40,10);
			printf("|   请输入用户名：            |\n");
			toxy(40,11);
			printf("|                             |\n");
			toxy(40,12);
			printf("|   请输入密码：              |\n");
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
			printf("验证中...");
			Sleep(500);
			system("cls");
			if(p==NULL) {
				toxy(40,15);
				printf("未有人注册，欢迎成为第一位用户\n");
				toxy(40,16);
				printf("按任意键前往注册");
				getch();
				input_registration();
			}
			p=head;
			while(p!=NULL) {
				for(p=head; p!=NULL; p=p->next) {//判断是否有相匹配的用户名 
					if(strcmp(p->name,name)==0)
						n++;
				}
				p=head;
				for(p=head; p!=NULL; p=p->next) {
					if(strcmp(p->name,name)==0) {
						if(strcmp(p->code,code)==0) {
							toxy(40,15);
							printf("登录成功，请稍等...");
							Sleep(500);
							system("cls");
							menu();
						} else if(strcmp(p->code,code)!=0) {
							toxy(40,15);
							printf("密码错误，请重新登录\n");
							toxy(40,16);
							printf("按任意键重新登录");
							getch();
						}
					}
				}
				if(n==0)
				{
					toxy(40,15);
					printf("此账号未注册，请前往注册\n");
					toxy(40,16);
					printf("按任意键前往注册");
					getch();
					input_registration();
				}
			}

		}
		system("cls");
		toxy(40,15);
		printf("您错误的次数太多，即将退出系统...\n");
		Sleep(1000);
		exit(0);
	} while(1);
}

void homepage() { //首页
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
		printf("|              1.用户模式            |\n");
		toxy(35,13);
		printf("|              2.管理者模式          |\n");
		toxy(35,14);
		printf("|                                    |\n");
		toxy(35,15);
		printf("--------------------------------------\n");
		toxy(35,16);
		printf("     请输入你需要进行的操作序号！     \n");
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

void manager() { //管理者模式
	do {
		char t;
		system("cls");
		HideCursor();
		color(15);
		toxy(35,10);
		printf("----------------管理者模式----------------\n");
		toxy(35,11);
		printf("|                                        |\n");
		toxy(35,12);
		printf("|             1.用户信息总览             |\n");
		toxy(35,13);
		printf("|             2.删除用户信息             |\n");
		toxy(35,14);
		printf("|             3.修改用户信息             |\n");
		toxy(35,15);
		printf("|             4.返回首页                 |\n");
		toxy(35,16);
		printf("|             5.进入学生信息管理系统     |\n");
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

void amend_member() { //修改用户信息
	do {
		system("cls");
		color(10);
		registration head,p;
		int j=0,x;
		char ch,t;
		FILE *fp;  //文件指针
		char name[12];   //姓名
		char code[20];  //密码 
		char telephone[14];   //手机号码
		head=cc();
		p=head;
		while(p!=NULL) { //初始化p->x为0
			p->x=0;
			p=p->next;
		}
		p=head;  //让p重新指向表头
		printf("****************************用户信息****************************\n");
		printf("---------------------------------------------------------------\n");
		printf(" 序号    用户名        密码                       联系方式     \n");
		printf("---------------------------------------------------------------\n");
		if(head==NULL) {
			printf("信息库中暂时没有注册信息哦~^_^(按任意键返回)");
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
			printf("请输入您要修改的用户信息排列的序号：\n");
			scanf("%d",&x);
			getchar();
			if(x>j||x<=0) 
			{
				printf("输入错误，请重新输入!\n");
				Sleep(500);
			} 
			else 
			{
				break;
			}
		}
		p=head;   //让p重新指向表头
		while(p!=NULL&&p->x!=x) { //遍历链表查询符合条件的结点
			p=p->next;
		}
		if(p) { //如果p不为空
			system("cls");
			//输入要修改的信息
			toxy(40,11);
			printf("------请输入要修改的用户信息的序列号！------\n");
			toxy(40,12);
			printf("|                                          |\n");
			toxy(40,13);
			printf("|                   1.姓名                 |\n");
			toxy(40,14);
			printf("|                   2.密码                 |\n");
			toxy(40,15);
			printf("|                   3.联系方式             |\n");
			toxy(40,16);
			printf("|                                          |\n");
			toxy(40,17);
			printf("--------------------------------------------\n");
			t=getch();
			switch(t) {
				case '1':
					toxy(20,19);
					printf("请输入姓名(小于6个字或者12个字符)：\n");
					scanf("%s",p->name);
					getchar();
					break;
				case '2':
					toxy(20,19);
					printf("请输入密码(小于20位字符)：\n");
					scanf("%s",p->code);
					getchar();
					break;
				case '3':
					toxy(20,19);
					printf("请输入联系方式(小于等于13位数)：\n");
					scanf("%s",p->telephone);
					getchar();
					break;
			}
		}
		color(7);
		system("cls");
		toxy(40,15);
		printf("跳转中...");
		Sleep(1000);
		system("cls");
		toxy(40,12);
		printf("-------------------------\n");
		toxy(40,13);
		printf("|                       |\n");
		toxy(40,14);
		printf("|     是否确认修改？    |\n");
		toxy(40,15);
		printf("|    1.是       2.否    |\n");
		toxy(40,16);
		printf("|                       |\n");
		toxy(40,17);
		printf("-------------------------\n");
		while(1) { //利用死循环防止其他按键干扰
			t=getch();
			if(t=='1') {
				break;
			} else if(t=='2') {
				manager();
			}
		}
		system("cls");
		toxy(40,15);
		printf("正在修改，请稍后....\n");
		fp=fopen("registration.txt","wb");  //以只写的方式打开名为studentlist的二进制文件，打开的同时清空文件中的内容
		if(fp==NULL) {
			printf("cannot open file\n");
		}
		if(fwrite(head,M,1,fp)!=1) { //将head写入fp所指向的文件中
			printf("write error!\n");
		}
		fclose(fp);  //关闭文件
		if(head!=NULL) { //如果head不为空
			p=head->next;   //让p指向第二个结点
			fp=fopen("registration.txt","ab");  //以追加的方式打开文件
			if(fp==NULL) {
				printf("cannot open file\n");
			}
			while(p!=NULL) {
				if(fwrite(p,M,1,fp)!=1) { //将p写入fp所指向的文件中
					printf("write error!\n");
				}
				p=p->next;
			}
			fclose(fp); //关闭文件
		}
		Sleep(500);  //暂停0.5秒
		system("cls");
		toxy(40,15);
		printf("修改成功！\n");
		Sleep(500);
		system("cls");
		toxy(40,12);
		printf("-------------------------\n");
		toxy(40,13);
		printf("|                       |\n");
		toxy(40,14);
		printf("|     是否继续修改？    |\n");
		toxy(40,15);
		printf("|    1.是       2.否    |\n");
		toxy(40,16);
		printf("|                       |\n");
		toxy(40,17);
		printf("-------------------------\n");
		while(1) { //利用死循环可有效防止其他按键干扰
			t=getch();
			if(t=='1') break;
			else if(t=='2') manager();
		}
	} while(1);
}

void print_member() { //注册信息总览
	system("cls");
	color(6);
	registration head,p;
	int j=0;
	char t;
	head=cc();
	printf("****************************用户信息****************************\n");
	printf("---------------------------------------------------------------\n");
	printf(" 序号    用户名        密码                       联系方式     \n");
	printf("---------------------------------------------------------------\n");
	if(head==NULL) {
		printf("信息库中暂时没有注册信息哦~^_^(按任意键返回)");
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
	printf("******你先一步需要进行的操作是？******\n");
	printf("|                                    |\n");
	printf("|            1.返回主界面            |\n");
	printf("|                                    |\n");
	printf("|            2.修改用户信息          |\n");
	printf("|                                    |\n");
	printf("|            3.删除用户信息          |\n");
	printf("|                                    |\n");
	printf("--------------------------------------\n");
	printf("      请输入你需要进行操作的序号      \n");
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
	Sleep(500);  //暂停0.5秒
	system("cls");
	toxy(55,15);
	printf("请稍等...\n");
	Sleep(500);  //暂停0.5秒
	system("cls");
	toxy(55,15);
	printf("按任意键返回!\n");
	getch();//不回显函数
}

void del_member() { //删除用户信息
	do {
		system("cls");
		color(9);
		FILE *fp;
		registration head,p,pre=NULL;
		int j=0,x;
		char t,c,ch;
		head=cc();  //调用函数，返回表头地址
		p=head;
		while(p!=NULL) {
			p->x=0;
			p=p->next;
		}
		p=head;  //让p重新指向表头
		printf("****************************用户信息****************************\n");
		printf("---------------------------------------------------------------\n");
		printf(" 序号    用户名        密码                       联系方式     \n");
		printf("---------------------------------------------------------------\n");
		if(head==NULL) {
			printf("信息库中暂时没有注册信息哦~^_^(按任意键返回)");
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
			printf("请输入您要删除的用户的序号：\n");
			scanf("%d",&x);
			getchar();
			if(x>j||x==0) {
				printf("输入错误，请重新输入!\n");
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
		printf("|     是否确认删除？    |\n");
		toxy(40,15);
		printf("|    1.是       2.否    |\n");
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
		while(p!=NULL&&p->x!=x) { //遍历链表查询符合条件的结点
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
		fp=fopen("registration.txt","wb");//以只写的方式打开名为studentlist的二进制文件，打开的同时清空文件中的内容
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
		printf("正在删除，请稍后....\n");
		Sleep(500);
		system("cls");
		toxy(40,12);
		printf("-------------------------\n");
		toxy(40,13);
		printf("|                       |\n");
		toxy(40,14);
		printf("|  删除成功，是否继续？ |\n");
		toxy(40,15);
		printf("|    1.是       2.否    |\n");
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

void amend_student() { //修改学生信息
	do {
		system("cls");
		color(10);
		student head,p;
		int j=0,x;
		char ch,t;
		FILE *fp;  //文件指针
		char _name[10];
		char number[12];  //学号 
		char name[10];   //姓名
		char profession[10];  //专业名
		char telephone[13];   //手机号码
		char nationality[10]; //籍贯
		char sex[4];    //性别
		float Language;    	 	//语文成绩
		float Math;             //数学成绩
		float English;          //英语成绩
		head=ss();
		p=head;

		printf("请输入你要修改的学生姓名：\n");
		gets(_name);
		while(p!=NULL) { //初始化p->x为0
			p->x=0;
			p=p->next;
		}
		p=head;  //让p重新指向表头
		printf("*******************************************************学生信息*******************************************************\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf(" 序号   学号         姓名     性别    专业     籍贯         联系方式      语文     数学     英语    总成绩   平均成绩 \n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		while(p!=NULL) {
			if(p!=NULL&&strcmp(p->name,_name)==0) {
				j++;
				printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-4.2f     %-4.2f   %-4.2f   %-4.2f    %-4.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
				p->x=j;  //给符合查询标准的结点标号
			}
			p=p->next;
		}
		if(j==0) {        //如果j=0，即没有进入前面的搜索循环，也就是没有找到相应的信息
			printf("没有找到相应的信息！\n(按0返回，按1重新搜索)");
			while(1) {      //死循环是为了防止除0和1的其他按键干扰
				ch=getch();
				if(ch=='0') {
					menu();
					break;
				} else if(ch=='1') {
					break;
				}
			}
			if(ch=='1')   //如果输入的ch等于1，则结束本次循环
				continue;
		}
		while(1) {
			printf("请输入您要修改的学生信息排列的序号：\n");
			scanf("%d",&x);
			getchar();
			if(x>j||x==0) {
				printf("输入错误，请重新输入!\n");
				Sleep(500);
			} else {
				break;
			}
		}
		p=head;   //让p重新指向表头
		while(p!=NULL&&p->x!=x) { //遍历链表查询符合条件的结点
			p=p->next;
		}
		if(p) { //如果p不为空
			system("cls");
			//输入要修改的信息
			toxy(40,7);
			printf("请输入要修改的学生信息的序列号！\n");
			toxy(40,8);
			printf("|           1.学号             |\n");
			toxy(40,9);
			printf("|           2.姓名             |\n");
			toxy(40,10);
			printf("|           3.专业名           |\n");
			toxy(40,11);
			printf("|           4.联系方式         |\n");
			toxy(40,12);
			printf("|           5.籍贯             |\n");
			toxy(40,13);
			printf("|           6.性别             |\n");
			toxy(40,14);
			printf("|           7.语文成绩         |\n");
			toxy(40,15);
			printf("|           8.数学成绩         |\n");
			toxy(40,16);
			printf("|           9.英语成绩         |\n");
			toxy(40,17);
			printf("--------------------------------\n");
			t=getch();
			switch(t) {
				case '1':
					toxy(20,19);
					printf("请输入学号(小于12位数)：\n");
					scanf("%s",p->number);
					getchar();
					break;
				case '2':
					toxy(20,19);
					printf("请输入姓名(小于等于5个字)：\n");
					scanf("%s",p->name);
					getchar();
					break;
				case '3':
					toxy(20,19);
					printf("请输入专业名(小于等于5个字)：\n");
					scanf("%s",p->profession);
					getchar();
					break;
				case '4':
					toxy(20,19);
					printf("请输入联系方式(小于等于13位数)：\n");
					scanf("%s",p->telephone);
					getchar();
					break;
				case '5':
					toxy(20,19);
					printf("请输入籍贯(小于5个字)：\n");
					scanf("%s",p->nationality);
					getchar();
					break;
				case '6':
					toxy(20,19);
					printf("请输入性别(小于等于4个字)：\n");
					scanf("%s",p->sex);
					getchar();
					break;
				case '7':
					toxy(20,19);
					printf("请输入语文成绩：\n");
					scanf("%f",&p->Language);
					getchar();
					break;
				case '8':
					toxy(20,19);
					printf("请输入数学成绩：\n");
					scanf("%f",&p->Math);
					getchar();
					break;
				case '9':
					toxy(20,19);
					printf("请输入英语成绩：\n");
					scanf("%f",&p->English);
					getchar();
					break;
			}
		}
		color(7);
		system("cls");
		printf("跳转中...");
		Sleep(1500);
		system("cls");
		toxy(40,12);
		printf("-------------------------\n");
		toxy(40,13);
		printf("|                       |\n");
		toxy(40,14);
		printf("|     是否确认修改？    |\n");
		toxy(40,15);
		printf("|    1.是       2.否    |\n");
		toxy(40,16);
		printf("|                       |\n");
		toxy(40,17);
		printf("-------------------------\n");
		while(1) { //利用死循环防止其他按键干扰
			t=getch();
			if(t=='1') {
				break;
			} else if(t=='2') {
				menu();
			}
		}
		system("cls");
		printf("正在修改，请稍后....\n");
		fp=fopen("studentlist","wb");  //以只写的方式打开名为studentlist的二进制文件，打开的同时清空文件中的内容
		if(fp==NULL) {
			printf("cannot open file\n");
		}
		if(fwrite(head,N,1,fp)!=1) { //将head写入fp所指向的文件中
			printf("write error!\n");
		}
		fclose(fp);  //关闭文件
		if(head!=NULL) { //如果head不为空
			p=head->next;   //让p指向第二个结点
			fp=fopen("studentlist","ab");  //以追加的方式打开文件
			if(fp==NULL) {
				printf("cannot open file\n");
			}
			while(p!=NULL) {
				if(fwrite(p,N,1,fp)!=1) { //将p写入fp所指向的文件中
					printf("write error!\n");
				}
				p=p->next;
			}
			fclose(fp); //关闭文件
		}
		Sleep(500);  //暂停0.5秒
		system("cls");
		printf("修改成功！\n");
		Sleep(500);
		system("cls");
		printf("-------------------------\n");
		printf("|                       |\n");
		printf("|     是否继续修改？    |\n");
		printf("|    1.是       2.否    |\n");
		printf("|                       |\n");
		printf("-------------------------\n");
		while(1) { //利用死循环可有效防止其他按键干扰
			t=getch();
			if(t=='1') break;
			else if(t=='2') menu();
		}
	} while(1);
}

void del_student() { //删除学生信息
	do {
		system("cls");
		color(9);
		FILE *fp;
		student head,p,pre=NULL;
		int j=0,x;
		char name[10];
		char t,c,ch;
		head=ss();  //调用函数，返回表头地址
		printf("请输入你要删除的学生姓名：\n");
		scanf("%s",name);
		p=head;
		while(p!=NULL) {
			p->x=0;
			p=p->next;
		}
		p=head;
		printf("*******************************************************学生信息*******************************************************\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf(" 序号   学号         姓名     性别    专业     籍贯         联系方式      语文     数学     英语    总成绩   平均成绩 \n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		while(p!=NULL) {
			if(p!=NULL&&strcmp(p->name,name)==0) {
				j++;
				printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-4.2f     %-4.2f   %-4.2f   %-4.2f    %-4.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
				p->x=j;
			}
			p=p->next;
		}
		if(j==0) {        //如果j=0，即没有进入前面的搜索循环，也就是没有找到相应的信息
			printf("没有找到相应的信息！\n(按0返回，按1重新搜索)");
			while(1) {      //死循环是为了防止除0和1的其他按键干扰
				ch=getch();
				if(ch=='0') {
					menu();
					break;
				} else if(ch=='1') {
					break;
				}
			}
			if(ch=='1')   //如果输入的ch等于1，则结束本次循环
				continue;
		}
		while(1) {
			printf("请输入您要删除的学生的序号：\n");
			scanf("%d",&x);
			getchar();
			if(x>j||x==0) {
				printf("输入错误，请重新输入!\n");
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
		printf("|     是否确认删除？    |\n");
		toxy(40,15);
		printf("|    1.是       2.否    |\n");
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
		printf("正在删除，请稍后....\n");
		Sleep(500);
		system("cls");
		toxy(40,12);
		printf("-------------------------\n");
		toxy(40,13);
		printf("|                       |\n");
		toxy(40,14);
		printf("|  删除成功，是否继续？ |\n");
		toxy(40,15);
		printf("|    1.是       2.否    |\n");
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

void print_student() { //学生信息总览
	system("cls");
	color(6);
	student head,p;
	int j=0;
	char t;
	head=ss();
	printf("*******************************************************学生信息*******************************************************\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf(" 序号   学号         姓名     性别    专业     籍贯         联系方式      语文     数学     英语    总成绩   平均成绩 \n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	if(head==NULL) {
		printf("信息库中暂时没有学生信息哦~赶快去添加几条吧^_^(按任意键返回)");
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
	printf("        -------您需要进行的下一步的操作是？-------\n");
	printf("        |         1.标记成绩有不及格的学生       |\n");;
	printf("        |         2.对学生成绩进行排序           |\n");
	printf("        |         3.查看最高分和最低分           |\n");
	printf("        |         4.返回主菜单                   |\n");
	printf("        ------------------------------------------\n");
	t=getch();
	Sleep(500);  //暂停0.5秒
	system("cls");
	switch(t) {
		case '1':
			p=head;
			printf("*******************************************************学生信息*******************************************************\n");
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			printf(" 序号   学号         姓名     性别    专业     籍贯         联系方式      语文     数学     英语    总成绩   平均成绩 \n");
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
			printf("按任意键进行下一步操作!\n");
			getch();
			printf("\n");
			printf("      -----您下一步的操作是？-----\n");
			printf("      |     1.返回成绩列表       |\n");
			printf("      |     2.对成绩进行排序     |\n");
			printf("      |     3.返回主菜单         |\n");
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
	Sleep(500);  //暂停0.5秒
	system("cls");
	toxy(55,15);
	printf("请稍等...\n");
	Sleep(500);  //暂停0.5秒
	system("cls");
	toxy(55,15);
	printf("按任意键返回!\n");
	getch();//不回显函数
}

void rank_student(student head) { //学生成绩排序
	color(6);
	do {
		system("cls");
		Sleep(500);
		student flag = NULL, j = NULL, t = NULL;
		student q = head, h = head;
		char v,m;
		int g=0;
		toxy(40,8);
		printf("请您选择需要排序的选项！\n");
		toxy(40,9);
		printf("|  --  1.语文成绩  --  |\n");
		toxy(40,10);
		printf("|  --  2.数学成绩  --  |\n");
		toxy(40,11);
		printf("|  --  3.英语成绩  --  |\n");
		toxy(40,12);
		printf("|  --  4.总成绩    --  |\n");
		toxy(40,13);
		printf("|  --  5.平均成绩  --  |\n");
		toxy(40,14);
		printf("------------------------\n");
		toxy(40,15);
		printf("\n");
		toxy(40,16);
		printf("请输入您要选择的序号^-^\n");
		v=getch();
		Sleep(500);  //暂停0.5秒
		system("cls");
		if(q!=NULL) {
			switch(v) {
				case '1':
					print_rank();
					m=getch();
					switch(m) {
						case '1'://语文升序
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//交换指针
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
							// 更换头节点, 并且将头节点插入到合适的位置(一次插排)

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

						case '2'://语文降序
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//交换指针
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
							// 更换头节点, 并且将头节点插入到合适的位置(一次插排)

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
						case '1'://数学升序
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//交换指针
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
							// 更换头节点, 并且将头节点插入到合适的位置(一次插排)

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

						case '2'://数学降序
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//交换指针
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
							// 更换头节点, 并且将头节点插入到合适的位置(一次插排)

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
						case '1'://英语升序
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//交换指针
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
							// 更换头节点, 并且将头节点插入到合适的位置(一次插排)

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

						case '2'://英语降序
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//交换指针
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
							// 更换头节点, 并且将头节点插入到合适的位置(一次插排)

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
						case '1'://总成绩升序
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//交换指针
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
							// 更换头节点, 并且将头节点插入到合适的位置(一次插排)

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

						case '2'://总成绩降序
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//交换指针
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
							// 更换头节点, 并且将头节点插入到合适的位置(一次插排)

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
						case '1'://平均成绩升序
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//交换指针
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
							// 更换头节点, 并且将头节点插入到合适的位置(一次插排)

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

						case '2'://平均成绩降序
							if (head->next == NULL) {
								return;
							}
							do {
								j = head;
								t = flag;
								flag = NULL;

								while (j->next->next != t) {
									//交换指针
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
							// 更换头节点, 并且将头节点插入到合适的位置(一次插排)

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
			printf("信息库中暂时没有学生信息哦~赶快去添加几条吧^_^(按任意键返回)");
			getch();
			menu();
		}
		Sleep(500);  //暂停0.5秒
		system("cls");
		printf("排序中请稍等！\n");
		Sleep(500);
		system("cls");
		q=head;
		printf("*******************************************************学生信息*******************************************************\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf(" 序号   学号         姓名     性别    专业     籍贯         联系方式      语文     数学     英语    总成绩   平均成绩 \n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		while(q!=NULL) {
			g++;
			printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-5.2f     %-5.2f   %-5.2f   %-5.2f    %-5.2f\n",g,q->number,q->name,q->sex,q->profession,q->nationality,q->telephone,q->Language,q->Math,q->English,q->total,q->average);
			q=q->next;
		}
		printf("\n");
		printf("-------------------------\n");
		printf("|                       |\n");
		printf("|    下一步的操作是？   |\n");
		printf("|    1.返回学生成绩表   |\n");
		printf("|    2.返回主菜单       |\n");
		printf("|                       |\n");
		printf("-------------------------\n");
		while(1) { //利用死循环可有效防止其他按键干扰
			v=getch();
			if(v=='1')
				print_student();
			else if(v=='2') menu();
		}
	} while(1);
}

void print_rank() { //排列输出框架
	toxy(40,10);
	printf("请问您需要对此成绩进行升序排列还是降序排列？\n");
	toxy(40,11);
	printf("|                                          |\n");
	toxy(40,12);
	printf("|        ****       1.升序       ****      |\n");
	toxy(40,13);
	printf("|        ****       2.降序       ****      |\n");
	toxy(40,14);
	printf("|                                          |\n");
	toxy(40,15);
	printf("--------------------------------------------\n");
}

void max_min(student head) { //输出最高分和最低分以及相关信息
	color(6);
	student p=head;
	char t,m;
	float max,min;
	printf("\n");
	printf("-----------------------------------\n");
	printf("|                                 |\n");
	printf("|     1.查看语文最高分和最低分    |\n");
	printf("|     2.查看数学最高分和最低分    |\n");
	printf("|     3.查看英语最高分和最低分    |\n");
	printf("|     4.查看总分最高分和最低分    |\n");
	printf("|     5.查看平均分最高分和最低分  |\n");
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
			printf("语文最高分为：%5.2f\t最低分为：%5.2f\n",max,min);
			printf("\n\n\n");
			p=head;
			do {
				if(max==p->Language) {
					printf("语文最高分同学的基本信息是：\n");
					printf("学号：%s\t姓名：%s\t专业：%s\t语文得分：%5.2f\n",p->number,p->name,p->profession,p->Language);
				}
				p=p->next;
			} while(p!=NULL);
			printf("\n\n\n");
			p=head;
			do {
				if(min==p->Language) {
					printf("语文最低分同学的基本信息是：\n");
					printf("学号：%s\t姓名：%s\t专业：%s\t语文得分：%5.2f\n",p->number,p->name,p->profession,p->Language);
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
			printf("数学最高分为：%5.2f\t最低分为：%5.2f\n",max,min);
			printf("\n\n\n");
			p=head;
			do {
				if(max==p->Math) {
					printf("数学最高分同学的基本信息是：\n");
					printf("学号：%s\t姓名：%s\t专业：%s\t数学得分：%5.2f\n",p->number,p->name,p->profession,p->Math);
				}
				p=p->next;
			} while(p!=NULL);
			printf("\n\n\n");
			p=head;
			do {
				if(min==p->Math) {
					printf("数学最低分同学的基本信息是：\n");
					printf("学号：%s\t姓名：%s\t专业：%s\t数学得分：%5.2f\n",p->number,p->name,p->profession,p->Math);
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
			printf("英语最高分为：%5.2f\t最低分为：%5.2f\n",max,min);
			printf("\n\n\n");
			p=head;
			do {
				if(max==p->English) {
					printf("英语最高分同学的基本信息是：\n");
					printf("学号：%s\t姓名：%s\t专业：%s\t英语得分：%5.2f\n",p->number,p->name,p->profession,p->English);
				}
				p=p->next;
			} while(p!=NULL);
			printf("\n\n\n");
			p=head;
			do {
				if(min==p->English) {
					printf("英语最低分同学的基本信息是：\n");
					printf("学号：%s\t姓名：%s\t专业：%s\t英语得分：%5.2f\n",p->number,p->name,p->profession,p->English);
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
			printf("总分最高分为：%5.2f\t最低分为：%5.2f\n",max,min);
			printf("\n\n\n");
			p=head;
			do {
				if(max==p->total) {
					printf("总分最高分同学的基本信息是：\n");
					printf("学号：%s\t姓名：%s\t专业：%s\t总分得分：%5.2f\n",p->number,p->name,p->profession,p->total);
				}
				p=p->next;
			} while(p!=NULL);
			printf("\n\n\n");
			p=head;
			do {
				if(min==p->total) {
					printf("总分最低分同学的基本信息是：\n");
					printf("学号：%s\t姓名：%s\t专业：%s\t总分得分：%5.2f\n",p->number,p->name,p->profession,p->total);
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
			printf("平均分最高分为：%f\t最低分为：%f\n",max,min);
			printf("\n\n\n");
			p=head;
			do {
				if(max==p->average) {
					printf("平均分最高分同学的基本信息是：\n");
					printf("学号：%s\t姓名：%s\t专业：%s\t平均分：%f\n",p->number,p->name,p->profession,p->average);
				}
				p=p->next;
			} while(p!=NULL);
			printf("\n\n\n");
			p=head;
			do {
				if(min==p->average) {
					printf("平均分最低分同学的基本信息是：\n");
					printf("学号：%s\t姓名：%s\t专业：%s\t平均分：%f\n",p->number,p->name,p->profession,p->average);
				}
				p=p->next;
			} while(p!=NULL);
			break;
	}
	printf("\n");
	printf("-------------------------\n");
	printf("|                       |\n");
	printf("|    下一步的操作是？   |\n");
	printf("|    1.返回学生成绩表   |\n");
	printf("|    2.返回主菜单       |\n");
	printf("|                       |\n");
	printf("-------------------------\n");
	while(1) { //利用死循环可有效防止其他按键干扰
		m=getch();
		if(m=='1')
			print_student();
		else if(m=='2') menu();
	}
}

void find_student() { //查询学生信息
	do {
		system("cls"); //清屏
		color(8);
		char t;
		toxy(40,8);
		printf("----------学生信息查询---------\n");
		toxy(40,9);
		printf("|         1.姓名查询          |\n");
		toxy(40,10);
		printf("|         2.专业查询          |\n");
		toxy(40,11);
		printf("|         3.学号查询          |\n");
		toxy(40,12);
		printf("|         4.籍贯查询          |\n");
		toxy(40,13);
		printf("|         5.模糊查询          |\n");
		toxy(40,14);
		printf("---------按0返回主菜单---------\n");
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

void find_name_student() { //按姓名查询
	system("cls");
	student head,p;
	int j=0;
	head=ss();
	char name[10];
	printf("请输入您要查询学生的姓名：\n");
	gets(name);
	printf("正在查询....\n");
	Sleep(500);
	p=head;
	printf("*******************************************************学生信息*******************************************************\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf(" 序号   学号         姓名     性别    专业     籍贯         联系方式      语文     数学     英语    总成绩   平均成绩 \n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	while(p!=NULL) {
		if(p!=NULL&&strcmp(p->name,name)==0) {
			j++;
			printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-4.2f     %-4.2f   %-4.2f   %-4.2f    %-4.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
		}
		p=p->next;
	}
	printf("按任意键返回！\n");
	getch();
	find_student();
}

void find_profession_student() { //按专业名查询
	system("cls");
	color(8);
	student head,p;
	int j=0;
	head=ss();
	char profession[10];
	printf("请输入您要查询学生姓名：\n");
	gets(profession);
	printf("正在查询....\n");
	Sleep(500);
	p=head;
	printf("*******************************************************学生信息*******************************************************\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf(" 序号   学号         姓名     性别    专业     籍贯         联系方式      语文     数学     英语    总成绩   平均成绩 \n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	while(p!=NULL) {
		if(p!=NULL&&strcmp(p->profession,profession)==0) {
			j++;
			printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-4.2f     %-4.2f   %-4.2f   %-4.2f    %-4.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
		}
		p=p->next;
	}
	printf("按任意键返回！\n");
	getch();
	find_student();
}

void find_number_student() { //按学号查询
	system("cls");
	color(8);
	student head,p;
	int j=0;
	head=ss();
	char number[10];
	printf("请输入您要查询学生学号：\n");
	gets(number);
	printf("正在查询....\n");
	p=head;
	printf("*******************************************************学生信息*******************************************************\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf(" 序号   学号         姓名     性别    专业     籍贯         联系方式      语文     数学     英语    总成绩   平均成绩 \n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	while(p!=NULL) {
		if(p!=NULL&&strcmp(p->number,number)==0) {
			j++;
			printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-4.2f     %-4.2f   %-4.2f   %-4.2f    %-4.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
		}
		p=p->next;
	}
	printf("按任意键返回！\n");
	getch();
	find_student();
}

void find_nationality_student() { //按籍贯查询
	system("cls");
	color(8);
	student head,p;
	int j=0;
	head=ss();
	char nationality[10];
	printf("请输入您要查询的学生籍贯：\n");
	gets(nationality);
	printf("正在查询....\n");
	Sleep(500);
	p=head;
	printf("*******************************************************学生信息*******************************************************\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf(" 序号   学号         姓名     性别    专业     籍贯         联系方式      语文     数学     英语    总成绩   平均成绩 \n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	while(p!=NULL) {
		if(p!=NULL&&strcmp(p->nationality,nationality)==0) {
			j++;
			printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-4.2f     %-4.2f   %-4.2f   %-4.2f    %-4.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
		}
		p=p->next;
	}
	printf("按任意键返回！\n");
	getch();
	find_student();
}

void fuzzy_search() { //模糊查询
	system("cls");
	color(8);
	student head,p;
	int j=0;
	head=ss();
	char information[10];
	printf("请输入您要查询学生的信息：\n");
	gets(information);
	printf("正在查询....\n");
	Sleep(500);
	p=head;
	printf("*******************************************************学生信息*******************************************************\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf(" 序号   学号         姓名     性别    专业     籍贯         联系方式      语文     数学     英语    总成绩   平均成绩 \n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	while(p!=NULL) {
		if(p!=NULL&&(strcmp(p->name,information)==0||strcmp(p->profession,information)==0||strcmp(p->number,information)==0||strcmp(p->nationality,information)==0)||strcmp(p->sex,information)==0||strcmp(p->telephone,information)==0) {
			j++;
			printf(" %-4d  %-12s  %-6s   %-4s   %-8s  %-10s %-12s   %-4.2f     %-4.2f   %-4.2f   %-4.2f    %-4.2f\n",j,p->number,p->name,p->sex,p->profession,p->nationality,p->telephone,p->Language,p->Math,p->English,p->total,p->average);
		}
		p=p->next;
	}
	printf("按任意键返回！\n");
	getch();
	find_student();
}

void save_student(student p) { //将学生信息p中内容写入文件
	FILE *fp;  //文件指针
	fp=fopen("studentlist.txt","ab");  //以追加的方式打开名字为studentlist的二进制文件
	if(fp==NULL) {
		printf("cannot open file!\n");
	}
	if(fwrite(p,N,1,fp)!=1) { //将p所指向的一段大小为N的内容存入fp所指向的文件中
		printf("write error!\n");
	}
	fclose(fp);  //关闭文件
}

void save_registration(registration p) { //将注册p中内容写入文件
	FILE *fp;  //文件指针
	fp=fopen("registration.txt","ab");  //以追加的方式打开名字为studentlist的二进制文件
	if(fp==NULL) {
		printf("cannot open file!\n");
	}
	if(fwrite(p,M,1,fp)!=1) { //将p所指向的一段大小为M的内容存入fp所指向的文件中
		printf("write error!\n");
	}
	fclose(fp);  //关闭文件
}

void over() {  //退出软件
	system("cls");
	char t;
	toxy(40,12);
	printf("-----------------------\n");
	toxy(40,13);
	printf("|                     |\n");
	toxy(40,14);
	printf("|   您确定要退出吗？  |\n");
	toxy(40,15);
	printf("|   1.确定   2.取消   |\n");
	toxy(40,16);
	printf("|                     |\n");
	toxy(40,17);
	printf("-----------------------\n");
	while(1) {
		t=getch();     //输入t
		switch(t) {
			case '1':
				system("cls");
				color(6);
				toxy(45,15);
				printf("正在安全退出....\n");
				Sleep(1000);   //暂停1秒
				system("cls");
				color(8);
				toxy(45,14);
				printf("已安全退出软件!\n");
				toxy(45,15);
				printf("谢谢使用！\n");
				toxy(45,16);
				printf("by-by^_^\n");
				exit(0);
				break; //终止程序
			case '2':
				menu();
				break;
			default :
				break;
		}
	}
}

