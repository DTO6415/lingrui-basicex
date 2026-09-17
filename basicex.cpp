#include<iostream>
#include<string>
#include<algorithm>
#include<random>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;
int pattern[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char grid[15][15];
bool judge(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int newX=x+pattern[i][0];
        int newY=y+pattern[i][1];
        if(newX>=1&&newX<11&&newY>=1&&newY<11)
        {
            if(grid[newX][newY]=='.')
            {
                return true;
            }
        }
    }
    return false;
}
bool judge2(int x,int y,int random)
{
    int newX=x+pattern[random][0];
    int newY=y+pattern[random][1];
    if(newX>=1&&newX<11&&newY>=1&&newY<11)
    {
        if(grid[newX][newY]=='.')
        {
            grid[newX][newY]='#';
            return true;
        }
    }
    return false;
}
int main()
{
    srand(time(0));
    int pointX=1,pointY=1;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            grid[i][j]='.';
        }
    }
    grid[pointX][pointY]='A';
    for(int sum=1;sum<26;sum++)
    {
        if(!judge(pointX,pointY))
        {
            break;
        }
        else 
        {
            while(1)
            {
                int random=rand()%4;
                if(judge2(pointX,pointY,random))
                {
                    pointX+=pattern[random][0];
                    pointY+=pattern[random][1];
                    grid[pointX][pointY]='A'+sum;
                    break;
                }
            }
        }
    }
    for(int i=1;i<11;i++)
    {
        for(int j=1;j<11;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}