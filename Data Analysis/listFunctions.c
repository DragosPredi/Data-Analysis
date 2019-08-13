#include "header.h"



//Numele functiilor sunt destul de intuitive, fac exact ce crezi ca ar face

List initList(double value, int timestamp) {
	
	List list = malloc (sizeof(struct list));
	list->next = NULL;
	list->prev = NULL;
	list->value = value;	
	list->timestamp = timestamp;
	return list;
}

void printList(List l) {
	while(l != NULL)
	{
		l->value *= 100;
		l->value = round(l->value);
		l->value /= 100;
		printf("%d %.2f\n",l->timestamp, l->value);
		l = l->next;
	}
}


List addLast(List l, double value, int timestamp) {
	List list = initList(value , timestamp);
	List temp = l;
	if(l == NULL)
		l = list;
	else
	{
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = list;
		list->prev = temp;
	}
	return l;
}

List deleteItem(List l, double value) {
	List temp;
	List prev = NULL;
	temp = l;
	while(temp != NULL && temp->value != value)
	{
		prev = temp;
		temp = temp->next;
	}
	if(prev != NULL)
		prev->next = temp->next;
	free(temp);
	return l;
}
List citire(List l, int *n)
{
	int i, timestamp;
	double k;
	scanf("%d%d%lf", n, &timestamp, &k);
	List list = initList(k, timestamp);

	for(i = 0; i < (*n-1); i++)
	{
		scanf("%d%lf", &timestamp, &k);
		list = addLast(list, k, timestamp);
	}

	return list;
}

List addItem(List l, int stamp, double value, int timestamp) {
	List list = initList(value , timestamp);
	List temp = l;
	while(temp->timestamp != stamp)
		temp = temp->next;

	list->next = temp->next;
	temp->next->prev = list;
	temp->next = list;
	list->prev = temp;


	return l;
}

void sortList(List list)
{
	List i, j;
	double temp;

	for(i = list ; i->next != NULL ; i = i->next)
	{
		for(j = i->next ; j!= NULL ; j = j->next)
		{
			if(i->value > j->value){
				temp = i->value;
				i->value = j->value;
				j->value = temp;
			}
		}
	}
}

double max(List list)
{
	List temp = list;
	double max = -1;
	while(temp != NULL)
	{
		if(max < temp->value)
			max = temp->value;
		temp = temp->next;
	}
	return max;
}

List deleteList(List l) 
{
	List temp;

	while (l != NULL)
	{
		temp = l;
		l = l->next;
		free(temp);
	}

	return NULL;
}