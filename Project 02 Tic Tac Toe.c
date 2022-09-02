#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>


void compare(char []);
void compare2(char []);
void rules();
void entername(char [], int);
void gameplay(char *, int *,char);
void smart_computer(char *, int *, char);
void game_display(char *);
void display_tictactoe();
int main()
{
    srand(time(NULL));
    int option;
    while(1)
    {
        char name1[25], name2[25], str[15]="123456789";
        system("cls");
        display_tictactoe();
        printf("Select an Option to start the game.\n\n");
        printf("1: Play with Smart computer\n");
        printf("2: Play with Evil computer.\n");
        printf("3: Play with player.\n");
        printf("4: Exit\n");
        option=getch();
        if(option==27)
            break;
        system("cls");
        int count=0;
        char esc;                                                 //variable to get character in function gameplay.
        switch(option)
        {
            case 49:
                display_tictactoe();
                printf("Enter the name of the player.\n");
                printf("Player 1       : ");
                entername(name1, 25);
                printf("\n\n");
                rules();
                printf("\n\nPress any key to proceed.\n");
                option=getch();
                if(option==27)
                    exit(0);
                while(1)
                {
                    system("cls");
                        game_display(str);
                        if(count==9)
                        {
                            printf("Game is DRAW.\n\n");
                            while(1)
                            {
                                printf("Press ENTER to play again or Press ESC to exit the game.");
                                option=getch();
                                if(option==27)
                                    exit(0);
                                else if(option==13)
                                break;
                            }
                            break;
                        }
                        if((str[0]==str[1]&&str[0]==str[2])||(str[0]==str[3]&&str[0]==str[6])||(str[0]==str[4]&&str[0]==str[8])||(str[1]==str[4]&&str[1]==str[7])||
                           (str[2]==str[5]&&str[2]==str[8])||(str[2]==str[4]&&str[2]==str[6])||(str[3]==str[4]&&str[3]==str[5])||(str[6]==str[7]&&str[6]==str[8]))
                        {
                            if((str[0]=='X'&&str[1]=='X'&&str[2]=='X')||(str[0]=='X'&&str[4]=='X'&&str[8]=='X')||(str[0]=='X'&&str[3]=='X'&&str[6]=='X')||(str[3]=='X'&&str[4]=='X'&&str[5]=='X')||
                               (str[6]=='X'&&str[7]=='X'&&str[8]=='X')||(str[1]=='X'&&str[4]=='X'&&str[7]=='X')||(str[2]=='X'&&str[5]=='X'&&str[8]=='X')||(str[2]=='X'&&str[4]=='X'&&str[6]=='X'))
                                printf("\"%s\" won the game.\n\n",name1);
                            else
                                printf("Smart Computer won the game.\n\n");
                            while(1)
                            {
                                printf("Press ENTER to play again or Press ESC to exit the game.");
                                option=getch();
                                if(option==27)
                                    exit(0);
                                else if(option==13)
                                break;
                            }
                            break;
                        }
                        if(count%2)
                        {
                            printf("           Computer's turn.\n\n");
                            count++;
                            compare(str);
                        }
                        else
                        {
                            printf("           Player 1 turn.\n\n");
                            esc=getch();
                        }
                        if(esc==27)
                            exit(0);
                        smart_computer(str, &count, esc);
                }
                break;
            case 50:
                display_tictactoe();
                printf("Enter the name of the player.\n");
                printf("Player 1       : ");
                entername(name1, 25);
                printf("\n\n");
                rules();
                printf("\n\nPress any key to proceed.\n");
                option=getch();
                if(option==27)
                    exit(0);
                while(1)
                {
                    system("cls");
                        game_display(str);
                        if(count==9)
                        {
                            printf("Game is DRAW.\n\n");
                            while(1)
                            {
                                printf("Press ENTER to play again or Press ESC to exit the game.");
                                option=getch();
                                if(option==27)
                                    exit(0);
                                else if(option==13)
                                break;
                            }
                            break;
                        }
                        if((str[0]==str[1]&&str[0]==str[2])||(str[0]==str[3]&&str[0]==str[6])||(str[0]==str[4]&&str[0]==str[8])||(str[1]==str[4]&&str[1]==str[7])||
                           (str[2]==str[5]&&str[2]==str[8])||(str[2]==str[4]&&str[2]==str[6])||(str[3]==str[4]&&str[3]==str[5])||(str[6]==str[7]&&str[6]==str[8]))
                        {
                            if((str[0]=='X'&&str[1]=='X'&&str[2]=='X')||(str[0]=='X'&&str[4]=='X'&&str[8]=='X')||(str[0]=='X'&&str[3]=='X'&&str[6]=='X')||(str[3]=='X'&&str[4]=='X'&&str[5]=='X')||
                               (str[6]=='X'&&str[7]=='X'&&str[8]=='X')||(str[1]=='X'&&str[4]=='X'&&str[7]=='X')||(str[2]=='X'&&str[5]=='X'&&str[8]=='X')||(str[2]=='X'&&str[4]=='X'&&str[6]=='X'))
                                printf("\"%s\" won the game.\n\n",name1);
                            else
                                printf("evil Computer won the game.\n\n");
                            while(1)
                            {
                                printf("Press ENTER to play again or Press ESC to exit the game.");
                                option=getch();
                                if(option==27)
                                    exit(0);
                                else if(option==13)
                                break;
                            }
                            break;
                        }
                        if(count%2)
                        {
                            printf("           Computer's turn.\n\n");
                            count++;
                            compare(str);
                            compare2(str);
                        }
                        else
                        {
                            printf("           Player 1 turn.\n\n");
                            esc=getch();
                        }
                        if(esc==27)
                            exit(0);
                        smart_computer(str, &count, esc);
                }
                break;
            case 51:
                display_tictactoe();
                printf("Enter the names of both the players.\n");
                printf("Player 1       : ");
                entername(name1, 25);
                printf("Player 2       : ");
                entername(name2, 25);
                printf("\n\n");
                rules();
                printf("\n\nPress any key to proceed.\n");
                option=getch();
                if(option==27)
                    exit(0);
                while(1)
                {
                    system("cls");
                        game_display(str);
                        if(count==9)
                        {
                            printf("Game is DRAW.\n\n");
                            while(1)
                            {
                                printf("Press ENTER to play again or Press ESC to exit the game.");
                                option=getch();
                                if(option==27)
                                    exit(0);
                                else if(option==13)
                                break;
                            }
                            break;
                        }
                        if((str[0]==str[1]&&str[0]==str[2])||(str[0]==str[3]&&str[0]==str[6])||(str[0]==str[4]&&str[0]==str[8])||(str[1]==str[4]&&str[1]==str[7])||
                           (str[2]==str[5]&&str[2]==str[8])||(str[2]==str[4]&&str[2]==str[6])||(str[3]==str[4]&&str[3]==str[5])||(str[6]==str[7]&&str[6]==str[8]))
                        {
                            if((str[0]=='X'&&str[1]=='X'&&str[2]=='X')||(str[0]=='X'&&str[4]=='X'&&str[8]=='X')||(str[0]=='X'&&str[3]=='X'&&str[6]=='X')||(str[3]=='X'&&str[4]=='X'&&str[5]=='X')||
                               (str[6]=='X'&&str[7]=='X'&&str[8]=='X')||(str[1]=='X'&&str[4]=='X'&&str[7]=='X')||(str[2]=='X'&&str[5]=='X'&&str[8]=='X')||(str[2]=='X'&&str[4]=='X'&&str[6]=='X'))
                                printf("\"%s\" won the game.\n\n",name1);
                            else
                                printf("\"%s\" won the game.\n\n",name2);
                            while(1)
                            {
                                printf("Press ENTER to play again or Press ESC to exit the game.");
                                option=getch();
                                if(option==27)
                                    exit(0);
                                else if(option==13)
                                break;
                            }
                            break;
                        }
                        if(count%2)
                            printf("           Player 2 turn.\n\n");
                        else
                            printf("           Player 1 turn.\n\n");
                        esc=getch();
                        if(esc==27)
                            exit(0);
                        gameplay(str, &count, esc);
                }

                break;
            case 52:
                exit(0);
        }
    }

    return 0;
}

