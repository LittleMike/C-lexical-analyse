#include"declaration.h"

void fenGeFuAndYunSuanFuChuLi(FILE* fPtr,FILE* op)
{

    //分隔符
    for(i=0; i<11; i++)
    {
        if(!strcmp(a,fenGeFu[i].mPtr)) //比较
        {
            printf("1   分隔符     %2d   %s\n",fenGeFu[i].mNum,fenGeFu[i].mPtr);
            fprintf(op,"1   分隔符     %2d   %s\n",fenGeFu[i].mNum,fenGeFu[i].mPtr);

            //对出现过的分隔符进行存档
            for(j=0; j<fgfA_i; j++)
            {
                if(fenGeFuAppeared[j]==&fenGeFu[i])
                {
                    break;
                }
            }
            if(j==fgfA_i)
            {
                fenGeFuAppeared[fgfA_i++]=&fenGeFu[i];
            }
            //对出现过的分隔符进行存档结束

            break;
        }
    }//分隔符终止

    //运算符
    if(i==11)
    {
        for(i=0; i<=14; i++)
        {
            if(!strcmp(a,yunSuanFu[i].mPtr)) //一个符号
            {
                if(yunSuanFu[i].mNum>=4&&yunSuanFu[i].mNum<=15)
                {
                    for(j=8; j<=14; j++)
                    {
                        if(c==yunSuanFu[j].mPtr[0]) //两个符号组合
                        {
                            a[1]=c;
                            a[2]='\0';
                            if(c=='<'||c=='>') //三个符号组合（<<=和>>=）
                            {
                                c=fgetc(fPtr);
                                if(c=='=')
                                {
                                    a[2]=c;
                                    a[3]='\0';
                                    c=fgetc(fPtr);
                                    if(!strcmp(a,yunSuanFu[34].mPtr))
                                    {
                                        printf("2   运算符     %2d   %s\n",yunSuanFu[34].mNum,yunSuanFu[34].mPtr);
                                        fprintf(op,"2   运算符     %2d   %s\n",yunSuanFu[34].mNum,yunSuanFu[34].mPtr);

                                        for(k=0; k<ysfA_i; k++)
                                        {
                                            if(yunSuanFuAppeared[k]==&yunSuanFu[34])
                                            {
                                                break;
                                            }
                                        }
                                        if(k==ysfA_i)
                                        {
                                            yunSuanFuAppeared[ysfA_i++]=&yunSuanFu[34];
                                        }

                                        break;
                                    }
                                    else
                                    {
                                        printf("2   运算符     %2d   %s\n",yunSuanFu[33].mNum,yunSuanFu[33].mPtr);
                                        fprintf(op,"2   运算符     %2d   %s\n",yunSuanFu[33].mNum,yunSuanFu[33].mPtr);

                                        for(k=0; k<ysfA_i; k++)
                                        {
                                            if(yunSuanFuAppeared[k]==&yunSuanFu[33])
                                            {
                                                break;
                                            }
                                        }
                                        if(k==ysfA_i)
                                        {
                                            yunSuanFuAppeared[ysfA_i++]=&yunSuanFu[33];
                                        }

                                        break;
                                    }
                                }
                                else // ( <<和>>和-> )
                                {
                                    if(!strcmp(a,yunSuanFu[32].mPtr))
                                    {
                                        printf("2   运算符     %2d   %s\n",yunSuanFu[32].mNum,yunSuanFu[32].mPtr);
                                        fprintf(op,"2   运算符     %2d   %s\n",yunSuanFu[32].mNum,yunSuanFu[32].mPtr);

                                        for(k=0; k<ysfA_i; k++)
                                        {
                                            if(yunSuanFuAppeared[k]==&yunSuanFu[32])
                                            {
                                                break;
                                            }
                                        }
                                        if(k==ysfA_i)
                                        {
                                            yunSuanFuAppeared[ysfA_i++]=&yunSuanFu[32];
                                        }

                                        break;
                                    }
                                    else if(!strcmp(a,yunSuanFu[31].mPtr))
                                    {
                                        printf("2   运算符     %2d   %s\n",yunSuanFu[31].mNum,yunSuanFu[31].mPtr);
                                        fprintf(op,"2   运算符     %2d   %s\n",yunSuanFu[31].mNum,yunSuanFu[31].mPtr);

                                        for(k=0; k<ysfA_i; k++)
                                        {
                                            if(yunSuanFuAppeared[k]==&yunSuanFu[31])
                                            {
                                                break;
                                            }
                                        }
                                        if(k==ysfA_i)
                                        {
                                            yunSuanFuAppeared[ysfA_i++]=&yunSuanFu[31];
                                        }

                                        break;
                                    }
                                    else
                                    {
                                        printf("2   运算符     %2d   %s\n",yunSuanFu[35].mNum,yunSuanFu[35].mPtr);
                                        fprintf(op,"2   运算符     %2d   %s\n",yunSuanFu[35].mNum,yunSuanFu[35].mPtr);

                                        for(k=0; k<ysfA_i; k++)
                                        {
                                            if(yunSuanFuAppeared[k]==&yunSuanFu[35])
                                            {
                                                break;
                                            }
                                        }
                                        if(k==ysfA_i)
                                        {
                                            yunSuanFuAppeared[ysfA_i++]=&yunSuanFu[35];
                                        }

                                        break;
                                    }
                                }
                            }
                            else
                            {
                                for(k=15; k<31; k++)
                                {
                                    if(!strcmp(a,yunSuanFu[k].mPtr))
                                    {
                                        printf("2   运算符     %2d   %s\n",yunSuanFu[k].mNum,yunSuanFu[k].mPtr);
                                        fprintf(op,"2   运算符     %2d   %s\n",yunSuanFu[k].mNum,yunSuanFu[k].mPtr);

                                        for(t=0; t<ysfA_i; t++)
                                        {
                                            if(yunSuanFuAppeared[t]==&yunSuanFu[k])
                                            {
                                                break;
                                            }
                                        }
                                        if(t==ysfA_i)
                                        {
                                            yunSuanFuAppeared[ysfA_i++]=&yunSuanFu[k];
                                        }

                                        c=fgetc(fPtr);
                                        break;
                                    }
                                }
                                if(k==31) //一个符号
                                {
                                    printf("2   运算符     %2d   %s\n",yunSuanFu[i].mNum,yunSuanFu[i].mPtr);
                                    fprintf(op,"2   运算符     %2d   %s\n",yunSuanFu[i].mNum,yunSuanFu[i].mPtr);

                                    for(t=0; t<ysfA_i; t++)
                                    {
                                        if(yunSuanFuAppeared[t]==&yunSuanFu[i])
                                        {
                                            break;
                                        }
                                    }
                                    if(t==ysfA_i)
                                    {
                                        yunSuanFuAppeared[ysfA_i++]=&yunSuanFu[i];
                                    }

                                    break;
                                }
                                break;
                            }
                        }
                    }
                    if(j==15)
                    {
                        printf("2   运算符     %2d   %s\n",yunSuanFu[i].mNum,yunSuanFu[i].mPtr);
                        fprintf(op,"2   运算符     %2d   %s\n",yunSuanFu[i].mNum,yunSuanFu[i].mPtr);

                        for(k=0; k<ysfA_i; k++)
                        {
                            if(yunSuanFuAppeared[k]==&yunSuanFu[i])
                            {
                                break;
                            }
                        }
                        if(k==ysfA_i)
                        {
                            yunSuanFuAppeared[ysfA_i++]=&yunSuanFu[i];
                        }

                        break;
                    }
                }
                else
                {
                    printf("2   运算符     %2d   %s\n",yunSuanFu[i].mNum,yunSuanFu[i].mPtr);
                    fprintf(op,"2   运算符     %2d   %s\n",yunSuanFu[i].mNum,yunSuanFu[i].mPtr);

                    for(j=0; j<ysfA_i; j++)
                    {
                        if(yunSuanFuAppeared[j]==&yunSuanFu[i])
                        {
                            break;
                        }
                    }
                    if(j==ysfA_i)
                    {
                        yunSuanFuAppeared[ysfA_i++]=&yunSuanFu[i];
                    }

                    break;
                }
            }
        }//运算符终止
    }//if(i==11)
}
