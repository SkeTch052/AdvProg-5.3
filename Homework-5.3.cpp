#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include <sstream>

class myClass {
private:
	int sum;
	int count;

public:
	myClass() : sum(0), count(0) {}

	void operator()(int number) {
		if (number % 3 == 0) {
			sum += number;
			count++;
		}
	}

	int get_sum() const {
		return sum;
	}

	int get_count() const {
		return count;
	}
};

int main() {
	std::string user_s;
	std::vector<int> user_v;

	std::cout << "[IN]:";
	std::getline(std::cin, user_s);
	std::stringstream ss(user_s);
	int v;
	while (ss >> v) {
		user_v.push_back(v);
	}

	myClass counter = std::for_each(user_v.begin(), user_v.end(), myClass());

	std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;

	return 0;
}