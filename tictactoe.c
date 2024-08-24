#include <stdio.h>
char board[3][3]; 

void initialize_board() 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            board[i][j] = ' ';
        }
    }
}

void display_board() 
{
    printf("  1   2   3\n");
    printf("1 %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---|---|---\n");
    printf("2 %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---|---|---\n");
    printf("3 %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int is_valid_move(int row, int col) 
{
    row--; 
    col--; 
    if (row < 0 || row >= 3 || col < 0 || col >= 3) 
    {
        return 0; 
    }
    if (board[row][col] != ' ') 
    {
        return 0; 
    }
    return 1;
}

char check_winner() 
{
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') 
        {
            return board[i][0];
        }
    }
    for (int i = 0; i < 3; i++) 
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') 
        {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') 
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') 
    {
        return board[0][2];
    }
    return ' '; 
}

int main() 
{
    int row, col;
    char player = 'X'; 
    initialize_board();
    printf("Welcome to Tic Tac Toe!\n");
    do 
    {
        display_board();
        printf("Player %c, enter your move (row column): ", player);
        scanf("%d %d", &row, &col);

        if (is_valid_move(row, col)) 
        {
            board[row - 1][col - 1] = player; // Adjusting to 0-based index
            char winner = check_winner();
            if (winner != ' ') 
            {
                display_board();
                printf("Player %c wins!\n", winner);
                break;
            }
            player = (player == 'X') ? 'O' : 'X';
        } 
        else 
        {
            printf("Invalid move. Try again.\n");
        }
    } 
    while (1);
    return 0;
}
