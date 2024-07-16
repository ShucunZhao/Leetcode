#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <memory>

using namespace std;

class Coffee {
public:
	virtual ~Coffee() {}
	virtual void brew() = 0;
};

class BlackCoffee : public Coffee {
public:
	void brew() override {
		std::cout << "Brewing Black Coffee" << std::endl;
	}
};

class Latte : public Coffee {
public:
	void brew() override {
		std::cout << "Brewing Latte" << std::endl;
	}
};


class Decorator : public Coffee {
protected:
	unique_ptr<Coffee> coffee;
public:
	Decorator(unique_ptr<Coffee> inCoffee) :coffee(move(inCoffee)) {}
	void brew() override {
		if (coffee != nullptr) {
			coffee->brew();
		}
	}
};

class Milk : public Decorator {
public:
	Milk(unique_ptr<Coffee> inCoffee) : Decorator(move(inCoffee)) {};
	void brew() override {
		Decorator::brew();
		std::cout << "Adding Milk" << std::endl;
	}
};

class Sugar : public Decorator {
public:
	Sugar(unique_ptr<Coffee> inCoffee) : Decorator(move(inCoffee)) {};
	void brew() override {
		Decorator::brew();
		std::cout << "Adding Sugar" << std::endl;
	}
};

int main(int argc, char* argv[]) {
	while (true) {
		unique_ptr<Coffee> coffee;
		cout << "Enter coffee type:" << endl;
		string T;
		getline(cin, T);
		if (T == "q") {
			break;
		}
		cout << "Enter adding type:" << endl;
		string A;
		getline(cin, A);
		if (A == "q") {
			break;
		}
		int type = stoi(T);
		int adding = stoi(A);
		if (type == 1) {
			coffee = std::make_unique<BlackCoffee>();
		}
		else if (type == 2) {
			coffee = std::make_unique<Latte>();
		}
		else {
			std::cout << "Invalid coffee type" << std::endl;
			continue;
		}
		if (adding == 1) {
			coffee = make_unique<Milk>(move(coffee));
		}
		else if (adding == 2) {
			coffee = make_unique<Sugar>(move(coffee));
		}
		else {
			std::cout << "Invalid adding type" << std::endl;
			continue;
		}
		coffee->brew();
	}
	return 0;
}