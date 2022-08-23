#ifndef LIST_H
#define LIST_H

//�ṹ���ض��� 
typedef struct STUDENT Student;
typedef Student *student;
typedef struct REGISTRATION Registration;
typedef Registration *registration;

//���ӹ��� 
void HideCursor(); 		//���ع��

void toxy(int x, int y);  		//������ƶ���X,Y���괦

void color(short x);   	//������ɫ

void over();       		//�˳�

void print_rank();		//����������

//��Ҫ���� 
void save_student(student p);	//��ѧ����Ϣ�����ļ�

void save_registration(registration p);		//���û�ע����Ϣ�����ļ���

void user_choice();		//�û�ģʽ

void land_interface();	//��¼����

void homepage();		//��¼ѡ�����

void manager();			//������ģʽ

void manager_code();//����Ա��¼������֤ 

void amend_member();	//�޸��û���Ϣ

void print_member();  	//ע����Ϣ����

void del_member();  	//ɾ���û���Ϣ 

void menu();     		//�˵�

void input_student();   //ѧ����Ϣ���

void del_student();   	//ɾ��ѧ����Ϣ

void amend_student();  	//�޸�ѧ����Ϣ

void find_student();   	//��ѯѧ����Ϣ

void print_student(); 	//ѧ����Ϣ����

student ss();   		//��ѧ����Ϣ�ļ��е����ݶ����������У�����ֵΪ��ͷ��ַ 

registration cc(); 		//���û���Ϣ�ļ��е����ݶ����������У�����ֵΪ��ͷ��ַ

void input_registration();  //����¼��

void find_name_student(); //��������ѯ

void find_profession_student(); //��רҵ����ѯ

void find_number_student(); //��ѧ�Ų�ѯ

void find_nationality_student(); //�������ѯ

void fuzzy_search();   //ģ������

void rank_student(student head);//�ɼ�����

void max_min(student head);//�����߷ֺ���ͷ��Լ������Ϣ

#endif
