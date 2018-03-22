#pragma once
#include <iostream>
#include <string>
using namespace std;

class Product
{
private :
	string m_product_name;	//��ǰ �̸�
	int m_product_price;	//��ǰ ����
	bool is_selled; //�Ǹ� ���� ����

public :
	Product();
	Product(string _product_name, int _product_price);
	~Product();

	string get_product_name();		//��ǰ �̸� ����
	int get_product_price();	//��ǰ ���� ����
	bool get_is_selled();	// �Ǹ� ���� ����

	void set_product_name(string _product_name);//��ǰ �̸� �Է�
	void set_product_price(int _product_price);	//��ǰ ���� �Է�
	void set_is_selled(bool _is_selled);

	void print();	//��º�
};
