#include "Product.h"
#include <iomanip>
Product::Product()//�⺻������
{

}

Product::Product(string _product_name, int _product_price)//������
{
	m_product_name = _product_name;
	m_product_price = _product_price;
}

Product::~Product()//�Ҹ���
{

}

string Product::get_product_name()//��ǰ �̸� ����
{
	return m_product_name;
}

int Product::get_product_price()//��ǰ ���� ����
{
	return m_product_price;
}

bool Product::get_is_selled()//��ǰ �Ǹſ��� ����
{
	return is_selled;
}

void Product::set_product_name(string _product_name)//��ǰ �̸� �Է�
{
	m_product_name = _product_name;
}

void Product::set_product_price(int _product_price)	//��ǰ ���� �Է�
{
	m_product_price = _product_price;
}

void Product::set_is_selled(bool _is_selled)
{
	is_selled = _is_selled;
}

void Product::print()//���
{
	if(is_selled == true)
		cout<<setw(15)<<m_product_name<<setw(15)<<m_product_price;		
}