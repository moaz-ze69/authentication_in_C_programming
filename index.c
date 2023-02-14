
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAB 9
#define BCSPC 8
#define ENTER 13
void Username();
void MaskPass();
void MaskLogin(char[]);
void Title();
void Log_In();
void Sign_Up();
void Terminator();
void Defaulter();

int main()
{

    int a;
    system("color 03");
    Title();
    scanf("%d", &a);
    system("CLS");

    switch (a)
    {
    case 1:
        Log_In();
        break;

    case 2:

        Sign_Up();
        break;
    case 3:
        Terminator();
        break;

    default:
        Defaulter();
    }
}

void Title()
{
    printf("\t\t\t\t\t\t\t<<<<<***************************************>>>>>\n\n\t\t\t\t\t\t\t______________________________________________\n");
    printf("\t\t\t\t\t\t\t|\t\tEnter Your Choice !!!\t\t|\n\t\t\t\t\t\t\t|\t\tEnter 1 For Log-IN\t\t|\n\t\t\t\t\t\t\t|\t\tEnter 2 For Sign-UP\t\t|\n\t\t\t\t\t\t\t|\t\tEnter 3 For Exit\t\t|\n");
    printf("\t\t\t\t\t\t\t----------------------------------------------------\n");
}

void Log_In()
{
    system("color F0");
    int k = 0;
    char usern[20], passw[20], username[20], password[20];
    FILE *filecal;
    int flag = 0;
    filecal = fopen("data.txt", "r");
    if (filecal == NULL)
    {
        printf("\n\t-------File Does Not Exist-------\n\n");
        main();
    }

    printf("Enter Your User-Name : \n");
    fflush(stdin);
    gets(usern);
    fscanf(filecal, "%s", username);
    int flag1 = 1;
    while (!feof(filecal) && flag1 == 1)
    {
        if (strcmp(usern, username) == 0)
        {
            printf("\nValid User-Name\n\n");
            fscanf(filecal, "%s", password);
            flag1 = 0;
            flag = 1;
        }
        if (flag1 == 1)
        {
            fscanf(filecal, "%s", username);
        }
    }

    if (flag == 0)
    {

        printf("\nInvalid User!!!\n");
        main();
    }
    else
    {
        printf("Enter Password : ");
    B:
        fflush(stdin);
        // while(!feof(filecal))
        // fscanf(filecal, "%s", password);
        MaskLogin(passw);
    C:
        if (k <= 2)
        {
            if (strcmp(passw, password) == 0)
            {
                printf("\n\n**********************\n");
                printf("*Login Successfull!!!*\n");
                printf("**********************\n");
                main();
            }
            else
            {
                k++;
                if (k < 3)
                {
                    printf("\n\nIncorrect Password!!!\n\nRe-Enter Password : \n\n");
                }
                if (k == 2)
                {
                    printf("\nIt's Your Last Attempt!!!\n");
                    system("color 48");
                }
                if (k == 3)
                {
                    printf("here");
                    goto C;
                }

                goto B;
            }
        }
        else
            printf("\n\n\a\aIllegal Attempts!!!\nGet Ready To Be Investigated...");
        return;
    }
    flag = 0;
    fclose(filecal);
    main();
}

void Sign_Up()
{
    system("color B1");
    char username[20], password[20];
    FILE *filecal;
    filecal = fopen("data.txt", "a");
    if (filecal == NULL)
    {
        printf("File Does Not Exist");
        return;
    }
    printf("\nEnter New User-Name :\n");
    // Username(username);
    fflush(stdin);
    gets(username);
    fprintf(filecal, "%s\n", username);
    printf("\nEnter New Password :\n");
    fflush(stdin);
    MaskPass(password);
    fprintf(filecal, "%s\n", password);

    fclose(filecal);
    printf("\n\t^<---Account Successfully Created!!!--->^\n");
    main();
}

void Defaulter()
{
    system("color B4");
    int a;
    printf("\nEnter 3 To Exit And Press Any Other Number To Continue...!!!\n");
    scanf("%d", &a);
    if (a == 3)
        Terminator();
    else
        system("CLS");
    main();
}

void Terminator()
{
    system("CLS");
    system("color 90");
    printf("\n\t\t\t\t\t\t*****Thanks For Using Our Program <3 :)***** \n");
    return;
}

void MaskPass(char pass[])

{
    system("color f1");
    int i = 0;
    char ch;
    printf("\nAlert!!! Password Must Be A Combination Of Alpha-Numeric Keys\nHigh Alert!!! Password Being Encrypted\n\n");

    while (1)
    {
        ch = getch();
        if (ch == ENTER)
        {
            pass[i] = '\0';
            break;
        }

        else if (ch == TAB)
        {
            continue;
        }
        else
        {
        C:
            if (isalnum(ch))
            {
                ch = toupper(ch);
                pass[i] = ch;
                i++;
                printf("*");
            }
            while ((ch = getch()) != 13)
            {
                if (ch == 8)
                {
                    i--;
                    printf("\b \b");
                    goto C;
                }
                if (isalnum(ch))
                {
                    ch = toupper(ch);
                    pass[i] = ch;
                    i++;
                    printf("*");
                }
                else
                {
                    printf("Consider Alert!!!\n");
                    continue;
                }
                pass[i] = '\0';
            }
        }
    }
}

void MaskLogin(char pass1[])
{
    int i = 0;
    char ch;
C:
    while ((ch = getch()) != 13)
    {
        if (ch == 8)
        {
            i--;
            printf("\b \b");
            goto C;
        }

        pass1[i++] = ch;
        printf("*");
    }
    pass1[i] = '\0';
}
