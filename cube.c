#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strswap(char *s,char *t);  
void strarrswap(char *matrix[3][3],char *rc,char *matrix1[3][3],char *rc1);     
void facerotate(char *matrix[3][3]);void rfacerotate(char *matrix[3][3]);    
void notationf();void notationb();void notationd();void notationl();void notationr();void notationu();      
void notationfp();void notationbp();void notationdp();void notationlp();void notationrp();void notationup();
void scanface(char *matrix[3][3],int row,int col);      
void printface(char *matrix[3][3],int row,int col);     
void paintface(char *matrix[3][3],int row,int col,char *color);     
void freeface(char *matrix[3][3],int row,int col);
void manualcube(char *s);
void initcube();void endcube();
void printcube();   

struct face{
    char *color[3][3];  
};
typedef struct face face;

face front,back,down,up,left,right;     

void strswap(char *s,char *t)
{
    char* temp=(char*)malloc(strlen(s)+1);
    strcpy(temp,s);
    strcpy(s,t);
    strcpy(t,temp);
}

void facerotate(char *matrix[3][3])
{
    strswap(matrix[0][0],matrix[0][2]);
    strswap(matrix[0][0],matrix[2][2]);
    strswap(matrix[0][0],matrix[2][0]);
    strswap(matrix[0][1],matrix[1][2]);
    strswap(matrix[0][1],matrix[2][1]);
    strswap(matrix[0][1],matrix[1][0]);
}

void rfacerotate(char *matrix[3][3])
{
    strswap(matrix[0][0],matrix[2][0]);
    strswap(matrix[0][0],matrix[2][2]);
    strswap(matrix[0][0],matrix[0][2]);
    strswap(matrix[0][1],matrix[1][0]);
    strswap(matrix[0][1],matrix[2][1]);
    strswap(matrix[0][1],matrix[1][2]);
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
                strswap(matrix[cr][i],matrix1[cr1][i]);
            }
        }

        else if (*rc1=='c')
        {
            for (int i=0;i<3;++i)
            {
                strswap(matrix[cr][i],matrix1[i][cr1]);
            }
        }
    }

    else if (*rc=='c')
    {
        if (*rc1=='c')
        {
            for (int i=0;i<3;++i)
            {
                strswap(matrix[i][cr],matrix1[i][cr1]);
            }
        }

        else if(*rc1=='r')
        {
            for (int i=0;i<3;++i)
            {
                strswap(matrix[i][cr],matrix1[cr1][i]);
            }
        }
    }
}

void notationf()
{
    strswap(left.color[0][2],left.color[2][2]);
    strswap(right.color[0][0],right.color[2][0]);
    strarrswap(down.color,(char *)"r0",left.color,(char *)"c2");
    strarrswap(down.color, (char *)"r0",up.color, (char *)"r2");
    strarrswap(down.color, (char *)"r0",right.color, (char *)"c0");
    facerotate(front.color);
}

void notationr()
{
    strarrswap(down.color, (char *)"c2",front.color, (char *)"c2");
    strarrswap(down.color, (char *)"c2",up.color, (char *)"c2");
    strarrswap(down.color, (char *)"c2",back.color, (char *)"c2");
    facerotate(right.color);
}

void notationl()
{
    strarrswap(down.color, (char *)"c0",back.color, (char *)"c0");
    strarrswap(down.color, (char *)"c0",up.color, (char *)"c0");
    strarrswap(down.color, (char *)"c0",front.color, (char *)"c0");
    facerotate(left.color);
}

void notationu()
{
    strswap(back.color[2][0],back.color[2][2]);
    strswap(left.color[0][0],left.color[0][2]);
    strarrswap(front.color, (char *)"r0",left.color, (char *)"r0");
    strarrswap(front.color, (char *)"r0",back.color, (char *)"r2");
    strarrswap(front.color, (char *)"r0",right.color, (char *)"r0");
    facerotate(up.color);
}

void notationd()
{
    strswap(back.color[0][0],back.color[0][2]);
    strswap(right.color[2][0],right.color[2][2]);
    strarrswap(front.color, (char *)"r2",right.color, (char *)"r2");
    strarrswap(front.color, (char *)"r2",back.color, (char *)"r0");
    strarrswap(front.color, (char *)"r2",left.color, (char *)"r2");
    facerotate(down.color);
}

void notationb()
{
    strswap(up.color[0][0],up.color[0][2]);
    strswap(down.color[2][0],down.color[2][2]);
    strarrswap(down.color, (char *)"r2",right.color, (char *)"c2");
    strarrswap(down.color, (char *)"r2",up.color, (char *)"r0");
    strarrswap(down.color, (char *)"r2",left.color, (char *)"c0");
    rfacerotate(back.color);
}

void notationfp()
{
    strswap(up.color[2][0],up.color[2][2]);
    strswap(down.color[0][0],down.color[0][2]);
    strarrswap(down.color, (char *)"r0",right.color, (char *)"c0");
    strarrswap(down.color, (char *)"r0",up.color, (char *)"r2");
    strarrswap(down.color, (char *)"r0",left.color, (char *)"c2");
    rfacerotate(front.color);
}

