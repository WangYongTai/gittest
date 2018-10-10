#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int num1, num2, num3, count=0;
	int resultTrue,flag;   // resultTrue:答案, flag=0 :先算左边, flag=1先算右边
	char op1, op2;         //运算符
	int N;
	printf("请输入要生成的运算题数目:\n");
	scanf("%d",&N);
	srand(time(NULL));    //生成随机数
	do {
		count++;
		num1 = rand() % 100+1; //生成0-100的随机数
		num2 = rand() % 10+1;
		num3 = rand() % 10+1;
		switch (num1 % 3)      //运算符op1
		{
		case 0:
			op1 = '+';
			break;
		case 1:
			op1 = '-';
			break;
		case 2:
			op1 = '*';
			break;
		default:
			break;
		}
		switch (num2 % 4)     //运算符op2
		{
		case 0:
			op2 = '+';
			flag = 0;
			break;
		case 1:
			op2 = '-';
			flag = 0;
			break;
		case 2:
			op2 = '*';
			if((op1=='*')) flag = 0;//判断op1是否为*，是*(flag=0)就先算左边;
			else flag = 1;          
			break;
		case 3:
			op2 = '/';
			if((op1=='*')) flag = 0;
			else flag = 1;
			break;
		default:
			break;
		}
		
		if(flag==0) //判断先算那边
		{
			resultTrue = 0;
			switch (op1)
			{
			case '+':
				resultTrue = num1+num2;
				break;
			case '-':
				resultTrue = num1-num2;
				break;
			case '*':
				resultTrue = num1*num2;
				break;
			default:
				break;
			}
			switch (op2)
			{
			case '+':
				resultTrue += num3;
				break;
			case '-':
				resultTrue -= num3;
				break;
			case '*':
				resultTrue *= num3;
				break;
			case '/':
				resultTrue /= num3;
				break;
			default:
				break;
			}
		}
		else
		{
			resultTrue = 0;
			switch (op2)
			{
			case '+':
				resultTrue = num2+num3;
				break;
			case '-':
				resultTrue = num2-num3;
				break;
			case '*':
				resultTrue = num2*num3;
				break;
			case '/':
				resultTrue = num2/num3;
				break;
			default:
				break;
			}
			switch (op1)
			{
			case '+':
				resultTrue = num1 + resultTrue;
				break;
			case '-':
				resultTrue = num1 - resultTrue;
				break;
			case '*':
				resultTrue = num1 * resultTrue;
				break;
			default:
				break;
			}
		} 
		printf("%d %c %d %c %d = %d \n",num1,op1,num2,op2,num3,resultTrue);//输出运算式  
  } while(count<=N);
  return 0;
}

