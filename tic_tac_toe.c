#include <stdio.h>

char board[3][3];  // 3x3 Tic-Tac-Toe board
char current_player = 'X';  // Current player ('X' or 'O')

// Function prototypes
void initialize_board();
void print_board();
int check_winner();
void make_move();

int main() {
    int winner = 0;
    int moves = 0;

    initialize_board();

    while (!winner && moves < 9) {
        print_board();
        make_move();
        winner = check_winner();
        moves++;
        current_player = (current_player == 'X') ? 'O' : 'X';  // Switch player
    }

    print_board();

    if (winner) {
        printf("Player %c wins!\n", current_player == 'X' ? 'O' : 'X');
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

// Initialize the board with empty spaces
void initialize_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the current state of the board
void print_board() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Check if there's a winner
int check_winner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    return 0;
}

// Handle a player's move
void make_move() {
    int row, col;
    int valid_move = 0;

    while (!valid_move) {
        printf("Player %c, enter your move (row and column): ", current_player);
        scanf("%d %d", &row, &col);

        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = current_player;
            valid_move = 1;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
}
