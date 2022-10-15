#include "NegaScout.h"

NegaScout::NegaScout(int max_depth, int coef_dist_enemys, int coef_dist_end)
	:Algorithm(max_depth, coef_dist_enemys, coef_dist_end)
{
}

pair<int, int> NegaScout::coordinate_move(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const
{
	Entities start_state_entities(player, enemys);
	pair<int, pair<int, int>> value_move = negascout(0, Side::PLAYER_SIDE, MIN_VALUE, MAX_VALUE, maze, start_state_entities);

	if (value_move.second == pair<int, int>(-1, -1))
		return player.get_coordinates();

	return value_move.second;
}

pair<int, pair<int, int>> NegaScout::negascout(const int depth, const Side side, int alpha, int beta, const Maze& maze, const Entities& entities) const
{
    if (depth == MAX_DEPTH || is_terminal(maze, entities.player, entities.enemys))
        return {side * calculate_value(maze, entities.player, entities.enemys), entities.player.get_coordinates() };

    vector<Entities> states_entities = get_states_entities(side, maze, entities);

    int value;
    pair<int, int> best_move = pair<int, int>(-1, -1);

    for (int i = 0; i < states_entities.size(); i++)
    {
        if (i == 0)
        {
            value = -negascout(depth + 1, (Side)-side, -beta, -alpha, maze, states_entities[i]).first;
        }
        else
        {
            value = -negascout(depth + 1, (Side)-side, -alpha - 1, -alpha, maze, states_entities[i]).first;
        }

        if ((value > alpha) && (value < beta))
        {
            value = - negascout(depth + 1, (Side)-side, -beta, -value, maze, states_entities[i]).first;
        }
           
        if (value > alpha)
        {
            alpha = value;
            best_move = states_entities[i].player.get_coordinates();
        }

        if (alpha >= beta)
            break;
    }
    return { alpha, best_move };
}
