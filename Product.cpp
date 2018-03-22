#include "Product.h"
#include <iomanip>
Product::Product()//기본생성자
{

}

Product::Product(string _product_name, int _product_price)//생성자
{
	m_product_name = _product_name;
	m_product_price = _product_price;
}

Product::~Product()//소멸자
{

}

string Product::get_product_name()//상품 이름 리턴
{
	return m_product_name;
}

int Product::get_product_price()//상품 가격 리턴
{
	return m_product_price;
}

bool Product::get_is_selled()//상품 판매여부 리턴
{
	return is_selled;
}

void Product::set_product_name(string _product_name)//상품 이름 입력
{
	m_product_name = _product_name;
}

void Product::set_product_price(int _product_price)	//상품 가격 입력
{
	m_product_price = _product_price;
}

void Product::set_is_selled(bool _is_selled)
{
	is_selled = _is_selled;
}

void Product::print()//출력
{
	if(is_selled == true)
		cout<<setw(15)<<m_product_name<<setw(15)<<m_product_price;		
}