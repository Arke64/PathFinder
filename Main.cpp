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
		grid(istream& stream);

		void print_input(ostream& stream);
		void print_output(ostream& stream);
};

grid::grid(istream& stream) {
	stream >> this->width >> this->height;
	stream >> this->start_x >> this->start_y;
	stream >> this->end_x >> this->end_y;

	this->cells.resize(this->width);

	for (word x = 0; x < this->width; x++)
		this->cells[x].resize(this->height);

	for (word y = 0; y < this->height; y++)
		for (word x = 0; x < this->width; x++)
			stream >> this->cells[x][y];
}

void grid::print_input(ostream& stream) {
	for (word y = 0; y < this->height; y++) {
		for (word x = 0; x < this->width; x++)
			stream << this->cells[x][y] << " ";

		stream << endl;
	}
}

void grid::print_output(ostream& stream) {

}

int main() {
	string path;

	cout << "Filename: ";
	cin >> path;

	ifstream file(path);

	grid g(file);

	g.print_input(cout);
	g.print_output(cout);

	return 0;
}
