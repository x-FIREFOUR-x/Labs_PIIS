#include "NegaMax.h"


NegaMax::NegaMax(int max_depth, int coef_dist_enemys, int coef_dist_end)
    :Algorithm(max_depth, coef_dist_enemys, coef_dist_end)
{
}

pair<int, int> NegaMax::coordinate_move(const Maze& maze, const Player& player, const vector<shared_ptr<AbstractEnemy>>& enemys) const
{
    Entities start_state_entities(player, enemys);
    pair<int, pair<int, int>> value_move = negamax(0, Side::PLAYER_SIDE, maze, start_state_entities);

    if (value_move.second == pair<int, int>(-1, -1))
        return player.get_coordinates();

    return value_move.second;
}

pair<int, pair<int, int>> NegaMax::negamax(const int depth, const Side side,
                                           const Maze& maze, const Entities& entities) const
{
    if (depth == MAX_DEPTH || is_terminal(maze, entities.player, entities.enemys))
        return { side * calculate_value(maze, entities.player, entities.enemys), entities.player.get_coordinates() };

    int best = MIN_VALUE;
    pair<int, int> best_move = pair<int,int>(-1, -1);

    vector<Entities> states_entities = get_states_entities(side, maze, entities);

    for (int i = 0; i < states_entities.size(); i++)
    {
        pair<int, pair<int, int>> val_move = negamax(depth + 1, (Side)-side, maze, states_entities[i]);

        val_move.first = -val_move.first;

        if (val_move.first > best)
        {
            best = val_move.first;
            best_move = states_entities[i].player.get_coordinates();
        }
    }
    return { best, best_move };
}
