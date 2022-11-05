#include "Entities.h"

Entities::Entities(const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys)
{
	this->player = player;
	this->enemys = enemys;
}
