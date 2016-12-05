#include "ext_sort.cpp"
#include <catch.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <locale> 
using namespace std;
 
SCENARIO("8mb", "[8mb]"){
 setlocale(LC_ALL, "Russian");
 sorting("8.txt","8out_name.txt",1);
 ifstream f1("8out_name.txt");
ifstream f2("test8_name.txt");
int i=0;
 bool p=true;
 line l1,l2;
 string s1,s2;
 while (!hay.eof()&&!file.eof()){
getline(file,l1);
 getline(hay,l2);
  i++;
  if (l1.name!=l2.name){
  p=false;
   cout<<i<<endl;
   cout<<l1.name<<endl;
   cout<<l2.name<<endl;
   break;
  }
 }
  file.close();
 hay.close();
  REQUIRE(p==true);
}


SCENARIO("15mb", "[15mb]"){
 setlocale(LC_ALL, "Russian");
 sorting("15.txt","15out_name.txt",4);
  ifstream hay("test15_name.txt");
ifstream file("test15_name.txt");
int i=0;
 bool p=true;
 string s1,s2;
 while (!hay.eof()&&!file.eof()){
getline(file,s1);
 getline(hay,s2);
  i++;
  if (s1!=s2){
  p=false;
   cout<<i<<endl;
   cout<<s1<<endl;
   cout<<s2<<endl;
   break;
  }
 }
  file.close();
 hay.close();
  REQUIRE(p==true);
}

SCENARIO("32mb", "[32mb]"){
 setlocale(LC_ALL, "Russian");
 sorting("32.txt","32out_name.txt",17);
 ifstream hay("test32_name.txt");
ifstream file("test32_name.txt");
int i=0;
 bool p=true;
 string s1,s2;
 while (!hay.eof()&&!file.eof()){
getline(file,s1);
 getline(hay,s2);
  i++;
  if (s1!=s2){
  p=false;
   cout<<i<<endl;
   cout<<s1<<endl;
   cout<<s2<<endl;
   break;
  }
 }
  file.close();
 hay.close();
  REQUIRE(p==true);
}

