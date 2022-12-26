// Предметная область - наследование, методы, операторы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <ctime>
#include "Source.h"


int main() {
	srand(time(NULL));
	std::cout << "------------------------------------------------------" << std::endl;
	protagonist pers;
	pers.name = "Muwert";
	std::cout << "name: " << pers.name << std::endl;
	pers.rost = 196;
	std::cout << "rassa: " << pers.rassa(pers) << std::endl;
	pers.klass = "Assassin";
	pers.print();
	std::cout << "difficulty: " << pers.difficulty(pers) << std::endl;
	pers.weapon = "Knife";
	std::cout << "weapon: " << pers.weapon << std::endl;
	pers.protection();
	std::cout << "attack: " << pers.attack() << std::endl;
	std::cout << "regeneration: " << pers.regeneration() << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
	antagonist pers1;
	pers1.name = "Kurt";
	std::cout << "name: " << pers1.name << std::endl;
	pers1.rost = 157;
	std::cout << "rassa: " << pers1.rassa(pers1) << std::endl;
	pers1.klass = "Destroyer";
	pers1.print();
	std::cout << "difficulty: " << pers1.difficulty(pers1) << std::endl;
	pers1.animal = "Lion";
	std::cout << "animal: " << pers1.animal << std::endl;
	pers1.skils();
	pers1.posledovateli();
	std::cout << "------------------------------------------------------" << std::endl;
	protagonist pers2;
	pers2.name = "Myrt";
	std::cout << "name: " << pers2.name << std::endl;
	pers2.rost = 72;
	std::cout << "rassa: " << pers2.rassa(pers2) << std::endl;
	pers2.klass = "Blade master";
	pers2.print();
	std::cout << "difficulty: " << pers2.difficulty(pers2) << std::endl;
	pers2.weapon = "Knife";
	std::cout << "weapon: " << pers2.weapon << std::endl;
	pers2.protection();
	std::cout << "attack: " << pers2.attack() << std::endl;
	std::cout << "regeneration: " << pers2.regeneration() << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "Weapon" << std::endl;
	if (pers == pers2) {
		std::cout << pers.name << " and " << pers2.name << " have similar weapon" << std::endl;
	}
	else std::cout << pers.name << " and " << pers2.name << " have different weapon" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
