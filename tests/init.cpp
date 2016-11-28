#include <ext_sort.cpp>
#include <catch.hpp>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

SCENARIO("ext1", "[in100]")
{
  	sorting("in100.txt", "out100.txt", 2);
	string *str1 = new string[100], *str2 = new string[100];
	bool flag = false;
	ifstream f1("out100.txt"), f2("test100.txt");
	for (int i = 0; i < 100; ++i)
	{
		getline(f1, str1[i]);
		getline(f2, str2[i]);
	}
	size_t st = 0;
	for (int i = 0; i < 100; ++i)
	{
		if (str1[i] == str2[i]) ++st;
	}
	if (st == 100) flag = true;
  REQUIRE(flag);
} 
/*
SCENARIO("ext2", "[in20k]")
{
  sorting("in100.txt", "output20000k.txt", 16);
	string *str1 = new string[20000], *str2 = new string[20000];
	bool flag = false;
	ifstream f1("output20000k.txt"), f2("test20000k.txt");
	for (int i = 0; i < 4000; ++i)
	{
		getline(f1, str1[i]);
		getline(f2, str2[i]);
	}
	size_t st = 0;
	for (int i = 0; i < 4000; ++i)
	{
		if (str1[i] == str2[i]) ++st;
	}
	if (st == 4000) flag = true;
  REQUIRE(flag);
} 
*/
