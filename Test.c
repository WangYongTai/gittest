#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int num1, num2, num3, count=0;
	int resultTrue,flag;   // resultTrue:��, flag=0 :�������, flag=1�����ұ�
	char op1, op2;         //�����
	int N;
	printf("������Ҫ���ɵ���������Ŀ:\n");
	scanf("%d",&N);
	srand(time(NULL));    //���������
	do {
		count++;
		num1 = rand() % 100+1; //����0-100�������
		num2 = rand() % 10+1;
		num3 = rand() % 10+1;
		switch (num1 % 3)      //�����op1
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
		switch (num2 % 4)     //�����op2
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
			if((op1=='*')) flag = 0;//�ж�op1�Ƿ�Ϊ*����*(flag=0)���������;
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
		
		if(flag==0) //�ж������Ǳ�
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
		printf("%d %c %d %c %d = %d \n",num1,op1,num2,op2,num3,resultTrue);//�������ʽ  
  } while(count<=N);
  return 0;
}