void notationrp()
{
    strarrswap(down.color, (char *)"c2",back.color, (char *)"c2");
    strarrswap(down.color, (char *)"c2",up.color, (char *)"c2");
    strarrswap(down.color, (char *)"c2",front.color, (char *)"c2");
    rfacerotate(right.color);
}

void notationlp()
{
    strarrswap(down.color, (char *)"c0",front.color, (char *)"c0");
    strarrswap(down.color, (char *)"c0",up.color, (char *)"c0");
    strarrswap(down.color, (char *)"c0",back.color, (char *)"c0");
    rfacerotate(left.color);
}

void notationup()
{
    strswap(back.color[2][0],back.color[2][2]);
    strswap(right.color[0][0],right.color[0][2]);
    strarrswap(front.color, (char *)"r0",right.color, (char *)"r0");
    strarrswap(front.color, (char *)"r0",back.color, (char *)"r2");
    strarrswap(front.color, (char *)"r0",left.color, (char *)"r0");
    rfacerotate(up.color);
}

void notationdp()
{
    strswap(back.color[0][0],back.color[0][2]);
    strswap(left.color[2][0],left.color[2][2]);
    strarrswap(front.color, (char *)"r2",left.color, (char *)"r2");
    strarrswap(front.color, (char *)"r2",back.color, (char *)"r0");
    strarrswap(front.color, (char *)"r2",right.color, (char *)"r2");
    rfacerotate(down.color);
}

void notationbp()
{
    strswap(right.color[0][2],right.color[2][2]);
    strswap(left.color[0][0],left.color[2][0]);
    strarrswap(down.color, (char *)"r2",left.color, (char *)"c0");
    strarrswap(down.color, (char *)"r2",up.color, (char *)"r0");
    strarrswap(down.color, (char *)"r2",right.color, (char *)"c2");
    rfacerotate(back.color);
}

void scanface(char *matrix[3][3],int row,int col)
{
    for(int r=0;r<row;++r)
    {
        for(int c=0;c<col;++c)
        {
            matrix[r][c]=(char*)malloc(10);
            printf("row%dcolumn%d:",r,c);
            scanf("%s",matrix[r][c]);
        }
    }
}

void printface(char *matrix[3][3],int row,int col)
{
    for(int r=0;r<row;++r)
    {
        for(int c=0;c<col;++c)
        {
            printf("%s   ",matrix[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

void paintface(char *matrix[3][3],int row,int col,char *color)
{
    for(int r=0;r<row;++r)
    {
        for(int c=0;c<col;++c)
        {
            matrix[r][c]=(char*)malloc(strlen(color)+2);
            strcpy(matrix[r][c],color);
        }
    }
}

void freeface(char *matrix[3][3],int row,int col)
{
    for(int r=0;r<row;++r)
    {
        for(int c=0;c<col;++c)
        {
            free(matrix[r][c]);
        }
    }
}

void manualcube(char *s)
{
    for(int i=0;s[i]!='\0';++i)
    {
        if(s[i+1]=='p')
        {
            switch(s[i]){
            case 'R':case 'r':
                notationrp();
                break;
            case 'L':case 'l':
                notationlp();
                break;
            case 'U':case 'u':
                notationup();
                break;
            case 'D':case 'd':
                notationdp();
                break;
            case 'F':case 'f':
                notationfp();
                break;
            case 'B':case 'b':
                notationbp();
                break;
            }
            ++i;
        }

        else if(s[i+1]=='2')
        {
            switch(s[i]){
            case 'R':case 'r':
                notationr();
                notationr();
                break;
            case 'L':case 'l':
                notationl();
                notationl();
                break;
            case 'U':case 'u':
                notationu();
                notationu();
                break;
            case 'D':case 'd':
                notationd();
                notationd();
                break;
            case 'F':case 'f':
                notationf();
                notationf();
                break;
            case 'B':case 'b':
                notationb();
                notationb();
                break;
            }
            ++i;
        }

        else
        {
            switch(s[i]){
            case 'R':case 'r':
                notationr();
                break;
            case 'L':case 'l':
                notationl();
                break;
            case 'U':case 'u':
                notationu();
                break;
            case 'D':case 'd':
                notationd();
                break;
            case 'F':case 'f':
                notationf();
                break;
            case 'B':case 'b':
                notationb();
                break;
            }
        }
    }
}

void initcube()
{
    paintface(front.color,3,3, (char *)"G");
    paintface(back.color,3,3, (char *)"B");
    paintface(down.color,3,3, (char *)"W");
    paintface(up.color,3,3, (char *)"Y");
    paintface(left.color,3,3, (char *)"R");
    paintface(right.color,3,3, (char *)"O");
}

void endcube()
{
    freeface(front.color,3,3);
    freeface(back.color,3,3);
    freeface(down.color,3,3);
    freeface(up.color,3,3);
    freeface(left.color,3,3);
    freeface(right.color,3,3);
}

void printcube()
{
    printf("front:\n");
    printface(front.color,3,3);
    printf("back:\n");
    printface(back.color,3,3);
    printf("down:\n");
    printface(down.color,3,3);
    printf("up\n");
    printface(up.color,3,3);
    printf("left\n");
    printface(left.color,3,3);
    printf("right\n");
    printface(right.color,3,3);
}

int main()
{
    initcube();
    ///////////
    manualcube((char *)"ru2rpupru2lpurpupl");
    ///////////
    printcube();
    endcube();
}