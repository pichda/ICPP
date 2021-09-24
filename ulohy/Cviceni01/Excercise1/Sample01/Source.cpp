#include <iostream>

struct Triangle {
	int a, b, c;
};

bool canExist(Triangle* t) {
	if (t->a + t->b > t->c && t->a + t->c > t->b && t->c + t->b > t->a) {
		return true;
	}
	else return false;
}

int main(int argc, char** argv)
{
	Triangle* testTriangle = new Triangle{ 3, 3, 3 };
	
	if (canExist(testTriangle)) {
		std::cout << "lze sestrojit";
	}
	else std::cout << "nelze sestrojit";
	
	int countTriangle;
	std::cout << "\nZadej pocet trojuhelniku:";
	std::cin >> countTriangle;
	Triangle* triangles = new Triangle[countTriangle];
	for (int i = 0; i < countTriangle; i++)
	{
		std::cout << "Zadej strany pro trojuhelnik:" << i + 1;
		std::cout << "\nZadej stranu a=";
		std::cin >> triangles[i].a;
		std::cout << "\nZadej stranu b=";
		std::cin >> triangles[i].b;
		std::cout << "\nZadej stranu c=";
		std::cin >> triangles[i].c;
		std::cout << "\n";

	}

	delete testTriangle;
	delete[] triangles;
	return 0;
}
