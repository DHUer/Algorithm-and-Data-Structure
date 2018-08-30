#include<iostream>
#include<stack>
#define mazeRowNum 10
#define mazeColumnNum 10
using namespace std;

static char maze[mazeRowNum][mazeColumnNum] = {
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{'#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
	{'#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
	{'#', ' ', ' ', ' ', ' ', '#', '#', ' ', ' ', '#'},
	{'#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#'},
	{'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
	{'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
	{'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#'},
	{'#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

typedef struct PosType
{
    int x;
    int y;
    bool operator == (PosType & tem)
    {
        if(x==tem.x&&y==tem.y)
            return true;
        else
            return false;
    }
}PosType;

typedef struct 
{
    int dir;
    PosType seat;
}SElemType;

bool isPassable(PosType cur)
{
    if(maze[cur.x][cur.y]==' ')
        return true;
    else
        return false;
}

void nextPos(PosType &curPos,int dir)
{
    if(dir==0)
        curPos.y++;
    if(dir==1)
        curPos.x++;
    if(dir==2)
        curPos.x--;
    if(dir==3)
        curPos.y--;
}

void footPrint(PosType pos)
{
    maze[pos.x][pos.y] = '*';
}

void makePrint(PosType pos)
{
    maze[pos.x][pos.y] = '@';
}

bool MazePath(PosType start,PosType end)
{
    stack<SElemType> s;
    PosType curPos = start;
    do
    {
        if(isPassable(curPos))
        {
            footPrint(curPos);
            SElemType e;
            e.dir = 0;
            e.seat = curPos;
            s.push(e);
            if(curPos==end)
                return true;
            nextPos(curPos, 0);
        }
        else
        {
            SElemType e;
            e = s.top();
            s.pop();
            while(e.dir==3&&!s.empty())
            {
                makePrint(e.seat);
                e = s.top();
                s.pop();
            }
            if(e.dir<3)
            {
                e.dir++;
                s.push(e);
                nextPos(curPos, e.dir);
            }
        }
    } while (!s.empty());
    return false;
}

void printMaze()
{
    for (int i = 0; i < mazeRowNum;i++)
    {
        for (int j = 0; j < mazeColumnNum;j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    PosType start,end;
    start = {1, 1};
    end = {8, 8};
    MazePath(start, end);
    printMaze();
    return 0;
}