#include <iostream>
#include "Actor.hpp"
#include "ActorA.hpp"
#include "ActorB.hpp"
#include "SaveLoad.hpp"

int main()
{
	std::cout << "First" << std::endl;
	Actor* p_actor = new Actor();
	Actor* p_actorA = new ActorA();
	Actor* p_actorB = new ActorB();
	ActorA* p_Aactor = new ActorA();
	ActorB* p_Bactor = new ActorB();

	std::cout << typeid(*p_actor).name() << std::endl;
	std::cout << typeid(*p_actorA).name() << std::endl;
	std::cout << typeid(*p_actorB).name() << std::endl;
	std::cout << typeid(*p_Aactor).name() << std::endl;
	std::cout << typeid(*p_Bactor).name() << std::endl;

	SaveLoad::Reset();

	SaveLoad::InitAdd(const_cast<char*>(typeid(*p_actor).name()), p_actor->GetX(), p_actor->GetY(), p_actor->GetZ(), p_actor->GetDirection());
	SaveLoad::InitAdd(const_cast<char*>(typeid(*p_actorA).name()), p_actorA->GetX(), p_actorA->GetY(), p_actorA->GetZ(), p_actorA->GetDirection());
	SaveLoad::InitAdd(const_cast<char*>(typeid(*p_actorB).name()), p_actorB->GetX(), p_actorB->GetY(), p_actorB->GetZ(), p_actorB->GetDirection());
	SaveLoad::InitAdd(const_cast<char*>(typeid(*p_Aactor).name()), p_Aactor->GetX(), p_Aactor->GetY(), p_Aactor->GetZ(), p_Aactor->GetDirection());
	SaveLoad::InitAdd(const_cast<char*>(typeid(*p_Bactor).name()), p_Bactor->GetX(), p_Bactor->GetY(), p_Bactor->GetZ(), p_Bactor->GetDirection());

	SaveLoad::Save();

	SaveLoad::Reset();

	delete p_actor;

	return 0;
}