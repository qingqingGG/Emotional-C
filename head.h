#ifndef LIST_H
#define LIST_H

//结构体重定义 
typedef struct STUDENT Student;
typedef Student *student;
typedef struct REGISTRATION Registration;
typedef Registration *registration;

//附加功能 
void HideCursor(); 		//隐藏光标

void toxy(int x, int y);  		//将光标移动到X,Y坐标处

void color(short x);   	//设置颜色

void over();       		//退出

void print_rank();		//排列输出框架

//主要函数 
void save_student(student p);	//将学生信息存入文件

void save_registration(registration p);		//将用户注册信息存入文件中

void user_choice();		//用户模式

void land_interface();	//登录界面

void homepage();		//登录选择界面

void manager();			//管理者模式

void manager_code();//管理员登录密码验证 

void amend_member();	//修改用户信息

void print_member();  	//注册信息总览

void del_member();  	//删除用户信息 

void menu();     		//菜单

void input_student();   //学生信息入库

void del_student();   	//删除学生信息

void amend_student();  	//修改学生信息

void find_student();   	//查询学生信息

void print_student(); 	//学生信息总览

student ss();   		//将学生信息文件中的内容读出到链表中，返回值为表头地址 

registration cc(); 		//将用户信息文件中的内容读出到链表中，返回值为表头地址

void input_registration();  //密码录入

void find_name_student(); //按姓名查询

void find_profession_student(); //按专业名查询

void find_number_student(); //按学号查询

void find_nationality_student(); //按籍贯查询

void fuzzy_search();   //模糊查找

void rank_student(student head);//成绩排序

void max_min(student head);//输出最高分和最低分以及相关信息

#endif
