#include"declaration.h"

void ziFuChuLi(FILE* fPtr,FILE* op){

				for(i=1;c!='\'';i++){//存入（存在''里面有多个符号的可能，所以这样存）
					a[i]=c;
					if(c=='\\'){
						c=fgetc(fPtr);
						if(c=='\''||c=='\\'){//对于这两种情况的处理
							i++;
							a[i]=c;
							c=fgetc(fPtr);
						}
					}
					else c=fgetc(fPtr);
				}
				a[i]=c;
				a[i+1]='\0';
				c=fgetc(fPtr);

				for(i=0;i<ziFu_i;i++){//先查找
					if(!strcmp(a,ziFu[i].mPtr)){
						printf("4 2 字符常量   %2d   %s\n",ziFu[i].mNum,ziFu[i].mPtr);
						fprintf(op,"4 2 字符常量   %2d   %s\n",ziFu[i].mNum,ziFu[i].mPtr);
						break;
					}
				}
				if(i==ziFu_i){//没找到就存储
				strcpy(ziFu[ziFu_i++].mPtr,a);
				ziFu[ziFu_i-1].mNum=ziFu_i;
				printf("4 2 字符常量   %2d   %s\n",ziFu[ziFu_i-1].mNum,ziFu[ziFu_i-1].mPtr);
				fprintf(op,"4 2 字符常量   %2d   %s\n",ziFu[ziFu_i-1].mNum,ziFu[ziFu_i-1].mPtr);
				}
}

void ziFuChuanChuLi(FILE* fPtr,FILE* op){

				for(i=1;c!='\"'&&i<ZIDUAN_LENGTH-1;i++){//存入
					a[i]=c;
					if((i==ZIDUAN_LENGTH-3&&a[i]=='\\')||(i==ZIDUAN_LENGTH-2&&a[i]!='\"')){//检查字符串数组超界
						printf("字符串长度超过了%d，修改宏定义吧~\n",ZIDUAN_LENGTH-1);
						fprintf(op,"字符串长度超过了%d，修改宏定义吧~\n",ZIDUAN_LENGTH-1);
						printf("输入任意字符后回车退出:");
						scanf("%c",&renYiZiFu);
						exit(0);
					}
					if(c=='\\'){
						c=fgetc(fPtr);
						if(c=='\"'||c=='\\'){//对于" "中含有"的情况和'\\'的情况的处理
							i++;
							a[i]=c;
							c=fgetc(fPtr);
						}
					}
					else c=fgetc(fPtr);
				}
				a[i]=c;
				a[i+1]='\0';
				c=fgetc(fPtr);

				for(i=0;i<chuan_i;i++){
					if(!strcmp(a,ziFuChuan[i].mPtr)){
						printf("4 3 字符串常量 %2d   %s\n",ziFuChuan[i].mNum,ziFuChuan[i].mPtr);
						fprintf(op,"4 3 字符串常量 %2d   %s\n",ziFuChuan[i].mNum,ziFuChuan[i].mPtr);
						break;
					}
				}
				if(i==chuan_i){//没找到，存储
					strcpy(ziFuChuan[chuan_i++].mPtr,a);
					ziFuChuan[chuan_i-1].mNum=chuan_i;
					printf("4 3 字符串常量 %2d   %s\n",ziFuChuan[chuan_i-1].mNum,ziFuChuan[chuan_i-1].mPtr);
					fprintf(op,"4 3 字符串常量 %2d   %s\n",ziFuChuan[chuan_i-1].mNum,ziFuChuan[chuan_i-1].mPtr);
				}
}

