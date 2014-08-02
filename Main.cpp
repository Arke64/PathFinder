#include <Utilities/Common.h>

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class grid {
	word width;
	word height;
	word start_x;
	word start_y;
	word end_x;
	word end_y;

	vector<vector<word>> cells;

	public:
		void parse_file(string path);

		void print_input(ostream& stream);
		void print_output(ostream& stream);
};

void grid::parse_file(string path) {
	ifstream file(path);

	file >> this->width >> this->height;
	file >> this->start_x >> this->start_y;
	file >> this->end_x >> this->end_y;

	this->cells.resize(this->width);

	for (word x = 0; x < this->width; x++)
		this->cells[x].resize(this->height);

	for (word y = 0; y < this->height; y++)
		for (word x = 0; x < this->width; x++)
			file >> this->cells[x][y];
}

void grid::print_input(ostream& stream) {
	for (word y = 0; y < this->height; y++) {
		for (word x = 0; x < this->width; x++)
			stream << this->cells[x][y] << " ";

		stream << endl;
	}
}

void grid::print_input(ostream& stream) {

}

int main() {
	string path;

	cout << "Filename: ";
	cin >> path;

	grid g;
	g.parse_file(path);

	g.print_input(cout);
	g.print_output(cout);

	return 0;
}
