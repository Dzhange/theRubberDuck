#include "doubll.h"
#include <stdlib.h>
#include <stdio.h>




bool less(const void* a, const void*b)
{
	return *(int *)a < *(int *)b;
}



void display_list(doubll * list) {
	int* value;
	doubll_item* current;
	doubll_item* tail;
	size_t count;
	FILE * fp;


	if (list->items == 0) {

		fp = fopen ("m.txt","w");
		fprintf(fp, " ");
		fclose(fp);
		return;
	}
	current = list_begin(list);

	tail = list_end(list);

	fp = fopen ("m.txt","w");


	count = 0;
	while (current != tail) {
		count++;
		value = (int *)current->data;
		
		fprintf(fp, "%d\n",*value);
		
		current = current->next;
	}
	fclose(fp);
}

doubll_item* get_Item(doubll* list,size_t n){
	size_t count = 0;
	doubll_item* cur = list_head(list);
	if (n > list_size(list)){
		return NULL;
	}
	
	
	while(count < n){
		cur = cur->next;
		count ++;
	}
	return cur;
}



int main(int argc,char* argv[])
{
	
	
	int operation;
	int data;
	int loc;
	doubll_item* tar;
	size_t i;
	size_t size = atoi(argv[argc-1]);

	doubll* ll = (doubll*)malloc(sizeof(doubll));
	list_init(ll);
	
	for (i = 0;i < size;i++){
		scanf("%d",&operation);
		scanf("%d",&data);
		scanf("%d",&loc);
		
		switch (operation)
		{
			case 1 :
				tar = get_Item(ll,loc);
				
				insert_list(ll,tar,&data,sizeof(int));
				
				break;
			case 2 :
				
				tar = get_Item(ll,loc);
				remove_item(ll,tar);
				break;
			case 3 :
				
				sort_list(ll,less);
				break;			
			case 4 :
				purge_list(ll);
				break;
			default:
				break;
		}
		
	}	
	display_list(ll);

	purge_list(ll);
	return 0;
}