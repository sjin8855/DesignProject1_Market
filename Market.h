#pragma once
#include "User.h"
#include <fstream>

class Market
{	
private :
	User m_user_infos[50];			// 로드된 사용자 정보 저장
	Product m_product_infos[100];	// 로드된 상품 정보 저장
	int product_count;	// 로드된 상품 개수
	int user_count;		// 로드된 사용자 수

public :
	Market();
	~Market();
	User* login(string _user_id, string _pass_word);	//로그인 관리 함수 
	void sort_product(Product sort_array[]);	//로드된 상품 정렬
	int search_product(string product_name);	// 상품 목록 이진 탐색

	void load_file(char* product_filename, char* user_filename);	//user.txt, product.txt 불러오는 함수 ★
	void add_product_array(Product _product_infos);	//로드된 상품DB 객체배열에 저장
	void add_user_array(User _user_infos);	//로드된 사용자DB 객체배열에 저장
	void save_file(char* outfile);	//파일 저장
	
	User get_user_infos(string _id);	// 사용자 정보 리턴
	Product get_product_Infos(string product_name);	// 상품 정보 리턴
	Product* buy_product(string product_name);	// 상품 구매
	Product* cancel_product(string product_name);	// 구매 취소

	void print_product();	//로드된 상품목록 출력
};
