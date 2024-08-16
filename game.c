// project for puzzle game.

#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>

void entername(char [], int);
void matrix(int []);
void game(int, int [], int[], char []);
void random(int [], int, int);
int main()
{
    srand(time(NULL));
    int a=16, b=16, x, ary1[16], ary[16]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 32};
    char name[20];
    printf("Enter player's name: ");
    entername(name, 20);                                //function call to enter player's name.(line no. 235)
    while(1)
    {
        system("cls");                                 // to clear the screen.
        printf("                            NUMBER PUZZLE\n");
        printf("                           ---------------\n\n");
        printf("                          Rules of the Game\n\n");
        printf("1. You can move only one step at a time\n   Left Right Up or Down using arrow keys.\n");
        printf("2. You can make your move to empty position only.\n");
        printf("3. With each valid move the given move will decrease by 1.\n");
        printf("4. You can quit the game any time you like.\n");
        printf("5. You get 250 chances to solve the puzzle.\n");
        printf("6. The winning situation is below.\n\n");
        printf(" WINNING SITUATION\n");
        matrix(ary);                                   //function call to print the game matrix, (line no. 56).
        printf("\n");
        random(ary1, a,b);                             //function call to generate random numbers, (line no. 211)
        printf("Press ENTER/y to start the Game.\nor ESC/n to exit.\n");
        printf("\n\n\n\n\nProgramed by AWNISH.");
        while(1)
        {
            x=getch();
            if(x==27 || x==110 || x==13 || x==121)
                break;
        }
        if(x==27)
            x+=83;
        else if(x==13)
            x+=108;
        game(x, ary, ary1, name);                    //function call to display game array passing character, display array game array and name string of player.(line 144)
    }

    getch();
    return 0;
}

void matrix(int a[])                                 //function made to print the game matrix.
{
    int i, j, k=5, x=0;
    for(i=0; i<6; i++)
    {
        for(j=0; j<21; j++)
        {
            if(i==0 || i==5)
                printf("-");
            else if(i>0 && (j==0 || j%k==0))
                printf("|");
            else if(i>0 && (j==1 || j%6==0))
            {
                if(a[x]<=9)
                {
                    printf(" %d  ",a[x]);
                    x++;
                }
                else
                {
                    if(a[x]==32)
                    {
                        printf("    ");
                        x++;
                    }
                    else
                    {
                        printf("%d  ",a[x]);
                        x++;
                    }
                }
            }
        }
        printf("\n");
    }
}



void move(int z[], int a)                            //function made to move the numbers in game
{
    int i, j;
    for(i=0; i<16; i++)
    {
        if(z[i]==32)
            break;
    }
    if(a==80 && i-4>=0)
    {
        j=z[i];
        z[i]=z[i-4];
        z[i-4]=j;
    }
    else if(a==72 && i+4<=15)
    {
        j=z[i];
        z[i]=z[i+4];
        z[i+4]=j;
    }
    else if(a==77 && i-1>=0 && z[4]!=32 && z[8]!=32 && z[12]!=32)
    {
            j=z[i];
            z[i]=z[i-1];
            z[i-1]=j;
    }
    else if(a==75 && i+1<=15 && z[3]!=32 && z[7]!=32 && z[11]!=32)
    {
        {
            j=z[i];
            z[i]=z[i+1];
            z[i+1]=j;
        }
    }

}

int compare( int a[], int b[])                                //function to compare array.
{
    int i;
    for(i=0; i<16; i++)
        if(a[i]!=b[i])
            break;
    return i;
}


int compare( int [], int []);
void move(int [], int);
void game(int x, int j[], int b[], char n[])                  //function made for game display.
{
    int a, i=0, y;
    switch(x)
        {
            case 110:
                exit(0);
                break;
            case 121:
                system("cls");
                printf("Press ESC to exit the game.\n");
                printf("Use UP DOWN LEFT or RIGHT Keys to move.\n");
                printf("You get 250 chances to solve the puzzle.\n\n");
                matrix(b);                                   //function call to print the game matrix.(line 56)
                printf("Count: %d\n",i);
                while(i<250)
                {
                    getch();
                    y=getch();
                    switch(y)          //y is equal to key released.
                    {
                        case 72:
                            move(b,y);                     //function call to move number.(line 95)
                            printf("up\n");
                            break;
                        case 80:
                            move(b,y);                    //function call to move number.(line 95)
                            printf("down\n");
                            break;
                        case 75:
                            move(b,y);                    //function call to move number.(line 95)
                            printf("left\n");
                            break;
                        case 77:
                            move(b,y);                    //function call to move number.(line 95)
                            printf("right\n");
                            break;
                        case 27:
                            exit(0);

                    }
                    if(y==72 || y==80 || y==75 || y==77)
                        i++;
                    system("cls");
                    printf("Press ESC to exit the game.\n");
                    printf("Use UP DOWN LEFT or RIGHT Keys to move.\n");
                    printf("You get 250 chances to solve the puzzle.\n\n");
                    matrix(b);                                //function call to print the game matrix.
                    printf("Count: %d\n",i);
                    a=compare(j, b);                          //function call for comparing.(line 132)
                    if(a==16)
                    {
                        printf("CONGRATULATION %s!!! You have won in just %d moves.",n, i);
                        getch();
                        break;
                    }
                    if(i==250)
                    {
                        printf("SORRY!!! %s, You have lost the game You ran out of moves.",n);
                        getch();
                    }
                }

        }
}


void random(int a[], int x, int y)                      //function made to generate random number for the matrix.
{
    int i, j, k, c[16];
    a[0]=(rand()%16)+1;
    for(i=0; i<16; i++)
    {
        c[i]= (rand()%16)+1;
        for(j=0, k=0; j<=i; j++)
        {
            if(c[i]!=a[j])
                k++;
        }
        if(k==i+1)
            a[i]=c[i];
        else
            i--;

    }
    for(i=0; i<16; i++)
        if(a[i]==16)
            a[i]=32;

}

void entername(char x[], int n)                  //function made to enter player's name.
{
    while(1)
    {
        fgets(x, n, stdin);
        if(x[1]!=0)
            break;
        else
            printf("Enter player's name: ");
    }
    x[strlen(x)-1]='\0';
}
