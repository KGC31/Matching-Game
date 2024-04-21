#include"Board.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define LIGHT_GREEN 2
#define WHITE 7
#define LIGHT_BLUE 9
#define LIGHT_RED 12
#define LIGHT_YELLOW 14 


int countx = 1; int county = 1; int count_choice = 1;

void Set_Window_Size(SHORT width, SHORT height) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;

    SetConsoleScreenBufferSize(hStdout, NewSize);
}

void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = CursorVisibility;

    SetConsoleCursorInfo(handle, &ConCurInf);
}

void DisableSelection()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

    SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}

void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Gotoxy(short x, short y) {
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x, y };
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void Set_Color(int color) {
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

bool check(string** array, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (array[i][j] != " ")
                return false;
        }

    return true;
}

void read(string** a, int n, int m, ifstream& fin)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            fin >> a[i][j];
            if (a[i][j] == "*")
                a[i][j] = " ";
        }
}

void generate(string**& array, int& n, int& m)
{
    ifstream fin("input.txt");
    fin >> n >> m;
    array = new string * [n];
    for (int i = 0; i < n; i++)
        array[i] = new string[m];
    read(array, n, m, fin);
    fin.close();
}

void choice(string**& array, int& n1, int& n2, int& m1, int& m2, int n, int m)
{
    if (Matching(array, n1, n2, m1, m2, n, m) == true)
    {
        array[n1][m1] = " ";
        array[n2][m2] = " ";
        Beep(2000, 500);
    }
    n1 = 0; n2 = 0; m1 = 0; m2 = 0;
    count_choice = 1;
}

void dele(string** array, int n)
{
    for (int i = 0; i < n; i++)
        delete[]array[i];
    delete[] array;
}

int Menu()
{
    color(5);
    Gotoxy(10, 5);
    cout << " _______         __         __     __                                              " << endl;
    Gotoxy(10, 6);
    cout << "|   |   |.---.-.|  |_.----.|  |--.|__|.-----.-----.    .-----.---.-.--------.-----." << endl;
    Gotoxy(10, 7);
    cout << "|       ||  _  ||   _|  __||     ||  ||     |  _  |    |  _  |  _  |        |  -__|" << endl;
    Gotoxy(10, 8);
    cout << "|__|_|__||___._||____|____||__|__||__||__|__|___  |    |___  |___._|__|__|__|_____|" << endl;
    Gotoxy(10, 9);
    cout << "                                            |_____|    |_____|                     " << endl;

    Gotoxy(38, 13);
    cout << "-------------------------";
    Gotoxy(38, 14);
    cout << "|";
    Gotoxy(62, 14);
    cout << "|";
    Gotoxy(38, 15);
    cout << "|";
    Gotoxy(62, 15);
    cout << "|";
    Gotoxy(38, 16);
    cout << "|";
    Gotoxy(62, 16);
    cout << "|";
    Gotoxy(38, 17);
    cout << "|";
    Gotoxy(62, 17);
    cout << "|";
    Gotoxy(38, 18);
    cout << "|";
    Gotoxy(62, 18);
    cout << "|";
    Gotoxy(38, 19);
    cout << "|";
    Gotoxy(62, 19);
    cout << "|";
    Gotoxy(38, 20);
    cout << "-------------------------";

    int Set[] = {LIGHT_BLUE, WHITE, WHITE, WHITE};
    int counter = 1;
    char key;
    for (int i = 0; ; )
    {
        Gotoxy(46, 15);
        color(Set[0]);
        cout << "Play game";

        Gotoxy(45, 16);
        color(Set[1]);
        cout << "How to play";

        Gotoxy(45, 17);
        color(Set[2]);
        cout << "Leaderboard";

        Gotoxy(48, 18);
        color(Set[3]);
        cout << "Exit";


        key = getch();

        if (key == UP && counter >= 2 && counter <= 4)
        {
            counter--;
        }

        if (key == DOWN && counter >= 1 && counter <= 3)
        {
            counter++;
        }

        Set[0] = LIGHT_BLUE;
        Set[1] = WHITE;
        Set[2] = WHITE;
        Set[3] = WHITE;

        if (counter == 1)
            Set[0] = LIGHT_BLUE;
        if (counter != 1)
            Set[0] = WHITE;
        if (counter == 2)
            Set[1] = LIGHT_YELLOW;
        if (counter == 3)
            Set[2] = LIGHT_GREEN;
        if (counter == 4)
            Set[3] = LIGHT_RED;

        if (key == '\r') //Enter key (choose)
        {
            if (counter == 1)
            {
                system("cls");
                return 1;
            }
            if (counter == 2)
            {
                system("cls");
                return 2;
            }
            if (counter == 3)
            {
                system("cls");
                return 3;
            }
            if (counter == 4)
            {
                system("cls");
                return 4;
            }
        }
    }
    return 0;
}

