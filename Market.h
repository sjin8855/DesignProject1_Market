#pragma once
#include "User.h"
#include <fstream>

class Market
{	
private :
	User m_user_infos[50];			// �ε�� ����� ���� ����
	Product m_product_infos[100];	// �ε�� ��ǰ ���� ����
	int product_count;	// �ε�� ��ǰ ����
	int user_count;		// �ε�� ����� ��

public :
	Market();
	~Market();
	User* login(string _user_id, string _pass_word);	//�α��� ���� �Լ� 
	void sort_product(Product sort_array[]);	//�ε�� ��ǰ ����
	int search_product(string product_name);	// ��ǰ ��� ���� Ž��

	void load_file(char* product_filename, char* user_filename);	//user.txt, product.txt �ҷ����� �Լ� ��
	void add_product_array(Product _product_infos);	//�ε�� ��ǰDB ��ü�迭�� ����
	void add_user_array(User _user_infos);	//�ε�� �����DB ��ü�迭�� ����
	void save_file(char* outfile);	//���� ����
	
	User get_user_infos(string _id);	// ����� ���� ����
	Product get_product_Infos(string product_name);	// ��ǰ ���� ����
	Product* buy_product(string product_name);	// ��ǰ ����
	Product* cancel_product(string product_name);	// ���� ���

	void print_product();	//�ε�� ��ǰ��� ���
};
