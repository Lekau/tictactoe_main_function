#include <unistd.h>

void our_putchar(char k)
{
    write(1, &k, 1);
}

void our_putstr(char *str)
{
    int i = 0;
    while(str[i] != '\0')
        our_putchar(str[i++]);
}

void draw_X_or_O(char str[9], int pos, int player)
{
    int xo = 0;
    if (player%2 != 1)
    {
        while(xo != pos)
            xo++;
        str[xo] = 'X';
    }
    else 
    {
        while(xo != pos)
            xo++;
        str[xo] = 'O';
    }
}

int game_over(char str[9], int turns)
{
    if((str[0] == str[4] && str[8]) || (str[2] == str[4] && str[6]))
    {
        return (2);
    }
    else if ((str[0] == str[4] && str[8]) || (str[2] == str[4] && str[6]) || (str[2] == str[4] && str[6]))
    {
        return (2);
    } 
    else if ((str[0] == str[4] && str[8]) || (str[2] == str[4] && str[6]) || (str[2] == str[4] && str[6]))
    {
        return (2);
    }
    else if (turns == 9)
    {
        return (1);
    } 
    else
    {
        return (0);
    }
}

int disqualifier(char str[9], int pos)
{
    if (str[pos] == 'O' || str[pos] == 'X')
        return (1);
    else
        return (0); 
}

void print_grid(char str[9])
{
    int i = 0, k = 0, h_div = 0, v_div = 0;

    while(i < 9)
    {
        k = 0;
        h_div = 0;
        while(k++ < 3)
        {
            if (h_div++ < 2)
            {
                our_putchar(str[i++]);
                our_putstr(" | ");
            }
            else
            {
                our_putchar(str[i++]);
                our_putstr(" \n");
            }
        }
        if (v_div++ < 2)
            our_putstr("----------\n"); 
    }
}

int main(void)
{
    int player2 = 5;
    int player1 = 0;
    int turns = 1;
    char cur_player = '1';
    char winner[14] = "Player 1 Wins\n";
    int DQ = 0;
    char draw_check = 'Y';
    char playing_grid[9] = "Z12345678";

    while(turns <= 9)
    {
        if(turns % 2 != 0)
        {
            cur_player = '1';

            if (disqualifier(playing_grid, player1) == 1)
            {
            our_putstr("Player 1, You are disqualified \n");
            DQ = 1;
            break;
            }

            draw_X_or_O(playing_grid, player1, turns);
        
            if (game_over(playing_grid, turns) == 1)
                draw_check = 'Y';
            else
                draw_check = 'N';
        }
        else
        {
           cur_player = '2';

            if (disqualifier(playing_grid, player2) == 1)
            {
            our_putstr("Player 2, You are disqualified \n");
            DQ = 1;
            break;
            }
        
            draw_X_or_O(playing_grid, player2, turns);
        
            if (game_over(playing_grid, turns) == 1)
            {
                draw_check = 'Y';
                break;
            }
            else if (game_over(playing_grid, turns) == 2)
            {
                draw_check = 'N';
                break;
            }
        }
        turns++;
    }

    print_grid(playing_grid);

    if (draw_check == 'Y' && DQ == 0)
    {
        our_putstr("its a Draw Kids \n");
    } 
    else if (draw_check == 'N' && DQ == 0)
    {
        winner[7] = cur_player;
        our_putstr(winner);
    }
    return (0);
}