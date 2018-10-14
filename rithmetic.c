#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Calculate(int x,char op,int y,char op2,int k);/*声明函数Calculate（），计算（x，y）的四则运算（由op定）*/
int CreateRandomNumber();          /*声明函数CreateRandomNumber（），生成一个1-10的随机整数*/
char CreateRandomOperator();       /*声明函数CreateRandomOperator()，随机生成一个运算符号（+、-、*、/）*/
void PrintRandomRightEvaluation(); /*声明函数PrintRandomRightEvaluation()，生成一个题目做对的随机提示*/
int main()
{
    int a,b,c,userAnswer,Answer,i,rightNumber=0,flag=0;
	int q;
	int ret;
	int number;
    /*a,b随机整数，userAnswer是用户答案，i是控制循环的变量,rightNumber是正确答案数，flag成绩标志，当成绩<75分，其值为1*/
    char opChar,opChar2;/*opChar是运算符*/
    srand(time(NULL));                           /*time(NULL)的返回值作为产生随机数的种子*/

	printf("题目数目：");
loop3: ret=scanf("%d",&number);
	if(ret==0){
				fflush(stdin);
				printf("输入格式错误，请重新输整数：");
				goto loop3;
			}
    do{
        for(i=0;i<number;i++)                        /*循环10次，做10道题*/
        {

loop:   a=CreateRandomNumber();              /*产生一个随机数赋值给整型变量a*/
            b=CreateRandomNumber();              /*产生一个随机数赋值给整型变量b*/
			c=CreateRandomNumber();              /*产生一个随机数赋值给整型变量b*/
            opChar=CreateRandomOperator();       /*产生一个随机运算符赋值给字符变量opChar*/
			opChar2=CreateRandomOperator();       /*产生一个随机运算符赋值给字符变量opChar*/
			//实现真分数
			if(opChar2=='/'&& b<c){
				q = b;
				b = c;
				c = q;
			}
			if(opChar=='/'&& a<b){
				q = a;
				a = b;
				b = q;
			}
			if(opChar2=='/'&& b<c){
				q = b;
				b = c;
				c = q;
			}
			userAnswer=Calculate(a,opChar,b,opChar2,c);
			if(userAnswer<0)
				goto loop;
            printf("%d%c%d%c%d=",a,opChar,b,opChar2,c);     /*输出一个四则运算表达式=？*/


loop2:      ret=scanf("%d",&Answer);             /*用户输入答案*/
			if(ret==0){
				fflush(stdin);
				printf("输入格式错误，请重新输整数：");
				goto loop2;
			}
		          			
            if(userAnswer==Answer)//如果答案正确
            {
                PrintRandomRightEvaluation();    //输出一个题目做对的随机提示
                rightNumber++;                   //回答正确题数加1
            }
            else                                 //如果回答不正确
            {
        
				printf("回答错误！，答案为：%d\n",userAnswer);
			
            }
		
        }
        
		
    }while(flag);
	rightNumber=rightNumber*100/number;
    printf("得分 %d%%\n",rightNumber);
   
	getch();
    return 0;
}
/*函数功能：计算两个数（x,y）的四则运算（运算符由op确定？），返回计算结果值*/
int Calculate(int x,char op,int y,char op2,int k)
{
	int swer;
	int h;
	if((op=='+' || op=='-') && op2=='*')
	{
		y=y*k;
	}
	if((op=='+' || op=='-') && op2=='/')
	{
		y=y/k;
	}
    switch(op)
    {
	case '+':
		h=x+y;
        
		break;
    case '-':
		h=x-y;
        
		break;
    case '*':
		h=x*y;
		break;
    case '/':

        h=x/y;
		break;
    }
	if(op2=='+')
	{
		h=h+k;
	}
	if(op2=='-')
	{
		h=h-k;
	}
	//同级运算符
	if((op=='*'||op=='/') && op2=='*')
	{
		h=h*k;
	}
	if((op=='*'||op=='/') && op2=='/')
	{
		h=h/k;
	}
	return h;
}
/*函数功能：生成一个1-10的随机整数*/
int CreateRandomNumber()
{
    return rand()%100+1;
}
/*函数功能：随机生成一个运算符号（+，-，*，/）*/
char CreateRandomOperator()
{
    int op;
    op=rand()%4+1;
    switch(op)
    {
    case 1:
		return '+';
    case 2:
		return '-';
    case 3:
		return '*';
    case 4:
		return '/';
    }
    return 0;
}
/*函数功能：生成一个题目做对的随机提示*/
void PrintRandomRightEvaluation()
{
    int i;
    i=rand()%4+1;
    switch(i)
    {
        case 1:printf("回答正确，很棒!\n");
               break;
        case 2:printf("回答正确，good!\n");
               break;
        case 3:printf("回答正确，加油!\n");
               break;
        case 4:printf("回答正确，保持住!\n");
               break;
        default:printf("再见!");
    }
}
