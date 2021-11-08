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

const int WINDOW_W = 1200, WINDOW_H = 800;

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
PT inv_convertPixel(PT p)
{
    p.x -= WINDOW_W/2;

    p.y -= WINDOW_H/2;
    p.y = -p.y;

    return p;
}

void drawPixel(PT p, int color)
{
    p = convertPixel(p);
    putpixel(p.x, p.y, color);
}

void bressenhams_line(PT p1, PT p2, int col)
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
void rectangle_l(double x1,double y1,double x2,double y2, int col)
{
    PT p1 =  PT(x1,y1);
    PT p2 =  PT(x1,y2);
    PT p3 =  PT(x2,y2);
    PT p4 =  PT(x2,y1);


    bressenhams_line(p1,p2,col);
    bressenhams_line(p2,p3,col);
    bressenhams_line(p3,p4,col);
    bressenhams_line(p4,p1,col);


}


void bressenham_circle(PT p, int r, int col)

{
    int x =0;
    int y = r;
    int d = 3  - 2*r;
    PT ww = PT(x,y);
    drawPixel(ww, col);
    int xx= p.x;
    int yy= p.y;
    while(y >= x)
    {
        drawPixel(PT(xx+x,yy+y),col);
        drawPixel(PT(xx-x,yy+y),col);
        drawPixel(PT(xx+x,yy-y),col);
        drawPixel(PT(xx-x,yy-y),col);
        drawPixel(PT(xx+y,yy+x),col);
        drawPixel(PT(xx-y,yy+x),col);
        drawPixel(PT(xx+y,yy-x),col);
        drawPixel(PT(xx-y,yy-x),col);



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
bool check_body(int x1, int y1, int x2,
                int y2, int x, int y)
{
    if (x > x1 and x < x2 and y > y1 and y < y2)
        return true;

    return false;
}

bool check_tyre(int circle_x, int circle_y,
                int rad, int x, int y)
{
    // Compare radius of circle with distance
    // of its center from given point
    if ((x - circle_x) * (x - circle_x) +
            (y - circle_y) * (y - circle_y) <= rad * rad)
        return true;
    else
        return false;
}
void make_road()
{
    for(int j=0; j<2; j++)
        for(int i=0; i<WINDOW_W; i++) putpixel(i, WINDOW_H/2+100+j, WHITE);
}
int main()
{

    initwindow(WINDOW_W,WINDOW_H);

    int car_length = 250;
    int car_height = 150;
    int tyre_radius = 50;
    int x=0;
    int y=0;

    int p=0;
    int flag=0;
    int flag2=0;
    int flag3=0;
    int flag4=0;


    while(1)
    {



        setactivepage(p);
        setvisualpage(1-p);
        cleardevice();
        int c1,c2;
        POINT cursorPos;
        GetCursorPos(&cursorPos);

        ScreenToClient(GetForegroundWindow(),&cursorPos);
        PT point= PT(cursorPos.x, cursorPos.y);
        PT point2= inv_convertPixel(point);
        int X1,Y1,X2,Y2,X3,Y3,X4,Y4,X11,Y11,X33,Y33;
        make_road();
        PT tyre_p1, tyre_p2;


        /// Creating Object: Car Body and Tyres and front light


        for(int i=0; i<=5; i++)
        {
            rectangle_l(x+i,y+i,x+car_length-i,y+car_height-i,RED); ///making object with my implemented algorithm
            rectangle_l(x+car_length-i+5,y+car_height-i-40,x+car_length-i+40,y+car_height-i,CYAN);

            tyre_p1 = PT((x+25),(y-50));
            tyre_p2 = PT((x+car_length-20), (y-50));

            bressenham_circle(tyre_p1,50-i,BLUE);  ///making object with my implemented algorithm
            bressenham_circle(tyre_p2,50-i,BLUE);
            X1= x+i;
            Y1= y+i;
            X3= x+car_length-i;
            Y3= y+car_height-i;
            X2=X3;
            Y2=Y1;
            X4=X1;
            Y4=Y3;
            X11 = x+car_length-i+5;
            Y11 = y+car_height-i-40;
            X33 = x+car_length-i+40;
            Y33 = y+car_height-i;
            tyre_radius= 50-i;

        }

        ///Checking The Mouse Cursor Whether in the Car body or not

        int xx,yy;
        if(check_body(X1,Y1,X3,Y3,point2.x,point2.y))
        {

            if(flag==0 && GetAsyncKeyState(VK_LBUTTON))
            {
                flag=1;
                //BoundaryFill(PT(point2.x,point2.y), RED, YELLOW );

                int backgroundColor = BLACK;
                FloodFill(PT(point2.x,point2.y), backgroundColor, YELLOW); ///Doing flood-fill of my implementation algo at click
                xx= point2.x;
                yy= point2.y;

            }
            if(flag==1 and GetAsyncKeyState(VK_LBUTTON))
            {
                flag=0;
                int backgroundColor = YELLOW;
                FloodFill(PT(point2.x,point2.y), backgroundColor, BLACK); ///Undo that with another click
                xx= point2.x;
                yy= point2.y;

            }
        }
        int xx1,yy1;


        ///Checking The Mouse Cursor Whether in the First tyre or not


        if(check_tyre(tyre_p1.x,tyre_p1.y,tyre_radius,point2.x,point2.y))
        {

            if(flag2==0 and GetAsyncKeyState(VK_LBUTTON))
            {
                flag2=1;
                //BoundaryFill(PT(point2.x,point2.y), RED, YELLOW );
                int backgroundColor = BLACK;
                FloodFill(PT(point2.x,point2.y), backgroundColor, MAGENTA);
                xx1= point2.x;
                yy1= point2.y;

            }
            if(flag2==1 and GetAsyncKeyState(VK_LBUTTON))
            {
                flag2=0;
                int backgroundColor = MAGENTA;
                FloodFill(PT(point2.x,point2.y), backgroundColor, BLACK);
                xx1= point2.x;
                yy1= point2.y;

            }
        }




        ///Checking The Mouse Cursor Whether in the Second tyre or not



        int xx2,yy2;

        if(check_tyre(tyre_p2.x,tyre_p2.y,tyre_radius,point2.x,point2.y))
        {

            if(flag3==0 and GetAsyncKeyState(VK_LBUTTON))
            {
                flag3=1;
                //BoundaryFill(PT(point2.x,point2.y), RED, YELLOW );
                int backgroundColor = BLACK;
                FloodFill(PT(point2.x,point2.y), backgroundColor, MAGENTA);
                xx2= point2.x;
                yy2= point2.y;

            }
            if(flag3==1 and GetAsyncKeyState(VK_LBUTTON))
            {
                flag3=0;
                int backgroundColor = MAGENTA;
                FloodFill(PT(point2.x,point2.y), backgroundColor, BLACK);
                xx2= point2.x;
                yy2= point2.y;

            }
        }

        ///Checking The Mouse Cursor Whether in the car front light or not

        int xx3,yy3;
        if(check_body(X11,Y11,X33,Y33,point2.x,point2.y))
        {

            if(flag4==0 and GetAsyncKeyState(VK_LBUTTON))
            {

                flag4=1;
                //BoundaryFill(PT(point2.x,point2.y), RED, YELLOW );
                int backgroundColor = getpixel(point.x,point.y);
                FloodFill(PT(point2.x,point2.y), backgroundColor, LIGHTGRAY); ///Doing flood-fill of my implementation algo at click
                xx3= point2.x;
                yy3= point2.y;


            }
            if(flag4==1 and GetAsyncKeyState(VK_LBUTTON))
            {
                flag4=0;
                int backgroundColor = LIGHTGRAY;
                FloodFill(PT(point2.x,point2.y), backgroundColor, BLACK); ///Undo that with another click
                xx3= point2.x;
                yy3= point2.y;

            }
        }


        ///Moving the Car


        int backgroundColor = BLACK;
        int alpha = 15;    ///Moving rate of each key stroke is alpha
        if(GetAsyncKeyState(VK_RIGHT))
        {
            x+=alpha;
            if(flag==1)
            {
                FloodFill(PT(xx+alpha,yy),backgroundColor, YELLOW);

            }
            if(flag2 ==1)
            {
                FloodFill(PT(xx1+alpha,yy1),backgroundColor, MAGENTA);
            }
            if(flag3 ==1)
            {
                FloodFill(PT(xx2+alpha,yy2),backgroundColor, MAGENTA);
            }
            if(flag4 ==1)
            {
                FloodFill(PT(xx3+5,yy3),backgroundColor, LIGHTGRAY);
            }
            xx=xx+alpha;
            xx1=xx1+alpha;
            xx2=xx2+alpha;
            xx3=xx3+alpha;



        }


        else if(GetAsyncKeyState(VK_LEFT))
        {
            x-=alpha;
            if(flag==1)
            {
                FloodFill(PT(xx-alpha,yy),backgroundColor, YELLOW);
            }
            if(flag2 ==1)
            {
                FloodFill(PT(xx1-alpha,yy1),backgroundColor, MAGENTA);
            }
            if(flag3 ==1)
            {
                FloodFill(PT(xx2-alpha,yy2),backgroundColor, MAGENTA);
            }
            if(flag4 ==1)
            {
                FloodFill(PT(xx3-5,yy3),backgroundColor, LIGHTGRAY);
            }
            xx=xx-alpha;
            xx1=xx1-alpha;
            xx2=xx2-alpha;
            xx3=xx3-alpha;

        }
        else
        {
            if(flag==1)
            {
                FloodFill(PT(xx,yy), backgroundColor, YELLOW);
            }
            if(flag2==1)
            {
                FloodFill(PT(xx1,yy1), backgroundColor, MAGENTA);
            }
            if(flag3==1)
            {
                FloodFill(PT(xx2,yy2), backgroundColor, MAGENTA);
            }
            if(flag4==1)
            {
                FloodFill(PT(xx3,yy3), backgroundColor, LIGHTGRAY);
            }
        }
        if(GetAsyncKeyState(VK_LSHIFT))
        {
            break;
        }

        delay(10);

        p = 1-p;


    }





    closegraph();
    getchar();

}
