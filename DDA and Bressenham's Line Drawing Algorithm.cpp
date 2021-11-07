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
void dda_line(PT p1, PT p2)
{

    double m = (double)(p1.y-p2.y)/(double)(p1.x-p2.x);


    if (abs(m) <= 1)
    {

        int x = p1.x, y = p1.y;
        drawPixel(PT(x,y),BLUE);
        while(x <= p2.x)
        {
            y =(int)floor(y+m);
            x++;
            drawPixel(PT(x,y),BLUE);
        }
    }

    else
    {

        double m_inv = (double)1/(double)m;
        int x = p1.x ,y = p2.y;
        drawPixel(PT(x,y),BLUE);
        while(y <= p2.y)
        {
            x =(int)floor(x+m);
            y++;
            drawPixel(PT(x,y),BLUE);
        }


    }


}


void bressenhams_line(PT p1, PT p2)
{

    double m = (double)(p1.y-p2.y)/(double)(p1.x-p2.x);
//    cout<<m;
    if(p1.x!=p2.x && p1.y!=p2.y)
    {

        if(m>1)
        {
            if(p1.y>p2.y) swap(p1,p2);
            int dx=p2.x-p1.x;
            int dy=p2.y-p1.y;
            int d0 = 2*dx-dy;
            int d=d0;
            int y=p1.y;
            int xx= p1.x;
            int yy=p1.y;
            drawPixel(PT(xx,yy),RED);

            while(yy<p2.y)
            {
                if(d<0)
                {
                    yy++;
                    PT nw=PT(xx,yy);

                    drawPixel(nw,RED);
                    d= d+2*dx;
                }
                else
                {
                    xx++;
                    yy++;
                    PT nw=PT(xx,yy);
                    drawPixel(nw,RED);
                    d=d+2*dx-2*dy;
                }

            }
        }
        else if(m<=1&&m>0)
        {
            if(p1.x>p2.x) swap(p1,p2);
            int dx=p2.x-p1.x;
            int dy=p2.y-p1.y ;
            int d0 = 2*dy-dx;
            int d=d0;
            int x=p1.x;
            int xx= p1.x;
            int yy=p1.y;
            drawPixel(PT(xx,yy),RED);
            while(xx<p2.x)
            {

                //cout<<xx<<" "<<yy<<"\n";
                if(d<0)
                {
                    xx++;
                    PT nw=PT(xx,yy);
                    //cout<<nw.x<<" "<<nw.y<<"\n";
                    drawPixel(nw,RED);
                    d= d+2*dy;
                }
                else
                {
                    xx++;
                    yy++;
                    PT nw=PT(xx,yy);
                    drawPixel(nw,RED);
                    d=d+2*dy-2*dx;
                }
            }
        }
        else if(-1<=m && m<0)
        {

            if(p1.y>p2.y)
            {
                swap(p1, p2);
            }
            int dx = p1.x-p2.x;
            int dy = p2.y-p1.y;
            int d0= 2*dy-dx;
            int d = d0;
            int xx= p1.x;
            int yy=p1.y;
            //cout<<p2.x<<" "<<xx<<"\n";
            drawPixel(PT(xx,yy),RED);
            while(p2.x<xx)
            {
                if(d<0)
                {
                    xx--;
                    d=d+2*dy;
                }
                else
                {
                    yy++;
                    xx--;
                    d=d+2*dy-2*dx;
                }
                PT nw= PT(xx,yy);
                drawPixel(nw,RED);
            }

        }
        else if(m<-1)
        {

            if(p1.y>p2.y)
            {
                swap(p1, p2);
            }
            int dx = p1.x-p2.x;
            int dy = p2.y-p1.y;
            int d0= 2*dx-dy;
            int d = d0;
            int xx= p1.x;
            int yy=p1.y;
            drawPixel(PT(xx,yy),RED);
            while(yy<p2.y)
            {
                if(d<0)
                {
                    yy++;
                    d=d+2*dx;
                }
                else
                {
                    yy++;
                    xx--;
                    d=d+2*dx-2*dy;
                }
                PT nw= PT(xx,yy);
                drawPixel(nw,RED);
            }

        }
    }
    else if(p1.y==p2.y)
    {
        if(p1.x>p2.x)
        {
            swap(p1,p2);
        }
        int xx=p1.x;
        int yy=p1.y;
        while(xx<=p2.x)
        {
            xx++;

            PT nw = PT(xx,yy);
            drawPixel(nw,RED);
        }

    }
    else
    {
        if(p1.y>p2.y)
        {
            swap(p1,p2);
        }
        int xx=p1.x;
        int yy=p1.y;
        while(yy<=p2.y)
        {
            yy++;

            PT nw = PT(xx,yy);
            drawPixel(nw,RED);
        }

    }
}
int main()
{

    initwindow(WINDOW_W,WINDOW_H);
    drawAxis();
    PT p1 = PT(0,0);
    PT p2 = PT(250,-250);
    PT p3 = PT(0,0);
    PT p4 = PT(250,250);
    bressenhams_line(p1,p2);
    dda_line(p3,p4);
    cout<<"Bressenham's Line Is in RED (0,0) and (250,-250) End Co-ordinates"<<"\n";
    cout<<"DDA line Is in BLUE (0,0) and (250,250) End Co-ordinates"<<"\n";



//    PT a = PT(150, -200);
//    PT b = PT(0,200);
//
//    drawLine(a,b);


    getchar();

}
