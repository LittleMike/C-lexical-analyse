#include"declaration.h"

void shuChuBiaoZF(FILE* op)
{
    printf("\n本程序涉及的标识符表如下:\n\n");
    fprintf(op,"\n本程序涉及的标识符表如下:\n\n");
    if(biaoXu==0)
    {
        printf("无\n");
        fprintf(op,"无\n");
    }
    else
    {
        printf("地址    标识符\n");
        fprintf(op,"地址    标识符\n");
        for(i=0; i<biaoXu; i++)
        {
            printf("%4d    %s\n",biaoZhiFu[i].mNum,biaoZhiFu[i].mPtr);
            fprintf(op,"%4d    %s\n",biaoZhiFu[i].mNum,biaoZhiFu[i].mPtr);
        }
    }
}

void shuChuZhengXing(FILE* op)
{
    printf("\n本程序涉及的整数类型常量表如下:\n\n");
    fprintf(op,"\n本程序涉及的整数类型常量表如下:\n\n");
    if(zhengShu_i==0)
    {
        printf("无\n");
        fprintf(op,"无\n");
    }
    else
    {
        printf("地址    整数类型常量\n");
        fprintf(op,"地址    整数类型常量\n");
        for(i=0; i<zhengShu_i; i++)
        {
            printf("%4d    %s\n",zhengShu[i].mNum,zhengShu[i].mPtr);
            fprintf(op,"%4d    %s\n",zhengShu[i].mNum,zhengShu[i].mPtr);
        }
    }
}

void shuChuFuDianXing(FILE* op)
{
    printf("\n本程序涉及的浮点类型常量表如下:\n\n");
    fprintf(op,"\n本程序涉及的浮点类型常量表如下:\n\n");
    if(fuDian_i==0)
    {
        printf("无\n");
        fprintf(op,"无\n");
    }
    else
    {
        printf("地址    浮点类型常量\n");
        fprintf(op,"地址    浮点类型常量\n");
        for(i=0; i<fuDian_i; i++)
        {
            printf("%4d    %s\n",fuDian[i].mNum,fuDian[i].mPtr);
            fprintf(op,"%4d    %s\n",fuDian[i].mNum,fuDian[i].mPtr);
        }
    }
}

void shuChuZiFu(FILE* op)
{
    printf("\n本程序涉及的字符类型常量表如下:\n\n");
    fprintf(op,"\n本程序涉及的字符类型常量表如下:\n\n");
    if(ziFu_i==0)
    {
        printf("无\n");
        fprintf(op,"无\n");
    }
    else
    {
        printf("地址    字符类型常量\n");
        fprintf(op,"地址    字符类型常量\n");
        for(i=0; i<ziFu_i; i++)
        {
            printf("%4d    %s\n",ziFu[i].mNum,ziFu[i].mPtr);
            fprintf(op,"%4d    %s\n",ziFu[i].mNum,ziFu[i].mPtr);
        }
    }
}

void shuChuZiFuChuan(FILE* op)
{
    printf("\n本程序涉及的字符串类型常量表如下:\n\n");
    fprintf(op,"\n本程序涉及的字符串类型常量表如下:\n\n");
    if(chuan_i==0)
    {
        printf("无\n");
        fprintf(op,"无\n");
    }
    else
    {
        printf("地址    字符串类型常量\n");
        fprintf(op,"地址    字符串类型常量\n");
        for(i=0; i<chuan_i; i++)
        {
            printf("%4d    %s\n",ziFuChuan[i].mNum,ziFuChuan[i].mPtr);
            fprintf(op,"%4d    %s\n",ziFuChuan[i].mNum,ziFuChuan[i].mPtr);
        }
    }
}

void shuChuBaoLiuZ(FILE* op)
{
    printf("\n本程序涉及的保留字编码如下:\n\n");
    fprintf(op,"\n本程序涉及的保留字编码如下:\n\n");
    if(blzA_i==0)
    {
        printf("无\n");
        fprintf(op,"无\n");
    }
    else
    {
        printf("编码    保留字\n");
        fprintf(op,"编码    保留字\n");
        for(i=0; i<blzA_i; i++)
        {
            printf("%4d    %s\n",baoLiuZAppeared[i]->mNum,baoLiuZAppeared[i]->mPtr);
            fprintf(op,"%4d    %s\n",baoLiuZAppeared[i]->mNum,baoLiuZAppeared[i]->mPtr);
        }
    }
}

void shuChuFenGeF(FILE* op)
{
    printf("\n本程序涉及的分隔符编码如下:\n\n");
    fprintf(op,"\n本程序涉及的分隔符编码如下:\n\n");
    if(fgfA_i==0)
    {
        printf("无\n");
        fprintf(op,"无\n");
    }
    else
    {
        printf("编码    分隔符\n");
        fprintf(op,"编码    分隔符\n");
        for(i=0; i<fgfA_i; i++)
        {
            printf("%4d    %s\n",fenGeFuAppeared[i]->mNum,fenGeFuAppeared[i]->mPtr);
            fprintf(op,"%4d    %s\n",fenGeFuAppeared[i]->mNum,fenGeFuAppeared[i]->mPtr);
        }
    }
}

void shuChuYunSuanFu(FILE* op)
{
    printf("\n本程序涉及的运算符编码如下:\n\n");
    fprintf(op,"\n本程序涉及的运算符编码如下:\n\n");
    if(ysfA_i==0)
    {
        printf("无\n");
        fprintf(op,"无\n");
    }
    else
    {
        printf("编码    运算符\n");
        fprintf(op,"编码    运算符\n");
        for(i=0; i<ysfA_i; i++)
        {
            printf("%4d    %s\n",yunSuanFuAppeared[i]->mNum,yunSuanFuAppeared[i]->mPtr);
            fprintf(op,"%4d    %s\n",yunSuanFuAppeared[i]->mNum,yunSuanFuAppeared[i]->mPtr);
        }
    }
}
