#include <gl/glut.h>
#include <math.h>
#include <windows.h>
#include<stdio.h>
#include<conio.h>
#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x;
    int y;

};

Point p1, p2;
int decision;
void draw_dda(Point p1, Point p2)
{
    glColor3f(0.0f, 0.0f, 1.0f);
    GLfloat dx = p2.x - p1.x;
    GLfloat dy = p2.y - p1.y;
    GLfloat x1 = p1.x;
    GLfloat y1 = p1.y;
    GLfloat step = 0;
    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    GLfloat xInc = dx / step;
    GLfloat yInc = dy / step;

    glBegin(GL_POINTS);

    for (float i = 1; i <= step; i++)
    {
        glVertex2i(x1, y1);
        x1 += xInc;
        y1 += yInc;
    }
    glEnd();
    glFlush();
}

void Midpoint_circle(Point p1, Point p2)
{
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POINTS);

    int radious = (int)sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));

    int d = 1 - 1 * radious;
    int x = 0, y = radious;

    while (x <= y)
    {
        glVertex2i(p1.x + x, p1.y + y);

        glVertex2i(p1.x + x, p1.y - y);

        glVertex2i(p1.x - x, p1.y + y);
        glVertex2i(p1.x - x, p1.y - y);

        glVertex2i(p1.x + y, p1.y + x);
        glVertex2i(p1.x + y, p1.y - x);
        glVertex2i(p1.x - y, p1.y + x);

        glVertex2i(p1.x - y, p1.y - x);
        if (d < 0)
        {

            d = d + 2 * x + 3;
        }
        else

        {
            d = d + 2 * (x - y) + 10 / 2;

            y--;
        }
        x++;

    }

    glEnd();

    glFlush();
}

void Bresenham_circle(Point p1, Point p2)
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
    int radious = (int)sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    int d = 3 - 2 * radious;
    int x = 0, y = radious;
    while (x <= y)
    {
        glVertex2i(p1.x + x, p1.y + y);
        glVertex2i(p1.x + x, p1.y - y);
        glVertex2i(p1.x - x, p1.y + y);
        glVertex2i(p1.x - x, p1.y - y);
        glVertex2i(p1.x + y, p1.y + x);
        glVertex2i(p1.x + y, p1.y - x);
        glVertex2i(p1.x - y, p1.y + x);
        glVertex2i(p1.x - y, p1.y - x);
        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
    glEnd();
    glFlush();

}

void Bresenham_line(Point p1, Point p2)
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
    int dx = abs(p2.x - p1.x);
    int dy = abs(p2.y - p1.y);

    float m = float(p2.y - p1.y) / float(p2.x - p1.x);
    if (m >= 0 && m <= 1)
    {
        int d = 2 * dy - dx;
        int ds = 2 * dy;

        int dt = 2 * (dy - dx);
        int xn, yn, xend, yend;

        xn = p1.x;
        yn = p1.y;
        xend = p2.x;

        if (p2.x < p1.x)
        {
            xn = p2.x;

            yn = p2.y;
            xend = p1.x;
        }

        d = 2 * dy - dx;
        glVertex2i(xn, yn);
        while (xn < xend)

        {
            xn++;
            if (d < 0)

            {
                d += ds;
            }

            else

            {
                yn++;

                d += dt;
            }
            glVertex2i(xn, yn);

        }
    }
    else if (m > 1)
    {
        int d = 2 * dy - dx;
        int ds = 2 * dy;

        int dt = 2 * (dy - dx);

        int xn, yn, xend, yend;
        xn = p1.x;
        yn = p1.y;

        yend = p2.y;
        if (p2.y < p1.y)
        {

            xn = p2.x;
            yn = p2.y;
            yend = p1.y;

        }
        glVertex2i(xn, yn);
        d = 2 * dx - dy;

        ds = 2 * dx;
        dt = 2 * dx - 2 * dy;

        while (yn < yend)
        {
            yn++;
            if (d < 0)
            {
                d += ds;
            }
            else
            {
                xn++;
                d += dt;
            }
            glVertex2i(xn, yn);
        }

    }
    else if (m <= -1)
    {

        if (dx >= 0)
        {
            dx = dx * (-1);
        }
        int xn, yn, xend, yend;
        xn = p1.x;
        yn = p1.y;
        yend = p2.y;
        int d = -2 * dx - dy;

        if (p2.y < p1.y)
        {
            xn = p2.x;
            yn = p2.y;
            yend = p1.y;
        }
        int ds = -2 * dx;
        int dt = -2 * dx - 2 * dy;
        glVertex2i(xn, yn);
        while (yn < yend)
        {
            yn++;
            if (d < 0)
            {
                d += ds;
            }
            else

            {
                xn--;
                d += dt;

            }
            glVertex2i(xn, yn);
        }

    }
    else

    {
        if (dx >= 0)
        {

            dx = dx * (-1);
        }
        int d = +2 * dy + dx;

        int xn = p1.x;
        int yn = p1.y;
        int xend = p2.x;

        if (p2.x > p1.x)
        {

            xn = p2.x;
            yn = p2.y;
            xend = p1.x;

        }
        glVertex2i(xn, yn);
        int ds = +2 * dy;

        int dt = +2 * dy + 2 * dx;
        while (xn > xend)
        {

            xn--;
            if (d < 0)
            {

                d += ds;
            }
            else

            {
                yn++;
                d += dt;

            }
            glVertex2i(xn, yn);
        }
    }

    glEnd();
    glFlush();

}

void clearall()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glEnd();
    glFlush();
}

void _MouseFunc(int button, int state, int x, int y)
{
    int d;
    bool b = 1;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        p1.x = x;
        p1.y = 480 - y;
        cout<<x<<" - "<<y<<endl;
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        p2.x = x;
        p2.y = 480 - y;
        b = 0;
        cout<<x<<" - "<<y<<endl;
    }
    if (b == 0)
    {
        glFlush();
        if (decision == 1)
        {
            draw_dda(p1, p2);
            cout<<"DDA Line ^ "<<endl;
        }
        else if (decision == 2)
        {
            Bresenham_line(p1, p2);
            cout<<"Bresenham Line ^ "<<endl;
        }
        else if(decision == 3)
        {
            Bresenham_circle(p1, p2);
            cout<<"Bresenham Circle ^ "<<endl;
        }
        else if(decision == 4)
        {
            Midpoint_circle(p1, p2);
            cout<<"Midpoint Circle ^ "<<endl;
        }
        else
        {
            draw_dda(p1, p2);
            cout<<"DDA Line ^ "<<endl;
        }
    }

}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);

    glPointSize(2.0f);
    gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

void display()
{
}

void mainMenu(int c)
{
    decision = c;
    if(decision == 5)
    {
        clearall();
    }
    else if(decision == 6)
    {
        exit(0);
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 200);

    glutInitWindowSize(640, 480);
    glutCreateWindow("Computer Graphics Lab ( 170213 & 170209 )");
    glutDisplayFunc(display);
    init();
    glutCreateMenu(mainMenu);
    glutAddMenuEntry("1.DDA Line", 1);
    glutAddMenuEntry("2.Bresenham Line", 2);
    glutAddMenuEntry("3.Bresenham Circle", 3);
    glutAddMenuEntry("4.Midpoint Circle", 4);
    glutAddMenuEntry("5.Clear All", 5);
    glutAddMenuEntry("6.Exit", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glClear(GL_COLOR_BUFFER_BIT);
    glutMouseFunc(_MouseFunc);
    glutMainLoop();
    _getch();

    return 0;
}
