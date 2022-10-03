#include "Expectimax.h"

#include "AStar.h"
#include "Player.h"
#include "AbstractEnemy.h"

Expectimax::Expectimax(int max_depth, int coef_dist_enemys, int coef_dist_end):
    Algorithm(max_depth, coef_dist_enemys, coef_dist_end)
{
}

pair<int, int> Expectimax::coordinate_move(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const
{
    pair<float, pair<int, int>> value_move = expectiMax(0, true, maze, player, enemys);

    if (value_move.first == MIN_VALUE)
        return player.get_coordinates();

    return value_move.second;
}

pair<float, pair<int, int>> Expectimax::expectiMax(const int depth, const bool is_maximizing, const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const
{
    if (depth == MAX_DEPTH || is_terminal(maze, player, enemys))
        return { calculate_value(maze, player, enemys), player.get_coordinates() };

    if (is_maximizing)
    {
        int best = MIN_VALUE;
        pair<int, int> best_move;

        vector<Player> states_player = get_states_player(maze, player);
        for (int i = 0; i < states_player.size(); i++)
        {
            pair<int, pair<int, int>> val_move = expectiMax(depth + 1, false, maze, states_player[i], enemys);

            if (val_move.first > best)
            {
                best = val_move.first;
                best_move = val_move.second;
            }
        }
        return { best, best_move };
    }
    else
    {
        int math_expectation = 0;
        pair<int, int> best_move = player.get_coordinates();

        vector<vector<shared_ptr<AbstractEnemy>>> state_enemys = get_states_enemys(maze, enemys);
        for (int i = 0; i < state_enemys.size(); i++)
        {
            pair<int, pair<int, int>> val_move = expectiMax(depth + 1, true, maze, player, state_enemys[i]);
            math_expectation +=  val_move.first * (1 / state_enemys.size());

        }
        return { math_expectation, best_move };
    }
}

