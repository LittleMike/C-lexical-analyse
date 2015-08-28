#include"declaration.h"

void shuZiChangLiangChuLi(FILE* fPtr,FILE* op)
{

    flag=0;
    for(i=1; (c>='0'&&c<='9')||c=='.'||c=='x'||c=='X'; i++) //存入 //涵盖16进制和8进制
    {
        a[i]=c;       //此时c可能是'.'
        c=fgetc(fPtr);//此时c可能是'.'

        //浮点型常量的情况
        if(c=='.'||a[i]=='.'||a[0]=='.') //浮点型定点形式3种情况都涵盖
        {
            if(a[i]=='.'&&(c<'0'||c>'9')) //处理xxx.的形式
            {
                i++;
                a[i]='\0';
            }
            else
            {
                a[i+1]=c;
                c=fgetc(fPtr);
                for(j=i+2; c>='0'&&c<='9'; j++) //存入
                {
                    a[j]=c;
                    c=fgetc(fPtr);
                }
                a[j]='\0';
            }

            //x.xe(或E)(+或-或没有)xx的情况以及数字后面有l(L)或f(F)的情况
            if(c=='e'||c=='E')
            {
                k=strlen(a);
                a[k]=c;
                c=fgetc(fPtr);
                if(c=='-'||c=='+') //这样写是为了防止指数形式浮点数相加减时出错
                {
                    a[++k]=c;
                    c=fgetc(fPtr);
                }
                for(k++; (c>='0'&&c<='9')||c=='l'||c=='L'||c=='f'||c=='F'; k++)
                {
                    a[k]=c;
                    c=fgetc(fPtr);
                }
                a[k]='\0';
            }
            else if(c=='l'||c=='L'||c=='f'||c=='F')
            {
                k=strlen(a);
                a[k]=c;
                a[k+1]='\0';
                c=fgetc(fPtr);
            }

            for(k=0; k<fuDian_i; k++) //查找
            {
                if(!strcmp(a,fuDian[k].mPtr))
                {
                    printf("4 1 浮点型常量 %2d   %s\n",fuDian[k].mNum,fuDian[k].mPtr);
                    fprintf(op,"4 1 浮点型常量 %2d   %s\n",fuDian[k].mNum,fuDian[k].mPtr);
                    flag=1;
                    break;
                }
            }
            if(k==fuDian_i) //没找到则新建
            {
                strcpy(fuDian[fuDian_i++].mPtr,a);
                fuDian[fuDian_i-1].mNum=fuDian_i;
                printf("4 1 浮点型常量 %2d   %s\n",fuDian[fuDian_i-1].mNum,fuDian[fuDian_i-1].mPtr);
                fprintf(op,"4 1 浮点型常量 %2d   %s\n",fuDian[fuDian_i-1].mNum,fuDian[fuDian_i-1].mPtr);
                flag=1;
            }
        }
    }

    //整型常量的情况
    if(flag==0)
    {
        if(c=='e'||c=='E') //xxe(或E)(+或-或没有)xx的情况
        {
            a[i]=c;
            c=fgetc(fPtr);
            if(c=='-'||c=='+') //防止进行加减时出错
            {
                a[++i]=c;
                c=fgetc(fPtr);
            }
            for(i++; (c>='0'&&c<='9')||c=='l'||c=='L'; i++)
            {
                a[i]=c;
                c=fgetc(fPtr);
            }
            a[i]='\0';

            for(i=0; i<fuDian_i; i++) //查找
            {
                if(!strcmp(a,fuDian[i].mPtr))
                {
                    printf("4 1 浮点型常量 %2d   %s\n",fuDian[i].mNum,fuDian[i].mPtr);
                    fprintf(op,"4 1 浮点型常量 %2d   %s\n",fuDian[i].mNum,fuDian[i].mPtr);
                    flag=1;
                    break;
                }
            }
            if(i==fuDian_i) //没找到则新建
            {
                strcpy(fuDian[fuDian_i++].mPtr,a);
                fuDian[fuDian_i-1].mNum=fuDian_i;
                printf("4 1 浮点型常量 %2d   %s\n",fuDian[fuDian_i-1].mNum,fuDian[fuDian_i-1].mPtr);
                fprintf(op,"4 1 浮点型常量 %2d   %s\n",fuDian[fuDian_i-1].mNum,fuDian[fuDian_i-1].mPtr);
                flag=1;
            }

        }
        else if(c=='l'||c=='L') //整数数字后面有l(L)的处理
        {
            a[i]=c;
            a[i+1]='\0';
            c=fgetc(fPtr);
        }
        else a[i]='\0';//没有l(L)的处理

        if(flag==0) //需要把插入整型代码中的浮点型代码过滤掉
        {
            for(i=0; i<zhengShu_i; i++) //查找
            {
                if(!strcmp(a,zhengShu[i].mPtr))
                {
                    printf("4 0 整型常量   %2d   %s\n",zhengShu[i].mNum,zhengShu[i].mPtr);
                    fprintf(op,"4 0 整型常量   %2d   %s\n",zhengShu[i].mNum,zhengShu[i].mPtr);
                    break;
                }
            }
            if(i==zhengShu_i) //没找到则新建
            {
                strcpy(zhengShu[zhengShu_i++].mPtr,a);
                zhengShu[zhengShu_i-1].mNum=zhengShu_i;
                printf("4 0 整型常量   %2d   %s\n",zhengShu[zhengShu_i-1].mNum,zhengShu[zhengShu_i-1].mPtr);
                fprintf(op,"4 0 整型常量   %2d   %s\n",zhengShu[zhengShu_i-1].mNum,zhengShu[zhengShu_i-1].mPtr);
            }
        }
    }
}
