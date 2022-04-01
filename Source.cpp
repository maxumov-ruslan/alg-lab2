#include <fstream>
#include <iostream>
#include <string>
#include <vector>
//#include <format>

using namespace std;

class Point {
public:
	const int x, y;
	const string s;
	Point(int x, int y, string name) : x(x), y(y), s(name)
	{
	}
};

class Algo2 {
	int n ,w;
	vector<Point> ps;
public:
	void Read(string fname) {
		ifstream f;
		//ps.resize(10, Point{ 1,2,"q" });
		//ps.clear();
		f.open(fname);
		if (!f.is_open()) throw "File not opened";
		f >> n >> w;
		int x, y;
		for (int i = 0; i < n; i++) {
			f >> x >> y;
			//ps.push_back(Point(x, y, "--"));
			ps.emplace_back(x, y, "P" + std::to_string(i));
		}
		//ps.resize(n, Point(0,0,""));
		//v.resize(n);
	}

	vector<char> v;
	void Add(int idx) {
		//if????
		if (idx == n) {
			for (char z : v) {
				cout << z;
			}
			cout << endl;
			return;
		}

		if (0) {
			//v.push_back('A');
			v[idx] = 'A';
			Add(idx + 1);
			//v.pop_back();
			v[idx] = '-';
			//v.push_back('B');
			v[idx] = 'B';
			Add(idx + 1);
			v[idx] = '-';
			//v.pop_back();
		} else {

			for (char c = v.empty()?'A':v.back() + 1; c < 'E'; c++) {
				v.push_back(c);
				///v[idx]=...
				
				// if????
				Add(idx + 1);
				v.pop_back();

			}
		}
	}
	void Print() {
		for (Point &p: ps) {
			cout << p.s << ":   " << "x=" << p.x << "  y=" << p.y << endl;
		}
	}

};

int main() {
	Algo2 a;
	a.Read("input.txt");
	a.Print();
	a.Add(0);
	return 0;
}