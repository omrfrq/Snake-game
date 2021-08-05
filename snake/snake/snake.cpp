// snake.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;

class snake
{
protected:

    bool gameover;
    int x, y, fruitX, fruitY, score;
    int tailX[100], tailY[100];
    int nTail;
    enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirecton dir;

public:

    virtual void setup() = 0;
    virtual void draw() = 0;
    virtual void input() = 0;
    virtual void logic() = 0;
    virtual void scoring(int) = 0;
    virtual int read_score() = 0;
};

class level1 :public snake
{
    int* width;
    int* height;

public:

    level1()
    {
        width = new int;
        height = new int;
        width = 0;
        height = 0;
    }

    level1(level1& c)
    {
        width = new int;
        height = new int;
        width = c.width;
        height = c.width;
    }

    void set_height(int* h)
    {
        height = h;
    }
    int* get_height()
    {
        return height;
    }

    void set_width(int* w)
    {
        width = w;
    }
    int* get_width()
    {
        return width;
    }

    void set_gameover(bool go)
    {
        gameover = go;
    }
    bool get_gameover()
    {
        return gameover;
    }

    void set_score(int s)
    {
        score = s;
    }
    int get_score()
    {
        return score;
    }


    void setup()
    {
        gameover = false;
        dir = STOP;
        x = *width / 2;
        y = *height / 2;
        fruitX = rand() % *width;
        fruitY = rand() % *height;
        score = 0;
    }

    void draw()
    {
        int* h = get_height();
        int* w = get_width();

        system("cls");
        for (int i = 0; i < *w + 2; i++)
            cout << "#";
        cout << endl;

        for (int i = 0; i < *h; i++)
        {
            for (int j = 0; j < *w; j++)
            {
                if (j == 0)
                    cout << "#";
                if (i == y && j == x)
                    cout << "O";
                else if (i == fruitY && j == fruitX)
                    cout << "@";
                else
                {
                    bool print = false;
                    for (int k = 0; k < nTail; k++)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print)
                        cout << " ";
                }


                if (j == *w - 1)
                    cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < *w + 2; i++)
            cout << "#";
        cout << endl;
        cout << "Score:" << score << endl;
    }

    void input()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
            {
                bool n = true;
                set_gameover(n);
            }
            break;
            }
        }
    }

    void logic()
    {
        int* h = get_height();
        int* w = get_width();
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1; i < nTail; i++)
        {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        switch (dir)
        {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
        }

        if (x >= *w) x = 0; else if (x < 0) x = *w - 1;
        if (y >= *h) y = 0; else if (y < 0) y = *h - 1;

        for (int i = 0; i < nTail; i++)
            if (tailX[i] == x && tailY[i] == y)
            {
                bool n = true;
                set_gameover(n);
            }

        if (x == fruitX && y == fruitY)
        {
            score += 1;
            fruitX = rand() % *w;
            fruitY = rand() % *h;
            nTail++;
        }
    }

    void scoring(int s)
    {
        int olds = read_score();

        ofstream out;
        out.open("highscore.txt");

        if (s > olds)
            out << s;
        else
            out << olds;

        out.close();
    }

    int read_score()
    {
        int x, olds;

        ifstream in;
        in.open("highscore.txt");

        while (in >> x)
            olds = x;

        return olds;
    }

};

class level2 :public snake
{
    int* width;
    int* height;

public:

    level2()
    {
        width = new int;
        height = new int;
        width = 0;
        height = 0;
    }

    level2(level2& c)
    {
        width = new int;
        height = new int;
        width = c.width;
        height = c.width;
    }

    void set_height(int* h)
    {
        height = h;
    }
    int* get_height()
    {
        return height;
    }

    void set_width(int* w)
    {
        width = w;
    }
    int* get_width()
    {
        return width;
    }

    void set_gameover(bool go)
    {
        gameover = go;
    }
    bool get_gameover()
    {
        return gameover;
    }

    void set_score(int s)
    {
        score = s;
    }
    int get_score()
    {
        return score;
    }


    void setup()
    {
        gameover = false;
        dir = STOP;
        x = *width / 2;
        y = *height / 2;
        fruitX = rand() % *width;
        fruitY = rand() % *height;
        score = 0;
    }

    void draw()
    {
        int* h = get_height();
        int* w = get_width();

        system("cls");
        for (int i = 0; i < *w + 2; i++)
            cout << "#";
        cout << endl;

        for (int i = 0; i < *h; i++)
        {
            for (int j = 0; j < *w; j++)
            {
                if (j == 0)
                    cout << "#";
                if (i == y && j == x)
                    cout << "O";
                else if (i == fruitY && j == fruitX)
                    cout << "@";
                else
                {
                    bool print = false;
                    for (int k = 0; k < nTail; k++)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print)
                        cout << " ";
                }


                if (j == *w - 1)
                    cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < *w + 2; i++)
            cout << "#";
        cout << endl;
        cout << "Score:" << score << endl;
    }

    void input()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
            {
                bool n = true;
                set_gameover(n);
            }
            break;
            }
        }
    }


    void logic()
    {
        int* h = get_height();
        int* w = get_width();
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1; i < nTail; i++)
        {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        switch (dir)
        {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
        }

        if (x > *w || x < 0 || y > *h || y < 0)
        {
            bool n = true;
            set_gameover(n);
        }

        for (int i = 0; i < nTail; i++)
            if (tailX[i] == x && tailY[i] == y)
            {
                bool n = true;
                set_gameover(n);
            }

        if (x == fruitX && y == fruitY)
        {
            score += 1;
            fruitX = rand() % *w;
            fruitY = rand() % *h;
            nTail++;
        }
    }

    void scoring(int s)
    {
        int olds = read_score();

        ofstream out;
        out.open("highscore.txt");

        if (s > olds)
            out << s;
        else
            out << olds;

        out.close();
    }

    int read_score()
    {
        int x, olds;

        ifstream in;
        in.open("highscore.txt");

        while (in >> x)
            olds = x;

        return olds;
    }

};

