#pragma once
#include <iostream>
#include <string>
using namespace std;

class Product
{
private :
	string m_product_name;	//상품 이름
	int m_product_price;	//상품 가격
	bool is_selled; //판매 여부 저장

public :
	Product();
	Product(string _product_name, int _product_price);
	~Product();

	string get_product_name();		//상품 이름 리턴
	int get_product_price();	//상품 가격 리턴
	bool get_is_selled();	// 판매 여부 리턴

	void set_product_name(string _product_name);//상품 이름 입력
	void set_product_price(int _product_price);	//상품 가격 입력
	void set_is_selled(bool _is_selled);

	void print();	//출력부
};
