#include <iostream> 
#include <ctime>

class Power
{
public:
	std::string weapon;
	bool operator==(Power& obj)
	{
		return obj.weapon == weapon;
	}
	int pr;
	int protection() {
		return pr = rand() % 101;
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

class person : public Power
{
public:
	std::string name;
	std::string gender;
	std::string ras;
	std::string rassa(person pers) {
		if ((rost > 50) && (rost <= 140)) return ras = "Lyn";
		else if ((rost > 140) && (rost <= 170)) return ras = "Yun";
		else if ((rost > 170) && (rost <= 190)) return ras = "Jin";
		else if (rost > 190) return ras = "Gon";
	}
	int rost;
	std::string klass;
	int difficulty(person pers) {
		if (pers.ras == "Lyn") return dif = 4;
		else if (pers.ras == "Yun") return dif = 5;
		else if (pers.ras == "Jin") return dif = 5;
		else if (pers.ras == "Gon") return dif = 3;
	}
private:
	int dif;
};