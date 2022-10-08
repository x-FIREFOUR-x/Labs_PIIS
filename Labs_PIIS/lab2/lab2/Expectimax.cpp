#include "Expectimax.h"

#include "AStar.h"
#include "Player.h"
#include "AbstractEnemy.h"
#include "EnemyAStar.h"
#include "EnemyRandom.h"

Expectimax::Expectimax(int max_depth, int coef_dist_enemys, int coef_dist_end):
    Algorithm(max_depth, coef_dist_enemys, coef_dist_end)
{
}

pair<int, int> Expectimax::coordinate_move(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const
{
    pair<float, pair<int, int>> value_move = expectiMax(0, NodeState::MAX, maze, player, enemys);

    if (value_move.first == MIN_VALUE)
        return player.get_coordinates();

    return value_move.second;
}

pair<float, pair<int, int>> Expectimax::expectiMax(const int depth, const NodeState nodeState, const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const
{
    if (depth == MAX_DEPTH || is_terminal(maze, player, enemys))
        return { calculate_value(maze, player, enemys), player.get_coordinates() };

    if (nodeState == NodeState::MAX)
    {
        float best = MIN_VALUE;
        pair<int, int> best_move;

        vector<Player> states_player = get_states_player(maze, player);

        for (int i = 0; i < states_player.size(); i++)
        {
            pair<float, pair<int, int>> val_move = expectiMax(depth + 1, NodeState::MIN, maze, states_player[i], enemys);

            if (val_move.first > best)
            {
                best = val_move.first;
                best_move = val_move.second;
            }
        }

        return { best, best_move };
    }
    else if(nodeState == NodeState::MIN)
    {
        float best = MAX_VALUE;
        pair<int, int> best_move = player.get_coordinates();;
        
        vector<vector<shared_ptr<AbstractEnemy>>> state_enemys = get_combine_states_AstarEnemys(enemys, maze);

        for (int i = 0; i < state_enemys.size(); i++)
        {
            pair<float, pair<int, int>> val_move = expectiMax(depth + 1, NodeState::CHANSE_MIN, maze, player, state_enemys[i]);

            best = min(best, val_move.first);
        }

        return { best, best_move };
    }
    else if (nodeState == NodeState::CHANSE_MIN)
    {
        float math_expectation = 0;
        pair<int, int> best_move = player.get_coordinates();

        vector<vector<shared_ptr<AbstractEnemy>>> state_enemys = get_combine_states_RandomEnemys(enemys, maze);

        for (int i = 0; i < state_enemys.size(); i++)
        {
            pair<float, pair<int, int>> val_move = expectiMax(depth + 1, NodeState::MAX, maze, player, state_enemys[i]);
            math_expectation +=  val_move.first * (1 / state_enemys.size());

        }

        return { math_expectation, best_move };
    }
}



vector<vector<shared_ptr<AbstractEnemy>>> Expectimax::get_combine_states_AstarEnemys(const vector<shared_ptr<AbstractEnemy>>& enemys, const Maze& maze) const
{
    vector<shared_ptr<AbstractEnemy>> AstarEnemys;
    for (int i = 0; i < enemys.size(); i++)
    {
        if (enemys[i]->symbol_view() == '*')
        {
            shared_ptr <EnemyAStar> enemy = make_shared<EnemyAStar>(enemys[i]->get_coordinates());
            AstarEnemys.push_back(enemy);
        }   
    }

    vector<shared_ptr<AbstractEnemy>> randomEnemys;
    for (int i = 0; i < enemys.size(); i++)
    {
        if (enemys[i]->symbol_view() == '&')
        {
            shared_ptr <EnemyRandom> enemy = make_shared<EnemyRandom>(enemys[i]->get_coordinates());
            randomEnemys.push_back(enemy);
        }    
    }

    vector<vector<shared_ptr<AbstractEnemy>>> state_astar_enemys = get_states_enemys(maze, AstarEnemys);
    vector<vector<shared_ptr<AbstractEnemy>>> state_enemys;

    for (int i = 0; i < state_astar_enemys.size(); i++)
    {
        vector<shared_ptr<AbstractEnemy>> one_state;
        for (int j = 0; j < state_astar_enemys[i].size(); j++)
        {
            shared_ptr <EnemyAStar> enemy = make_shared<EnemyAStar>(state_astar_enemys[i][j]->get_coordinates());
            one_state.push_back(enemy);
        }

        for (int j = 0; j < randomEnemys.size(); j++)
        {
            shared_ptr <EnemyRandom> enemy = make_shared<EnemyRandom>(randomEnemys[j]->get_coordinates());
            one_state.push_back(enemy);
        }
        state_enemys.push_back(one_state);
    }

    return state_enemys;
}

vector<vector<shared_ptr<AbstractEnemy>>> Expectimax::get_combine_states_RandomEnemys(const vector<shared_ptr<AbstractEnemy>>& enemys, const Maze& maze) const
{
    vector<shared_ptr<AbstractEnemy>> AstarEnemys;
    for (int i = 0; i < enemys.size(); i++)
    {
        if (enemys[i]->symbol_view() == '*')
        {
            shared_ptr <EnemyAStar> enemy = make_shared<EnemyAStar>(enemys[i]->get_coordinates());
            AstarEnemys.push_back(enemy);
        }
    }

    vector<shared_ptr<AbstractEnemy>> randomEnemys;
    for (int i = 0; i < enemys.size(); i++)
    {
        if (enemys[i]->symbol_view() == '&')
        {
            shared_ptr <EnemyRandom> enemy = make_shared<EnemyRandom>(enemys[i]->get_coordinates());
            randomEnemys.push_back(enemy);
        }
    }

    vector<vector<shared_ptr<AbstractEnemy>>> state_random_enemys = get_states_enemys(maze, randomEnemys);
    vector<vector<shared_ptr<AbstractEnemy>>> state_enemys;

    for (int i = 0; i < state_random_enemys.size(); i++)
    {
        vector<shared_ptr<AbstractEnemy>> one_state;
        for (int j = 0; j < state_random_enemys[i].size(); j++)
        {
            shared_ptr <EnemyRandom> enemy = make_shared<EnemyRandom>(state_random_enemys[i][j]->get_coordinates());
            one_state.push_back(enemy);
        }

        for (int j = 0; j < AstarEnemys.size(); j++)
        {
            shared_ptr <EnemyAStar> enemy = make_shared<EnemyAStar>(AstarEnemys[j]->get_coordinates());
            one_state.push_back(enemy);
        }
        state_enemys.push_back(one_state);
    }

    return state_enemys;
}

