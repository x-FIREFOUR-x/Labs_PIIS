#include "CreaterEnemy.h"

vector<shared_ptr<AbstractEnemy>> CreaterEnemy::createEnemys(int amount_enemyR, int amount_enemyA, const Maze& maze, const Player& player)
{
    srand(time(NULL));

	vector<shared_ptr<AbstractEnemy>> enemys;

	for (int i = 0; i < amount_enemyA; i++)
	{
		pair<int, int> new_coordinates = randCoordinates(maze, player, enemys);
		shared_ptr<EnemyAStar> enemy = make_shared<EnemyAStar>(new_coordinates);
		enemys.push_back(enemy);
	}

	for (int i = 0; i < amount_enemyR; i++)
	{
		pair<int, int> new_coordinates = randCoordinates(maze, player, enemys);
		shared_ptr <EnemyRandom> enemy = make_shared<EnemyRandom>(new_coordinates);
		enemys.push_back(enemy);
	}
	return enemys;
}

pair<int, int> CreaterEnemy::randCoordinates(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys)
{
	bool rand_correct = false;
	pair<int, int> new_coor;

	while (!rand_correct)
	{
		int column = rand() % maze.get_width_maze();
		int line = rand() % maze.get_hight_maze();

		new_coor = make_pair(line, column);

		if (maze.is_cell(new_coor) && player.get_coordinates() != new_coor && not_collision_other_enemys(new_coor, enemys))
			rand_correct = true;
	}

	return new_coor;
}

bool CreaterEnemy::not_collision_other_enemys(pair<int, int>& coor_new_enemy, const vector<shared_ptr<AbstractEnemy>>& enemys)
{
	bool not_coolision = true;

	for (int i = 0; i < enemys.size() && not_coolision; i++)
	{
		if (enemys[i]->get_coordinates() == coor_new_enemy)
			not_coolision = false;
	}

	return not_coolision;
}
