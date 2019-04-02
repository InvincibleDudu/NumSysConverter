/*NumSysConverter
(c)2018, Malcolm "Addition" Kenneth, aka InvincibleDudu, USST*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#define N 200

void LogIn();				
void Register();
void change_code();
void FreeHead();
void ast();
void veri();
void intro();
void func();
void input();
void input2();
void choose();
void choose2();
void bin(unsigned int x);
void oct(unsigned int x);
void cvt(unsigned int a,int to); 
int val(char c);
int toDeci(char *str, int base);
int TenNum(char a[],int B);          
void Numchange(int m, int B);      
void invalid();
void warn();
void warn2();
void notice();
void error();
void intro2();
void source();
void target();
void boro();
void press();


int main(){							//main
    //veri();
    puts("\nVerification Success!\n");
    Sleep(2);
	system("cls"); 
    char str[N];
	int a,t,base,m;
	unsigned int i;
	intro();
	loop: func();
	scanf("%d",&a);		
	switch (a){
	case 1:			//Step-by-Step
		input();
		scanf("%d",&i);
		source(i);
		choose();
		scanf("%d",&t);
		boro(i,t);
		target(i,t);
		press();
		goto loop;
		break;
		
	case 2:			//To decimal
		notice();
		input();
		scanf("%d",&i);
		source(i);
		choose2();
		scanf("%d",&t);
		target(i,t);
		press();
		goto loop;
		break;
		
	case 5:			//Credit
		intro2();
		press();
		goto loop; 
		break;
	
	case 3:			//Decimal conversion
		input2();
   		scanf("%s",str);
    	choose2();
    	scanf("%d",&base);
    	printf("Decimal Equivalent of %s in Base-%d is " " %d\n", str, base, toDeci(str, base));
		sleep(2);
		press();
		goto loop;
		break;
		
	case 4:			//Ultimate Number System Converter
		warn2();
		printf("\nPlease read the EULA CAREFULLY for terms and conditions.");
		Sleep(2);
		press();
		printf("Source Base(2~36):");
		do {
			scanf_s("%d", &base);         
		} while (base < 2 && base > 16);
		if(base>36 || base<2){
			invalid();
			goto loop;
		}
		printf("SourceNumber:");
		getchar();
		scanf("%s",str);           
		m = TenNum(str, base);            
		printf("Target Base(2-36):");
		
		do {
			scanf_s("%d", &t);
		} while (base < 2 && base > 16);
		if(t>36 || t<2){
			invalid();
			goto loop;
		}
		printf("Base-%d Equivelant of %s is %d: ",t,str,base);
		Numchange(m, t);                
		printf("\n");
		warn();
    	press();
		goto loop;
		break;
	
	case 0:		//exit
		printf("\nThanks for using!");
		sleep(2);
		return 0;
		
	default:
		invalid();
		sleep(1);
		goto loop;
	}
	return 0;
}




 
typedef struct user
{
    char name[N];
    char password[N];
    struct user *next;
}USER;

struct user *head=NULL;

void LogIn()
{
   struct user *now;
    char pass[N];
    char nam[N];
    int i;
    for(i=0;i<N;i++)
    {
        memset(pass,0x00,sizeof(pass));		//Initialization
        memset(nam,0x00,sizeof(nam)); 
        printf("Username:\n");
        scanf("%s",nam);
        printf("Password:\n");
        scanf("%s",pass);
        now=head;
        while(now)
        {
            if((strcmp(nam,now->name)==0)&&(strcmp(pass,now->password)==0))
            {
                return;
            }
            now=now->next;
        }
        printf("Verification Failed, please try agian.\n");
    }
}

void Register()
{	FILE *fp;
    fp=fopen("account.txt","w");
    USER *tmp,*now=head;
    tmp=(USER*)calloc(1,sizeof(USER));
    printf("Username:\n");
    scanf("%s",tmp->name);
    fprintf(fp,"Username£º%s\n",tmp->name);
    while(now)
    {
        if(strcmp(tmp->name,now->name)==0)
        {
            printf("This Username's been registered. \n");
            free(tmp);
            return;
        }
    }
    printf("Password:\n");
    scanf("%s",tmp->password);
    fprintf(fp,"Password£º%s\n",tmp->password);
    printf("Success!\n\n");
    press();
    sleep(1);
    tmp->next=head;
    head=tmp;
    return;
}

void change_code()
{
    USER *tmp,*now=head;
    tmp=(USER*)calloc(1,sizeof(USER));
    char pass_code[N];
    int i;
    for(i=0;i<N;i++)
    {
        memset(pass_code,0x00,sizeof(pass_code));
        printf("Old Password:\n");
        scanf("%s",pass_code);
        now=head;
        while(now)
        {
            if((strcmp(pass_code,now->password)==0))
            {
                printf("New Password\n");
                scanf("%s",tmp->password);
                tmp->next=head;
                head=tmp;
                printf("Success!¡\\n");
                return ;
            }
            now=now->next;
        }
        printf("Verification Failed£¡\n");
    }
    printf("To many tries, plz try agian later.\n");
}
    
void FreeHead()
{
   struct user *now;
    now=head;
    while(now)
    {
        head=now->next;
        free(now);
        now=head;
    }
}

void ast(){
	printf("***********************************\n");
}

void veri()          //Full Verification Function
{
    int a=0;
    do
    {	
    	ast();
    	printf("NumSysCvtr Verification System Version 1.14\n\n");
    	sleep(1);
        printf("Plz select 1:Log in      \n");
        printf("           2:Sign up      \n");
        printf("           3:Change your password\n\n");
        printf("Or Input Any other key to exit...\n");
        scanf("%d",&a);
        if(a==1)
            {LogIn();
            break;}
        else if(a==2)
            Register();
        else if(a==3)
            change_code();
        else 
        	exit(1);
    }while(a==1||a==2||a==3);
    if(head)
        FreeHead();
}


  
void intro(){
	ast();
	printf("**    Number System Converter    **\n");
	printf("**        Version 3.00           **\n");
	ast();
	printf("\n            Welcome!\n");
	sleep(1);
}

void func(){
	ast();
	printf("\n\n1.Dec to Bin & Oct Converter(with Step-by-Step Solution)\n");
	printf("2.*Dec to Base-(2 to 36) Converter\n");
	printf("3.*Base(2-36) to Decimal Converter\n");
	printf("4.**Ultimate Number System Converter\n");
	printf("5.Program Info & Credits\n");
	printf("0.Exit Program\n");
	sleep(1);
	printf("\nSelect what you want and press Enter: ");
}

void input(){
	sleep(1);
	printf("\nInput an Unsigned Integer, or input \"0\" to exit: ");
}

void input2(){
	sleep(1);
	printf("Input an Unsigned Integer, with Uppercase Letter replacing numbers that are >= 10: ");
} 

void choose(){
	printf("\nInput your Target Number System [Binary(2) / Octal(8)]: ");
}

void choose2(){
	printf("\nInput your Target Number System (2~36): ");
}

void bin(unsigned int x){			//Decimal to Binary Step-by-step
	if ((x+1)/2){
		printf("%d mod 2----------%d\n",x,x%2);
		bin(x/2);
	}
}

void oct(unsigned int x){			//Decimal to Octal Step-by-step
	if((x+7)/8){
		printf("%d mod 8---------%d\n",x,x%8);
		oct(x/8);
	}
}

void cvt(unsigned int a,int to) 		//Core Convert Function
{

	int i=0;	
	printf("\n%d",a);
	char array[64]="";
	while(a!=0)	{
		array[i]=a%to;
		if(array[i]>=10)
			array[i]=array[i]-10+'A';
		else
			array[i]+=48;
	a/=to;
	i++;
	}
	i--;
	printf(" in BASE-%d number system: ",to);
	while(i>=0)
	{
	printf("%c",array[i]);
	i--;
}
}

void invalid(){
	sleep(1);
	printf("\nInvalid Input.\n");
}

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

// Function to convert a number from given base 'b' to decimal
int toDeci(char *str, int base)
{
    int len = strlen(str);
    int power = 1; // Initialize power of base
    int num = 0;  // Initialize result
    int i;
 
    // Decimal equivalent is str[len-1]*1 +
    // str[len-1]*base + str[len-1]*(base^2) + ...
    for (i = len - 1; i >= 0; i--)
    {
        // A digit in input number must be less than number's base
        if (val(str[i]) >= base)
        {
           invalid();
           return -1;
        }
        num += val(str[i]) * power;
        power = power * base;
    }
 
    return num;
}

int CVT(char a[32],int n){			// Convert to Decimal
	int i,j;
	long c=0;
	j=strlen(a);
	for(i=j-1,j=0;i>=0;i--,j++)
	c=c+(long)((a[i]-'0')*pow(n,j));
	return c;
}

int TenNum(char a[], int B){	//Ultimate Converter
	int len, i, num;
	int sum = 0;     
	len = strlen(a);                
	for (i = 0; i < len; i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
			num = a[i] - '0';
		else if (a[i] >= 'A' && a[i] <= 'F')
			num = a[i] - 'A' + 10;
		sum = sum * B + num;
	}
	return sum;
}


void Numchange(int m, int B)	//Ultimate Converter
{
	int n;
	if (m){
		Numchange(m / B, B);
		n = m % B;
		if (n < 10)
			printf("%d", n);           //Directly outputs numbers that are <10
		else
			printf("%c", n + 55);      //Replace numbers with Letters when it's >=10
	}
}


void warn(){
	sleep(1);
	printf("\n\n*This is a test function,");
	printf("\nSo we recommend to confirm the results here: https://bit.ly/1Y1BlM0\n");
	sleep(3);
}
void warn2(){
	printf("**Waring: This is an Test Function and maybe UNSTABLE");
}
void notice(){
	printf("\n*Notice: This is a test function\n");
} 

void error(){
	printf("\nError: Base-%d Converison is NOT supported in this build.");
}


void intro2(){
	printf("\nNumSysConverter Version 3.00");
	sleep(1);
	printf("\n(c)2018, Du Jiachen, USST.");
	printf("\ntwitter.com/InvincibleDudu");
	printf("\ngithub.com/InvincibleDudu") ;
	sleep(2);
	printf("\nIf you have any questions or suggestions, ");
	printf("plz contact D.Addition@foxmail.com for further info.\n");
}


void source(int i){ 	//Origin Source Number Verification & Exit Function
	if (i==0)
		exit(1);
	if (i<0)
		invalid();
}

void target(int i,int t){	//Target Number System Verification
	if ((t!=2)&&(t!=8)&&(t>1)&&(t<=36)){
		cvt(i,t);
		warn();
	}
	
	else if (t<=1){
		invalid();
	}
	else if (t>36){
		error();
	}
	else
		cvt(i,t);
}


void boro(unsigned x,int t){	//Binary or Octal
	if (t==2)
	bin(x);
	if (t==8)
	oct(x);
}

void press(){
	sleep(1);
	printf("\nPress any key to continue...\n");
	getch();
} 




