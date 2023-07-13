#include <iostream>// declaration of cin cout object
#include <cstdlib>
#include <ctime> 
#include <conio.h>
#include <windows.h>// declaration of setcursorpositon position 
using namespace std;
void setcurser(int row, int col);
class Game
{
private:
    char Tic[5][5]; //declare tic array
    int help[5][5];  // declare help array 

public:
    void game_with_SmartComputer();
    int play_game_With_SmartComputer();
    int HumanTurn();
    void pattern();
    int Winner();
    int Drow_game();
    int ComputerTurn();
    void game_with_player();
    int play_game();
    void game_with_EvailComputer();
    int play_game_With_EvailComputer();
    int EvailComputerTurn();
    void row_Winning_Probability();
    void AssingByDefaultValue();
};
void Game::game_with_SmartComputer()
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            Tic[i][j] = ' '; // Assign space  in Tic Array
        }
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            help[i][j] = 2; // Assing 2 in help Array
    }
    play_game_With_SmartComputer();
}
int Game::play_game_With_SmartComputer()
{
    int turn = 1;
    int i, j;
    while (1)
    {
        if (turn)
        {
            HumanTurn(); //  Calling function for HumanTurn

            if (Winner()) // Calling function for check Who is Winner 
            {
                pattern();
                cout << endl << endl << " Congratulatin YOU WON " << endl<< endl;
                cout<<"####################################################################" << " Press Enter ";
                return (1);
            }
            if (Drow_game())
            {
                cout << endl << endl<< " Draw Game " << endl  << "Press Enter ";
                return (1);
            }
            turn = 1 - turn;
        }
        else
        {
            ComputerTurn();
            if (Winner())
            {
                pattern();
                cout << endl << endl << " Computer WON " << endl << endl;
                cout<<"###########################################################################" << " Press Enter ";
                return (0);
            }
            if (Drow_game())
            {
                cout << endl << "Draw Game" << endl << " Press Enter ";
                return (1);
            }
            turn = 1 - turn;
        }
    }
}
int Game::HumanTurn()
{
    int Marking_place;
label1:
    pattern(); // print pattern 
    cout << endl << endl << "Player 1 ,Enter Marking Place (X):";
    cin.ignore();
    cin >> Marking_place;  // Enter the marking palce 
    int i, j, k = 1;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (k == Marking_place)
                goto l1;
            k++;
        }
    }
l1:
    if (Tic[i][j] == 'X' || Tic[i][j] == 'O')
        goto label1;
    Tic[i][j] = 'X';
    help[i][j] = 1;
    pattern();     //   Print the pattern 
    return (0);
}
void Game::pattern()
{
    int i, j;
    system("cls"); // clear the screen
    cout << endl << endl;
    cout << "############################### Tic Tac Toe ###################################" << endl
         << endl;
    cout << "1st Player X" << endl<< "2nd Player O" << endl<< endl;
    for (i = 0; i < 5; i++)
    {
        cout << "\t|\t |\t  |\t   |\t    |\n";
        for (j = 0; j < 5; j++)
        {
            cout << "   " << Tic[i][j] << "    |";
        }
        cout << endl;
        if (i != 4)
            cout << "________|________|________|________|________|" << endl;
        if (i == 4)
            cout << "        |        |        |        |        |" << endl;
    }
    cout << endl
         << endl;
    //setcurser(6, 51);
    cout << "Enter the Marking Place From Giver Number -> "<<endl<<endl;
    //setcurser(7, 56);
    //int set = 8;
    int k = 1;
    for (i = 0; i < 5; i++)
    {
        cout << "\t|\t |\t  |\t   |\t    |\n";
       // setcurser(set, 55);
        //set += 1;
        for (j = 0; j < 5; j++)
        {
            if (k <= 9)
                cout << "    " << k<< "   |";
            else
                cout << "   " << k << "   |";
            k += 1;
        }
        cout << endl;
       // setcurser(set, 57);  // set cursonr position 
       // set += 1;
        if (i != 4)
            cout << "________|________|________|________|________|" << endl;
        if (i == 4)
            cout << "        |        |        |        |        |" << endl;
       // setcurser(set, 57);  // setcursor positon 
      //  set += 1;
    }

    cout << endl
         << "################################################################################";
}

