#include <random>

#define SIZE 4
#define MAX 11

int board[SIZE][SIZE];

void addRandom();

void reset(){
    for (int x = 0; x < SIZE; x++)
        for(int y = 0; y < SIZE; y++)
            board[x][y]=0;
    addRandom();
    addRandom();
}

void addRandom()
{
	int x, y;
	int r, len = 0;
	int n, list[SIZE * SIZE][2];

	for (x = 0; x < SIZE; x++)
	{
		for (y = 0; y < SIZE; y++)
		{
			if (board[x][y] == 0)
			{
				list[len][0] = x;
				list[len][1] = y;
				len++;
			}
		}
	}

	if (len > 0)
	{
		r = std::rand() % len;
		x = list[r][0];
		y = list[r][1];
		n = (std::rand() % 4) / 3 + 1;
		board[x][y] = n;
	}
}

void rotate(){
    for(int i = 0; i < SIZE / 2; i++){
      for(int j = i; j < SIZE - i - 1; j++){
         int ptr = board[i][j];
         board[i][j] = board[SIZE - 1 - j][i];
         board[SIZE - 1 - j][i] = board[SIZE - 1 - i][SIZE - 1 - j];
         board[SIZE - 1 - i][SIZE - 1 - j] = board[j][SIZE - 1 - i];
         board[j][SIZE - 1 - i] = ptr;
      }
   }
}

void slide(){
    bool moved = false;
    for(int _i=0;_i<SIZE-1;_i++)
    for(int x=0;x<SIZE;x++)
        for(int y = 0; y < SIZE-1; y++){
            if(board[x][y]==0 && board[x][y+1]!=0){
                board[x][y]=board[x][y+1];
                board[x][y+1]=0;
                moved = true;}
            }
    for(int x=0;x<SIZE;x++)
        for(int y = 0; y < SIZE-1; y++)
            if(board[x][y]!=0 && board[x][y]==board[x][y+1]){
                board[x][y]=board[x][y]+1;
                board[x][y+1]=0;
                moved = true;}
    for(int x=0;x<SIZE;x++)
        for(int y = 0; y < SIZE-1; y++)
            if(board[x][y]==0 && board[x][y+1]!=0){
                board[x][y]=board[x][y+1];
                board[x][y+1]=0;
                moved = true;}
    if(moved){
    addRandom();}
}

void up(){
    slide();
}

void right(){
    rotate();
    slide();
    rotate();
    rotate();
    rotate();
}

void down(){
    rotate();
    rotate();
    slide();
    rotate();
    rotate();
}

void left(){
    rotate();
    rotate();
    rotate();
    slide();
    rotate();
}