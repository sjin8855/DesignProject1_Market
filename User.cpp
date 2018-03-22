#include "User.h"

User::User()//�⺻������
{
	m_apple = 0;
	m_banana = 0;
	m_orange = 0;
	m_phone = 0;
	m_bag = 0;
	m_umbrella = 0;
	m_computer = 0;
	m_netbook = 0;
	m_note = 0;
	m_car = 0;
	total_price = 0;
	user_bought_count = 0;
	//loaded_bought_count = 0;
}

User::User(string _user_id, string _password,string _user_name,int apple,int banana,int orange, int phone, int bag, int umbrella, int computer, int netbook, int note, int car, int total)//������
{
	m_user_id = _user_id;
	m_password = _password;
	m_user_name = _user_name;
	m_apple = apple;
	m_banana = banana;
	m_orange = orange;
	m_phone = phone;
	m_bag = bag;
	m_umbrella = umbrella;
	m_computer = computer;
	m_netbook = netbook;
	m_note = note;
	m_car = car;
	total_price = total;
}

User::~User()//�Ҹ���
{
	//for(int i=0; i<loaded_bought_count; i++)
	//	delete user_bought_products[i];
}

void User::user_update_buyInfo(Product* _product) // ������ ���ǰ��� ������ �ѱݾ� ����
{
	string product_name = _product->get_product_name();

	if(product_name.compare("apple") == 0)
		m_apple++;

	else if(product_name.compare("banana") == 0)
		m_banana++;
	
	else if(product_name.compare("orange") == 0) 
		m_orange++;
	
	else if(product_name.compare("phone") == 0) 
		m_phone++;

	else if(product_name.compare("bag") == 0) 
		m_bag++;

	else if(product_name.compare("umbrella") == 0)
		m_umbrella++;

	else if(product_name.compare("computer") == 0)
		m_computer++;

	else if(product_name.compare("netbook") == 0)
		m_netbook++;

	else if(product_name.compare("note") == 0)
		m_note++;

	else if(product_name.compare("car") == 0)
		m_car++;

	user_bought_count++;
	total_price+=_product->get_product_price();
}
void User::user_cancel_buyInfo(Product* _product) // ��������� ���ǰ��� ���ҿ� �ѱݾ׿��� ����
{
	string product_name = _product->get_product_name();

	if(product_name.compare("apple") == 0)
		m_apple--;

	else if(product_name.compare("banana") == 0)
		m_banana--;
	
	else if(product_name.compare("orange") == 0) 
		m_orange--;
	
	else if(product_name.compare("phone") == 0) 
		m_phone--;

	else if(product_name.compare("bag") == 0) 
		m_bag--;

	else if(product_name.compare("umbrella") == 0)
		m_umbrella--;

	else if(product_name.compare("computer") == 0)
		m_computer--;

	else if(product_name.compare("netbook") == 0)
		m_netbook--;

	else if(product_name.compare("note") == 0)
		m_note--;

	else if(product_name.compare("car") == 0)
		m_car--;

	user_bought_count--;
	total_price-=_product->get_product_price();
}


string User::get_userID() // ����� ID ����
{
	return m_user_id;
}

string User::get_password()	// ����� ��й�ȣ ����
{
	return m_password;
}

string User::get_userName()	// ����� �̸� ����
{
	return m_user_name;
}

int User::get_user_sell_count()//�� ���� ����
{
	return user_bought_count;
}


void User::set_userID(string _user_id)//����� ID �Է�
{
	m_user_id = _user_id;
}

void User::set_password(string _password)//����� Password �Է�
{
	m_password = _password;
}

void User::set_userName(string _user_name)//����� �̸� �Է�
{
	m_user_name = _user_name;
}

void User::user_buy_product(Product* _product)//��ǰ ����
{
	user_bought_products[user_bought_count] = _product;
	user_update_buyInfo(_product);
}

void User::user_cancel_product(Product* _product)//��ǰ ���
{
	for(int i=0; i<user_bought_count; i++)
		if((user_bought_products[i]->get_product_name()).compare(_product->get_product_name()) == 0) 
		{
			for(int j=i; j<user_bought_count-1; j++)
				user_bought_products[j] = user_bought_products[j+1];
			user_bought_products[user_bought_count-1] = NULL;
			break;
		}
	
	user_cancel_buyInfo(_product);
}

void User::print_bought_product() //������ ��ǰ ���
{
	for(int i=0; i<user_bought_count; i++)
		user_bought_products[i]->print();
}

int User::get_apple()	// apple�� ���������� ���� ����
{
	return m_apple;
}

int User::get_banana()	// banana�� ���������� ���� ����
{
	return m_banana;
}