int Game::Winner()
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        if (Tic[i][0] == Tic[i][1] && Tic[i][1] == Tic[i][2] && Tic[i][2] == Tic[i][3] && Tic[i][3] == Tic[i][4])
        {
            if (Tic[i][0] != ' ' && Tic[i][1] != ' ' && Tic[i][2] != ' ' && Tic[i][3] != ' ' && Tic[i][4] != ' ')
                return 1;
        }
    }
    for (i = 0; i < 5; i++)
    {
        if (Tic[0][i] == Tic[1][i] && Tic[1][i] == Tic[2][i] && Tic[2][i] == Tic[3][i] && Tic[3][i] == Tic[4][i])
        {
            if (Tic[0][i] != ' ' && Tic[1][i] != ' ' && Tic[2][i] != ' ' && Tic[3][i] != ' ' && Tic[4][i] != ' ')
                return (1);
        }
    }
    for (i = 0; i < 4; i++)
    {
        if (Tic[i][i] == Tic[i + 1][i + 1] && Tic[i][i] != ' ' && Tic[i + 1][i + 1] != ' ')
        {
            continue; // continue for loop
        }
        else
        {
            break; // break the loop
        }
    }
    if (i == 4)
        return 1;
    for (j = 4; j > 0; j--)
    {
        if (Tic[4 - j][j] == Tic[4 - j + 1][j - 1] && Tic[4 - j][j] != ' ' && Tic[4 - j + 1][j - 1] != ' ')
            continue; // continue for loop
        else
            break; // break the loop
    }
    if (j == 0)
        return (1);
    return (0);
}
int Game::Drow_game()
{
    int count_1 = 0, count_2 = 0, i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (Tic[i][j] == 'X')  // check the place have 'x' of not 
                count_1++;
            if (Tic[i][j] == 'O')
                count_2++;
        }
    }
    if (count_1 == 13 && count_2 == 12 || count_1 == 12 && count_2 == 13)
        return (1);
    else
        return (0);
}
int Game::ComputerTurn()
{
    int i, j, place, k, multi_1 = 1, value = 0;
    cout << endl<< endl<< " player 2 : Computer Turn   :  ";
    srand(time(NULL));
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (help[i][j] == 5)
                goto l1;
        }
    }
    if (i == 5)
    {
    l3:
        place = rand() % 25 + 1;  // Generate the random Number 
        k = 1;
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (k == place)
                    goto l2;
                k++;
            }
        }
    l2:
        if (help[i][j] == 1 || help[i][j] == 5) // Check place have one or not 
            goto l3;
        else
        {
            help[i][j] = 5;
            Tic[i][j] = 'O';
            return (0);
        }
    }

l1:
    for (i = 0; i < 5; i++)
    {
        if (help[i][i] != 1 && help[i][i] != 5)
        {
            help[i][i] = 5;  // replace the help[i][i] positon to 5
            multi_1 = 1;
            for (k = 0; k < 5; k++)
            {
                multi_1 = multi_1 * help[k][k]; 
            }
            if (multi_1 == 3125)
            {
                Tic[i][i] = 'O'; 
                return (0);
            }
            else if (multi_1 == 5)
            {
                Tic[i][i] = 'O';
                return (0);
            }
            else
            {
                help[i][i] = 2; // replace the help[i][i position to 2]
            }
        }
    }
    for (i = 0; i < 5; i++)
    {
        if (help[i][4 - i] != 1 && help[i][4 - i] != 5)
        {
            help[i][4 - i] = 5;
            multi_1 = 1;
            for (k = 0; k < 5; k++)
            {
                multi_1 = multi_1 * help[k][4 - k];
            }
            if (multi_1 == 3125)
            {
                Tic[i][4 - i] = 'O';
                return (0);
            }
            else if (multi_1 == 5)
            {
                Tic[i][4 - i] = 'O';
                return (0);
            }
            else
            {
                help[i][4 - i] = 2;
            }
        }
    }
    // Checking row winning Probability
    int p = -1, q = -1;
    int a = -1, b = -1;
    value = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (help[i][j] != 1 && help[i][j] != 5)
            {
                multi_1 = 1;
                help[i][j] = 5;
                for (k = 0; k < 5; k++)
                {
                    multi_1 = multi_1 * help[i][k];
                }
                if (multi_1 == 3125)
                {
                    Tic[i][j] = 'O';
                    return (0);
                }
                else if (multi_1 == 5)
                {
                    a = i;
                    b = j;
                    help[i][j] = 2;
                }
                else
                {
                    help[i][j] = 2;
                }
            }
        }
    }

    // check_column wise winning probability
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (help[i][j] != 1 && help[i][j] != 5)
            {
                multi_1 = 1;
                help[i][j] = 5; // replace the help[i][j] position to 5
                for (k = 0; k < 5; k++)
                {
                    multi_1 = multi_1 * help[k][j];
                }
                if (multi_1 == 3125)
                {
                    Tic[i][j] = 'O';
                    return (0);
                }
                else if (multi_1 == 5)
                {
                    p = i;
                    q = j;
                    help[i][j] = 2;
                }
                else
                {
                    help[i][j] = 2;
                }
            }
        }
    }
    if (p != -1)
    {
        Tic[p][q] = 'O';
        help[p][q] = 5;
        return (0);
    }
    if (a != -1)
    {
        Tic[a][b] = 'O';
        help[a][b] = 5;
        return (0);
    }

    //     by default kisi pr bhi value assign nhi hui then :
    AssingByDefaultValue(); // call the function 
}
void Game::AssingByDefaultValue()
{
    int place, a, b, k;
A3:
    place = rand() % 25 + 1;
    k = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (k == place)
            {
                a = i;
                b = j;
                goto A2;
            }
            k++;
        }
    }