class custom :public snake
{
    int* width;
    int* height;
    bool _collision;

public:

    custom()
    {
        width = new int;
        height = new int;
        width = 0;
        height = 0;
    }

    custom(custom& c)
    {
        width = new int;
        height = new int;
        width = c.width;
        height = c.width;
    }

    void set_height(int* h)
    {
        height = h;
    }
    int* get_height()
    {
        return height;
    }

    void set_width(int* w)
    {
        width = w;
    }
    int* get_width()
    {
        return width;
    }

    void set_gameover(bool go)
    {
        gameover = go;
    }
    bool get_gameover()
    {
        return gameover;
    }

    void set_score(int s)
    {
        score = s;
    }
    int get_score()
    {
        return score;
    }

    void set_col(bool c)
    {
        _collision = c;
    }
    bool get_col()
    {
        return _collision;
    }

    void setup()
    {
        gameover = false;
        dir = STOP;
        x = *width / 2;
        y = *height / 2;
        fruitX = rand() % *width;
        fruitY = rand() % *height;
        score = 0;
    }

    void draw()
    {
        int* h = get_height();
        int* w = get_width();

        system("cls");
        for (int i = 0; i < *w + 2; i++)
            cout << "#";
        cout << endl;

        for (int i = 0; i < *h; i++)
        {
            for (int j = 0; j < *w; j++)
            {
                if (j == 0)
                    cout << "#";
                if (i == y && j == x)
                    cout << "O";
                else if (i == fruitY && j == fruitX)
                    cout << "@";
                else
                {
                    bool print = false;
                    for (int k = 0; k < nTail; k++)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print)
                        cout << " ";
                }


                if (j == *w - 1)
                    cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < *w + 2; i++)
            cout << "#";
        cout << endl;
        cout << "Score:" << score << endl;
    }

    void input()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
            {
                bool n = true;
                set_gameover(n);
            }
            break;
            }
        }
    }

    void logic()
    {
        int* h = get_height();
        int* w = get_width();
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1; i < nTail; i++)
        {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        switch (dir)
        {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
        }

        bool C = get_col();

        switch (C)
        {
        case true:
        {
            if (x > *w || x < 0 || y > *h || y < 0)
            {
                bool n = true;
                set_gameover(n);
            }
        }
        break;

        case false:
        {
            if (x >= *w) x = 0; else if (x < 0) x = *w - 1;
            if (y >= *h) y = 0; else if (y < 0) y = *h - 1;
        }
        break;

        default:
            break;
        }

        for (int i = 0; i < nTail; i++)
            if (tailX[i] == x && tailY[i] == y)
            {
                bool n = true;
                set_gameover(n);
            }

        if (x == fruitX && y == fruitY)
        {
            score += 1;
            fruitX = rand() % *w;
            fruitY = rand() % *h;
            nTail++;
        }
    }

    void scoring(int s)
    {
        int olds = read_score();

        ofstream out;
        out.open("highscore.txt");

        if (s > olds)
            out << s;
        else
            out << olds;

        out.close();
    }

    int read_score()
    {
        int x, olds;

        ifstream in;
        in.open("highscore.txt");

        while (in >> x)
            olds = x;

        return olds;
    }

};

int main()
{
    cout << "\n                     SNAKE GAME\n\n";
    cout << "select level\n";
    cout << "a.easy\nb.medium\nc.custom game\n\n";
    char n;
    cout << "select option(a,b,c)="; cin >> n;
    system("cls");

    switch (n)
    {
    case 'a':
    {
        level1 l1;
        int a = 30;
        int b = 50;

        int* h = &a;
        int* w = &b;
        l1.set_height(h);
        l1.set_width(w);

        l1.setup();
        while (!l1.get_gameover())
        {
            l1.draw();
            l1.input();
            l1.logic();
            //Sleep(0);
        }
        int score = l1.get_score();
        l1.scoring(score);
    }
    break;

    case 'b':
    {
        snake* s;
        level2 l2;
        s = &l2;
        int a = 20;
        int b = 20;
        int* h = &a;
        int* w = &b;
        l2.set_height(h);
        l2.set_width(w);

        s->setup();
        while (!l2.get_gameover())
        {
            s->draw();
            s->input();
            s->logic();
            Sleep(30);
        }
        int score = l2.get_score();
        s->scoring(score);
    }
    break;

    case 'c':
    {
        cout << "ENTER LEVEL PARAMETERS\n";
        custom c;
        int a;
        int b;
        bool col;
        char col_chek;

        cout << "enter height="; cin >> a;
        cout << "enter width="; cin >> b;
        cout << "enable wall collision? y/n="; cin >> col_chek;

        if (col_chek == 'y')
            col = true;
        else if (col_chek == 'n')
            col = false;
        else
            cout << "wrong input";
        c.set_col(col);

        int* h = &a;
        int* w = &b;
        c.set_height(h);
        c.set_width(w);

        c.setup();
        while (!c.get_gameover())
        {
            c.draw();
            c.input();
            c.logic();
            Sleep(20);
        }
        int score = c.get_score();
        c.scoring(score);
    }
    break;

    default:
        cout << "wrong selection";
    }
}