int End_menu()
{
    system("cls");
    int Set[] = { LIGHT_RED, WHITE, WHITE };
    int counter = 1;
    char key;
    for (int i = 0; ; )
    {
        Gotoxy(45, 15);
        color(Set[0]);
        cout << "Play again";

        Gotoxy(45, 16);
        color(Set[1]);
        cout << "Main menu";

        Gotoxy(45, 17);
        color(Set[2]);
        cout << "Exit";

        key = getch();

        if (key == UP && counter >= 2 && counter <= 3)
        {
            counter--;
        }

        if (key == DOWN && counter >= 1 && counter <= 2)
        {
            counter++;
        }


        Set[0] = LIGHT_RED;
        Set[1] = WHITE;

        if (counter == 1)
            Set[0] = LIGHT_RED;
        if (counter != 1)
            Set[0] = WHITE;
        if (counter == 2)
            Set[1] = LIGHT_RED;
        if (counter == 3)
            Set[2] == LIGHT_RED;

        if (key == '\r') //Enter key (choose)
        {
            if (counter == 1)
            {
                system("cls");
                return 1;
            }
            if (counter == 2)
            {
                system("cls");
                return 5;
            }
            if (counter == 3)
            {
                system("cls");
                return 4;
            }

        }
    }
    return 0;
}

void Animation_Loading()
{
    int x, y;
    x = 10, y = 10;
    Gotoxy(x, y);
    Set_Color(LIGHT_BLUE);
    cout << char(218);
    for (int i = 1; i <= 80; i++) cout << char(196);
    cout << char(191);
    Gotoxy(x, y + 1);
    cout << char(179);
    for (int i = 1; i <= 80; i++) cout << " ";
    cout << char(179);
    Gotoxy(x, y + 2);
    cout << char(192);
    for (int i = 1; i <= 80; i++) cout << char(196);
    cout << char(217);
    Set_Color(WHITE);

    Set_Color(LIGHT_YELLOW);
    Gotoxy(x + 1, y + 3);
    for (int i = 1; i <= 80; i++)
    {
        if (i == 1)
        {
            Gotoxy(x + 86, y + 1);
            cout << "%";
            Gotoxy(x + 31, y + 3);
            cout << ". . . LOADING . . .";
            Gotoxy(x + 1, y + 1);
        }
        cout << char(219);
        Gotoxy(x + 83, y + 1);
        cout << i + 20;
        Gotoxy(i + x + 1, y + 1);
        if (i + 20 == 100)
        {
            Gotoxy(x + 31, y + 3);
            Set_Color(LIGHT_RED);
            cout << ". . . COMPLETE . . .";
            Set_Color(WHITE);
        }
        Sleep(40);
    }
    Gotoxy(x + 87, y + 1);
    Sleep(3000);
    system("cls");
}

void Cursor(string** array, int n, int m, int& n1, int& n2, int& m1, int& m2, int& x, int& y)
{
    char key;
    key = getch();
    if (key == UP || key == 87 || key == 119)
    {
        if(county - 1 > 0)
        {
            y -= 5;
            county -= 1;
        }
        
    }

    if (key == DOWN || key == 83 || key == 115)
    {
        if(county  < n - 2)
        {
            y += 5;
            county += 1;
        }
    }

    if (key == RIGHT || key == 68 || key == 100)
    {
        if(countx < m - 2)
        {
            x += 9;
            countx += 1;
        }
        
    }

    if (key == LEFT || key == 65 || key == 97)
    {
        if(countx - 1 > 0)
        {
            x -= 9;
            countx -= 1;
        }
        
    }

    if (key == 13)
    {
        if (count_choice == 1)
        {
            n1 = county;
            m1 = countx;
            count_choice = 2;
        }
        else
        {
            if (count_choice == 2)
            {
                n2 = county;
                m2 = countx;
                choice(array, n1, n2, m1, m2, n, m);
            }
        }
    }
}

