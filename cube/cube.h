#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strswap(char *s, char *t); 
void strarrswap(char *matrix[3][3],char *rc,char *matrix1[3][3],char *rc1);     
void facerotate(char *matrix[3][3]);void rfacerotate(char *matrix[3][3]);    
void notation_f();void notation_b();void notation_d();void notation_l();void notation_r();void notation_u();      
void printface(char *matrix[3][3]);     
void paintface(char *matrix[3][3],char *color);     
void freeface(char *matrix[3][3]);
void manualcube(char *s);
void initcube();void endcube();
void printcube();   

typedef struct {
    char *color[3][3];  
}face;
face front, back, down, up, left, right;     

void strswap(char *s,char *t)
{
    char* temp=(char*)malloc(strlen(s)+1);
    strcpy(temp,s);
    strcpy(s,t);
    strcpy(t,temp);
}

void facerotate(char *matrix[3][3])
{
    //corner pieces
    strswap(matrix[0][0],matrix[0][2]);
    strswap(matrix[0][0],matrix[2][2]);
    strswap(matrix[0][0],matrix[2][0]);
    //edge pieces
    strswap(matrix[0][1],matrix[1][2]);
    strswap(matrix[0][1],matrix[2][1]);
    strswap(matrix[0][1],matrix[1][0]);
}

void strarrswap(char *matrix[3][3],char *rc,char *matrix1[3][3],char *rc1)
{
    int cr=*(rc+1)-'0';
    int cr1=*(rc1+1)-'0';
    
    if (*rc=='r')
    {
        if (*rc1=='r')
        {
            for (int i=0;i<3;++i)
            {
                strswap(matrix[i][cr],matrix1[i][cr1]);
            }
        }

        else if (*rc1=='c')
        {
            for (int i=0;i<3;++i)
            {
                strswap(matrix[i][cr],matrix1[cr1][i]);
            }
        }
    }

    else if (*rc=='c')
    {
        if (*rc1=='c')
        {
            for (int i=0;i<3;++i)
            {
                strswap(matrix[cr][i],matrix1[cr1][i]);
            }
        }

        else if(*rc1=='r')
        {
            for (int i=0;i<3;++i)
            {
                strswap(matrix[cr][i],matrix1[i][cr1]);
            }
        }
    }
}

void notation_f()
{
    strarrswap(down.color, (char *)"r2",left.color,(char *)"c2");
    strswap(left.color[2][0],left.color[2][2]);                    
    strarrswap(down.color, (char *)"r2",up.color, (char *)"r0");
    strarrswap(down.color, (char *)"r2",right.color, (char *)"c0");
    strswap(right.color[0][0],right.color[0][2]);
    facerotate(front.color);
}

void notation_b()
{
    strarrswap(down.color, (char *)"r0",right.color, (char *)"c2");
    strarrswap(down.color, (char *)"r0",up.color, (char *)"r2");
    strswap(up.color[0][2],up.color[2][2]);
    strarrswap(down.color, (char *)"r0",left.color, (char *)"c0");
    strswap(down.color[0][0],down.color[2][0]);
    facerotate(back.color);
}

void notation_r()
{
    strarrswap(down.color, (char *)"c2",front.color, (char *)"c2");
    strarrswap(down.color, (char *)"c2",up.color, (char *)"c2");
    strarrswap(down.color, (char *)"c2",back.color, (char *)"c0");
    strswap(back.color[0][0],back.color[0][2]);
    strswap(down.color[2][0],down.color[2][2]);
    facerotate(right.color);
}

void notation_l()
{
    strarrswap(down.color, (char *)"c0",back.color, (char *)"c2");
    strswap(back.color[2][0],back.color[2][2]);
    strarrswap(down.color, (char *)"c0",up.color, (char *)"c0");
    strswap(up.color[0][0],up.color[0][2]);
    strarrswap(down.color, (char *)"c0",front.color, (char *)"c0");
    facerotate(left.color);
}

