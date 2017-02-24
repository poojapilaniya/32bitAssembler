#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int bintodec(char c[]);
void mov1(int,int);
void mov2(int ind1,int ind2);
void add(int ind1,int ind2);
void mul(int ind1,int ind2);
void divi(int ind1,int ind2);
int cmp(int ind1,int ind2);
void dec(int ind);
void pop(int);
void push1(int);
void push2(int);
void print_reg();
float arr[10];
int stk[100];
int top=-1;
void set();
int main()
{
	FILE *f_reg,*f_out,*f_in,*f_sym;
	char ch,oneword[100];
	char names[44][33],bits[44][33],extracted[33];
	char op1[10],op2[10];
	int l,i,cmp_res;
	int d1,d2;
	f_reg= fopen("registers.txt","r");
	//to read value from registers.txt and store it in a array
	ch= fscanf(f_reg,"%s",oneword);
	int j=0;
	set();
	while(ch!=EOF)
	{
		l=strlen(oneword);
		for(i=0;i<l;i++)
		{	
			names[j][i]=oneword[i];
		}
		names[j][i]='\0';
		ch=fscanf(f_reg,"%s",oneword);
		for(i=0;i<32;i++)
		{
			bits[j][i]=oneword[i];
		}
		bits[j][i]='\0';
		j++;
		ch=fscanf(f_reg,"%s",oneword);
	}
	fclose(f_reg);
	f_in= fopen("final_output.txt","r");
	ch=fscanf(f_in,"%s",oneword);
	j=0;
	int k,count=20;
	while(ch!=EOF)
	{
		//printf("oneword %s\n",oneword);
		//for checking first 20 bits
		printf("back in here\n");
	here:	j=0;
		count=20;
		while(j<5)
		{
			//printf("hey\n");
			for(i=0;i<count;i++) //20=count
				extracted[i]=oneword[i];
				extracted[i]='\0';
				//printf("extracted %s\n",extracted);
				if(strlen(oneword)<20)
					j=5;
				else
				{
				if(strcmp(extracted,"00000000000000000000")==0)
				{
						printf("mov1\n"); 
						j=5;
						//printf("
						for(i=count+1;i<count+8;i++)
						{
								op1[i-count-1]=oneword[i];
						}
						op1[i-count]='\0';
						for(k=i;k<32;k++)
						{
								op2[k-i]=oneword[k];
						}
						op2[k-i]='\0';
						/*printf("%s",extracted);
						printf("op1 %s",op1);
						printf("op2 %s\n",op2);*/
						//set();
						d1=bintodec(op1);
						d2=bintodec(op2);
						mov1(d1,d2);
						printf("hey");
						//for(j=i;i<32;i++
				}		//mov1
				else if(strcmp(extracted,"000000000000000000010000")==0)
				{
						printf("mov2\n");
						j=5;
						for(i=count;i<count+5;i++)
						{
								op1[i-count]=oneword[i];
								op2[i-count+1]=oneword[i+5];
						}
						op1[i-count]='\0';
						op2[i-count+1]='\0';
						d1=bintodec(op1);
						d2=bintodec(op2);
						mov2(d1,d2);
						/*printf("%s",extracted);
						printf("op1 %s",op1);
						printf("op2 %s\n",op2);*/
						
				}		//mov2();
				else if(strcmp(extracted,"000000000000000000010001")==0)
				{
						printf("mul\n");
						j=5;
						for(i=count;i<count+4;i++)
						{
								op1[i-count]=oneword[i];
								op2[i-count+1]=oneword[i+5];
						}
						op1[i-count]='\0';
						op2[i-count+1]='\0';
						d1=bintodec(op1);
						d2=bintodec(op2);
						mul(d1,d2);
						/*printf("%s",extracted);
						printf("op1 %s",op1);
						printf("op2 %s\n",op2);*/
				}		//mul();
				else if(strcmp(extracted,"000000000000000000010010")==0)
				{
						printf("add\n");	
						j=5;
						for(i=count;i<count+4;i++)
						{
								op1[i-count]=oneword[i];
								op2[i-count+1]=oneword[i+5];
						}
						op1[i-count]='\0';
						op2[i-count+1]='\0';
						d1=bintodec(op1);
						d2=bintodec(op2);
						add(d1,d2);
						/*printf("%s",extracted);
						printf("op1 %s",op1);
						printf("op2 %s\n",op2);*/
					
				}	//add();
				else if(strcmp(extracted,"000000000000000000010011")==0)
				{
						printf("div\n");	
						j=5;
						for(i=count;i<count+4;i++)
						{
								op1[i-count]=oneword[i];
								op2[i-count+1]=oneword[i+5];
						}
						op1[i-count]='\0';
						op2[i-count+1]='\0';
						d1=bintodec(op1);
						d2=bintodec(op2);
						divi(d1,d2);
						/*printf("%s",extracted);
						printf("op1 %s",op1);
						printf("op2 %s\n",op2);*/
				}	//div();
				else if(strcmp(extracted,"000000000000000000010100")==0)
				{
						printf("cmp\n");	
						j=5;
						for(i=count;i<count+4;i++)
						{
								op1[i-count]=oneword[i];
								op2[i-count+1]=oneword[i+5];
						}
						op1[i-count]='\0';
						op2[i-count+1]='\0';
						d1=bintodec(op1);
						d2=bintodec(op2);
						cmp_res=cmp(d1,d2);
						/*printf("%s",extracted);
						printf("op1 %s",op1);
						printf("op2 %s\n",op2);*/
				}	//cmp();
				else if(strcmp(extracted,"000000000000000000010101")==0)
				{
						printf("push1\n");	
						j=5;
						for(i=count+1;i<count+8;i++)
						{
								op1[i-count-1]=oneword[i];
								//op2[i-count]=oneword[i+4];
						}
						op1[i-count-1]='\0';
						d1=bintodec(op1);
						push1(d1);
						//op2[i-count-1]='\0';
						//printf("%s",extracted);
						//printf("op1 %s",op1);
						//printf("op2 %s\n",op2);
				}	//push1();
				else if(strcmp(extracted,"0000000000000000000101100")==0)
				{
						printf("jnz\n");	
						j=5;
						for(i=count+1;i<count+8;i++)
						{
								op1[i-count-1]=oneword[i];
								//op2[i-count+1]=oneword[i+5];
						}
						op1[i-count]='\0';
						printf("jnz %s\n",op1);
						d1=bintodec(op1);
						//printf("decimal %d\n",d1);
						if(cmp_res==-1)
						{
							rewind(f_in);
							ch=fseek(f_in,(d1-1)*32+7,SEEK_SET);
							ch=fscanf(f_in,"%s",oneword);
							//ch=fscanf(f_in,"%s",oneword);
							//printf("return %s\n",oneword);
							//goto here;
						}
						
				}	//jnz();
				else if(strcmp(extracted,"0000000000000000000101101000")==0)
				{
						j=5;
						printf("dec\n");		//dec();
						for(i=count;i<count+5;i++)
						{
								op1[i-count]=oneword[i];
								//op2[i-count]=oneword[i+4];
						}
						op1[i-count-1]='\0';
						d1=bintodec(op1);
						dec(d1);
						//op2[i-count-1]='\0';
						//printf("%s",extracted);
						//printf("op1 %s\n",op1);
						//printf("op2 %s\n",op2);
				}
				else if(strcmp(extracted,"0000000000000000000101101001")==0)
				{
						j=5;
						printf("push2\n");		//push2();
						for(i=count;i<count+5;i++)
						{
								op1[i-count]=oneword[i];
								//op2[i-count]=oneword[i+4];
						}
						op1[i-count]='\0';
						d1=bintodec(op1);
						push2(d1);
						//op2[i-count-1]='\0';
						//printf("%s",extracted);
						//printf("op1 %s",op1);
						//printf("op2 %s\n",op2);
				}
				else if(strcmp(extracted,"0000000000000000000101101010")==0)
				{
						j=5;
						printf("pop\n");		//pop();
						for(i=count;i<count+5;i++)
						{
								op1[i-count]=oneword[i];
								//op2[i-count]=oneword[i+4];
						}
						op1[i-count]='\0';
						d1=bintodec(op1);
						pop(d1);
						//op2[i-count-1]='\0';
						//printf("%s",extracted);
						//printf("op1 %s",op1);
						//printf("op2 %s\n",op2);
				}
				else if(strcmp(extracted,"00000000000000000001011010110000")==0)
				{
						j=5;
						printf("hlt\n");	
						printf("Contents\n");
						print_reg();
						return 0;	//hault();
				}
				}
			if(count==24)
				count++;
			else if(count==25)
				count=28;
			else
				count=count+4;
			j++;	
		}
		ch=fscanf(f_in,"%s",oneword);
	}
	//print_reg();
		
		
}
int bintodec(char c[])
{
	//printf("hello in fn\n");
	int sum=0,i,j;
	int *arr;
	int l=strlen(c);
	arr=(int*)malloc(l*sizeof(int));
	for(i=0;i<l;i++)
		(*(arr+i))=c[i]-'0';
	/*for(i=0;i<l;i++)
		printf("%d",*(arr+i));
	printf("\n");*/
	//printf("hello in bet fn\n");
	for(i=l-1,j=0;i>=0;i--,j++)
	{
		//printf("hello in fn\n");
		sum=sum+(*(arr+i))*pow(2,j);
	}
	return sum;
}
void set()
{
	int x1;
	for(x1=0;x1<10;x1++)
		arr[x1]=0;
}
	
