#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Calculate(int x,char op,int y,char op2,int k);/*��������Calculate���������㣨x��y�����������㣨��op����*/
int CreateRandomNumber();          /*��������CreateRandomNumber����������һ��1-10���������*/
char CreateRandomOperator();       /*��������CreateRandomOperator()���������һ��������ţ�+��-��*��/��*/
void PrintRandomRightEvaluation(); /*��������PrintRandomRightEvaluation()������һ����Ŀ���Ե������ʾ*/
int main()
{
    int a,b,c,userAnswer,Answer,i,rightNumber=0,flag=0;
	int q;
	int ret;
	int number;
    /*a,b���������userAnswer���û��𰸣�i�ǿ���ѭ���ı���,rightNumber����ȷ������flag�ɼ���־�����ɼ�<75�֣���ֵΪ1*/
    char opChar,opChar2;/*opChar�������*/
    srand(time(NULL));                           /*time(NULL)�ķ���ֵ��Ϊ���������������*/

	printf("��Ŀ��Ŀ��");
loop3: ret=scanf("%d",&number);
	if(ret==0){
				fflush(stdin);
				printf("�����ʽ������������������");
				goto loop3;
			}
    do{
        for(i=0;i<number;i++)                        /*ѭ��10�Σ���10����*/
        {

loop:   a=CreateRandomNumber();              /*����һ���������ֵ�����ͱ���a*/
            b=CreateRandomNumber();              /*����һ���������ֵ�����ͱ���b*/
			c=CreateRandomNumber();              /*����һ���������ֵ�����ͱ���b*/
            opChar=CreateRandomOperator();       /*����һ������������ֵ���ַ�����opChar*/
			opChar2=CreateRandomOperator();       /*����һ������������ֵ���ַ�����opChar*/
			//ʵ�������
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
            printf("%d%c%d%c%d=",a,opChar,b,opChar2,c);     /*���һ������������ʽ=��*/


loop2:      ret=scanf("%d",&Answer);             /*�û������*/
			if(ret==0){
				fflush(stdin);
				printf("�����ʽ������������������");
				goto loop2;
			}
		          			
            if(userAnswer==Answer)//�������ȷ
            {
                PrintRandomRightEvaluation();    //���һ����Ŀ���Ե������ʾ
                rightNumber++;                   //�ش���ȷ������1
            }
            else                                 //����ش���ȷ
            {
        
				printf("�ش���󣡣���Ϊ��%d\n",userAnswer);
			
            }
		
        }
        
		
    }while(flag);
	rightNumber=rightNumber*100/number;
    printf("�÷� %d%%\n",rightNumber);
   
	getch();
    return 0;
}
/*�������ܣ�������������x,y�����������㣨�������opȷ�����������ؼ�����ֵ*/
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
	//ͬ�������
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
/*�������ܣ�����һ��1-10���������*/
int CreateRandomNumber()
{
    return rand()%100+1;
}
/*�������ܣ��������һ��������ţ�+��-��*��/��*/
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
/*�������ܣ�����һ����Ŀ���Ե������ʾ*/
void PrintRandomRightEvaluation()
{
    int i;
    i=rand()%4+1;
    switch(i)
    {
        case 1:printf("�ش���ȷ���ܰ�!\n");
               break;
        case 2:printf("�ش���ȷ��good!\n");
               break;
        case 3:printf("�ش���ȷ������!\n");
               break;
        case 4:printf("�ش���ȷ������ס!\n");
               break;
        default:printf("�ټ�!");
    }
}
