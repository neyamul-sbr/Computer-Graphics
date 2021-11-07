///MD. NEYAMUL ISLAM SHIBBIR
///REG. No. 2017331047
#include<bits/stdc++.h>
#include<windows.h>
#include<graphics.h>
using namespace std;
int axisColor = 15; ///white

struct PT
{
    double x, y;
    PT() {};
    PT(double a, double b)
    {
        x = a;
        y = b;
    }

    bool operator < (const PT &p)const
    {
        return x < p.x;
    }
};
struct PT2
{
    int x, y;
    PT2() {}
    PT2(int a, int b)
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

void bressenhams_line(PT p3, PT p4,int col)
{
    int x1=round(p3.x);
    int y1=round(p3.y);
    PT2 p1 = PT2(x1,y1);

    int x2=round(p4.x);
    int y2=round(p4.y);
    PT2 p2 = PT2(x2,y2);

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
            drawPixel(PT(xx,yy),col);

            while(yy<p2.y)
            {
                if(d<0)
                {
                    yy++;
                    PT nw=PT(xx,yy);

                    drawPixel(nw,col);
                    d= d+2*dx;
                }
                else
                {
                    xx++;
                    yy++;
                    PT nw=PT(xx,yy);
                    drawPixel(nw,col);
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
            drawPixel(PT(xx,yy),col);
            while(xx<p2.x)
            {

                //cout<<xx<<" "<<yy<<"\n";
                if(d<0)
                {
                    xx++;
                    PT nw=PT(xx,yy);
                    //cout<<nw.x<<" "<<nw.y<<"\n";
                    drawPixel(nw,col);
                    d= d+2*dy;
                }
                else
                {
                    xx++;
                    yy++;
                    PT nw=PT(xx,yy);
                    drawPixel(nw,col);
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
            drawPixel(PT(xx,yy),col);
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
                drawPixel(nw,col);
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
            drawPixel(PT(xx,yy),col);
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
                drawPixel(nw,col);
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
            drawPixel(nw,col);
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
            drawPixel(nw,col);
        }

    }
}

void drawPolygon(vector<PT> points, int color)
{
    int n = points.size();
    for(int i=0; i<n; i++)
    {
        bressenhams_line(points[i], points[(i+1)%n],color);
    }
}

struct EDGE
{
    double y_min, y_max, x_with_y_min, m_inv;
    EDGE() {};
    EDGE(double y_min1, double y_max1, double x_with_y_min1, double m_inv1)
    {
        y_min = y_min1;
        y_max = y_max1;
        x_with_y_min = x_with_y_min1;
        m_inv = m_inv1;
    }

    bool operator < (const EDGE &e)const
    {
        return y_min < e.y_min;
    }
};

void scanline_algo(vector<PT> points, int color)
{
    vector<EDGE> edges;

    int n = points.size();
    double start = DBL_MAX;
    double finish = DBL_MIN;

    map<double, int>mp;

    for(int i = 0; i<n; i++)
    {
        PT p1 = points[i];
        PT p2 = points[(i+1)%n];

        if(p1.y == p2.y)
        {
            continue;
        }
        EDGE temp;
        temp.y_min = min(p1.y, p2.y);
        temp.y_max = max(p1.y, p2.y);
        if(p1.y < p2.y )
        {
            temp.x_with_y_min= p1.x;
        }
        else
        {
            temp.x_with_y_min= p2.x;
        }
        temp.m_inv = (p2.x - p1.x)/(p2.y - p1.y);

        mp[temp.y_min] = 1;
        start = min(start, temp.y_min);
        finish = max(finish, temp.y_max);

        edges.push_back(temp);
    }

    sort(edges.begin(), edges.end());

    for(int i = 0; i<edges.size(); i++)
    {
        if(mp[edges[i].y_max] == 1)
        {
            edges[i].y_max--;
        }
    }


    for(int y = start; y <= finish; y++)
    {
        vector<PT> intersects;
        for(int i = 0; i < edges.size(); i++)
        {
            if(y >= edges[i].y_min && y <= edges[i].y_max)
            {
                intersects.push_back(PT(edges[i].x_with_y_min, y));
                edges[i].x_with_y_min += edges[i].m_inv;
            }
        }
        sort(intersects.begin(), intersects.end());

        for(int i = 0; i<intersects.size()-1; i+=2)
        {
            bressenhams_line(intersects[i], intersects[i+1], color);
        }
    }
}


int main()
{

    initwindow(WINDOW_W,WINDOW_H);
    drawAxis();

    vector<PT> poly;
    poly.push_back(PT(0, 120));
    poly.push_back(PT(110, 100));
    poly.push_back(PT(150, 20));
    poly.push_back(PT(90, -90));
    poly.push_back(PT(-70,-80));
    poly.push_back(PT(-110, 40));

    drawPolygon(poly, RED);
    scanline_algo(poly, GREEN);


    cout<<"Red Bordered Polygon Filled With GREEN color..Using Scanline Algo";



        getchar();

}
