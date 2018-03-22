#pragma once
#include "Market.h"

class MarketSystem
{
private :
	User* ms_current_user;	//���� �α����� �����
	Market market;	//Market class
	char user_filename[1024];	// user.txt
	char product_filename[1024];	// product.txt
	
public :
	MarketSystem();
	MarketSystem(char* user_filename, char* product_filename);
	~MarketSystem();
	void load_File();	//���� �ε�
	void save_file();	//���� ����

	bool login(string _user_id, string _pass_word);// �α��� 
	void logout();	//�α׾ƿ� ���� �Լ� 
	void print();	//��º�
	void print_bought_product();	// ��ǰ ���ų��� ���
	void print_loaded_product();	// ��ǰDB���� �ε�� ��ǰ ����

	void buy_product(string _product_name);// ��ǰ ����
	void cancel_product(string _product_name); // ���� ���
};