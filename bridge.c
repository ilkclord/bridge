#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct card{
	int data ;
	struct card * next ;
} ;
typedef struct card card ;

struct flower{
	int number ;// 0 club 1 dia 2 heart 3 splade
	struct flower * flower ;
	struct card * card ;
};
typedef struct flower flower ;

struct player{
	int win_n ;
	struct flower * card ;	
};
typedef struct player player ;

void card_add (card * card , int data){
	card->next = malloc(sizeof(card)) ;
	card->next->data = data ;
	card->next->next = NULL ;
}
void initial_flower(flower * flower){
	int i =1 ;
	for(; i < 4 ;i++){
		flower->flower = malloc(sizeof(flower)) ;
		flower->flower->number = i ;
		flower->flower->card = NULL ;
		flower = flower->flower ;
	}
}

void initial(player * player){
	player = malloc(sizeof(player)) ;
	player->win_n = 0 ;
	player->card = malloc(sizeof(flower));
	player->card->number = 0 ;
	player->card->card = NULL ;
	initial_flower(player->card) ;
}

void card_display(card * a){
	while(a != NULL){
		printf("%u ", a->data);
		a = a -> next;
	}
	printf("%s\n","--------" );
}

void shuffle(card * root,card * last){
	for(int i = 0 ;i < 50 ; i++){
		int top = rand()%52;
		int botton = rand()%(52-top) + 1 ;
		printf("%u %u\n",botton,top);
		if(i == 0)
			top = 0 ;
		card * topc  = root;
		for(int j = 0 ; j < top ;j++){
			if(topc->next != NULL)
				topc = topc->next ;
			else
				printf("%u %s\n",topc->data ,"ERRORt" );
		}
		card * bottonc = topc ; 
		for(int j = 0 ; j < botton ; j++){
			if(bottonc->next != NULL)
				bottonc = bottonc->next ;
			else
				printf("%u %s\n",bottonc->data ,"ERRORb" );
		}
		last->next = topc->next ;
		topc->next = bottonc->next ;
		bottonc->next = NULL ;
		last = bottonc ;
		//card_display(root->next) ;
	}
}

void deal(){
	card * root  = malloc(sizeof(card));
	card * tempt = root ;
	for(int i =  0 ; i < 52 ; i++){
		card_add(tempt,i) ;
		tempt = tempt->next ;
	}
	shuffle(root ,tempt) ;
	card_display(root->next) ;
}


int main(int argc, char const *argv[]){
	deal() ;
	return 0;
}