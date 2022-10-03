#include "Algorithm.h"

#include "Player.h"
#include "AbstractEnemy.h"
#include "AStar.h"

int Algorithm::calculate_value(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const
{
    if (maze.get_end() == player.get_coordinates())
        return MAX_VALUE;

    for (int i = 0; i < enemys.size(); i++)
    {
        if (enemys[i]->get_coordinates() == player.get_coordinates())
            return MIN_VALUE;
    }

    vector<int> distances_player_enemys;
    AStar algoAStar;
    for (int i = 0; i < enemys.size(); i++)
    {
        algoAStar.search_path(maze, enemys[i]->get_coordinates(), player.get_coordinates());
        distances_player_enemys.push_back(algoAStar.distance());
    }

    int min_distance_player_enemy = *min_element(distances_player_enemys.begin(), distances_player_enemys.end());
    int distance_player_finish = algoAStar.search_path(maze, player.get_coordinates(), maze.get_end());

    int value = 3 * min_distance_player_enemy - 2 * distance_player_finish;

    return value;
}

bool Algorithm::is_terminal(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const
{
    if (maze.get_end() == player.get_coordinates())
        return true;

    for (int i = 0; i < enemys.size(); i++)
    {
        if (enemys[i]->get_coordinates() == player.get_coordinates())
            return true;
    }

    return false;
}


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

vector<vector<shared_ptr<AbstractEnemy>>> Algorithm::get_states_enemys(const Maze& maze, const vector<shared_ptr<AbstractEnemy>>& enemys) const
{
    vector<vector<shared_ptr<AbstractEnemy>>> possible_state_enemys;
    for (int i = 0; i < enemys.size(); i++)
    {
        possible_state_enemys.push_back(get_states_enemy(maze, enemys[i]));
    }

    if (enemys.size() > 1)
    {
        vector<vector<shared_ptr<AbstractEnemy>>> all_combine_states_enemys = combine_states_two_enemys(possible_state_enemys[0], possible_state_enemys[1]);
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

vector<shared_ptr<AbstractEnemy>> Algorithm::get_states_enemy(const Maze& maze, const shared_ptr<AbstractEnemy>& enemy) const
{
    vector<shared_ptr<AbstractEnemy>> states;
    
    if (maze.is_cell(enemy->get_line() + 1, enemy->get_column()))
        states.push_back(make_shared<AbstractEnemy>(enemy->get_line() + 1, enemy->get_column()) );

    if (maze.is_cell(enemy->get_line() - 1, enemy->get_column()))
        states.push_back(make_shared<AbstractEnemy>(enemy->get_line() - 1, enemy->get_column()));

    if (maze.is_cell(enemy->get_line(), enemy->get_column() + 1))
        states.push_back(make_shared<AbstractEnemy>(enemy->get_line(), enemy->get_column() + 1));

    if (maze.is_cell(enemy->get_line(), enemy->get_column() - 1))
        states.push_back(make_shared<AbstractEnemy>(enemy->get_line(), enemy->get_column() - 1));

    return states;

}

vector<vector<shared_ptr<AbstractEnemy>>> Algorithm::combine_states_two_enemys(const vector<vector<shared_ptr<AbstractEnemy>>>& first,
                                                                               const vector<shared_ptr<AbstractEnemy>>& second) const
{
    vector<vector<shared_ptr<AbstractEnemy>>> result;

    for (int i = 0; i < second.size(); i++)
    {
        for (int j = 0; j < first.size(); j++)
        {
            vector<shared_ptr<AbstractEnemy>> one_combine = first[j];
            one_combine.push_back(second[i]);
            if (is_unique_state(one_combine))
            {
                result.push_back(one_combine);
            }
        }
    }

    return result;
}

vector<vector<shared_ptr<AbstractEnemy>>> Algorithm::combine_states_two_enemys(const vector<shared_ptr<AbstractEnemy>>& first,
                                                                               const vector<shared_ptr<AbstractEnemy>>& second) const
{
    vector<vector<shared_ptr<AbstractEnemy>>> result;

    for (int i = 0; i < first.size(); i++)
    {
        for (int j = 0; j < second.size(); j++)
        {
            vector<shared_ptr<AbstractEnemy>> one_combine;
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

bool Algorithm::is_unique_state(const vector<shared_ptr<AbstractEnemy>>& state_enemys) const
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
