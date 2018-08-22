#include<iostream>
#include<iomanip>
#include<cstring>
#define N 8
using namespace std;
static int tile = 1;
int Board[N][N];

void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
    if(size==1) return;
    int t = tile++, s = size / 2;
    //cover the top-left  of chessboard
    if(dr<tr+s&&dc<tc+s)
    //the defect tile in the area
    ChessBoard(tr, tc, dr, dc, s);
    else
    {
        //the defect tile isn't in the area
        //cover the bottle-right using t tile(assuming the one is a defect)
        Board[tr + s - 1][tc + s - 1]=t;
        ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }
    //cover the top-right  of chessboard
    if(dr<tr+s&&dc>=tc+s)
    //the ...
    ChessBoard(tr, tc + s, dr, dc, s);
    else
    {
        //bottle-left 
        Board[tr + s - 1][tc + s] = t;
        ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }

    //cover the bottle-left  of chessboard
    if(dr>=tr+s&&dc<tc+s)
        ChessBoard(tr + s, tc, dr, dc, s);
    else
    {
        //top-right
        Board[tr + s][tc + s - 1] = t;
        ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }
    //cover the bottle-right  of the chessboard
    if(dr>=tr+s&&dc>=tc+s)
        ChessBoard(tr + s, tc + s, dr, dc, s);
    else
    {
        //top-left
        Board[tr + s][tc + s]=t;
        ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
    }
}

int main()
{
    memset(Board, 0, sizeof(Board));
    ChessBoard(0, 0, 0, 0, N);
    for (int r = 0; r < N;r++)
    {
        for (int c = 0; c < N;c++)
            cout<<setw(4) << Board[r][c]<<" ";
        cout << endl;
    }
}