void mov1(int imm,int ind)
{
	int x1;
	arr[ind]=imm;
	//printf("the contents of registers are\n");
	/*for(x1=0;x1<10;x1++)
		printf("%d\n",arr[x1]);*/
}
void mov2(int ind1,int ind2)
{
	arr[ind2]=arr[ind1];
}
void add(int ind1,int ind2)
{
	arr[ind2]=arr[ind1]+arr[ind2];
}
void mul(int ind1,int ind2)
{
	arr[ind2]=arr[ind1]*arr[ind2];
}
void divi(int ind1,int ind2)
{
	arr[ind2]=arr[ind2]/arr[ind1];
}
int cmp(int ind1,int ind2)
{
	if(arr[ind2]!=arr[ind1])
		return -1;
	else
		return 1;
}
void dec(int ind)
{
	arr[ind]=arr[ind]-1;
}
/*void hault()
{
	return 0;
}*/
void print_reg()
{
	int x1;
	for(x1=0;x1<10;x1++)
		printf("r%d\t%f\n",x1,arr[x1]);
}
void pop(int ind)
{
	int i;
	arr[ind]=stk[top];
	top--;
	printf("elements in stack\n");
	for(i=top;i>=0;i--)
		printf("%d\n",stk[i]);
}
void push1(int r)
{
	int i;
	top++;
	stk[top]=r;
	printf("elements in stack\n");
	for(i=top;i>=0;i--)
		printf("%d\n",stk[i]);
}
void push2(int ind)
{
	int i;
	top++;
	stk[top]=arr[ind];
	printf("elements in stack\n");
	for(i=top;i>=0;i--)
		printf("%d\n",stk[i]);
}
	
		
		
