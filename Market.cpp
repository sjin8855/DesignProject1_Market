#include "Market.h"
#include <iomanip>
#include <Windows.h>
Market::Market()	// 생성자
{
	product_count = 0;
	user_count = 0;
}

Market::~Market()	// 소멸자
{

}

User* Market::login(string _user_id, string _pass_word)	// 로그인 관리 함수
{
	for(int i=0; i<user_count; i++) 
	{
		if((m_user_infos[i].get_userID()).compare(_user_id) == 0 && (m_user_infos[i].get_password()).compare(_pass_word) == 0)
			return &(m_user_infos[i]);
	}
	return false;
}

void Market::sort_product(Product sort_array[])	// 로드된 상품 정렬
{
	Product temp;
	for(int i=0; i<product_count; i++)
	{
		for(int j=i; j<product_count; j++)
		{
			if(sort_array[i].get_product_name() > sort_array[j].get_product_name())
			{
				temp = sort_array[i];
				sort_array[i] = sort_array[j];
				sort_array[j] = temp;
			}
		}
	}
}
			

int Market::search_product(string product_name)	// 상품 목록 이진 탐색
{
	{
		string s_high,s_low,s_middle;
		string s_key;
		int n_high=100, n_low=0, n_middle=(n_high+n_low)/2;
		s_low=m_product_infos[n_low].get_product_name();
		s_high=m_product_infos[n_high-1].get_product_name();
		

		while(n_low<=n_high)
		{
			if(s_key == m_product_infos[n_middle].get_product_name())
				return n_middle;

			else if(s_key > m_product_infos[n_middle].get_product_name())
				n_low=n_middle+1;
			else
				n_high=n_middle-1;
		}
	}
}

void Market::load_file(char* product_filename, char* user_filename)	//user.txt, product.txt 불러오는 함수 ★
{
	fstream inf;
	inf.open(user_filename);
	string id, pw, user_name;
	int apple, banana, orange, phone, bag, umbrella, computer, netbook, note, car, total;
	User user_infos;

	
	while (!inf.eof())
	{	
		inf >> id >> pw >> user_name >> apple >> banana >> orange >> phone >> bag >> umbrella >> computer >> netbook >> note >> car >>total;
		user_infos.set_userID(id);
		user_infos.set_password(pw);
		user_infos.set_userName(user_name);
		user_infos.set_apple(apple);
		user_infos.set_banana(banana);
		user_infos.set_orange(orange);
		user_infos.set_phone(phone);
		user_infos.set_bag(bag);
		user_infos.set_umbrella(umbrella);
		user_infos.set_computer(computer);
		user_infos.set_netbook(netbook);
		user_infos.set_note(note);
		user_infos.set_car(car);
		user_infos.set_total_price(total);
		
		add_user_array(user_infos);
	}
	inf.close();

	inf.open(product_filename);
	string product_name;
	int price;
	bool Is_Selled;
	Product product_infos;

	while (!inf.eof())
	{
		inf >> product_name >> price >> Is_Selled;
		
		product_infos.set_product_name(product_name);
		product_infos.set_product_price(price);
		product_infos.set_is_selled(Is_Selled);

		add_product_array(product_infos);
	}
	inf.close();
}

void Market::add_product_array(Product _product_infos)	//로드된 상품DB 객체배열에 저장
{
	m_product_infos[product_count] = _product_infos;
	product_count++;
}

void Market::add_user_array(User _user_infos)	//로드된 사용자DB 객체배열에 저장
{
	m_user_infos[user_count] = _user_infos;
	user_count++;
}

void Market::save_file(char* outfile)	//파일 저장
{

}

User Market::get_user_infos(string _id)	// 사용자 정보 리턴
{
	for(int i=0; i<user_count; i++)
		if(m_user_infos[i].get_userID() == _id)
			return m_user_infos[i];
}

Product Market::get_product_Infos(string product_name)	// 상품 정보 리턴
{
	for(int i=0; i<product_count; i++)
		if(m_product_infos[i].get_product_name() == product_name)
			return m_product_infos[i];
}

Product* Market::buy_product(string product_name)	// 상품 구매
{
	for(int i=0; i<product_count; i++)
		if(m_product_infos[i].get_product_name().compare(product_name) == 0)
			if(m_product_infos[i].get_is_selled()==true)
			{
				m_product_infos[i].set_is_selled(false);
				return &(m_product_infos[i]);
			}
			return false;
}

Product* Market::cancel_product(string product_name)	// 구매 취소
{
	for(int i=0; i<product_count; i++)
		if(m_product_infos[i].get_product_name().compare(product_name) == 0)
			if(m_product_infos[i].get_is_selled()==false)
			{
				m_product_infos[i].set_is_selled(true);
				return &(m_product_infos[i]);
			}
			return false;
}

void Market::print_product()	//로드된 상품목록 출력
{
	sort_product(m_product_infos);
	for(int i=0; i<product_count; i++)
		if(m_product_infos[i].get_is_selled() == true)
			cout << i+1 << ". " <<  m_product_infos[i].get_product_name() << setw(15) << m_product_infos[i].get_product_price() << endl;
	//system("pause");
}