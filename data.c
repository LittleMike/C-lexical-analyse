#include"declaration.h"

//**************************************
const Word baoLiuZi[37]=
{
    {"auto",1},
    {"bool",2},
    {"break",3},
    {"case",4},
    {"char",5},
    {"const",6},
    {"continue",7},
    {"default",8},
    {"restrict",9},
    {"do",10},
    {"double",11},
    {"else",12},
    {"enum",13},
    {"extern",14},
    {"float",15},
    {"for",16},
    {"goto",17},
    {"if",18},
    {"while",19},
    {"inline",20},
    {"int",21},
    {"long",22},
    {"register",23},
    {"return",24},
    {"short",25},
    {"signed",26},
    {"sizeof",27},
    {"static",28},
    {"struct",29},
    {"switch",30},
    {"typedef",31},
    {"union",32},
    {"unsigned",33},
    {"void",34},
    {"volatile",35},
    {"_imaginary",36},
    {"_complex",37}
};

const Word fenGeFu[11]=
{
    {"#",1},{"(",2},
    {")",3},{"[",4},
    {"]",5},{";",6},
    {":",7},{"{",8},
    {"}",9},{",",10},
    {"\\",11}
};

const Word yunSuanFu[36]=
{
    {"~",1},{".",2},
    {"?",3},{"*",4},//"\?"使用"?"也可以
    {"!",5},{"%",6},
    {"/",7},{"^",8},
    {"&",9},{"|",10},
    {"-",11},{"<",12},
    {">",13},{"+",14},
    {"=",15},{"&&",16},
    {"++",17},{"--",18},
    {"&=",19},{"-=",20},
    {"||",21},{"*=",22},
    {"/=",23},{"%=",24},
    {"^=",25},{"|=",26},
    {"<=",27},{">=",28},
    {"==",29},{"!=",30},
    {"+=",31},{">>",32},
    {"<<",33},{"<<=",34},
    {">>=",35},{"->",36}
};

//**************************************

char preC,c='\0';//传递字符用
int i,j,k,t;//循环变量
char a[ZIDUAN_LENGTH];//用于存读入的各种字段
Word biaoZhiFu[BIAOZHIFU_NUM];//存标识符
int biaoXu=0;//标识符下标
Word ziFu[ZIFU_NUM];//存字符常量
int ziFu_i=0;//字符常量下标
Word ziFuChuan[ZIFUCHUAN_NUM];//存字符串常量
int chuan_i=0;//字符串常量下标
Word fuDian[FUDIAN_NUM];//存浮点型常量
int fuDian_i=0;//浮点下标
Word zhengShu[ZHENGSHU_NUM];//存整形常量
int zhengShu_i=0;//整形下标
int flag;//布尔标志

const Word* baoLiuZAppeared[BIANMA_NUM];//程序中出现的保留字  它是一种指向常量的指针
int blzA_i=0;//程序中出现的保留字的数组下标


const Word* fenGeFuAppeared[BIANMA_NUM];//程序中出现的分隔符
int fgfA_i=0;

const Word* yunSuanFuAppeared[BIANMA_NUM];//出现的运算符
int ysfA_i=0;


char renYiZiFu='\0';//任意输入，退出用


//**************************************
