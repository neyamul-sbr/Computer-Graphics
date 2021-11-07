///MD. NEYAMUL ISLAM SHIBBIR
///REG. No. 2017331047
#include<bits/stdc++.h>
#include<windows.h>
#include<graphics.h>
using namespace std;
int axisColor = 15; ///white

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

void drawPolygon(vector<PT> points)
{
    int n = points.size();
    for(int i=0; i<n; i++)
    {
        bressenhams_line(points[i], points[(i+1)%n]);
    }
}

void BoundaryFill(PT currPixel, int boundaryColor, int fillColor)

{

    PT pixel = convertPixel(currPixel);
    int currColor = getpixel(pixel.x, pixel.y);

    if(currColor == boundaryColor|| currColor == fillColor)
    {
        return;
    }

    drawPixel(currPixel, fillColor);

    BoundaryFill(PT(currPixel.x, currPixel.y+1), boundaryColor, fillColor); ///upper
    BoundaryFill(PT(currPixel.x, currPixel.y-1), boundaryColor, fillColor);///lower
    BoundaryFill(PT(currPixel.x+1, currPixel.y), boundaryColor, fillColor); ///right
    BoundaryFill(PT(currPixel.x-1, currPixel.y), boundaryColor, fillColor); ///left

}

void FloodFill(PT currPixel, int backgroudColor, int fillColor)
{
    PT pixel = convertPixel(currPixel);
    int currColor = getpixel(pixel.x, pixel.y);
    if(currColor != axisColor && currColor != backgroudColor)
    {
        return;
    }
    drawPixel(currPixel,fillColor);

    FloodFill(PT(currPixel.x, currPixel.y+1), backgroudColor, fillColor);
    FloodFill(PT(currPixel.x, currPixel.y-1), backgroudColor, fillColor);
    FloodFill(PT(currPixel.x+1, currPixel.y), backgroudColor, fillColor);
    FloodFill(PT(currPixel.x-1, currPixel.y), backgroudColor, fillColor);
}
void rectangle(int x1,int y1,int x2,int y2, int col)
{

    PT p1 =  PT(x1,y1);
    PT p2 =  PT(x1,y2);
    PT p3 =  PT(x2,y2);
    PT p4 =  PT(x2,y1);


    bressenhams_line(p1,p2);
    bressenhams_line(p2,p3);
    bressenhams_line(p3,p4);
    bressenhams_line(p4,p1);


}
int main()
{

    initwindow(WINDOW_W,WINDOW_H);
//    drawAxis();
//
//    vector<PT> poly;
//    poly.push_back(PT(0, 120));
//    poly.push_back(PT(110, 100));
//    poly.push_back(PT(150, 20));
//    poly.push_back(PT(90, -90));
//    poly.push_back(PT(-70,-80));
//    poly.push_back(PT(-110, 40));
//
//    drawPolygon(poly);
//
//
//    cout<<"Tap 1 for Flood Fill"<<"\n"<<"Tap 2 for Boundary Fill"<<"\n";
//    int cc;
//    cin>>cc;
//    if(cc==1)
//    {
//        int backgroundColor = getpixel(10,0);
//
//        FloodFill(PT(10,0), backgroundColor, BLUE);
//        cout<<"Flood Fill done With BLUE color"<<"\n";
//
//    }
//    else if(cc==2)
//    {
//        BoundaryFill(PT(0,10), RED, YELLOW );
//        cout<<"Boundary Fill done With YELLOW COLOR"<<"\n";
//    }


  rectangle(50,50,100,100,RED);

    getchar();

}
