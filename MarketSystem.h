#pragma once
#include "Market.h"

class MarketSystem
{
private :
	User* ms_current_user;	//현재 로그인한 사용자
	Market market;	//Market class
	char user_filename[1024];	// user.txt
	char product_filename[1024];	// product.txt
	
public :
	MarketSystem();
	MarketSystem(char* user_filename, char* product_filename);
	~MarketSystem();
	void load_File();	//파일 로드
	void save_file();	//파일 저장

	bool login(string _user_id, string _pass_word);// 로그인 
	void logout();	//로그아웃 관리 함수 
	void print();	//출력부
	void print_bought_product();	// 상품 구매내역 출력
	void print_loaded_product();	// 상품DB에서 로드된 상품 정보

	void buy_product(string _product_name);// 상품 구매
	void cancel_product(string _product_name); // 구매 취소
};