void notation_u()
{
    strarrswap(front.color, (char *)"r2",left.color, (char *)"r2");
    strarrswap(front.color, (char *)"r2",back.color, (char *)"r2");
    strarrswap(front.color, (char *)"r2",right.color, (char *)"r2");
    facerotate(up.color);
}

void notation_d()
{
    strarrswap(front.color, (char *)"r0",right.color, (char *)"r0");
    strarrswap(front.color, (char *)"r0",back.color, (char *)"r0");
    strarrswap(front.color, (char *)"r0",left.color, (char *)"r0");
    facerotate(down.color);
}

void printface(char *matrix[3][3])
{
    for(int r=2;r>=0;--r)
    {
        for(int c=0;c<3;++c)
        {
            printf("%s   ",matrix[c][r]);
        }
        printf("\n");
    }
    printf("\n");
}

void paintface(char *matrix[3][3],char *color)
{
    for(int r=0;r<3;++r)
    {
        for(int c=0;c<3;++c)
        {
            matrix[c][r]=(char*)malloc(strlen(color)+2);
            strcpy(matrix[c][r],color);
        }
    }
}

void freeface(char *matrix[3][3])
{
    for(int r=0;r<3;++r)
    {
        for(int c=0;c<3;++c)
        {
            free(matrix[c][r]);
        }
    }
}

void manualcube(char *s)
{
    for(int i=0;s[i]!='\0';++i)
    {
        if(s[i+1]=='p' || s[i+1]=='\'' || s[i+1]=='P')
        {
            switch(s[i]){
            case 'R':case 'r':
                //notation_rp();
                notation_r();
                notation_r();
                notation_r();
                break;
            case 'L':case 'l':
                //notation_lp();
                notation_l();
                notation_l();
                notation_l();
                break;
            case 'U':case 'u':
                //notation_up();
                notation_u();
                notation_u();
                notation_u();
                break;
            case 'D':case 'd':
                //notation_dp();
                notation_d();
                notation_d();
                notation_d();
                break;
            case 'F':case 'f':
                //notation_fp();
                notation_f();
                notation_f();
                notation_f();
                break;
            case 'B':case 'b':
                //notation_bp();
                notation_b();
                notation_b();
                notation_b();
                break;
            }
        }

        else if(s[i+1]=='2')
        {
            switch(s[i]){
            case 'R':case 'r':
                notation_r();
                notation_r();
                break;
            case 'L':case 'l':
                notation_l();
                notation_l();
                break;
            case 'U':case 'u':
                notation_u();
                notation_u();
                break;
            case 'D':case 'd':
                notation_d();
                notation_d();
                break;
            case 'F':case 'f':
                notation_f();
                notation_f();
                break;
            case 'B':case 'b':
                notation_b();
                notation_b();
                break;
            }
        }

        else
        {
            switch(s[i]){
            case 'R':case 'r':
                notation_r();
                break;
            case 'L':case 'l':
                notation_l();
                break;
            case 'U':case 'u':
                notation_u();
                break;
            case 'D':case 'd':
                notation_d();
                break;
            case 'F':case 'f':
                notation_f();
                break;
            case 'B':case 'b':
                notation_b();
                break;
            }
        }
    }
}

void initcube()
{
    paintface(front.color, (char *)"G");
    paintface(back.color, (char *)"B");
    paintface(down.color, (char *)"Y");
    paintface(up.color, (char *)"W");
    paintface(left.color, (char *)"O");
    paintface(right.color, (char *)"R");
}

void endcube()
{
    freeface(front.color);
    freeface(back.color);
    freeface(down.color);
    freeface(up.color);
    freeface(left.color);
    freeface(right.color);
}

void printcube()
{
    printf("front:\n");
    printface(front.color);
    printf("back:\n");
    printface(back.color);
    printf("down:\n");
    printface(down.color);
    printf("up\n");
    printface(up.color);
    printf("left\n");
    printface(left.color);
    printf("right\n");
    printface(right.color);
    printf("-----------------------------\n");
}

