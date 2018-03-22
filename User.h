#pragma once
#include"Product.h"

class User
{
private:

	void user_update_buyInfo(Product* _product); // 구매한 물건개수 증가와 총금액 누적
	void user_cancel_buyInfo(Product* _product); // 구매취소한 물건개수 감소와 총금액에서 제외

	string m_user_id;	// 사용자 아이디
	string m_password;	// 사용자 비밀번호
	string m_user_name;	// 사용자 이름
	int m_apple;	// apple 개수
	int m_banana;	// banana 개수
	int m_orange;	// orange 개수
	int m_phone;	// phone 개수
	int m_bag;		// bag 개수
	int m_umbrella;	// umbrella 개수
	int m_computer;	// computer 개수
	int m_netbook;	// netbook 개수;
	int m_note;		// note 개수
	int m_car;			// car 개수
	int total_price;	// 총 금액
	int user_bought_count; // 구매한 상품 개수
	//int loaded_bought_count;	//동적할당 삭제
	Product* user_bought_products[1000]; // 구매한 상품 객체들

public :
	User();
	User (string _user_id, string _password,string _user_name,int apple,int banana,int orange, int phone, int bag, int umbrella, int computer, int netbook, int note, int car, int total);
	~User();

	string get_userID(); // 사용자 ID 리턴
	string get_password();	// 사용자 비밀번호 리턴
	string get_userName();	// 사용자 이름 리턴
	int get_user_sell_count();	//총 구매 개수

	void set_userID(string _user_id);	// // 사용자 ID 입력
	void set_password(string _password);	// 사용자 비밀번호 입력
	void set_userName(string _user_name);	// 사용자 이름 입력

	void user_buy_product(Product* _product);// 상품 구매
	void user_cancel_product(Product* _product);// 상품 취소
	
	void print_bought_product(); //구매한 상품 출력
	

	int get_apple();	// apple을 구매했을때 개수 리턴
	int get_banana();	// banana을 구매했을때 개수 리턴
	int get_orange();	// orange을 구매했을때 개수 리턴
	int get_phone();	// phone을 구매했을때 개수 리턴
	int get_bag();		// bag을 구매했을때 개수 리턴
	int get_umbrella();	// umbrella을 구매했을때 개수 리턴
	int get_computer();	// computer을 구매했을때 개수 리턴
	int get_netbook();	// netbook을 구매했을때 개수 리턴
	int get_note();		// note을 구매했을때 개수 리턴
	int get_car();		// car을 구매했을때 개수 리턴

	int get_total();	// 총금액 리턴
	void set_apple(int _apple);		// apple 개수 입력
	void set_banana(int _banana);	// banana 개수 입력
	void set_orange(int _orange);	// orange 개수 입력
	void set_phone(int _phone);		// phone 개수 입력
	void set_bag(int _bag);			// bag 개수 입력
	void set_umbrella(int _umbrella);// umbrella 개수 입력
	void set_computer(int _computer);// computer 개수 입력
	void set_netbook(int _netbook);	// netbook 개수 입력
	void set_note(int _note);		// note 개수 입력
	void set_car(int _car);			// car 개수 입력
	void set_total_price(int _total_price);	// 총금액 입력
	void print();	//출력		
	//void set_loaded_bought_count(); //loaded_bought_count값 초기화
	//void get_loaded_product();
};