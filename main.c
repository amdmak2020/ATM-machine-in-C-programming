#include <stdio.h>
int i, x;
int choice = 0;
typedef struct{
	int acc_numb;
	int pass;
	int amount;
}info;
info z[3] = {{12343432,1234,0},{12343433,5678,0},{89877182,1098,0}};
int acc_numb_x, acc_pass_x, amount_x;
int main(){
	while(1){

		printf("\n hello,\n what do you want to do?\n 1. DEPOSIT\n2. WITHDRAWAL\n3. BALANCE ENQUIRY\n4. EXIT\nEnter Your Choice\t");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				deposit();
				break;
			case 2:
				withdrawal();
				break;
			case 3:
				balance();
				break;
			case 4:
				printf("the program is exited");
				return 0;
			default:
				printf("pick on of the options please.");
		}
	}
	return 0;
}
int validate(int num, int pw){
	for (i = 0;i <3;i++){
		if(num == z[i].acc_numb){
			if (pw == z[i].pass){
				return i;
				break;
			}else{
				printf("\nPassword Mismatch");
				exit(1);
				}
		}if(i ==2){
			printf("wrong info");
			exit(1);
		}
	}
}
int deposit(){
	printf("\n account number please\n");
	scanf("%d", &acc_numb_x);
	printf("\n account password please\n");
	scanf("%d", &acc_pass_x);
	printf("\n amount to deposit please\n");
	scanf("%d", &amount_x);
	x = validate(acc_numb_x, acc_pass_x);
	z[x].amount += amount_x;
	printf("your account right now has %d", z[x].amount);
}
int withdrawal(){
	printf("\n account number please\n");
	scanf("%d", &acc_numb_x);
	printf("\n account password please\n");
	scanf("%d", &acc_pass_x);
	printf("\n amount to withdraw please\n");
	scanf("%d", &amount_x);
	x = validate(acc_numb_x, acc_pass_x);
	if (z[x].amount < amount_x){
		printf(" sorry mr scammer but your requested amount of money to withdraw is bigger that your whole account");
	}else{
		z[x].amount -= amount_x;
	}
	printf("your account right now has %d", z[x].amount);
}
int balance(){
	printf("\n account number please\n");
	scanf("%d", &acc_numb_x);
	printf("\n account password please\n");
	scanf("%d", &acc_pass_x);
	x = validate(acc_numb_x, acc_pass_x);
	printf("your account right now has %d", z[x].amount);
}
