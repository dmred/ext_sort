// extended_sort.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <chrono>

struct inp
{
	std::string st;
	std::ifstream *file;
	inp(const std::string& st_, std::ifstream* file_) : st(st_), file(file_) {}
	bool operator < (const inp& input) const
	{
		return (st > input.st);
	}
};

auto sorting(const std::string input_adress, const std::string output_adress, const unsigned int memory)
{
	std::ifstream fin("C:/Users/Dell/Documents/Visual Studio 2015/Projects/extended_sort/input700000k.txt");
	//std::ifstream fin(input_adress);
	if (fin.is_open() == false) throw ("Cant open ur file");
	std::ofstream fout("C:/Users/Dell/Documents/Visual Studio 2015/Projects/extended_sort/output700000k.txt");
	//std::ofstream fout(output_adress);
	size_t num_buff = 0;
	while (fin.eof() == false)
	{
		std::string s;
		std::ofstream buff(std::to_string(num_buff+1) + ".txt");
		//std::vector<std::string> vector_;
		std::deque<std::string> deque_;
		for (unsigned int size = 0; (size + sizeof(std::string)) <= memory; size += sizeof(std::string))
		{
			std::getline(fin, s);
			//vector_.push_back(s);
			deque_.push_back(s);
		}
		//std::sort(vector_.begin(), vector_.end());
		std::sort(deque_.begin(), deque_.end());
		for (auto i : deque_)
		{
			if (i != "") buff << i << std::endl;
		}
		num_buff++;
		buff.close();
	}
	fin.close();
	std::priority_queue<inp> PriQue;
	for (size_t i = 0; i < num_buff; ++i)
	{
		std::ifstream* f_ = new std::ifstream(std::to_string(i + 1) + ".txt");
		std::string str;
		std::getline(*f_, str);
		inp inp_(str, f_);
		PriQue.push(inp_);
	}
	while (PriQue.empty() == false)
	{
		inp inp_ = PriQue.top();
		PriQue.pop();
		if (inp_.st != "")
		{
			fout << inp_.st;
			fout << std::endl;
		}
		if (!(*inp_.file).eof())
		{
			getline(*inp_.file, inp_.st);
			PriQue.push(inp_);
		}
		else
		{
			(*(inp_.file)).close();
		}
	}
	for (size_t i = 0; i < num_buff; ++i)
	{
		remove((std::to_string(i + 1) + ".txt").data());
	}
	fout.close();
}

// void main(){
// 	std::string in, out;
// 	unsigned long int memory_size;
// 	std::cout << "input path: "; std::cin >> in;
// 	std::cout << "output path: "; std::cin >> out;
// 	std::cout << "write memory(mb): "; std::cin >> memory_size;
// 	memory_size *= 1024;
// 	std::chrono::time_point<std::chrono::system_clock> start, end;
// 	start = std::chrono::system_clock::now();
// 	sorting(in, out, memory_size);
// 	end = std::chrono::system_clock::now();
// 	std::cout << (end - start).count()<< std::endl; 
// 	system("pause");
// }
