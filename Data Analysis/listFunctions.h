
typedef struct list {
	double value;
	int timestamp;
	struct list* next;
	struct list* prev;
}*List;


List initList(double value, int timestamp);
void printList(List l);
List addFirst(List l, double value);
List addLast(List l, double value, int timestamp);
List deleteItem(List l, double value);
List citire(List l, int *n);
List addItem(List l, int stamp, double value, int timestamp);
void sortList(List list);
double max(List list);
List deleteList(List l);