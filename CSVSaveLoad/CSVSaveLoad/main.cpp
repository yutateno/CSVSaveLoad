#include <iostream>
#include "Actor.hpp"
#include "SaveLoad.hpp"

int main()
{
	std::cout << "First" << std::endl;
	Actor* p_actor = new Actor();

	std::cout << typeid(*p_actor).name() << std::endl;

	SaveLoad::Reset();

	SaveLoad::InitAdd(const_cast<char*>(typeid(*p_actor).name()), p_actor->GetX(), p_actor->GetY(), p_actor->GetZ(), p_actor->GetDirection());

	SaveLoad::Save();

	SaveLoad::Reset();

	delete p_actor;

	return 0;
}