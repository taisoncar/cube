#include <stdio.h>
#include "clibrary.h"
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
void initcube();
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
    strarrswap(down.color,"r0",left.color,"c2");
    strarrswap(down.color,"r0",up.color,"r2");
    strarrswap(down.color,"r0",right.color,"c0");
    facerotate(front.color);
}

void notationr()
{
    strarrswap(down.color,"c2",front.color,"c2");
    strarrswap(down.color,"c2",up.color,"c2");
    strarrswap(down.color,"c2",back.color,"c2");
    facerotate(right.color);
}

void notationl()
{
    strarrswap(down.color,"c0",back.color,"c0");
    strarrswap(down.color,"c0",up.color,"c0");
    strarrswap(down.color,"c0",front.color,"c0");
    facerotate(left.color);
}

void notationu()
{
    strswap(back.color[2][0],back.color[2][2]);
    strswap(left.color[0][0],left.color[0][2]);
    strarrswap(front.color,"r0",left.color,"r0");
    strarrswap(front.color,"r0",back.color,"r2");
    strarrswap(front.color,"r0",right.color,"r0");
    facerotate(up.color);
}

void notationd()
{
    strswap(back.color[0][0],back.color[0][2]);
    strswap(right.color[2][0],right.color[2][2]);
    strarrswap(front.color,"r2",right.color,"r2");
    strarrswap(front.color,"r2",back.color,"r0");
    strarrswap(front.color,"r2",left.color,"r2");
    facerotate(down.color);
}

void notationb()
{
    strswap(up.color[0][0],up.color[0][2]);
    strswap(down.color[2][0],down.color[2][2]);
    strarrswap(down.color,"r2",right.color,"c2");
    strarrswap(down.color,"r2",up.color,"r0");
    strarrswap(down.color,"r2",left.color,"c0");
    rfacerotate(back.color);
}

void notationfp()
{
    strswap(up.color[2][0],up.color[2][2]);
    strswap(down.color[0][0],down.color[0][2]);
    strarrswap(down.color,"r0",right.color,"c0");
    strarrswap(down.color,"r0",up.color,"r2");
    strarrswap(down.color,"r0",left.color,"c2");
    rfacerotate(front.color);
}

void notationrp()
{
    strarrswap(down.color,"c2",back.color,"c2");
    strarrswap(down.color,"c2",up.color,"c2");
    strarrswap(down.color,"c2",front.color,"c2");
    rfacerotate(right.color);
}

void notationlp()
{
    strarrswap(down.color,"c0",front.color,"c0");
    strarrswap(down.color,"c0",up.color,"c0");
    strarrswap(down.color,"c0",back.color,"c0");
    rfacerotate(left.color);
}

void notationup()
{
    strswap(back.color[2][0],back.color[2][2]);
    strswap(right.color[0][0],right.color[0][2]);
    strarrswap(front.color,"r0",right.color,"r0");
    strarrswap(front.color,"r0",back.color,"r2");
    strarrswap(front.color,"r0",left.color,"r0");
    rfacerotate(up.color);
}

void notationdp()
{
    strswap(back.color[0][0],back.color[0][2]);
    strswap(left.color[2][0],left.color[2][2]);
    strarrswap(front.color,"r2",left.color,"r2");
    strarrswap(front.color,"r2",back.color,"r0");
    strarrswap(front.color,"r2",right.color,"r2");
    rfacerotate(down.color);
}

void notationbp()
{
    strswap(right.color[0][2],right.color[2][2]);
    strswap(left.color[0][0],left.color[2][0]);
    strarrswap(down.color,"r2",left.color,"c0");
    strarrswap(down.color,"r2",up.color,"r0");
    strarrswap(down.color,"r2",right.color,"c2");
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
            matrix[r][c]=(char*)malloc(strlen(color)+1);
            strcpy(matrix[r][c],color);
        }
    }
}

void initcube()
{
    paintface(front.color,3,3,"G");
    paintface(back.color,3,3,"B");
    paintface(down.color,3,3,"W");
    paintface(up.color,3,3,"Y");
    paintface(left.color,3,3,"R");
    paintface(right.color,3,3,"O");
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
    notationb();
    notationbp();
    notationdp();
    notationf();
    printcube();
}