void board(string** array, int n, int m, int n1, int n2, int m1, int m2)
{
    system("cls");
    int i = 0;

    while (i < n)
    {
        for (int j = 0; j < m; j++)
        {
            if (array[i][j] == " ")
                cout << "         ";
            else
            {
                if ((i == county && j == countx) || (i == n1 && j == m1) || (i == n2 && j == m2))
                {
                    Set_Color(LIGHT_BLUE);
                    cout << " ------- ";
                }
                else {
                    Set_Color(WHITE);
                    cout << " ------- ";
                }
            }
        } cout << endl;

        for (int j = 0; j < m; j++)
        {
            if (array[i][j] == " ")
                cout << "         ";
            else
            {
                if ((i == county && j == countx) || (i == n1 && j == m1) || (i == n2 && j == m2))
                {
                    Set_Color(LIGHT_BLUE);
                    cout << "|";
                    Set_Color(LIGHT_YELLOW);
                    cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219);
                    Set_Color(LIGHT_BLUE);
                    cout << "|";
                }
                else
                {
                    Set_Color(WHITE);
                    cout << "|       |";
                }
            }
        } cout << endl;

        for (int j = 0; j < m; j++)
        {
            if (array[i][j] == " ")
                cout << "         ";
            else
            {
                if ((i == county && j == countx) || (i == n1 && j == m1) || (i == n2 && j == m2))
                {
                    Set_Color(LIGHT_BLUE);
                    cout << "|";
                    Set_Color(LIGHT_YELLOW);
                    cout << char(219) << char(219) << " ";
                    Set_Color(WHITE);
                    cout << array[i][j];
                    Set_Color(LIGHT_YELLOW);
                    cout << " " << char(219) << char(219);
                    Set_Color(LIGHT_BLUE);
                    cout << "|";
                }
                else
                {
                    Set_Color(WHITE);
                    cout << "|   " << array[i][j] << "   |";
                }
            }
        } cout << endl;

        for (int j = 0; j < m; j++)
        {
            if (array[i][j] == " ")
                cout << "         ";
            else
            {
                if ((i == county && j == countx) || (i == n1 && j == m1) || (i == n2 && j == m2))
                {
                    Set_Color(LIGHT_BLUE);
                    cout << "|";
                    Set_Color(LIGHT_YELLOW);
                    cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219);
                    Set_Color(LIGHT_BLUE);
                    cout << "|";
                }
                else
                {
                    Set_Color(WHITE);
                    cout << "|       |";
                }
            }
        } cout << endl;

        for (int j = 0; j < m; j++)
        {
            if (array[i][j] == " ")
                cout << "         ";
            else
            {
                if ((i == county && j == countx) || (i == n1 && j == m1) || (i == n2 && j == m2))
                {
                    Set_Color(LIGHT_BLUE);
                    cout << " ------- ";
                }
                else {
                    Set_Color(WHITE);
                    cout << " ------- ";
                }
            }
        }cout << endl;

        i++;
    }
}

void boardview()
{
    Set_Window_Size(104, 32);
    SetScreenBufferSize(104, 32);
    DisableResizeWindow();
    ShowScrollbar(0);
    ShowCur(0);
    DisableSelection();
    DisableCtrButton(0, 0, 1);
    SetConsoleTitle(L"Pikachu");
    string** array;
    int n, m, n1 = 0, n2 = 0, m1 = 0, m2 = 0;
    int k = Menu();
    int x = 13; int y = 7;
    if (k == 1)
    {
        for (int i = 0; ; )
        {
            ShowCur(1);
            Animation_Loading();
            clock_t time;
            time = clock();
            generate(array, n, m);
            board(array, n, m, n1, n2, m1, m2);
            while (check(array, n, m) != true)
            {
                Gotoxy(x, y);
                Cursor(array, n, m, n1, n2, m1, m2, x, y);
                board(array, n, m, n1, n2, m1, m2);
            }
            time = clock() - time;
            dele(array, n);
            point number;
            string t;
            cout << "Enter your name:";
            cin >> t;
            number.name = t;
            number.num = (float)time / CLOCKS_PER_SEC;
            write_file("time.txt", number);
            cout << "Time complete: " << (float)time / CLOCKS_PER_SEC << " seconds" << endl;
            system("pause");
            k = End_menu();
            if (k == 5)
            {
                k = Menu();
                if (k != 1)
                    break;
            }
            if (k == 4)
            {
                exit(0);
            }
        }
    }
    while (k == 2) {

        howtoplay();
    }
    while (k == 3)
    {
        printleaderboard();
    }
    if (k == 4)
    {
        exit(0);
    }
}

void howtoplay()
{
    color(LIGHT_YELLOW);
    system("cls");
    Gotoxy(15, 0);
    cout << " _______                      __                     __              " << endl;
    Gotoxy(15, 1);
    cout << "|   |   |.-----.--.--.--.    |  |_.-----.    .-----.|  |.---.-.--.--." << endl;
    Gotoxy(15, 2);
    cout << "|       ||  _  |  |  |  |    |   _|  _  |    |  _  ||  ||  _  |  |  |" << endl;
    Gotoxy(15, 3);
    cout << "|___|___||_____|________|    |____|_____|    |   __||__||___._|___  |" << endl;
    Gotoxy(15, 4);
    cout << "                                             |__|             |_____|" << endl;
    Gotoxy(30, 6);
    cout << "Select Play game to start the game" << endl;
    Gotoxy(30, 7);
    cout << "Use the arrow keys to move to the cell you want to select" << endl;
    Gotoxy(30, 8);
    cout << "To select any cell, press enter when moving to that cell" << endl;
    Gotoxy(30, 9);
    cout << "If you want to see the leaderboard, select Leaderboard" << endl;
    Gotoxy(15, 10);
    cout << "----------------------------------------------------------------------" << endl;
    Gotoxy(50, 12);
    cout << "ABOUT US" << endl;
    Gotoxy(40, 13);
    cout << "18127140 - Thai Hoang Long" << endl;
    Gotoxy(40, 14);
    cout << "21127333 - Nguyen Viet Kim" << endl;
    system("pause");
    system("cls");
    boardview();
}