int User::get_orange()	// orange�� ���������� ���� ����
{
	return m_orange;
}

int User::get_phone()	// phone�� ���������� ���� ����
{
	return m_phone;
}

int User::get_bag()		// bag�� ���������� ���� ����
{
	return m_bag;
}

int User::get_umbrella()// umbrella�� ���������� ���� ����
{
	return m_umbrella;	
}

int User::get_computer()// computer�� ���������� ���� ����
{
	return m_computer;
}

int User::get_netbook()	// netbook�� ���������� ���� ����
{
	return m_netbook;
}

int User::get_note()	// note�� ���������� ���� ����
{
	return m_note;
}

int User::get_car()		// car�� ���������� ���� ����
{
	return m_car;
}

int User::get_total()	// �ѱݾ� ����
{
	return total_price;
}

void User::set_apple(int _apple) // apple ���� �Է�
{
	m_apple = _apple;
}

void User::set_banana(int _banana)	// banana ���� �Է�
{
	m_banana = _banana;
}

void User::set_orange(int _orange)	// orange ���� �Է�
{
	m_orange = _orange;
}

void User::set_phone(int _phone)	// phone ���� �Է�
{
	m_phone = _phone;
}

void User::set_bag(int _bag)		// bag ���� �Է�
{
	m_bag = _bag;
}

void User::set_umbrella(int _umbrella)// umbrella ���� �Է�
{
	m_umbrella = _umbrella;
}

void User::set_computer(int _computer)// computer ���� �Է�
{
	m_computer = _computer;
}

void User::set_netbook(int _netbook)// netbook ���� �Է�
{
	m_netbook = _netbook;
}

void User::set_note(int _note)		// note ���� �Է�
{
	m_note = _note;
}

void User::set_car(int _car)		// car ���� �Է�
{
	m_car = _car;	
}

void User::set_total_price(int _total_price)	// �ѱݾ� �Է�
{
	total_price = _total_price;
}

void User::print()	//���
{
	cout<<" " <<endl;
}

//void User::set_loaded_bought_count() 
//{
//	loaded_bought_count = user_bought_count;
//}
//
//void User::get_loaded_product() 
//{
//	for(int i=0; i<m_apple; i++) 
//	{
//		user_bought_products[user_bought_count] = new Product("apple", 1000); //���� �Ҵ�
//		user_bought_products[user_bought_count]->set_is_selled(false);
//		user_bought_count++;
//	}
//
//	for(int i=0; i<m_banana; i++) 
//	{
//		user_bought_products[user_bought_count] = new Product("banana", 2000);
//		user_bought_products[user_bought_count]->set_is_selled(false);
//		user_bought_count++;
//	}
//
//	for(int i=0; i<m_orange; i++) 
//	{
//		user_bought_products[user_bought_count] = new Product("orange", 1500);
//		user_bought_products[user_bought_count]->set_is_selled(false);
//		user_bought_count++;
//	}
//	for(int i=0; i<m_phone; i++) 
//	{
//		user_bought_products[user_bought_count] = new Product("phone", 500000);
//		user_bought_products[user_bought_count]->set_is_selled(false);
//		user_bought_count++;
//	}
//
//	for(int i=0; i<m_bag; i++) 
//	{
//		user_bought_products[user_bought_count] = new Product("bag", 30000);
//		user_bought_products[user_bought_count]->set_is_selled(false);
//		user_bought_count++;
//	}
//
//	for(int i=0; i<m_umbrella; i++) 
//	{
//		user_bought_products[user_bought_count] = new Product("umbrella", 5000);
//		user_bought_products[user_bought_count]->set_is_selled(false);
//		user_bought_count++;
//	}
//	for(int i=0; i<m_computer; i++) 
//	{
//		user_bought_products[user_bought_count] = new Product("computer", 1000000);
//		user_bought_products[user_bought_count]->set_is_selled(false);
//		user_bought_count++;
//	}
//	for(int i=0; i<m_netbook; i++)
//	{
//		user_bought_products[user_bought_count] = new Product("netbook", 800000);
//		user_bought_products[user_bought_count]->set_is_selled(false);
//		user_bought_count++;
//	}
//	
//	for(int i=0; i<m_note; i++) 
//	{
//		user_bought_products[user_bought_count] = new Product("note", 3000);
//		user_bought_products[user_bought_count]->set_is_selled(false);
//		user_bought_count++;
//	}
//	
//	for(int i=0; i<m_car; i++) 
//	{
//		user_bought_products[user_bought_count] = new Product("car", 15000000);
//		user_bought_products[user_bought_count]->set_is_selled(false);
//		user_bought_count++;
//	}
//}