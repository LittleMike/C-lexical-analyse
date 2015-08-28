#include"declaration.h"

void zhuShiChuLi(FILE* fPtr,FILE* outputfile) //注释
{

    if(c=='/') // "//"的情况
    {
        printf("%c%c",preC,c);
        fprintf(outputfile,"%c%c",preC,c);
        while(!feof(fPtr))
        {
            c=fgetc(fPtr);
            printf("%c",c);
            fprintf(outputfile,"%c",c);
            if(c=='\n') break;
        }
    }

    else if(c=='*') // "/*...*/"的情况
    {
        printf("%c%c",preC,c);
        fprintf(outputfile,"%c%c",preC,c);
        while(!feof(fPtr))
        {
            c=fgetc(fPtr);
            printf("%c",c);
            fprintf(outputfile,"%c",c);
            if(c=='*')
            {
                c=fgetc(fPtr);
                printf("%c",c);
                fprintf(outputfile,"%c",c);
                if(c=='/')
                {
                    c=fgetc(fPtr);
                    printf("\n");
                    fprintf(outputfile,"\n");
                    break;
                }
            }
        }
    }
    else
    {
        printf("/");
        fprintf(outputfile,"/");
    }
}

void bianYiYuChuLi(FILE* fPtr,FILE* outputfile) //编译预处理
{

    printf("%c%c",preC,c);
    fprintf(outputfile,"%c%c",preC,c);
    while(!feof(fPtr))
    {
        c=fgetc(fPtr);
        printf("%c",c);
        fprintf(outputfile,"%c",c);
        if(c=='\n') break;
    }
}
