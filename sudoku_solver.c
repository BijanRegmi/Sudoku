#include <stdio.h>
#include <stdlib.h>

void show_board(int (*)[9]);
int check_board(int (*)[9]);
void add_board(int (*)[9]);
int solve(int (*)[9]);

int main()
{
    int board[9][9]={0};
    show_board(board);
    add_board(board);
    solve(board);
    show_board(board);

}

int solve(int (*board)[9])
{
    int stat=check_board(board),pt,c;
    if (stat == -1)
    {
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                if (board[i][j] == 0)
                {
                    for (int k=1;k<=9;k++)
                    {
                        c=0;
                        for (int m=0;m<9;m++)
                        {
                            if ((k == board[m][j]) || (k == board[i][m]))
                            {
                                c=1;
                                break;
                            }
                            
                        }
                        board[i][j] = k;
                        pt = solve(board);
                        if (pt == 0)
                            board[i][j]=0;
                        else
                            return 1;
                    }
                    return 0;
                }
            }
        }
    }
    else
        return stat;
}

void add_board(int (*board)[9])
{
    for (int i=0;i<9;i++)
    {
        for (int j=0;j<9;j++)
        {
            printf("\n");
            printf("board[%d][%d] = ",i,j);
            scanf("%d",&board[i][j]);
            show_board(board);
        }
    }
}

void show_board(int (*board)[9])
{
    system("clear");
    for (int i=0;i<9;i++)
    {
        for (int j=0;j<9;j++)
        {
            printf("%d\t",board[i][j]);
        }
        printf("\n\n");
    }
}

int check_board(int (*board)[9])
{
    int h_sum=0,v_sum=0,ctr=0,ss=0;
    for (int i=0;i<9;i++)
    {
        h_sum=0;
        v_sum=0;
        for (int j=0;j<9;j++)
        {
            if (board[i][j]!=0)
                ctr++;
            //Horizontal
            h_sum+=board[i][j];
            //Vertical
            v_sum+=board[j][i];
        }
        if ((h_sum == 45) && (v_sum == 45))
            ss++;
    }
    if (ss == 9)
        return 1;       //SOLVED CORRECTLY
    else if (ctr == 81)
        return 0;       //SOLVED INCORRECTLY
    else
        return -1;      //NOT SOLVED YET
}