#include"declaration.h"

void baoLZBiaoSF(FILE* fPtr,FILE* op)
{

    flag=0;//重要分支标志
    a[0]=preC;
    for(i=1; (c>='A'&&c<='Z')||(c>='a'&&c<='z')||c=='_'||(c>='0'&&c<='9'); i++) //将单词读入
    {
        a[i]=c;
        c=fgetc(fPtr);
    }
    a[i]='\0';
    for(j=0; j<i; j++) //查找有没有'_'和数字
    {
        if(a[j]=='_'||(a[j]>='0'&&a[j]<='9')) //显然，当j=0时，a[j]肯定不是数字
        {
            if(a[0]=='_') break;//考虑到两种可能情况：_Imaginary,_Complex
            flag=1;
            break;
        }
    }
    //以上是对读入的单词的判断算法

    if(flag==0) //保留字的情况
    {
        for(i=0; i<37; i++) //查找
        {
            if(!strcmp(a,baoLiuZi[i].mPtr))
            {
                printf("0   保留字     %2d   %s\n",baoLiuZi[i].mNum,baoLiuZi[i].mPtr);
                fprintf(op,"0   保留字     %2d   %s\n",baoLiuZi[i].mNum,baoLiuZi[i].mPtr);

                //对出现过的保留字进行存档
                for(j=0; j<blzA_i; j++)
                {
                    if(baoLiuZAppeared[j]==&baoLiuZi[i])
                    {
                        break;
                    }
                }
                if(j==blzA_i)
                {
                    baoLiuZAppeared[blzA_i++]=&baoLiuZi[i];
                }
                //对出现过的保留字进行存档结束

                break;
            }
        }
        if(i==37) flag=1;//保留字中没找到，是标识符
    }

    if(flag==1) //标识符的情况
    {
        for(i=0; i<biaoXu; i++) //先查找
        {
            if(!strcmp(a,biaoZhiFu[i].mPtr))
            {
                printf("3   标识符     %2d   %s\n",biaoZhiFu[i].mNum,biaoZhiFu[i].mPtr);
                fprintf(op,"3   标识符     %2d   %s\n",biaoZhiFu[i].mNum,biaoZhiFu[i].mPtr);
                break;
            }
        }
        if(biaoXu<=BIAOZHIFU_NUM)
        {
            if(i==biaoXu) //若没找到则保存它
            {
                strcpy(biaoZhiFu[biaoXu++].mPtr,a);
                biaoZhiFu[biaoXu-1].mNum=biaoXu;
                printf("3   标识符     %2d   %s\n",biaoZhiFu[biaoXu-1].mNum,biaoZhiFu[biaoXu-1].mPtr);
                fprintf(op,"3   标识符     %2d   %s\n",biaoZhiFu[biaoXu-1].mNum,biaoZhiFu[biaoXu-1].mPtr);
            }
        }
        else
        {
            printf("这个源文件的标识符个数超过了%d个，修改宏定义吧~\n",BIAOZHIFU_NUM);
            fprintf(op,"这个源文件的标识符个数超过了%d个，修改宏定义吧~\n",BIAOZHIFU_NUM);
            printf("输入任意字符后回车退出:");
            scanf("%c",&renYiZiFu);
            exit(0);
        }
    }
}
