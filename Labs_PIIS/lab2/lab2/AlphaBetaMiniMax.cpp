#include "AlphaBetaMiniMax.h"

#include "Player.h"
#include "AbstractEnemy.h"

AlphaBetaMiniMax::AlphaBetaMiniMax(int max_depth, int coef_dist_enemys, int coef_dist_end) 
    :Algorithm(max_depth, coef_dist_enemys, coef_dist_end)
{
}

pair<int, int> AlphaBetaMiniMax::coordinate_move(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const
{
    pair<int, pair<int, int>> value_move = minimax(0, true, MIN_VALUE, MAX_VALUE, maze, player, enemys);

    if (value_move.first == MIN_VALUE)
        return player.get_coordinates();

    return value_move.second;
}

pair<int, pair<int, int>> AlphaBetaMiniMax::minimax(const int depth, const bool is_maximizing, int alpha, int beta,
                                                    const Maze& maze, const Player& player,
                                                    const vector<shared_ptr<AbstractEnemy>>& enemys) const
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
            pair<int, pair<int, int>> val_move = minimax(depth + 1, false, alpha, beta, maze, states_player[i], enemys);

            if (val_move.first > best)
            {
                best = val_move.first;
                best_move = val_move.second;
            }

            alpha = max(alpha, best);
            if (beta <= alpha)
                break;
        }
        return { best, best_move };
    }
    else
    {
        int best = MAX_VALUE;
        pair<int, int> best_move = player.get_coordinates();

        vector<vector<shared_ptr<AbstractEnemy>>> state_enemys = get_states_enemys(maze, enemys);
        for (int i = 0; i < state_enemys.size(); i++)
        {
            pair<int, pair<int, int>> val_move = minimax(depth + 1, true, alpha, beta, maze, player, state_enemys[i]);
            best = min(best, val_move.first);

            beta = min(beta, best);
            if (beta <= alpha)
                break;
        }
        return { best, best_move };
    }
}

