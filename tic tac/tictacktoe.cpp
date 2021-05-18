#include <iostream>

using namespace std;
class Board
{
char board[4][4];
public:
Board()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            board[i][j]='_';
        }
    }
}
void printBoard()
{

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<board[i][j]<<'|';
        }
    cout<<endl;
    }
cout<<endl;
}
int setPosition(char choice)
{
while(1)
{
int row,column;
cout<<"Please enter the row and column"<<endl;
cin>>row>>column;
if(board[row][column]=='_')
{
board[row][column]=choice;
break;

}
else
{
cout<<"Position is taken"<<endl;

}
}
}
char getPosition()
{
for(int i=0;i<4;i++)
{
    for(int j=0;j<4;j++)
    {
        return board[i][j];
    }
    }

}
int checkHorizontal(char choice)
{


int count;
for(int i=0;i<4;i++)
{
    count=0;
    for(int j=0;j<4;j++)
    {
        if(board[i][j]==choice)
        {
            count++;
        }
        if(count==4)
        {

            return 1;
        }
    }

}
return 0;
}
int checkVertical(char choice)
{
int count;
for(int i=0;i<4;i++)
{
    count=0;
    for(int j=0;j<4;j++)
    {
        if(board[j][i]==choice)
        {
            count++;
        }
        if(count==4)
        {

            return 1;
        }
    }

}
return 0;
}
int checkprincipalDiagonal(char choice)
{
int count=0;
for(int i=0;i<4;i++)
{
    if (board[i][i]==choice)
    {
        count++;
    }

    }
if(count==4)
{

  return 1;
}


return 0;
}
int checkotherDiagonal(char choice)
{
int count=0;
for(int i=0;i<4;i++)
{

    for(int j=0;j<4;j++)
    {

        if((i+j)%3==0 && i!=j)
        {
         if (board[i][j]==choice)
        {
           count++;
        }
        }


    }
}

if(count==4)
{

    return 1;
}
    else
    {
        return 0;
    }
}
int checkDraw()
{
for(int i=0;i<4;i++)
{
    for(int j=0;j<4;j++)
    {
        if(board[i][j]=='_')
        {
            return 1;
            break;
        }

    }
 }
return 0;
}

};
class Player
{
string Name;
char choice;
public:
void setName(string NameIn)
{
 Name=NameIn;
}
void setChoice(char choiceIn)
{
    choice=choiceIn;
}
char getChoice()
{
    return choice;
    cout<<endl<<endl;
}

string getName()
{
    return Name;
    cout<<endl<<endl;
}
};
int main()
{
char choice1,choice2;
string Name1,Name2;
Board b1;
cout<<"The board is printed below:"<<endl;
b1.printBoard();
cout<<endl;
Player p1,p2;
cout<<"Player 1,Please Enter your name"<<endl<<endl;
cin>>Name1;
cout<<endl<<endl<<"Player 2,Please Enter your name"<<endl<<endl;
cin>>Name2;
p1.setName(Name1);
p2.setName(Name2);
cout<<endl<<endl<<"Player 1,Please Enter a character to use"<<endl<<endl;
cin>>choice1;
cout<<endl<<endl<<"Player 2,Please Enter a character to use"<<endl<<endl;
cin>>choice2;
p1.setChoice(choice1);
p2.setChoice(choice2);
while(1)
{
cout<<endl<<endl<<"Your turn,"<<Name1<<endl<<endl;
b1.setPosition(choice1);
b1.getPosition();
b1.printBoard();
if(b1.checkHorizontal(choice1)==1 || b1.checkVertical(choice1)==1|| 
b1.checkprincipalDiagonal(choice1)==1 || b1.checkotherDiagonal(choice1)==1)
{
    cout<<endl<<endl<<"Congrats"<<"\t"<<Name1<<"\t"<<"You have won"<<endl;
    break;
}
cout<<endl<<endl<<"Your turn,"<<Name2<<endl<<endl;
b1.setPosition(choice2);
b1.getPosition();
b1.printBoard();

if(b1.checkHorizontal(choice2)==1 || b1.checkVertical(choice2)==1|| 
b1.checkprincipalDiagonal(choice2)==1 || b1.checkotherDiagonal(choice2)==1)
{
    cout<<endl<<endl<<"Congrats "<<Name2<<" You Have won!"<<endl;
    break;
}
if(b1.checkDraw()==0)
{
    cout<<endl<<endl<<"The match is a draw!"<<endl;
    break;
}


}



}