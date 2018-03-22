#pragma once
#include"Product.h"

class User
{
private:

	void user_update_buyInfo(Product* _product); // ������ ���ǰ��� ������ �ѱݾ� ����
	void user_cancel_buyInfo(Product* _product); // ��������� ���ǰ��� ���ҿ� �ѱݾ׿��� ����

	string m_user_id;	// ����� ���̵�
	string m_password;	// ����� ��й�ȣ
	string m_user_name;	// ����� �̸�
	int m_apple;	// apple ����
	int m_banana;	// banana ����
	int m_orange;	// orange ����
	int m_phone;	// phone ����
	int m_bag;		// bag ����
	int m_umbrella;	// umbrella ����
	int m_computer;	// computer ����
	int m_netbook;	// netbook ����;
	int m_note;		// note ����
	int m_car;			// car ����
	int total_price;	// �� �ݾ�
	int user_bought_count; // ������ ��ǰ ����
	//int loaded_bought_count;	//�����Ҵ� ����
	Product* user_bought_products[1000]; // ������ ��ǰ ��ü��

public :
	User();
	User (string _user_id, string _password,string _user_name,int apple,int banana,int orange, int phone, int bag, int umbrella, int computer, int netbook, int note, int car, int total);
	~User();

	string get_userID(); // ����� ID ����
	string get_password();	// ����� ��й�ȣ ����
	string get_userName();	// ����� �̸� ����
	int get_user_sell_count();	//�� ���� ����

	void set_userID(string _user_id);	// // ����� ID �Է�
	void set_password(string _password);	// ����� ��й�ȣ �Է�
	void set_userName(string _user_name);	// ����� �̸� �Է�

	void user_buy_product(Product* _product);// ��ǰ ����
	void user_cancel_product(Product* _product);// ��ǰ ���
	
	void print_bought_product(); //������ ��ǰ ���
	

	int get_apple();	// apple�� ���������� ���� ����
	int get_banana();	// banana�� ���������� ���� ����
	int get_orange();	// orange�� ���������� ���� ����
	int get_phone();	// phone�� ���������� ���� ����
	int get_bag();		// bag�� ���������� ���� ����
	int get_umbrella();	// umbrella�� ���������� ���� ����
	int get_computer();	// computer�� ���������� ���� ����
	int get_netbook();	// netbook�� ���������� ���� ����
	int get_note();		// note�� ���������� ���� ����
	int get_car();		// car�� ���������� ���� ����

	int get_total();	// �ѱݾ� ����
	void set_apple(int _apple);		// apple ���� �Է�
	void set_banana(int _banana);	// banana ���� �Է�
	void set_orange(int _orange);	// orange ���� �Է�
	void set_phone(int _phone);		// phone ���� �Է�
	void set_bag(int _bag);			// bag ���� �Է�
	void set_umbrella(int _umbrella);// umbrella ���� �Է�
	void set_computer(int _computer);// computer ���� �Է�
	void set_netbook(int _netbook);	// netbook ���� �Է�
	void set_note(int _note);		// note ���� �Է�
	void set_car(int _car);			// car ���� �Է�
	void set_total_price(int _total_price);	// �ѱݾ� �Է�
	void print();	//���		
	//void set_loaded_bought_count(); //loaded_bought_count�� �ʱ�ȭ
	//void get_loaded_product();
};