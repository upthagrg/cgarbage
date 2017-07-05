#include <assert.h>
struct list_head{
	struct list_head* next;
	struct list_head* prev;
};
void init_list_head(struct list_head* head){
	head->next = head;	
	head->prev = head;	
}
void add_after(struct list_head* a, struct list_head* b){
	struct list_head* temp;
	temp = b->next;
	b->next = a;
	a->prev = b;
	a->next = temp;
}
void add_before(struct list_head* a, struct list_head* b){
	struct list_head* temp;
	temp = b->prev;
	b->prev = a;
	a->next = b;
	a->prev = temp;
}
void remove_after(struct list_head* a){
	struct list_head* temp;
	assert(a->next != a);
	temp = a->next;
	a->next = a->next->next;
	a->next->prev = a;
	free(temp);
}
void remove_before(struct list_head* a){
	struct list_head* temp;
	assert(a->next != a);
	temp = a->prev;
	a->prev = a->prev->prev;
	a->prev->next = a;
	free(temp);
}
