#include "AlphaBetaNegaMax.h"

AlphaBetaNegaMax::AlphaBetaNegaMax(int max_depth, int coef_dist_enemys, int coef_dist_end)
	:Algorithm(max_depth, coef_dist_enemys, coef_dist_end)
{
}

pair<int, int> AlphaBetaNegaMax::coordinate_move(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const
{
	Entities start_state_entities(player, enemys);
	pair<int, pair<int, int>> value_move = alpha_beta_negamax(0, Side::PLAYER_SIDE, MIN_VALUE, MAX_VALUE, maze, start_state_entities);

    if (value_move.second == pair<int, int>(-1, -1))
        return player.get_coordinates();

	return value_move.second;
}

pair<int, pair<int, int>> AlphaBetaNegaMax::alpha_beta_negamax(const int depth, const Side side, int alpha, int beta, const Maze& maze, const Entities& entities) const
{
    if (depth == MAX_DEPTH || is_terminal(maze, entities.player, entities.enemys))
        return {side * calculate_value(maze, entities.player, entities.enemys), entities.player.get_coordinates() };

    int best = MIN_VALUE;
    pair<int, int> best_move = pair<int, int>(-1, -1);

    vector<Entities> states_entities = get_states_entities(side, maze, entities);

    for (int i = 0; i < states_entities.size(); i++)
    {
        pair<int, pair<int, int>> val_move = alpha_beta_negamax(depth + 1, (Side)-side, -beta, -alpha, maze, states_entities[i]);

        val_move.first = -val_move.first;

        if (val_move.first > best)
        {
            best = val_move.first;
            best_move = states_entities[i].player.get_coordinates();
        }

        alpha = max(alpha, best);
        if (beta <= alpha)
            break;
    }
    return { best, best_move };
}
