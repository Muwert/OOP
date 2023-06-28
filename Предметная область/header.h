// предметная область Детский лагерь
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

class characteristic
{
public:
	std::string name;
	std::string birthday;
	std::string gender;
	int year;
	int height;
};

// дети
class children : public characteristic
{
public:
	std::string allergies;
	std::string hobbies;
	std::string room;
	std::string SquadName;
	std::string HowRoom(children object) 
	{
		if (gender == "Female")
			return object.room = "Women's room";
		if (gender == "Male")
			return object.room = "Men's room";
	}
	int NumberOfAnimals() {
		return count = rand() % 10;
	}
	int SQuad() {
		return squad = rand() % 10;
	}
private:
	int squad;
	int count;
};

// вожатые
class counselor : public characteristic
{
public:
	int experience;
	bool operator < (const counselor& object) {
		return object.experience > experience;
	}
	bool operator > (const counselor& object) {
		return object.experience < experience;
	}
	bool operator == (const counselor& object) {
		return object.experience == experience;
	}
	int NumberOfChildren() {
		return num = rand() % 10 + 10;
	}
private:
	int num;
	int group;
};


//--------------------------------------------------------------------------------------------------
//Декоратор
//Украсим уголок отряда
//Компонент
class ListPaper 
{
public:
	virtual void draw() = 0;
};

//Конкретный компонент
class ListPaper_with_text: public ListPaper
{
	std::string NameSquad;
public:
	ListPaper_with_text(std:: string k)
	{
		NameSquad = k;
	}
	void draw()
	{
		std::cout << NameSquad << std::endl;
	}
};

//Базовый декоратор
class Decorator : public ListPaper
{
	ListPaper* List;
public:
	Decorator(ListPaper* L) 
	{
		List = L;
	}
	void draw()
	{
		List->draw();
	}
};

// Добавим линии
class LineDecorator : public Decorator
{
public:
	LineDecorator(ListPaper* L): Decorator(L){}
	void draw() 
	{
		Decorator::draw();
		std::cout << "Draw line" << std::endl;
	}
};

// Добавим круги
class СircleDecorator : public Decorator
{
public:
	СircleDecorator(ListPaper* L) : Decorator(L) {}
	void draw()
	{
		Decorator::draw();
		std::cout << "Draw circle" << std::endl;
	}
};

//------------------------------------------------
// Строитель
// Роли детей в спектакле

class tree
{
public:
	void info() {
		std::cout << "I'm tree." << std::endl;
	}
};

class stump
{
public:
	void info() {
		std::cout << "I'm stump." << std::endl;
	}
};

class girl
{
public:
	void info() {
		std::cout << "I'm girl." << std::endl;
	}
};

class bird
{
public:
	void info() {
		std::cout << "I'm bird." << std::endl;
	}
};


// Класс "Сцена", содержащий все типы ролей
class Scene
{
public:
	std::vector <tree> v1;
	std::vector <stump> v2;
	std::vector <girl> v3;
	std::vector <bird> v4;
	void info() {
		int i;
		for (i = 0; i < v1.size(); ++i)  v1[i].info();
		for (i = 0; i < v2.size(); ++i)  v2[i].info();
		for (i = 0; i < v3.size(); ++i)  v3[i].info();
		for (i = 0; i < v4.size(); ++i)  v4[i].info();
	}
};


class SceneBuilder
{
protected:
	Scene* p;
public:
	SceneBuilder() : p(0) {}
	virtual ~SceneBuilder() {}
	virtual void createScene() {}
	virtual void buildTree() {}
	virtual void buildStump() {}
	virtual void buildGirl() {}
	virtual void buildBird() {}
	virtual Scene* getScene() { return p; }
};


// Сцена 1
class BeginScene : public SceneBuilder
{
public:
	void createScene() { p = new Scene; }
	void buildTree() { p->v1.push_back(tree()); }
	void buildStump() { p->v2.push_back(stump()); }
	void buildBird() { p->v4.push_back(bird()); }
};


// Сцена 2
class The_end_scene : public SceneBuilder
{
public:
	void createScene() { p = new Scene; }
	void buildTree() { p->v1.push_back(tree()); }
	void buildStump() { p->v2.push_back(stump()); }
	void buildGirl() { p->v3.push_back(girl()); }
};


// Класс-распорядитель
class Director
{
public:
	Scene* createScene(SceneBuilder& builder)
	{
		builder.createScene();
		builder.buildTree();
		builder.buildStump();
		builder.buildGirl();
		builder.buildBird();
		return(builder.getScene());
	}
};




//----------------------------------------------------------
// std::conditional 

const bool is_children = true;
const bool is_not_children = false;
using Type1 = std::conditional<is_children, children, counselor>::type;
using Type2 = std::conditional<is_not_children, children, counselor>::type;
//----------------------------------------------------------

