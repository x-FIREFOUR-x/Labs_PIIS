#include "Algorithm.h"

#include "Player.h"
#include "AbstractEnemy.h"

vector<Player> Algorithm::get_states_player(const Maze& maze, const Player& player) const
{
    vector<Player> states;

    if (maze.is_cell(player.get_line() + 1, player.get_column()))
        states.push_back(Player(player.get_line() + 1, player.get_column()));

    if (maze.is_cell(player.get_line() - 1, player.get_column()))
        states.push_back(Player(player.get_line() - 1, player.get_column()));

    if (maze.is_cell(player.get_line(), player.get_column() + 1))
        states.push_back(Player(player.get_line(), player.get_column() + 1));

    if (maze.is_cell(player.get_line(), player.get_column() - 1))
        states.push_back(Player(player.get_line(), player.get_column() - 1));

    return states;
}

vector<vector<AbstractEnemy*>> Algorithm::get_states_enemys(const Maze& maze, const vector<AbstractEnemy*>& enemys) const
{
    vector<vector<AbstractEnemy*>> possible_state_enemys;
    for (int i = 0; i < enemys.size(); i++)
    {
        possible_state_enemys.push_back(get_states_enemy(maze, enemys[i]));
    }

    if (enemys.size() > 1)
    {
        vector<vector<AbstractEnemy*>> all_combine_states_enemys = combine_states_two_enemys(possible_state_enemys[0], possible_state_enemys[1]);
        for (int i = 2; i < possible_state_enemys.size(); i++)
        {
            all_combine_states_enemys = combine_states_two_enemys(all_combine_states_enemys, possible_state_enemys[i]);
        }

        return all_combine_states_enemys;
    }
    else
    {
        return possible_state_enemys;
    }
}

vector<AbstractEnemy*> Algorithm::get_states_enemy(const Maze& maze, const AbstractEnemy* enemy) const
{
    vector<AbstractEnemy*> states;

    if (maze.is_cell(enemy->get_line() + 1, enemy->get_column()))
        states.push_back(new AbstractEnemy(enemy->get_line() + 1, enemy->get_column()));

    if (maze.is_cell(enemy->get_line() - 1, enemy->get_column()))
        states.push_back(new AbstractEnemy(enemy->get_line() - 1, enemy->get_column()));

    if (maze.is_cell(enemy->get_line(), enemy->get_column() + 1))
        states.push_back(new AbstractEnemy(enemy->get_line(), enemy->get_column() + 1));

    if (maze.is_cell(enemy->get_line(), enemy->get_column() - 1))
        states.push_back(new AbstractEnemy(enemy->get_line(), enemy->get_column() - 1));

    return states;

}

vector<vector<AbstractEnemy*>> Algorithm::combine_states_two_enemys(const vector<vector<AbstractEnemy*>>& first, const vector<AbstractEnemy*>& second) const
{
    vector<vector<AbstractEnemy*>> result;

    for (int i = 0; i < second.size(); i++)
    {
        for (int j = 0; j < first.size(); j++)
        {
            vector<AbstractEnemy*> one_combine = first[j];
            one_combine.push_back(second[i]);
            if (is_unique_state(one_combine))
            {
                result.push_back(one_combine);
            }
        }
    }

    return result;
}

vector<vector<AbstractEnemy*>> Algorithm::combine_states_two_enemys(const vector<AbstractEnemy*>& first, const vector<AbstractEnemy*>& second) const
{
    vector<vector<AbstractEnemy*>> result;

    for (int i = 0; i < first.size(); i++)
    {
        for (int j = 0; j < second.size(); j++)
        {
            vector<AbstractEnemy*> one_combine;
            one_combine.push_back(first[i]);
            one_combine.push_back(second[j]);
            if (is_unique_state(one_combine))
            {
                result.push_back(one_combine);
            }
        }
    }

    return result;
}

bool Algorithm::is_unique_state(const vector<AbstractEnemy*>& state_enemys) const
{
    bool is_unique = true;
    for (int i = 0; i < state_enemys.size() && is_unique; i++)
    {
        for (int j = i + 1; j < state_enemys.size(); j++)
        {
            if(state_enemys[i]->get_coordinates() == state_enemys[j]->get_coordinates())
            {
                is_unique = false;
                break;
            }
                
        }
    }
    return is_unique;
}
