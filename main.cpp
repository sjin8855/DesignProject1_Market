#include "MarketSystem.h"
using namespace std;

int main()
{
	MarketSystem marketsystem("user.txt", "product.txt");
	marketsystem.load_File();
	marketsystem.print();
	return 0;
}