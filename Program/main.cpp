// Lab_12_2_1
#include <iostream>
using namespace std;

struct S {
	S* next = nullptr;
	int num;
};

void list_factory(const int& count, S* next) {
	for (size_t i = 0; i < count; )
	{
		cout << "Input " << i << " num: "; cin >> next->num; 
		i++;
		if (i < count) {
			next->next = new S();
			next = next->next;
		}
	}
}

void list_draw(S* list) {
	while (list) {
		cout << list->num << endl;
		list = list->next;
	}
}

void list_swap_custom(S *&curr) {
	S** cur = &curr, **previous = &curr->next;
	while (*cur && *previous) {
		swap(*cur, *previous);
		swap((*previous)->next, (*cur)->next);
		if (!(*cur)->next->next || !(*cur)->next->next->next)
			break;
		cur = &(*cur)->next->next;
		previous = &(*cur)->next->next->next;
	}
}

void main() {
	int size;
	cout << "Input list size: "; cin >> size;
	S* start = new S();
	list_factory(size, start);
	list_draw(start);
	list_swap_custom(start);
	cout << endl;
	list_draw(start);
}