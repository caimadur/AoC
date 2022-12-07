// https://adventofcode.com/2022/day/7

#include <iostream>
#include <vector>
#include <string>
#include <sstream>


class File {
    std::string filename;
    int size;

    public:
    File(std::string n, int s): filename(n), size(s) {}
    int get_size() { return size; }
    std::string name() { return filename; }
};

class Directory {
    std::vector<Directory*> subdirs;
    std::vector<File> files;
    std::string dirname;
    Directory *parent;
    int size;

    public:
    Directory(std::string n, Directory *p): dirname(n), parent(p) {}
    ~Directory() { for(auto i : subdirs) delete i; }
    void add_subdir(std::string dname) { subdirs.emplace_back(new Directory(dname, this)); }
    void add_file(std::string fname, int fsize) { files.emplace_back(fname, fsize); }
    void calculate_size();
    Directory* get_subdir(std::string dname);
    int get_size() { return size; }
    int get_answer(int max_size);
    int smallest_sufficient(int min_size);
};

constexpr int capacity = 70000000;


int main()
{
    constexpr int max = 100000, needed = 30000000;

    Directory *current = nullptr, *root = nullptr;
    std::string line;

    while (getline(std::cin, line)) {
    	if (line.at(0) == '$') {
	    if (line.substr(2, 2) == "cd") {
	    	if (current)
	    	    current = current->get_subdir(line.substr(5));
		else {
		    root = new Directory(line.substr(5), current);
		    current = root;
		}
	    }
	} else if (line.substr(0, 3) == "dir")
	    current->add_subdir(line.substr(4));
	else {    // must be a file
	    std::istringstream lsout(line);
	    int size;
	    std::string name;
	    lsout >> size >> name;
	    current->add_file(name, size);
	}
    }
    root->calculate_size();
    std::cout << "Sum of small durs: " << root->get_answer(max) << std::endl;
    int to_free = root->get_size() + needed - capacity;
    std::cout << "Size of smallest big enough: " << root->smallest_sufficient(to_free) << std::endl;
    delete root;
}


Directory* Directory::get_subdir(std::string dname)
{
    if (dname == "..")
    	return parent;
    for (auto i : subdirs)
    	if (i->dirname == dname)
    	    return i;
    return nullptr;
}

void Directory::calculate_size()
{
    size = 0;
    for (auto&& i : subdirs)
    	i->calculate_size();
    for (auto&& i : subdirs)
    	size += i->get_size();
    for (auto&& i : files)
    	size += i.get_size();
}

int Directory::get_answer(int max_size)
{
    int answer = size <= max_size ? size : 0;
    for (auto&& i : subdirs)
    	answer += i->get_answer(max_size);
    return answer;
}

int Directory::smallest_sufficient(int min_size)
{
    int sssize = capacity;
    if (size < min_size)
    	return sssize;
    for (auto i : subdirs) {
    	int subsize = i->smallest_sufficient(min_size);
    	if (subsize < sssize)
    	    sssize = subsize;
    }
    return size < sssize ? size : sssize;
}
