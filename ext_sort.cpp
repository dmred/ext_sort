#include <iostream> 
#include <fstream> 
#include <string> 
#include <algorithm>
#include <vector> 
#include <locale> 
#include <queue> 
#include <iterator> 
#include <stdlib.h>

using namespace std;

struct STR {
public:
	int index;
	string str;
	STR(string s, size_t i) : str(s), index(i) {}
	bool operator < (const STR& s) const
	{
		return (str > s.str);
	}
};

//		╔══╦══╦═══╦════╦══╦╗─╔╦═══╦══╦╗─╔══╦══╦══╗
//		║╔═╣╔╗║╔═╗╠═╗╔═╩╗╔╣╚═╝║╔══╣╔═╣║─║╔╗║╔═╣╔═╝
//		║╚═╣║║║╚═╝║─║║──║║║╔╗─║║╔═╣║─║║─║╚╝║╚═╣╚═╗
//		╚═╗║║║║╔╗╔╝─║║──║║║║╚╗║║╚╗║║─║║─║╔╗╠═╗╠═╗║
//		╔═╝║╚╝║║║║──║║─╔╝╚╣║─║║╚═╝║╚═╣╚═╣║║╠═╝╠═╝║
//		╚══╩══╩╝╚╝──╚╝─╚══╩╝─╚╩═══╩══╩══╩╝╚╩══╩══╝
class ClassSort {
public:
	ClassSort(string name_main_file, size_t tmp_size);//открытие файла
	auto divide()->void; // разделение на блоки
	auto fileSize(string )->size_t;//размер файла
	auto makeTmp(string )->void;//создание блоков
	auto toSort()->void;//сортировка всех блоков
	auto writeSorted(string )->void;//запись сортированных данных в файл
	auto deleteTmps()->void;//удаление временных файлов
	auto fio() -> const bool; //открытый
	~ClassSort();//destr
private:
	fstream file;
	size_t tmp;
	size_t countTmps;
	size_t closedFiles;
	vector<string> lines;
	vector<string> file_names;
	priority_queue<A> pq;
};

ClassSort::~ClassSort() {
	file_names.clear();
}

auto ClassSort::ClassSort(string name_main_file, size_t tmp_size) :file(name_main_file), tmp(tmp_size), countTmps(0), closedFiles(0) {
	if (file.is_open()) {
		divide();
	}
};

auto ClassSort::fio() -> const bool{return (file.is_open());}

auto ClassSort::makeTmp(string name_file)->void {
	file_names.push_back(name_file);
	std::sort(lines.begin(), lines.end());
	ofstream temp(name_file);
	for (auto i : lines)
	{
		temp << i;
		if (i != *(--lines.end())) temp << endl;
	}
	temp.close();
	lines.clear();
}

auto ClassSort::fileSize(string name_file)->size_t {
	long fsize;
	ifstream temp(name_file);
	temp.seekg(0, ios::end);
	fsize = temp.tellg();
	temp.close();
	return fsize;

}

auto ClassSort::writeSorted(string line)->void {
	ofstream file("out.txt", ios::app);
	file << line << endl;
	file.close();

}

auto ClassSort::deleteTmps()->void {
	for (int i = 0; i < file_names.size(); ++i) {
		if (remove(file_names[i].c_str()) == -1) {
			throw;
		}
		else {
			cout << "Gj";
		}
	}

}




auto ClassSort::toSort()->void {
	ofstream file1("out.txt");
	string str;
	ifstream *streams = new ifstream[countTmps];
	for (int i = 0; i < countTmps; ++i) {
		streams[i].open(file_names[i]);
		getline(streams[i], str);
		A ff(str, i);
		pq.push(ff);
	}

	while (!pq.empty()) {
		A ff = pq.top();
		pq.pop();
		if (ff.str != "")file1 << ff.str << endl;

		if (!streams[ff.index].eof())
		{
			getline(streams[ff.index], ff.str);
			pq.push(ff);
		}
	}
	for (int i = 0; i < countTmps; ++i) streams[i].close();
	deleteTmps();
	file1.close();
}

auto ClassSort::divide()->void {
	string line_of_file;
	size_t temp_size_files = 0;
	while (!file.eof()) {
		getline(file, line_of_file);
		temp_size_files += line_of_file.size();


		if (temp_size_files <= tmp) {
			lines.push_back(line_of_file);
		}
		else {
			countTmps++;
			makeTmp(to_string(countTmps) + ".txt");
			lines.push_back(line_of_file);
			temp_size_files = line_of_file.size();
		}
	}
	file.close();

	if (lines.size()) {
		countTmps++;
		makeTmp(to_string(countTmps) + ".txt");
	}
	toSort();
}