void display_tictactoe()
{
    printf("Press ESC to exit.                              *=*=*=*=*=*=*=*=*=*\n");
    printf("                                                    TIC TAC TOE\n");
    printf("                                                *=*=*=*=*=*=*=*=*=*\n\n\n");
}

void entername(char x[], int n)                  //function defined to enter player's name.
{
    while(1)
    {
        fgets(x, n, stdin);
        if(x[1]!=0)
            break;
        else
            printf("\nYou must enter\nenter the name : ");
    }
    x[strlen(x)-1]='\0';
}


void display_tictactoe();
void game_display(char *str)
{
    int i, j, x=0;
    system("cls");
    display_tictactoe();
    for(i=1; i<16; i++)
    {
        for(j=1; j<40; j++)
        {
            if(j==20 || j==30)
                printf("|");
            else if((i==5 || i==10) && j>9)
                printf("_");
            else if((i==3 || i==8 || i==13)&&(j==15 || j==25 || j==35))
            {
                printf("%c",str[x]);
                x++;
            }
            else
                printf(" ");
        }
        printf("\n");
    }
}

void gameplay(char *str, int *i, char box)
{
    switch(box)
    {
        case 49:
            if(str[0]=='1')
            {
                str[0]=' ';
                game_display(str);
                getch();
                if(*i%2)
                    str[0]='O';
                else
                    str[0]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 50:
            if(str[1]=='2')
            {
                str[1]=' ';
                game_display(str);
                box=getch();
                if(*i%2)
                    str[1]='O';
                else
                    str[1]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 51:
            if(str[2]=='3')
            {
                str[2]=' ';
                game_display(str);
                box=getch();
                if(*i%2)
                    str[2]='O';
                else
                    str[2]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 52:
            if(str[3]=='4')
            {
                str[3]=' ';
                game_display(str);
                box=getch();
                if(*i%2)
                    str[3]='O';
                else
                    str[3]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 53:
            if(str[4]=='5')
            {
                str[4]=' ';
                game_display(str);
                box=getch();
                if(*i%2)
                    str[4]='O';
                else
                    str[4]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 54:
            if(str[5]=='6')
            {
                str[5]=' ';
                game_display(str);
                box=getch();
                if(*i%2)
                    str[5]='O';
                else
                    str[5]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 55:
            if(str[6]=='7')
            {
                str[6]=' ';
                game_display(str);
                box=getch();
                if(*i%2)
                    str[6]='O';
                else
                    str[6]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 56:
            if(str[7]=='8')
            {
                str[7]=' ';
                game_display(str);
                box=getch();
                if(*i%2)
                    str[7]='O';
                else
                    str[7]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 57:
            if(str[8]=='9')
            {
                str[8]=' ';
                game_display(str);
                box=getch();
                if(*i%2)
                    str[8]='O';
                else
                    str[8]='X';
                *i+=1;
                break;
            }
            else
                break;

    }
}

void smart_computer(char *str, int *i, char box)
{
   switch(box)
    {
        case 49:
            if(str[0]=='1')
            {
                str[0]=' ';
                game_display(str);
                getch();
                if(*i%2);
                else
                    str[0]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 50:
            if(str[1]=='2')
            {
                str[1]=' ';
                game_display(str);
                box=getch();
                if(*i%2);
                else
                    str[1]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 51:
            if(str[2]=='3')
            {
                str[2]=' ';
                game_display(str);
                box=getch();
                if(*i%2);
                else
                    str[2]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 52:
            if(str[3]=='4')
            {
                str[3]=' ';
                game_display(str);
                box=getch();
                if(*i%2);
                else
                    str[3]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 53:
            if(str[4]=='5')
            {
                str[4]=' ';
                game_display(str);
                box=getch();
                if(*i%2);
                else
                    str[4]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 54:
            if(str[5]=='6')
            {
                str[5]=' ';
                game_display(str);
                box=getch();
                if(*i%2);
                else
                    str[5]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 55:
            if(str[6]=='7')
            {
                str[6]=' ';
                game_display(str);
                box=getch();
                if(*i%2);
                else
                    str[6]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 56:
            if(str[7]=='8')
            {
                str[7]=' ';
                game_display(str);
                box=getch();
                if(*i%2);
                else
                    str[7]='X';
                *i+=1;
                break;
            }
            else
                break;
        case 57:
            if(str[8]=='9')
            {
                str[8]=' ';
                game_display(str);
                box=getch();
                if(*i%2);
                else
                    str[8]='X';
                *i+=1;
                break;
            }
            else
                break;

    }
}


void rules()
{
    printf("                      RULES\n");
    printf("                    =========\n\n");
    printf("1: Everybody knows the rule how to play Tic Tac Toe.\n");
    printf("2: To select the desired box press the NUMBER displayed \n   on that particular box you want to select.");

}

void compare(char str[])
{
    if((str[2]=='3' && str[1]=='X'&& str[0]=='X') || (str[2]=='3'&&str[4]=='X'&&str[6]=='X') || (str[2]=='3'&&str[5]=='X'&&str[8]=='X'))
        str[2]='O';
    else if((str[6]=='7'&&str[3]=='X'&&str[0]=='X') || (str[6]=='7'&&str[2]=='X'&&str[4]=='X') || (str[6]=='7'&&str[7]=='X'&&str[8]=='X'))
        str[6]='O';
    else if((str[1]=='2'&&str[2]=='X'&&str[0]=='X') || (str[1]=='2'&&str[4]=='X'&&str[7]=='X'))
        str[1]='O';
    else if((str[0]=='1'&&str[1]=='X'&&str[2]=='X') || (str[0]=='1'&&str[4]=='X'&&str[8]=='X') || (str[0]=='1'&&str[3]=='X'&&str[6]=='X'))
        str[0]='O';
    else if((str[3]=='4'&&str[0]=='X'&&str[6]=='X') || (str[3]=='4'&&str[4]=='X'&&str[5]=='X'))
        str[3]='O';
    else if((str[5]=='6'&&str[2]=='X'&&str[8]=='X') || (str[5]=='6'&&str[3]=='X'&&str[4]=='X'))
        str[5]='O';
    else if((str[7]=='8'&&str[1]=='X'&&str[4]=='X') || (str[7]=='8'&&str[6]=='X'&&str[8]=='X'))
        str[7]='O';
    else if((str[8]=='9'&&str[0]=='X'&&str[4]=='X') || (str[8]=='9'&&str[2]=='X'&&str[5]=='X') || (str[8]=='9'&&str[6]=='X'&&str[7]=='X'))
        str[8]='O';
    else if((str[4]=='5'&&str[0]=='X'&&str[8]=='X')||(str[4]=='5'&&str[1]=='X'&&str[7]=='X')||(str[4]=='5'&&str[2]=='X'&&str[6]=='X')||(str[4]=='5'&&str[3]=='X'&&str[5]=='x'))
        str[4]='O';
    else
    {
        while(1)
        {
            int a= (rand()%10);
            if(a==9)
                a-=1;
            if(str[a]!='X' && a!=0)
            {
                str[a]='O';
                break;
            }
        }
    }
}

void compare2(char str[])
{
    if((str[2]=='3' && str[1]=='X'&& str[0]=='X') || (str[2]=='3'&&str[4]=='X'&&str[6]=='X') || (str[2]=='3'&&str[5]=='X'&&str[8]=='X'))
        str[2]='O';
    else if((str[6]=='7'&&str[3]=='X'&&str[0]=='X') || (str[6]=='7'&&str[2]=='X'&&str[4]=='X') || (str[6]=='7'&&str[7]=='X'&&str[8]=='X'))
        str[6]='O';
    else if((str[1]=='2'&&str[2]=='X'&&str[0]=='X') || (str[1]=='2'&&str[4]=='X'&&str[7]=='X'))
        str[1]='O';
    else if((str[0]=='1'&&str[1]=='X'&&str[2]=='X') || (str[0]=='1'&&str[4]=='X'&&str[8]=='X') || (str[0]=='1'&&str[3]=='X'&&str[6]=='X'))
        str[0]='O';
    else if((str[3]=='4'&&str[0]=='X'&&str[6]=='X') || (str[3]=='4'&&str[4]=='X'&&str[5]=='X'))
        str[3]='O';
    else if((str[5]=='6'&&str[2]=='X'&&str[8]=='X') || (str[5]=='6'&&str[3]=='X'&&str[4]=='X'))
        str[5]='O';
    else if((str[7]=='8'&&str[1]=='X'&&str[4]=='X') || (str[7]=='8'&&str[6]=='X'&&str[8]=='X'))
        str[7]='O';
    else if((str[8]=='9'&&str[0]=='X'&&str[4]=='X') || (str[8]=='9'&&str[2]=='X'&&str[5]=='X') || (str[8]=='9'&&str[6]=='X'&&str[7]=='X'))
        str[8]='O';
    else if((str[4]=='5'&&str[0]=='X'&&str[8]=='X')||(str[4]=='5'&&str[1]=='X'&&str[7]=='X')||(str[4]=='5'&&str[2]=='X'&&str[6]=='X')||(str[4]=='5'&&str[3]=='X'&&str[5]=='x'))
        str[4]='O';

}