A2:
    if (help[a][b] == 1 || help[a][b] == 5)
        goto A3;
    else
    {
        help[a][b] = 5;
        Tic[a][b] = 'O';
    }
}
void Game::game_with_player()
{
    int i, j;
    char k = '1';
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            Tic[i][j] = ' ';
            k++;
        }
    }
    // pattern();
    if (play_game())
    {
        pattern();
        cout << endl
             << "Game Draw" << endl
             << "Press Enter ";
    }
}
int Game::play_game()
{
    int flag = 1, Marking_place;
    int i, j;
label1:
    pattern();
    while (1)
    {
        if (flag == 1)
        {
            cout << endl<< endl << "Player 1 - Enter Marking Place(X):";
            cin.ignore();
            cin >> Marking_place;
            int i, j, k = 1;
            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 5; j++)
                {
                    if (k == Marking_place)
                        goto l1;
                    k++;
                }
            }
        l1:
            if (Tic[i][j] == 'O' || Tic[i][j] == 'X')
                goto label1;
            else
                Tic[i][j] = 'X';
            pattern();
            if (Winner())
            {
                pattern();
                cout << endl
                     << endl
                     << "Player 1 WON " << endl
                     << endl;
                cout<<"##################################################################" << " Press Enter ";
                return (0);
            }
            flag = 1 - flag;
        }
        else
        {
        label2:
            pattern();
            cout << endl << endl << "Player  2 - Enter Marking Place(O): ";
            cin.ignore();
            cin >> Marking_place;
            int i, j, k = 1;
            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 5; j++)
                {
                    if (k == Marking_place)
                        goto l2;
                    k++;
                }
            }
        l2:
            if (Tic[i][j] == 'X' || Tic[i][j] == 'O')
                goto label2;
            else
                Tic[i][j] = 'O';
            pattern();
            if (Winner())
            {
                pattern();  // print the pattern 
                cout << endl
                     << endl
                     << "Player 2 Won " << endl
                     << endl;
                cout << "########################################################################"
                     << " Press Enter ";
                return (0);
            }
            flag = 1 - flag;
        }
        if (Drow_game())
            return (1);
    }
}
void Game::game_with_EvailComputer()
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            Tic[i][j] = ' ';
        }
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            help[i][j] = 2;
    }
    play_game_With_EvailComputer();
}
int Game::play_game_With_EvailComputer()
{
    int turn = 1, i, j;
    while (1)
    {
        if (turn)
        {
            HumanTurn();
            if (Winner())
            {
                pattern();
                cout << endl << endl<< " Congratulatin YOU WON " << endl << endl;
                cout<<"####################################################################"<< " Press Enter ";
                return (1);
            }
            if (Drow_game())
            {
                cout << endl
                     << endl
                     << " Draw Game " << endl
                     << " Press Enter";
                return (1);
            }
            turn = 1 - turn;
        }
        else
        {
            EvailComputerTurn();
            if (Winner())
            {
                pattern();
                cout << endl
                     << endl
                     << " Computer WON" << endl
                     << endl;
                cout << "##############################################################################"
                     << " Press Enter ";
                return (0);
            }
            if (Drow_game())
            {
                cout << endl
                     << "Draw Game" << endl
                     << " Press Enter ";
                return (1);
            }
            turn = 1 - turn;
        }
    }
}
int Game::EvailComputerTurn()
{
    int i, j, place, k, multi_1 = 1, mark = 0;
    srand(time(NULL));
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (help[i][j] == 5)
                goto l1;
        }
    }
    if (i == 5)
    {
    l3:
        place = rand() % 25 + 1;
        k = 1;
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (k == place)
                    goto l2;
                k += 1;
            }
        }
    l2:
        if (help[i][j] == 1 || help[i][j] == 5)
            goto l3;
        else
        {
            help[i][j] = 5;
            Tic[i][j] = 'O';
            return (0);
        }
    }

