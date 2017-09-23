#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "iProduct.h"
#include "Sale.h"

namespace w7 {
	Sale::Sale(const char* fn) {
		std::ifstream file(fn);
		while (file.good()) {
			iProduct* ip = readProduct(file);
			productList.push_back(ip);
		}
		productList.pop_back();
	}

	void Sale::display(std::ostream& os) {
		float sum = 0;
		os << "Product No      Cost Taxable\n";
		os << std::fixed << std::setprecision(2);

		for (auto p : productList) {
			os << *p;
			sum += p->getCharge();
		}
		os << "  Total" << std::setw(10) << std::right << sum << '\n';
	}
}