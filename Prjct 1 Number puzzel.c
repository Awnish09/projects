// project for puzzle game.

#include <stdio.h>
#include <stdlib.h>
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
    entername(name, 20);
    while(1)
    {
        system("cls");
        printf("                            NUMBER PUZZLE\n");
        printf("                           ---------------\n\n");
        printf("                          Rules of the Game\n\n");
        printf("1. You can move only one step at a time\n   Left Right Up or Down using keys 4, 6, 8 & 5.\n");
        printf("2. You can make your move to empty position only.\n");
        printf("3. With each valid move the given move will decrease by 1.\n");
        printf("4. You can quit the game any time you like.\n");
        printf("5. You get 250 chances to solve the puzzle.\n");
        printf("6. The winning situation is below.\n\n");
        printf(" WINNING SITUATION\n");
        matrix(ary);
        printf("\n");
        random(ary1, a,b);
        printf("Press ENTER/y to start the Game.\nor ESC/n to exit.\n");
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
        game(x, ary, ary1, name);
    }

    getch();
    return 0;
}

void matrix(int a[])
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



void move(int z[], int a)
{
    int i, j;
    for(i=0; i<16; i++)
    {
        if(z[i]==32)
            break;
    }
    if(a==53 && i-4>=0)
    {
        j=z[i];
        z[i]=z[i-4];
        z[i-4]=j;
    }
    else if(a==56 && i+4<=15)
    {
        j=z[i];
        z[i]=z[i+4];
        z[i+4]=j;
    }
    else if(a==54 && i-1>=0 && z[4]!=32 && z[8]!=32 && z[12]!=32)
    {
            j=z[i];
            z[i]=z[i-1];
            z[i-1]=j;
    }
    else if(a==52 && i+1<=15 && z[3]!=32 && z[7]!=32 && z[11]!=32)
    {
        {
            j=z[i];
            z[i]=z[i+1];
            z[i+1]=j;
        }
    }

}

int compare( int a[], int b[])
{
    int i;
    for(i=0; i<16; i++)
        if(a[i]!=b[i])
            break;
    return i;
}


int compare( int [], int []);
void move(int [], int);
void game(int x, int j[], int b[], char n[])
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
                printf("Use 8 for UP. 5 for DOWN. 4 for LEFT. and 6 for RIGHT.\n");
                printf("You get 250 chances to solve the puzzle.\n\n");
                matrix(b);
                printf("Count: %d\n",i);
                while(i<250)
                {

                    y=getch();
                    fflush(stdin);
                    switch(y)
                    {
                        case 56:
                            move(b,y);
                            printf("up\n");
                            break;
                        case 53:
                            move(b,y);
                            printf("down\n");
                            break;
                        case 52:
                            move(b,y);
                            printf("left\n");
                            break;
                        case 54:
                            move(b,y);
                            printf("right\n");
                            break;
                        case 27:
                            exit(0);

                    }
                    if(y==53 || y==52 || y==54 || y==56)
                        i++;
                    system("cls");
                    printf("Press ESC to exit the game.\n");
                    printf("Use 8 for UP. 5 for DOWN. 4 for LEFT. and 6 for RIGHT.\n");
                    printf("You get 250 chances to solve the puzzle.\n\n");
                    matrix(b);
                    printf("Count: %d\n",i);
                    a=compare(j, b);
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


void random(int a[], int x, int y)
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

void entername(char x[], int n)
{
    fgets(x, n, stdin);
    x[strlen(x)-1]='\0';
}
