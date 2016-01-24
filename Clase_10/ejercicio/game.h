#define DIM 3

// prototypes
void clear(void);
void mySleep(int ms);
void greet(void);
void init(int board[DIM][DIM]);
void draw(int board[DIM][DIM], int moveCount);
int move(int tile, int board[DIM][DIM]);
int won(int board[DIM][DIM]);
void showDate(void);

