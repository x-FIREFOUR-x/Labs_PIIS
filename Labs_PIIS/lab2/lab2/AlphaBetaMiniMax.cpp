#include "AlphaBetaMiniMax.h"

#include "AStar.h"

pair<int, int> AlphaBetaMiniMax::coordinate_move(const Maze& maze, Player player, vector<AbstractEnemy*> enemys)
{
    int value = minimax(0, true, MIN_VALUE, MAX_VALUE, maze, player, enemys);

    return pair<int, int>();
}

int AlphaBetaMiniMax::minimax(int depth, bool is_maximizing, int alpha, int beta, const Maze& maze, Player player, vector<AbstractEnemy*> enemys)
{
    if (depth == MAX_DEPTH || is_terminal(maze, player, enemys))
        return calculate_value(maze, player, enemys);

    if (is_maximizing)
    {
        int best = MIN_VALUE;

        vector<Player> states_player = get_states_player(maze, player);
        for (int i = 0; i < states_player.size(); i++)
        {
            int val = minimax(depth + 1, false, alpha, beta, maze, states_player[i], enemys);

            best = max(best, val);

            alpha = max(alpha, best);
            if (beta <= alpha)
                break;
        }
        return best;
    }
    else
    {
        int best = MAX_VALUE;
        pair<int, int> cur_move_player;

        vector<vector<AbstractEnemy*>> state_enemys = get_states_enemys(maze, enemys);
        for (int i = 0; i < state_enemys.size(); i++)
        {
            int val = minimax(depth + 1, true, alpha, beta, maze, player, state_enemys[i]);
            best = min(best, val);


            beta = min(beta, best);
            if (beta <= alpha)
                break;
        }
        return best;
    }
}

int AlphaBetaMiniMax::calculate_value(const Maze& maze, const Player& player, const vector<AbstractEnemy*>& enemys)
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
    
    int value = 2 * min_distance_player_enemy - distance_player_finish;

    return value;
}

bool AlphaBetaMiniMax::is_terminal(const Maze& maze, const Player& player, const vector<AbstractEnemy*>& enemys)
{
    if(maze.get_end() == player.get_coordinates())
        return true;

    for (int i = 0; i < enemys.size(); i++)
    {
        if (enemys[i]->get_coordinates() == player.get_coordinates())
            return true;
    }

    return false;
}

