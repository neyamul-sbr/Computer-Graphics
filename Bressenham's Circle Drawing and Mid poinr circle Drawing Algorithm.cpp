///MD. NEYAMUL ISLAM SHIBBIR
///REG. No. 2017331047
#include<bits/stdc++.h>
#include<windows.h>
#include<graphics.h>
using namespace std;

struct PT
{
    int x, y;
    PT() {}
    PT(int a, int b)
    {
        x = a;
        y = b;
    }
};

const int WINDOW_W = 800, WINDOW_H = 600;

void drawAxis()
{
    for(int i=0; i<WINDOW_H; i++) putpixel(WINDOW_W/2, i, WHITE);
    for(int i=0; i<WINDOW_W; i++) putpixel(i, WINDOW_H/2, WHITE);
}

PT convertPixel(PT p)
{
    p.x += WINDOW_W/2;
    p.y = -p.y;
    p.y += WINDOW_H/2;

    return p;
}

void drawPixel(PT p, int color)
{
    p = convertPixel(p);
    putpixel(p.x, p.y, color);
}
void bressenham_circle(PT p, int r)

{
    int x =0;
    int y = r;
    int d = 3  - 2*r;
    PT ww = PT(x,y);
    drawPixel(ww, RED);
    int xx= p.x;
    int yy= p.y;
    while(y >= x)
    {
        drawPixel(PT(xx+x,yy+y),RED);
        drawPixel(PT(xx-x,yy+y),RED);
        drawPixel(PT(xx+x,yy-y),RED);
        drawPixel(PT(xx-x,yy-y),RED);
        drawPixel(PT(xx+y,yy+x),RED);
        drawPixel(PT(xx-y,yy+x),RED);
        drawPixel(PT(xx+y,yy-x),RED);
        drawPixel(PT(xx-y,yy-x),RED);



        if (d >0)
        {
            y--;
            d= d + 4 *x -4*y +10;

        }
        else
        {
            d = d + 4 * x +6;
        }
        x++;

    }

}

void midpoint_circle(PT p, int r)

{
    int x =0;
    int y = r;
    double d = (double)5/(double)4 -r;
    PT ww = PT(x,y);
    int xx= p.x;
    int yy= p.y;
    drawPixel(PT(xx+x, yy+y), BLUE);
    drawPixel(PT(xx+y, yy+x), BLUE);
    drawPixel(PT(xx+x, yy-y), BLUE);
    drawPixel(PT(xx-y, yy+x), BLUE);
    while(x <= y)
    {
        if(d < 0)
        {
            d =  d + 2 * x +3;
            drawPixel(PT(xx+x+1, yy+y), BLUE);
            drawPixel(PT(xx+y, yy+x+1), BLUE);
            drawPixel(PT(xx+y, yy-x-1), BLUE);
            drawPixel(PT(xx+x+1, yy-y), BLUE);
            drawPixel(PT(xx-x-1, yy-y), BLUE);
            drawPixel(PT(xx-y, yy-x-1), BLUE);
            drawPixel(PT(xx-y, yy+x+1), BLUE);
            drawPixel(PT(xx-x-1, yy+y), BLUE);
        }
        else
        {
            d = d + 2 *x -2* y + 5;
            drawPixel(PT(xx+x+1, yy+y-1), BLUE);
            drawPixel(PT(xx+y-1, yy+x+1), BLUE);
            drawPixel(PT(xx+y-1, yy-x-1), BLUE);
            drawPixel(PT(xx+x+1, yy-y+1), BLUE);
            drawPixel(PT(xx-x-1, yy-y+1), BLUE);
            drawPixel(PT(xx-y+1, yy-x-1), BLUE);
            drawPixel(PT(xx-y+1, yy+x+1), BLUE);
            drawPixel(PT(xx-x-1, yy+y-1), BLUE);
            y --;
        }
        x++;

    }



}



int main()
{

    initwindow(WINDOW_W,WINDOW_H);
    drawAxis();
    int x1 = 0,y1 = 0,x2= 150,y2= 50, r1 =200, r2=100;
    PT p1= PT(x1,y1);
    PT p2= PT(x2,y2);

    bressenham_circle(p1,r1);
    midpoint_circle(p2,r2);
    cout<<"Bressenham's Circle Is in RED With center (0,0) and Radius 200"<<"\n" ;
    cout<<"Midpoint Cicle is in BLUE with center (100,30) and Radius 100"<<"\n";



//    PT a = PT(150, -200);
//    PT b = PT(0,200);
//
//    drawLine(a,b);


    getchar();

}
