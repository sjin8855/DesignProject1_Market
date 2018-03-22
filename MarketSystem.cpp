#include "MarketSystem.h"
#include <Windows.h>
MarketSystem::MarketSystem()	// �⺻������
{

}
MarketSystem::MarketSystem(char* user_filename, char* product_filename)	//������
{
	strcpy_s(this->user_filename, strlen(user_filename)+1, user_filename);
	strcpy_s(this->product_filename, strlen(product_filename)+1, product_filename);
	/*for(int i=0; i<user_filename[i] != NULL; i++)
	{
		this->user_filename[i] = user_filename[i];
		this->product_filename[i] = product_filename[i];
	}*/
}

MarketSystem::~MarketSystem()	//�Ҹ���
{

}

void MarketSystem::load_File()	//���� �ε�
{
	market.load_file(product_filename, user_filename);
}

void MarketSystem::save_file()	//���� ����
{
	market.save_file("product.txt");
	market.save_file("user.txt");
}

bool MarketSystem::login(string _user_id, string _pass_word)// �α��� 
{
	if(market.login(_user_id, _pass_word)==false)
		return false;
	else
		return true;
}

void MarketSystem::logout()	//�α׾ƿ� ���� �Լ� 
{
	if(login(ms_current_user->get_userID(), ms_current_user->get_password())==true)		// �α��� �� �������� �α׾ƿ�.
		save_file();
}	

void MarketSystem::print()	//��º�
{
	int sellect_menu1;
	int sellect_menu2;
	string user_ID;
	string user_password;
	while(true)
	{
		cout<<"			���θ� ���α׷�"<<endl<<endl;
		cout<<"���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�"<<endl;
		cout<<"��   �޴�                                     ��"<<endl;
		cout<<"��                                            ��"<<endl;
		cout<<"��1. �α���                                   ��"<<endl;
		cout<<"��2. �α׾ƿ�                                 ��"<<endl;
		cout<<"��3. ����                                     ��"<<endl;
		cout<<"���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�"<<endl<<endl;

		cout<<"�޴� ���� : ";
		cin >> sellect_menu1;
		if(sellect_menu1==1)
		{
			cout<<"ID �Է� : ";
			cin >> user_ID;
			cout<<"Password �Է� : ";
			cin >> user_password;
			if(login(user_ID, user_password)==true)
			{
				cout<<"�α��� �Ǿ����ϴ�."<<endl<<endl<<endl;
				Sleep(1000);
				system("cls");
				while(true)
				{
					cout<<"���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�"<<endl;
					cout<<"��   �޴�                                     ��"<<endl;
					cout<<"��                                            ��"<<endl;
					cout<<"��1. ��ǰ ����Ʈ                              ��"<<endl;
					cout<<"��2. ��ǰ ����                                ��"<<endl;
					cout<<"��3. ��ǰ ���                                ��"<<endl;
					cout<<"��4. ���� ����                                ��"<<endl;
					cout<<"��                                            ��"<<endl;
					cout<<"��0. ����                                     ��"<<endl;
					cout<<"���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�"<<endl<<endl;

					cout<<"�޴� ���� : ";
					cin >> sellect_menu2;
					Sleep(1000);
					system("cls");
					if((sellect_menu2)==0)
					{
						Sleep(1000);
						system("cls");
						getchar();
						break;
					}
					else if((sellect_menu2)==1)
					{
						cout<<"  <<��ǰ����Ʈ>>"<<endl;
						print_loaded_product();						
						system("cls");
					}

					else if((sellect_menu2)==2)
					{
						string _product;
						cout<<"  <<��ǰ ����>>"<<endl<<endl;
						print_loaded_product();
						cout<<"������ ��ǰ�� �Է��ϼ��� : ";
						cin >> _product;						
						buy_product(_product);
						Sleep(1000);
						system("cls");
					}

					else if((sellect_menu2)==3)
					{
						string _product;
						cout<<"  <<��ǰ ���>>"<<endl<<endl;
						print_bought_product();
						cout<<"����� ��ǰ�� �Է��ϼ��� : ";
						cin >> _product;
						cancel_product(_product);
						Sleep(1000);
						system("cls");
					}

					else if((sellect_menu2)==4)
					{
						cout<<"  <<���� ��ǰ ���>>"<<endl;
						print_bought_product();
						cout<<"--------------------------------------------"<<endl;
						cout<<"�ѱݾ� : "<< ms_current_user->get_total();
						system("pause");
						system("cls");
					}

					else if((sellect_menu2)==0)
					{
						save_file();
						Sleep(1000);
						system("cls");
						break;
					}
					else
					{
						cout<<"�߸��� ���� �Է��ϼ̽��ϴ�."<<endl;
						Sleep(1000);
						system("cls");
					}
				}
			}
			else
			{
				cout<<"ȸ�� ������ ��ġ���� �ʽ��ϴ�."<<endl;
				Sleep(1000);
				system("cls");
			}
		}

		else if(sellect_menu1==2)
		{
			logout();
			Sleep(1000);
			system("cls");
		}
		else if(sellect_menu1==3)
		{
			logout();
			break;
		}

		else
		{
			cout<<"�߸��� �Է��Դϴ�."<<endl;
			Sleep(1000);
			system("cls");
		}
	}
}
void MarketSystem::print_bought_product()	// ��ǰ ���ų��� ���
{
	ms_current_user->print_bought_product();
}	

void MarketSystem::print_loaded_product()	// ��ǰDB���� �ε�� ��ǰ ���� ���
{
	market.print_product();
}


void MarketSystem::buy_product(string _product_name)// ��ǰ ����
{
	Product *Bool_product =	market.buy_product(_product_name);
	if(Bool_product == false)
		cout<<"�Է¹��� ��ǰ�� �������� �ʽ��ϴ�."<<endl;
	else
		ms_current_user->user_buy_product(Bool_product);
}	

void MarketSystem::cancel_product(string _product_name) // ���� ���
{
	Product *Bool_product =	market.buy_product(_product_name);
	if(Bool_product == false)
		cout<<"�Է¹��� ��ǰ�� �������� �ʽ��ϴ�."<<endl;
	else
		ms_current_user->user_cancel_product(Bool_product);
}