#ifndef DINGYANDSHENGMH//编译警戒
#define DINGYANDSHENGMH

//所有用到的表头
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ZIDUAN_LENGTH 101//和STRUCT_CHAR_LENGTH取相同的值即可
#define BIAOZHIFU_NUM 100
#define ZIFU_NUM 100
#define ZIFUCHUAN_NUM 100
#define FUDIAN_NUM 100
#define ZHENGSHU_NUM 100
#define STRUCT_CHAR_LENGTH 101
#define BIANMA_NUM 37

typedef struct
{

    char mPtr[STRUCT_CHAR_LENGTH];

    int mNum;

} Word;

//外部变量声明
extern const Word baoLiuZi[];
extern const Word fenGeFu[];
extern const Word yunSuanFu[];

extern	char preC,c;
extern	int i,j,k,t;
extern	char a[];
extern	Word biaoZhiFu[];
extern	int biaoXu;
extern	Word ziFu[];
extern	int ziFu_i;
extern	Word ziFuChuan[];
extern	int chuan_i;
extern	Word fuDian[];
extern	int fuDian_i;
extern	Word zhengShu[];
extern	int zhengShu_i;
extern	int flag;

extern	const Word* baoLiuZAppeared[];
extern  int blzA_i;
extern	const Word* fenGeFuAppeared[];
extern  int fgfA_i;
extern	const Word* yunSuanFuAppeared[];
extern	int ysfA_i;

extern char renYiZiFu;

//函数声明
void zhuShiChuLi(FILE*,FILE*);
void bianYiYuChuLi(FILE*,FILE*);
void baoLZBiaoSF(FILE*,FILE*);
void ziFuChuLi(FILE*,FILE*);
void ziFuChuanChuLi(FILE*,FILE*);
void shuZiChangLiangChuLi(FILE*,FILE*);
void fenGeFuAndYunSuanFuChuLi(FILE*,FILE*);
void shuChuBiaoZF(FILE*);
void shuChuZhengXing(FILE*);
void shuChuFuDianXing(FILE*);
void shuChuZiFu(FILE*);
void shuChuZiFuChuan(FILE*);
void shuChuBaoLiuZ(FILE*);
void shuChuFenGeF(FILE*);
void shuChuYunSuanFu(FILE*);

#endif
