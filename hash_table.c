#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct element {
	int val;
	struct element *next;
};

struct hash {
	struct element *head;
};

struct element *H[8];
void init() {
	int i;
	for (i=0; i<8; i++);
		H[i] = NULL;
}

int h(int val) {
	float A;
	A=(sqrt(7)-1)/2;
	return 8*(A*val-(int)(A*val));
}

void insert(int val) {
	int i = h(val);
	struct element* tmp = malloc(sizeof(struct element));
	tmp->val = val;
	tmp->next = H[i];
	H[i] = tmp;
}

struct element* search(int k){
	
	int hashkey = h(k);
	struct element *tmp = H[hashkey];
	
	while (tmp != NULL){
		
		if (tmp->val == k){
			return tmp; 
		} 
		else{
			tmp = tmp->next;
		}	
	}
	return NULL;
}

void printHash(){
	
	int i;
	struct element *tmp;
	
	printf("Size of hashtable: %d\n", 8);
	for (i = 0; i < 8; i++) {
		if (H[i] != NULL) {
			printf("Key: %d, content: [", i);
			tmp = H[i];
			while(tmp != NULL) {
				printf("%d", tmp->val);
				tmp = tmp->next;
			}
			printf("]\n");
		}
	}
}

void main() {
	
	int i;
	struct element* tmp;
	int searchValues[] = {1, 10112, 1113, 5568, 337};
	
	init();
	insert(111);
	insert(10112);
	insert(1113);
	insert(5568);
	insert(63);
	insert(1342);
	insert(21231);
	printHash();
	
	
	for(i=0;i<5;i++){
		tmp = search(searchValues[i]);
		if(tmp==NULL){
			printf("Element %d, not found\n", searchValues[i]);
		}
		else{
			printf("Element %d, found %d\n", searchValues[i], tmp->val);		
		}
	}
}