l1:
    int a = -1;
    int b = -1;
    int p = -1;
    int q = -1;
    for (i = 0; i < 5; i++)
    {
        if (help[i][i] != 1 && help[i][i] != 5)
        {
            help[i][i] = 5;
            multi_1 = 1;
            for (k = 0; k < 5; k++)
            {
                // help[i][i]=3;
                multi_1 = multi_1 * help[k][k];
            }
            if (multi_1 == 3125 && mark == 0)
            {
                Tic[i][i] = 'O';
                return (0);
            }
            else if (multi_1 == 5)
            {
                a = i;
                b = i;
                help[i][i] = 2;
            }
            else
            {
                help[i][i] = 2;
            }
        }
    }
    for (i = 0; i < 5; i++)
    {
        if (help[i][4 - i] != 1 && help[i][4 - i] != 5)
        {
            help[i][4 - i] = 5;
            multi_1 = 1;
            for (k = 0; k < 5; k++)
            {
                // help[i][2-i]=3;
                multi_1 = multi_1 * help[k][4 - k];
            }
            if (multi_1 == 3125 && mark == 0)
            {
                Tic[i][4 - i] = 'O';
                return (0);
            }
            else if (multi_1 == 5)
            {
                // Tic[i][2 - i] = 'O';
                p = i;
                q = 4 - i;
                help[i][4 - i] = 2;
            }
            else
            {
                help[i][4 - i] = 2;
            }
        }
    }
    if (a != -1)
    {
        Tic[a][b] = 'O';
        help[a][b] = 5;
        mark = 1;
    }
    if (p != -1)
    {
        Tic[p][q] = 'O';
        help[p][q] = 5;
        mark = 1;
    }
    a = -1;
    b = -1;
    p = -1;
    q = -1;
    // Row wise Checking winning probability
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (help[i][j] != 1 && help[i][j] != 5)
            {
                multi_1 = 1;
                help[i][j] = 5;
                for (k = 0; k < 5; k++)
                {
                    // help[i][j]=3;
                    multi_1 = multi_1 * help[i][k];
                }
                if (multi_1 == 3125 && mark == 0)
                {
                    Tic[i][j] = 'O';
                    return (0);
                }
                else if (multi_1 == 5)
                {
                    // Tic[i][j] = 'O';
                    a = i;
                    b = j;
                    help[i][j] = 2;
                }
                else
                {
                    help[i][j] = 2;
                }
            }
        }
    }
    // Column wise checking winning probability
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (help[i][j] != 1 && help[i][j] != 5)
            {
                multi_1 = 1;
                help[i][j] = 5;
                for (k = 0; k < 5; k++)
                {
                    // help[i][j]=3;
                    multi_1 = multi_1 * help[k][j];
                }
                if (multi_1 == 3125 && mark == 0)
                {
                    Tic[i][j] = 'O';
                    return (0);
                }
                else if (multi_1 == 5)
                {
                    // Tic[i][j] = 'O';
                    p = i;
                    q = j;
                    help[i][j] = 2;
                }
                else
                {
                    help[i][j] = 2;
                }
            }
        }
    }
    if (a != -1)
    {
        Tic[a][b] = 'O';
        help[a][b] = 5;
        mark = 1;
    }
    if (p != -1)
    {
        Tic[p][q] = 'O';
        help[p][q] = 5;
        mark = 1;
    }
    //     by default kisi pr bhi value assign nhi hui then :
    if (mark == 0)
    {
        AssingByDefaultValue();
    }
}
int Menu()
{
    char choice = 0;
    system("cls");
    cout << endl<< "1.WANT TO PLAY WITH PLAYER" << endl;
    cout << "2.WANT TO PLAY WITH SMART COMPUTER" << endl;
    cout << "3.WANT TO PLAY WITH EVAIL COMPUTER" << endl;
    cout << "4.EXIT " << endl << endl;
    cout << "ENTER YOUR CHOICE";
    cin >> choice;
    return (choice - 48);
}
int main()
{
    Game player;
    while (1)
    {
        switch (Menu())
        {
        case 1:
            player.game_with_player();
            break;
        case 2:
            player.game_with_SmartComputer();
            break;
        case 3:
            player.game_with_EvailComputer();
            break;
        case 4:
            exit(0);
        default:
            cout << " Invalid Choice Press Enter ";
        }
        getch();
    }
}

void setcurser(int row, int col)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//The GetStdHandle() function gives us a mechanism for retrieving the standard input,
    int x_position = col;
    int y_position = row;
    COORD screen;
    HANDLE Output = GetStdHandle(STD_OUTPUT_HANDLE);
    screen.X = x_position;
    screen.Y = y_position;
    SetConsoleCursorPosition(Output, screen);
}
