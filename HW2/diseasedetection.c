#include <stdio.h>
#define MAX_PAIRS 10
#define MAX_INPUT_SIZE 25

char toUpper(char letter){ //simple function to change lowercase letters to uppercase
	if(letter > 96)
		return letter - 32;
	else
		return letter;
}

int main(){
	int A = 0, C = 0, G = 0, T = 0, inputsize = 0, pairAT=0, pairGC=0; 
	char last;
		printf("Enter a seq.:");
		for(inputsize = 0; inputsize < MAX_INPUT_SIZE; inputsize++){
			char input = toUpper(getchar()); //all uppercase input
			
			if(input == '\n')	//if user press enter break the loop
				break;
			
			while(last == input){ //filter out the repeating letters
				input = toUpper(getchar());	
				inputsize++;
			}

			if(inputsize == 0)//print out the message for dna sequence
				printf("DNA seq.:");

			if(input == 'A' && A <= T){ //increment 'A' if T needs a pair or there is not any pair
				A++;
				printf("%c", input);
			}
			else if(input == 'G' && G <= C){ //increment 'G' if C needs a pair or there is not any pair
				G++;
				printf("%c", input);
			}
			else if(input == 'C' && C <= G){ //increment 'C' if G needs a pair or there is not any pair
				C++;
				printf("%c", input);
			}
			else if(input == 'T' && T <= A){ //increment 'T' if A needs a pair or there is not any pair
				T++;
				printf("%c", input);
			}
			else if(input == 'X'){
				printf("\nTerminated");
				break;
			}

			last = input; // assign last to input for further use

			if(A == T && A > 0){ //increment pair counters and set nucleotides to zero since they are paired
				pairAT++;
				A = 0;
				T = 0;
			}
			else if(G == C && G > 0){ //increment pair counters and set nucleotides to zero since they are paired
				pairGC++;
				G = 0;
				C = 0;
			}
		if(pairGC+pairAT >= 5) //stop if there are five pairs
			break;
		}
		printf("\n"); //newline
		
		if(A+G+C+T == 0)	//if there are no extra nucleotides then we can say that the sequence is healthy
			printf("Healhty!\n");
		else if(A+T == 1 && A+G+C+T == 1){ //if there is one extra we need to find which one is extra
			A > T ? printf("Disease: A nucleotide\n"):printf("Disease: T nucleotide\n");
		}
		else if(G+C == 1 && A+G+C+T == 1){
			G > C ? printf("Disease: G nucleotide\n"):printf("Disease: C nucleotide\n");
		}
		else if(A+G+C+T == 2){ //if both nucleotide pairs (A-T, G-C) have an extra nucleotide we need to determine which of them are extra
			char extraF = A > T ? A : T;
			char extraS = G > C ? G : C;
			printf("Disease %c and %c nucleotides\n", extraF, extraS);
		}
	return 0;
}
