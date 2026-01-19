#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
#include <iostream.h>

/* --------- DDA Line Algorithm --------- */
void ddaLine(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1, y = y1;
    for(int i = 0; i <= steps; i++)
    {
        putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
        x += xInc;
        y += yInc;
    }
}

/* --------- Bresenham Line Algorithm --------- */
void bresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p = 2 * dy - dx;

    int x = x1, y = y1;
    int xEnd = x2;

    putpixel(x, y, WHITE);

    while(x < xEnd)
    {
        x++;
        if(p < 0)
            p = p + 2 * dy;
        else
        {
            y++;
            p = p + 2 * (dy - dx);
        }
        putpixel(x, y, WHITE);
    }
}

/* --------- Midpoint Circle Algorithm --------- */
void midpointCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int p = 1 - r;

    while(x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        x++;
        if(p < 0)
            p += 2 * x + 1;
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
    }
}

/* --------- Rectangle --------- */
void drawRectangle(int x1, int y1, int x2, int y2)
{
    rectangle(x1, y1, x2, y2);
}

/* --------- Triangle --------- */
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

/* --------- Ellipse --------- */
void drawEllipse(int xc, int yc, int rx, int ry)
{
    ellipse(xc, yc, 0, 360, rx, ry);
}

/* --------- MAIN PROGRAM --------- */
void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int choice, sub;
    int x1, y1, x2, y2, xc, yc, r, rx, ry;
    int x3, y3;

    do
    {
        cleardevice();
        cout << "\n---- GRAPHICS MENU ----";
        cout << "\n1. Line Algorithm";
        cout << "\n2. Circle Algorithm";
        cout << "\n3. Rectangle";
        cout << "\n4. Triangle";
        cout << "\n5. Ellipse";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        cleardevice();

        switch(choice)
        {
            case 1:
                cout << "\n1. DDA Line";
                cout << "\n2. Bresenham Line";
                cout << "\nEnter sub choice: ";
                cin >> sub;
                cout << "Enter x1 y1 x2 y2: ";
                cin >> x1 >> y1 >> x2 >> y2;
                if(sub == 1)
                    ddaLine(x1, y1, x2, y2);
                else
                    bresenhamLine(x1, y1, x2, y2);
                break;

            case 2:
                cout << "\n1. Midpoint Circle";
                cout << "\n2. Bresenham Circle";
                cout << "\nEnter sub choice: ";
                cin >> sub;
                cout << "Enter center (xc yc) and radius: ";
                cin >> xc >> yc >> r;
                midpointCircle(xc, yc, r);
                break;

            case 3:
                cout << "Enter x1 y1 x2 y2: ";
                cin >> x1 >> y1 >> x2 >> y2;
                drawRectangle(x1, y1, x2, y2);
                break;

            case 4:
                cout << "Enter x1 y1 x2 y2 x3 y3: ";
                cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                drawTriangle(x1, y1, x2, y2, x3, y3);
                break;

            case 5:
                cout << "Enter center (xc yc) and rx ry: ";
                cin >> xc >> yc >> rx >> ry;
                drawEllipse(xc, yc, rx, ry);
                break;

            case 6:
    		closegraph();
    		cout << "\nExiting Program...";
    		getch();
    		return;

        }

        getch();
    } while(choice != 6);
}
