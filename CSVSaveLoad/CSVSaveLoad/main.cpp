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

	p_actor->Update();
	p_actorA->Update();
	p_actorA->Update();

	if (typeid(*p_actor).name() == typeid(*p_actorA).name())
	{
		std::cout << "Šî’êƒNƒ‰ƒXActor‚ÆnewŽž‚ÉŒp³ƒNƒ‰ƒXActorA‚Íˆê’v‚Æ”»’f‚³‚ê‚é" << std::endl;
	}
	else
	{
		std::cout << "Šî’êƒNƒ‰ƒXActor‚ÆnewŽž‚ÉŒp³ƒNƒ‰ƒXActorA‚Íˆê’v‚Æ”»’f‚³‚ê‚È‚¢" << std::endl;
	}

	SaveLoad::Reset();

	SaveLoad::InitAdd(typeid(*p_actor).name(), p_actor->GetX(), p_actor->GetY(), p_actor->GetZ(), p_actor->GetDirection());
	SaveLoad::InitAdd(typeid(*p_Aactor).name(), p_Aactor->GetX(), p_Aactor->GetY(), p_Aactor->GetZ(), p_Aactor->GetDirection());
	SaveLoad::InitAdd(typeid(*p_actorA).name(), p_actorA->GetX(), p_actorA->GetY(), p_actorA->GetZ(), p_actorA->GetDirection());
	SaveLoad::InitAdd(typeid(*p_Bactor).name(), p_Bactor->GetX(), p_Bactor->GetY(), p_Bactor->GetZ(), p_Bactor->GetDirection());
	SaveLoad::InitAdd(typeid(*p_actorB).name(), p_actorB->GetX(), p_actorB->GetY(), p_actorB->GetZ(), p_actorB->GetDirection());

	SaveLoad::Save();

	SaveLoad::Reset();

	delete p_Bactor;
	delete p_Aactor;
	delete p_actorB;
	delete p_actorA;
	delete p_actor;

	SaveLoad::Load();

	std::vector<Actor*> vp_actor;
	vp_actor.resize(1);
	vp_actor[0] = nullptr;
	/*std::vector<ActorA*> vp_Aactor;
	vp_Aactor.resize(1);
	vp_Aactor[0] = nullptr;
	std::vector<ActorB*> vp_Bactor;
	vp_Bactor.resize(1);
	vp_Bactor[0] = nullptr;*/

	for (int i = 0, n = SaveLoad::GetIDNum(); i != n; ++i)
	{
		if (SaveLoad::GetName(i) == typeid(*vp_actor[0]).name())
		{
			if (i == 0)
			{
				vp_actor[0] = new Actor(SaveLoad::GetX(i), SaveLoad::GetY(i), SaveLoad::GetZ(i), SaveLoad::GetDirection(i));
			}
			else
			{
				vp_actor.push_back(new Actor(SaveLoad::GetX(i), SaveLoad::GetY(i), SaveLoad::GetZ(i), SaveLoad::GetDirection(i)));
			}
		}
		else
		{
			std::cout << SaveLoad::GetName(i) << std::endl;
		}
	}

	SaveLoad::Reset();

	for (int i = 0, n = vp_actor.size(); i != n; ++i)
	{
		delete vp_actor[i];
	}
	vp_actor.clear();
	vp_actor.shrink_to_fit();

	return 0;
}