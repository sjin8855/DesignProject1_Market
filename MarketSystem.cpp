#include "MarketSystem.h"
#include <Windows.h>
MarketSystem::MarketSystem()	// 기본생성자
{

}
MarketSystem::MarketSystem(char* user_filename, char* product_filename)	//생성자
{
	strcpy_s(this->user_filename, strlen(user_filename)+1, user_filename);
	strcpy_s(this->product_filename, strlen(product_filename)+1, product_filename);
	/*for(int i=0; i<user_filename[i] != NULL; i++)
	{
		this->user_filename[i] = user_filename[i];
		this->product_filename[i] = product_filename[i];
	}*/
}

MarketSystem::~MarketSystem()	//소멸자
{

}

void MarketSystem::load_File()	//파일 로드
{
	market.load_file(product_filename, user_filename);
}

void MarketSystem::save_file()	//파일 저장
{
	market.save_file("product.txt");
	market.save_file("user.txt");
}

bool MarketSystem::login(string _user_id, string _pass_word)// 로그인 
{
	if(market.login(_user_id, _pass_word)==false)
		return false;
	else
		return true;
}

void MarketSystem::logout()	//로그아웃 관리 함수 
{
	if(login(ms_current_user->get_userID(), ms_current_user->get_password())==true)		// 로그인 해 있을때만 로그아웃.
		save_file();
}	

void MarketSystem::print()	//출력부
{
	int sellect_menu1;
	int sellect_menu2;
	string user_ID;
	string user_password;
	while(true)
	{
		cout<<"			쇼핑몰 프로그램"<<endl<<endl;
		cout<<"┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐"<<endl;
		cout<<"ㅣ   메뉴                                     ㅣ"<<endl;
		cout<<"ㅣ                                            ㅣ"<<endl;
		cout<<"ㅣ1. 로그인                                   ㅣ"<<endl;
		cout<<"ㅣ2. 로그아웃                                 ㅣ"<<endl;
		cout<<"ㅣ3. 종료                                     ㅣ"<<endl;
		cout<<"└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘"<<endl<<endl;

		cout<<"메뉴 선택 : ";
		cin >> sellect_menu1;
		if(sellect_menu1==1)
		{
			cout<<"ID 입력 : ";
			cin >> user_ID;
			cout<<"Password 입력 : ";
			cin >> user_password;
			if(login(user_ID, user_password)==true)
			{
				cout<<"로그인 되었습니다."<<endl<<endl<<endl;
				Sleep(1000);
				system("cls");
				while(true)
				{
					cout<<"┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐"<<endl;
					cout<<"ㅣ   메뉴                                     ㅣ"<<endl;
					cout<<"ㅣ                                            ㅣ"<<endl;
					cout<<"ㅣ1. 상품 리스트                              ㅣ"<<endl;
					cout<<"ㅣ2. 상품 구매                                ㅣ"<<endl;
					cout<<"ㅣ3. 상품 취소                                ㅣ"<<endl;
					cout<<"ㅣ4. 구매 내용                                ㅣ"<<endl;
					cout<<"ㅣ                                            ㅣ"<<endl;
					cout<<"ㅣ0. 종료                                     ㅣ"<<endl;
					cout<<"└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘"<<endl<<endl;

					cout<<"메뉴 선택 : ";
					cin >> sellect_menu2;
					Sleep(1000);
					system("cls");
					if((sellect_menu2)==0)
					{
						Sleep(1000);
						system("cls");
						getchar();
						break;
					}
					else if((sellect_menu2)==1)
					{
						cout<<"  <<상품리스트>>"<<endl;
						print_loaded_product();						
						system("cls");
					}

					else if((sellect_menu2)==2)
					{
						string _product;
						cout<<"  <<상품 구매>>"<<endl<<endl;
						print_loaded_product();
						cout<<"구입할 상품을 입력하세요 : ";
						cin >> _product;						
						buy_product(_product);
						Sleep(1000);
						system("cls");
					}

					else if((sellect_menu2)==3)
					{
						string _product;
						cout<<"  <<상품 취소>>"<<endl<<endl;
						print_bought_product();
						cout<<"취소할 상품을 입력하세요 : ";
						cin >> _product;
						cancel_product(_product);
						Sleep(1000);
						system("cls");
					}

					else if((sellect_menu2)==4)
					{
						cout<<"  <<구매 상품 목록>>"<<endl;
						print_bought_product();
						cout<<"--------------------------------------------"<<endl;
						cout<<"총금액 : "<< ms_current_user->get_total();
						system("pause");
						system("cls");
					}

					else if((sellect_menu2)==0)
					{
						save_file();
						Sleep(1000);
						system("cls");
						break;
					}
					else
					{
						cout<<"잘못된 값을 입력하셨습니다."<<endl;
						Sleep(1000);
						system("cls");
					}
				}
			}
			else
			{
				cout<<"회원 정보가 일치하지 않습니다."<<endl;
				Sleep(1000);
				system("cls");
			}
		}

		else if(sellect_menu1==2)
		{
			logout();
			Sleep(1000);
			system("cls");
		}
		else if(sellect_menu1==3)
		{
			logout();
			break;
		}

		else
		{
			cout<<"잘못된 입력입니다."<<endl;
			Sleep(1000);
			system("cls");
		}
	}
}
void MarketSystem::print_bought_product()	// 상품 구매내역 출력
{
	ms_current_user->print_bought_product();
}	

void MarketSystem::print_loaded_product()	// 상품DB에서 로드된 상품 정보 출력
{
	market.print_product();
}


void MarketSystem::buy_product(string _product_name)// 상품 구매
{
	Product *Bool_product =	market.buy_product(_product_name);
	if(Bool_product == false)
		cout<<"입력받은 상품이 존재하지 않습니다."<<endl;
	else
		ms_current_user->user_buy_product(Bool_product);
}	

void MarketSystem::cancel_product(string _product_name) // 구매 취소
{
	Product *Bool_product =	market.buy_product(_product_name);
	if(Bool_product == false)
		cout<<"입력받은 상품이 존재하지 않습니다."<<endl;
	else
		ms_current_user->user_cancel_product(Bool_product);
}