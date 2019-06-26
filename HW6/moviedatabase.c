#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max_LENGTH 100

struct movie
{
	char name[Max_LENGTH];
	int year;
	float rating;
	char country[Max_LENGTH];
	char inspired[4];
	char bookname[Max_LENGTH];
	char bookwriter[Max_LENGTH];
	int bookyear;
	
};

void findKBest(struct movie* movies, int k, int cursor){
	//
}


void printMovie(struct movie X){
	if(!strncmp((X.inspired),"No",2))
		printf("%s, %d, %.2f, %s, %s, \n", X.name,X.year,X.rating,X.country,X.inspired);
	else
		printf("%s, %d, %.2f, %s, %s, %s, %s, %d\n",X.name,X.year,X.rating,X.country,X.inspired,X.bookname,X.bookwriter,X.bookyear);
}	

void DisplayScreen(struct movie* movies, int cursor){
int choice;

printf("Welcome to Movie Database!\nWhich action do you want:\n1-Insert a movie\n2- Search a movie\n3- Recommend top movies\n4- Exit\n\n");
scanf("%d", &choice);

if(choice == 1){
	printf("Insert a movie with its details (for exit please enter -1): ");
	
	scanf("%s",(movies[cursor]).name);
	if(!strncmp(movies[cursor].name,"-1",2)){
		printf("\n");
		DisplayScreen(movies,cursor);
	}
	
	scanf("%d %f %s %s", &movies[cursor].year, &movies[cursor].rating,movies[cursor].country, movies[cursor].inspired);

	if(!strncmp((movies[cursor].inspired),"Yes",3)){
		scanf("%s %s %d", movies[cursor].bookname, movies[cursor].bookwriter, &movies[cursor].bookyear);
	}

	printf("%s was inserted\n", movies[cursor].name);
	DisplayScreen(movies, cursor + 1);
}
else if(choice == 2){
	char compare[100];
	printf("Please Enter at least 3 characters for searching the database: ");
	scanf("%s", compare);

	int cmp1 = 0,cmp2 = 0, flag;

	for(int i=0; i<cursor; i++){
	char *p = strstr(movies[i].name,compare);
		
	if(p)
		printMovie(movies[i]);
	
	}
	printf("\n");
	DisplayScreen(movies, cursor);
}
else if(choice == 3){
	printf("How many movies will be listed? ");
	int amount;
	scanf("%d", &amount);
	findKBest(movies, amount, cursor);
}
else if(choice == 4)
	printf("Goodbye\n");
	exit(-1);
}

int main(){
	struct movie myMovies[Max_LENGTH];
	DisplayScreen(myMovies, 0);
	printf("\n\n%s\n %d %f %s %s", myMovies[0].name,myMovies[0].year, myMovies[0].rating,myMovies[0].country, myMovies[0].inspired);
}