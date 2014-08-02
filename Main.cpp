#include <Utilities/Common.h>

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

struct coord {
	word x;
	word y;
};

class grid {
	word width;
	word height;
	coord start;
	coord end;

	vector<vector<word>> cells;

	vector<coord> get_neighbors(coord c);
	word walk(coord next);

	public:
		grid(istream& stream);

		void print_input(ostream& stream);
		void print_output(ostream& stream);

		word find_path();
};

grid::grid(istream& stream) {
	stream >> this->width >> this->height;
	stream >> this->start.x >> this->start.y;
	stream >> this->end.x >> this->end.y;

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

vector<coord> grid::get_neighbors(coord c) {
	vector<coord> neighbors;

	if (c.x == 0) {
		neighbors.push_back(coord { 1, 0 });
	}
	else if (c.x == this->width - 1) {
		neighbors.push_back(coord { this->width - 2, 0 });
	}
	else {
		neighbors.push_back(coord { c.x - 1, c.y });
		neighbors.push_back(coord { c.x + 1, c.y });
	}

	if (c.y == 0) {
		neighbors.push_back(coord { 0, 1 });
	}
	else if (c.y == this->height - 1) {
		neighbors.push_back(coord { 0, this->height - 2 });
	}
	else {
		neighbors.push_back(coord { c.x, c.y - 1 });
		neighbors.push_back(coord { c.x, c.y + 1 });
	}

	return neighbors;
}

word grid::find_path() {
	return this->walk(this->start);
}

word grid::walk(coord next) {
	if (next.x == this->end.x && next.y == this->end.y)
		return this->cells[next.x][next.y];

	word cost = 0, highest = 0;

	for (auto i : this->get_neighbors(this->start)) {
		cost = this->walk(i);

		if (cost > highest)
			highest = cost;
	}

	return highest;
}

int main() {
	string path;

	cout << "Filename: ";
	cin >> path;

	ifstream file(path);

	grid g(file);

	auto cost = g.find_path();

	cout << "Input: " << endl;
	g.print_input(cout);

	cout << "Output: " << endl;
	cout << "Cost: " << cost << endl;
	g.print_output(cout);

	return 0;
}
