#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//		╔══╦══╦═══╦════╦══╦╗─╔╦═══╦══╦╗─╔══╦══╦══╗
//		║╔═╣╔╗║╔═╗╠═╗╔═╩╗╔╣╚═╝║╔══╣╔═╣║─║╔╗║╔═╣╔═╝
//		║╚═╣║║║╚═╝║─║║──║║║╔╗─║║╔═╣║─║║─║╚╝║╚═╣╚═╗
//		╚═╗║║║║╔╗╔╝─║║──║║║║╚╗║║╚╗║║─║║─║╔╗╠═╗╠═╗║
//		╔═╝║╚╝║║║║──║║─╔╝╚╣║─║║╚═╝║╚═╣╚═╣║║╠═╝╠═╝║
//		╚══╩══╩╝╚╝──╚╝─╚══╩╝─╚╩═══╩══╩══╩╝╚╩══╩══╝

class SortClass {
public:
	SortClass(string );//открытие файла
	auto divide()->void; // разделение на блоки
	auto size(string )->size_t;//размер файла
	auto makeBlocks(string )->void;//создание блоков
	auto  sort()->void;//сортировка всех блоков
	auto writeSorted(string )->void;//запись сортированных данных в файл
	auto deleteTmp()->void;//удаление временных файлов
	~SortClass();
private:
	fstream file;
	size_t buffer, count_of_files, closed_files;
	bool out;
	vector<string> lines;
	vector<string> file_names;
};

SortClass::~SortClass() {
	file_names.clear();
}

SortClass::SortClass(string name_main_file) :file(name_main_file), buffer(100), count_of_files(0), closed_files(0) {
	if (file.is_open()) {
		out=true;
		divide();
	}
};

auto SortClass::makeBlocks(string name_file)->void {
	file_names.push_back(name_file);
	std::sort(lines.begin(), lines.end());
	ofstream temp(name_file);
	if (!temp.is_open()) throw;
	for (auto i : lines)
	{
		temp << i;
		if (i != *(--lines.end())) temp << endl;
	}
	temp.close();
	lines.clear();
}

auto SortClass::size(string name_file)->size_t { 
	long fsize;
	ifstream temp(name_file);
	temp.seekg(0, ios::end);
	fsize = temp.tellg();
	temp.close();
	return fsize;
}

auto SortClass::writeSorted(string line)->void {
	ofstream out("out.txt", ios::app);
	if(!out.is_open) throw;
	file << line << endl;
	file.close();
}

auto SortClass::deleteTmp()->void {
	for (int i = 0; i < file_names.size(); ++i) {
		if (remove(file_names[i].c_str()) == -1) {
			throw;
		}
		else {
			cout << "Gj";
		}
	}

}


auto SortClass::sort()->void {
	ifstream *files_streams = new ifstream[count_of_files];
	for (int i = 0; i < count_of_files; ++i) {
		files_streams[i].open(file_names[i]);
	}
	string *top_line = new string[count_of_files];
	for (unsigned int i = 0; i < count_of_files; ++i)
	{
		getline(files_streams[i], top_line[i]);
	}

	while (out == true) {
		string temp_min_line = top_line[0];
		int num_min_line = 0;
		for (int i = 0; i < count_of_files; ++i)
		{
			if (top_line[i] < temp_min_line)
			{
				temp_min_line = top_line[i];
				num_min_line = i;
			}
		}
		writeSorted(temp_min_line);
		if (!files_streams[num_min_line].eof())
		{
			getline(files_streams[num_min_line], top_line[num_min_line]);
		}
		else {
			closed_files++;
			if (closed_files == count_of_files) { out = false; };
		}
	}
	for(int i=0;i<count_of_files;++i) files_streams[i].close();
	deleteTmp();
}


auto SortClass::division()->void {
	string line_of_file;
	size_t temp_size_files = 0;
	while (!file.eof()) {
		getline(file, line_of_file);
		temp_size_files += line_of_file.size();
		if (temp_size_files <= buffer) {
			lines.push_back(line_of_file);
		}
		else {
			count_of_files++;
			make_file(to_string(count_of_files) + ".txt");
			lines.push_back(line_of_file);
			temp_size_files = line_of_file.size();
		}
	}
	file.close();
	if (lines.size()) {
		count_of_files++;
		make_file(to_string(count_of_files) + ".txt");
	}
	sort();
};

/*
int main()
{
	setlocale(LC_ALL, "Russian");
	SortClass obj("names.txt");
	getch();
	return 0;
}
*/