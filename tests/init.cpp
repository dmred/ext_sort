#include "ext_sort.cpp"
#include <catch.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <locale> 
using namespace std;
 
SCENARIO("8mb", "[8mb]"){
 setlocale(LC_ALL, "Russian");
 std::chrono::time_point<std::chrono::system_clock> start, end;
start = std::chrono::system_clock::now();
 sorting("8.txt","8out_name.txt",1);
 end = std::chrono::system_clock::now();
int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
(end - start).count();
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "finished computation at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds << "s\n";
 ifstream file("test8_name.txt");
ifstream hay("test8_name.txt");
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


SCENARIO("15mb", "[15mb]"){
 setlocale(LC_ALL, "Russian");
  std::chrono::time_point<std::chrono::system_clock> start, end;
start = std::chrono::system_clock::now();
 sorting("15.txt","15out_name.txt",4);
 end = std::chrono::system_clock::now();
int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
(end - start).count();
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "finished computation at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds << "s\n";
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
  std::chrono::time_point<std::chrono::system_clock> start, end;
start = std::chrono::system_clock::now();
 sorting("32.txt","32out_name.txt",17);
 end = std::chrono::system_clock::now();
int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
(end - start).count();
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "finished computation at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds << "s\n";
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

