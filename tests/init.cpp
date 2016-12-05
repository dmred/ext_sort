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
 line s1, s2;
 bool x = true;
 int i=0;
  while(!f2.eof() && !f1.eof())
  {
   i++;
    if((f1>>s1)&&(f2>>s2))
    {
      if(s1.name!=s2.name)
      {
        x=false;
        cout<<i<<endl;
        cout<<s1<<endl;
        cout<<s2<<endl;
        break;
      }
    }
    else break;
  }
  f1.close();
  f2.close();
  REQUIRE(x);
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

