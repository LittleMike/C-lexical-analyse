#include"declaration.h"

int main(int argc,char* argv[])
{

    FILE* inputfile;//输入文件指针
    FILE* outfile;//输出文件指针

    char shuRu[51];//存储输入文件名  最长50个字符
    char xuanZe='\0';//存储用户的选择('1'和'2'),这里要用char型,保证不出错;若为int型,输入非数字会
    //出错
    for(i=0; i<BIANMA_NUM; i++)
    {
        baoLiuZAppeared[i]=NULL;
        fenGeFuAppeared[i]=NULL;
        yunSuanFuAppeared[i]=NULL;
    }//把指针变量先初始化(把这三个的数量最值(保留字的最值37)设成一样,方便初始化)


    printf("************************");
    printf("C词法分析程序 Zhenghz");
    printf("************************\n");//标题

    if((outfile=fopen("C词法分析结果.txt","a"))==NULL) //在输出文件中持续添加内容，不删除
    {
        printf("Can't create destination file!\n\n");
        exit(0);
    }//创建目标文件


    printf("\n/*说明:1.输入的文件名总长度不能超过50个字符。\n");
    printf("       2.本程序目前能存储的最长字段长度为%d。\n",ZIDUAN_LENGTH-1);
    printf("       3.本程序目前能解析的不同标识符个数最多为%d个。\n",BIAOZHIFU_NUM);
    printf("       4.本程序目前能解析的不同字符个数最多为%d个,字符串最多为%d个。\n",ZIFU_NUM,ZIFUCHUAN_NUM);
    printf("       5.本程序目前能解析的不同整型常量个数最多为%d个,浮点型最多为%d个。\n",ZHENGSHU_NUM,FUDIAN_NUM);
    printf("       6.本程序目前能检查到字符串常量的长度超界的情况。\n");
    printf("       7.本程序目前能检查到标识符个数超界的情况。*/\n");


p1:
    printf("\n1.加载源文件  2.退出\n");
    printf("请选择:");
    scanf("%c",&xuanZe);
    fflush(stdin);//清除输入缓冲区，以下所有作用同此
    if(xuanZe=='2')
    {
        printf("程序结束!\n");
        exit(0);
    }
    else if(xuanZe!='1')
    {
        printf("您的输入有误!请重新输入\n\n");
        goto p1;
    }
    else
    {
        while(1)//执行这里开始打开输入文件并进行处理
        {
            printf("Please input source file's name(e.g. xxx.c)：");//由用户输入文件名
            scanf("%s",shuRu);
            fflush(stdin);
            if((inputfile=fopen(shuRu,"r"))==NULL)
            {
                printf("Can't open source file!\n\n");
                goto p1;
            }//打开源文件

            printf("\n结果如下：\n\n");
            printf("分类          码/址\n");

            fprintf(outfile,"\n/*******************************************/\n");
            fprintf(outfile,"%s的词法分析结果如下：\n\n",shuRu);
            fprintf(outfile,"分类          码/址\n");


            while(!feof(inputfile))
            {

                preC=c;//preC是每次用来判断的字符
                c=fgetc(inputfile);//而实际处理的字符是c,每次处理完一种必须要让c存储下一个字符


                //编译预处理的情况
                if(preC=='#')
                {
                    bianYiYuChuLi(inputfile,outfile);
                }//编译预处理终止


                //关于注释的处理
                else if(preC=='/')
                {
                    if(c!='/'&&c!='*')
                    {
                        if(c==yunSuanFu[14].mPtr[0])
                        {
                            printf("2   运算符     %2d   %s\n",yunSuanFu[22].mNum,yunSuanFu[22].mPtr);
                            fprintf(outfile,"2   运算符     %2d   %s\n",yunSuanFu[22].mNum,yunSuanFu[22].mPtr);
                            c=fgetc(inputfile);

                            for(i=0; i<ysfA_i; i++) //存档
                            {
                                if(yunSuanFuAppeared[i]==&yunSuanFu[22])
                                {
                                    break;
                                }
                            }
                            if(i==ysfA_i)
                            {
                                yunSuanFuAppeared[ysfA_i++]=&yunSuanFu[22];
                            }

                        }
                        else
                        {
                            printf("2   运算符     %2d   %s\n",yunSuanFu[6].mNum,yunSuanFu[6].mPtr);
                            fprintf(outfile,"2   运算符     %2d   %s\n",yunSuanFu[6].mNum,yunSuanFu[6].mPtr);

                            for(i=0; i<ysfA_i; i++) //入档
                            {
                                if(yunSuanFuAppeared[i]==&yunSuanFu[6])
                                {
                                    break;
                                }
                            }
                            if(i==ysfA_i)
                            {
                                yunSuanFuAppeared[ysfA_i++]=&yunSuanFu[6];
                            }

                        }
                    }
                    else
                    {
                        zhuShiChuLi(inputfile,outfile);	   //调用注释函数
                    }
                }//注释结束


                //保留字,标识符的情况
                else if((preC>='A'&&preC<='Z')||(preC>='a'&&preC<='z')||preC=='_')
                {
                    baoLZBiaoSF(inputfile,outfile);
                }//终止


                //分隔符，运算符，各种常量的情况
                else if(((preC>='!'&&preC<='@')||(preC>='['&&preC<='`')||(preC>='{'&&preC<='~')))
                {
                    a[0]=preC;//这里情况比较复杂,于是用字符数组a来一个个的读取判断
                    a[1]='\0';//每次确定一些字符后,要用'\0'

                    //字符常量的情况
                    if(a[0]=='\'')
                    {
                        ziFuChuLi(inputfile,outfile);
                    }

                    //字符串常量的情况
                    else if(a[0]=='\"')
                    {
                        ziFuChuanChuLi(inputfile,outfile);
                    }

                    //数字类型常量的情况(所有情况)
                    else if((a[0]>='0'&&a[0]<='9')||a[0]=='.')
                    {
                        if(a[0]=='.'&&(c<='0'||c>='9'))
                        {
                            fenGeFuAndYunSuanFuChuLi(inputfile,outfile);
                        }
                        else
                        {
                            shuZiChangLiangChuLi(inputfile,outfile);
                        }
                    }

                    //分隔符 运算符
                    else
                    {
                        fenGeFuAndYunSuanFuChuLi(inputfile,outfile);
                    }
                }//分隔符，运算符，各种常量的终止

            }//读整个文件的循环

            //输出附表
            shuChuBaoLiuZ(outfile);
            shuChuFenGeF(outfile);
            shuChuYunSuanFu(outfile);
            shuChuBiaoZF(outfile);
            shuChuZhengXing(outfile);
            shuChuFuDianXing(outfile);
            shuChuZiFu(outfile);
            shuChuZiFuChuan(outfile);

            printf("\n以上结果已全部存入程序目录下的\"C词法分析结果.txt\"文件中\n\n");
            printf("/////////////////////////////////\n");

p2:
            printf("1.重新加载一个源文件  2.退出\n");
            printf("请选择:");
            scanf("%c",&xuanZe);
            fflush(stdin);

            if(xuanZe=='2')
            {
                printf("程序结束!\n");
                exit(0);
            }
            else if(xuanZe!='1')
            {
                printf("您的输入有误!请重新输入!\n\n");
                goto p2;
            }
        }//while(1)
    }//最上面的else

    fclose(inputfile);//关闭输入
    fclose(outfile);//关闭输出
    return 0;
}
