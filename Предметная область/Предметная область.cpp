#include <iostream>
#include "header.h"
#include <string>
#include <algorithm>
#include <vector>
#include <ranges>
#include "ForwardList.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	children children1;
	children1.name = "Nic";
	std::cout << children1.name << std::endl;
	children1.birthday = "12.06";
	std::cout << children1.birthday << std::endl;
	children1.gender = "Male";
	std::cout << children1.gender << std::endl;
	children1.SquadName = "Apple";
	std::cout << children1.SquadName << std::endl;
	children1.year = 15;
	std::cout << children1.year << std::endl;
	children1.height = 174;
	std::cout << children1.height << std::endl;
	children1.allergies = "No";
	std::cout << children1.allergies << std::endl;
	children1.hobbies = "Music";
	std::cout << children1.hobbies << std::endl;
	std::cout << children1.HowRoom(children1) << std::endl;
	std::cout << children1.NumberOfAnimals() << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	children children2;
	children2.name = "Raily";
	std::cout << children2.name << std::endl;
	children2.birthday = "17.06";
	std::cout << children2.birthday << std::endl;
	children2.gender = "Female";
	std::cout << children2.gender << std::endl;
	children2.SquadName = "Ambrella";
	std::cout << children1.SquadName << std::endl;
	children2.year = 13;
	std::cout << children2.year << std::endl;
	children2.height = 156;
	std::cout << children2.height << std::endl;
	children2.allergies = "Yes";
	std::cout << children2.allergies << std::endl;
	children2.hobbies = "Dance";
	std::cout << children2.hobbies << std::endl;
	std::cout << children2.HowRoom(children2) << std::endl;
	std::cout << children2.NumberOfAnimals() << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	counselor counselor1;
	counselor1.name = "Tom";
	std::cout << counselor1.name << std::endl;
	counselor1.birthday = "19.06";
	std::cout << counselor1.birthday << std::endl;
	counselor1.gender = "Male";
	std::cout << counselor1.gender << std::endl;
	counselor1.year = 19;
	std::cout << counselor1.year << std::endl;
	counselor1.height = 181;
	std::cout << counselor1.height << std::endl;
	counselor1.experience = 1;
	std::cout << counselor1.experience << std::endl;
	std::cout << counselor1.NumberOfChildren() << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	counselor counselor2;
	counselor2.name = "Cat";
	std::cout << counselor2.name << std::endl;
	counselor2.birthday = "19.08";
	std::cout << counselor2.birthday << std::endl;
	counselor2.gender = "Female";
	std::cout << counselor2.gender << std::endl;
	counselor2.year = 21;
	std::cout << counselor2.year << std::endl;
	counselor2.height = 175;
	std::cout << counselor2.height << std::endl;
	counselor2.experience = 3;
	std::cout << counselor2.experience << std::endl;
	std::cout << counselor2.NumberOfChildren() << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	if (counselor1 > counselor2)
	{
		std::cout << counselor1.name << " ñòàðøèé âîæàòûé, îïûò " << counselor1.experience << " ëåò" << std::endl;
	}
	else if (counselor2 > counselor1)
	{
		std::cout << counselor2.name << " ñòàðøèé âîæàòûé, îïûò " << counselor2.experience << " ëåò" << std::endl;
	}
	else
		std::cout << "Îäèíàêîâûé îïûò ðàáîòû" << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	/**std::cout << counselor1.name << " counselor in " << Group(counselor1) << " squad" << std::endl;
	std::cout << counselor2.name << " counselor in " << Group(counselor2) << " squad" << std::endl;
	std::cout << "------------------------------------------" << std::endl;*/

	//Decorator
	ListPaper* List = new LineDecorator(new ÑircleDecorator(new ListPaper_with_text(children1.SquadName)));
	List->draw();

	ListPaper* List1 = new LineDecorator(new ÑircleDecorator(new ListPaper_with_text(children2.SquadName)));
	List1->draw();
	std::cout << "------------------------------------------" << std::endl;

	//Building
	Director director;
	BeginScene BeginBuilder;
	The_end_scene LastBuilder;

	Scene* begin = director.createScene(BeginBuilder);
	Scene* last = director.createScene(LastBuilder);
	std::cout << children1.SquadName << " perform begin scene as part of: " << std::endl;
	begin->info();
	std::cout << std::endl;
	std::cout << children2.SquadName << " perform last scene  as part of: " << std::endl;
	last->info();
	std::cout << "------------------------------------------" << std::endl;


	// std::conditional 
	std::cout << children1.name + " - " + typeid(Type1).name() << '\n';
	std::cout << counselor1.name + " - " + typeid(Type2).name() << '\n';
	std::cout << "------------------------------------------" << std::endl;

	std::vector ShoeCabinet{ "Sneakers", "Boots", "Sandals", "Flats", "Heels", "Loafers", "Slippers", "Flip-flops" };
	auto shoe = ShoeCabinet | std::views::filter([](std::string item) {return item == "Boots"; });
	for (auto i : shoe)
	{
		std::cout << children1.name + " wears " + i << std::endl;
	}
	std::cout << "------------------------------------------" << std::endl;

	Container::forward_list <std::string> scenarii;
	scenarii.push_back("First Scene");
	scenarii.push_back("Second Scene");
	scenarii.push_back("Third Scene");
	scenarii.push_back("Fourth Scene");
	scenarii.push_back("Fifth Scene - Final");
	std::cout << "Acts of Show: " << std::endl;



};
