#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Singleton {
private:
	static Singleton * ins;
	unordered_map<string, int> ms;
	Singleton() {

	}
public:
	void add(string Name, int number) {
		ms[Name] = number;
	}
	void print() {
		for (auto x : ms) cout << x.first << " " << x.second << endl;
	}
	static Singleton& getIns() {
		if (ins == nullptr) ins = new Singleton();
		return *ins;
	}
	static void deleteIns() {
		if (ins != nullptr) delete ins;
		ins = nullptr;
	}
};

Singleton* Singleton::ins = nullptr;


int main(int argc, char* argv[]) {
	while (true) {
		Singleton & cart = Singleton::getIns();
		cout << "Enter:" << endl;
		string In;
		getline(cin, In);
		if (In == "q") {
			break;
		}
		size_t pos = In.find_first_of(" ");
		string name = In.substr(0, pos);
		string Val = In.substr(pos + 1);
		int val = stoi(Val);
		cart.add(name, val);
	}
	Singleton& cart2 = Singleton::getIns();
	cart2.print();
	cart2.deleteIns();
}