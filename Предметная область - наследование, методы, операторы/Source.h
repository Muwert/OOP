#include <iostream> 
#include <ctime>

class ñharackteristic
{
public:
	std::string name;
	std::string ras;
	std::string rassa(ñharackteristic pers) {
		if ((rost > 50) && (rost <= 140)) return ras = "Lyn";
		else if ((rost > 140) && (rost <= 170)) return ras = "Yun";
		else if ((rost > 170) && (rost <= 190)) return ras = "Jin";
		else if (rost > 190) return ras = "Gon";
	}
	int rost;
	std::string klass;
	int difficulty(ñharackteristic pers) {
		if (pers.ras == "Lyn") return dif = 4;
		else if (pers.ras == "Yun") return dif = 5;
		else if (pers.ras == "Jin") return dif = 5;
		else if (pers.ras == "Gon") return dif = 3;
	}
	virtual void print() { std::cout << "klass: " << klass << std::endl; }
private:
	int dif;
};


class protagonist: public ñharackteristic
{
public:
	std::string weapon;
	bool operator==(protagonist& obj)
	{
		return obj.weapon == weapon;
	}
	virtual void protection() {
		int pr;
		pr = rand() % 101;
		std::cout << "protection: " << pr << std::endl;
	}
	int at;
	int attack() {
		return at = rand() % 101;
	}
	int regeneration() {
		return reg = rand() % 101;
	}
private:
	int reg;
};

class antagonist : public ñharackteristic
{
public:
	std::string animal; 
	virtual void skils() {
		int sk;
		sk = rand() % 101;
		std::cout << "skils: " << sk << std::endl;
	}
	virtual void posledovateli() {
		k = rand() % 101;
		std::cout << "posledovateli: " << k << std::endl;
	}
private:
	int k;
};
