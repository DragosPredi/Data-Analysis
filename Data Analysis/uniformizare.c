#include "header.h"

List uniformizare(List list, int n)
{
	int i;
	List temp1 = list;
	List temp2 = list->next;
	//parcurg lista
	for(i = 0 ; i < n-1 ; i++)
	{
		//verific daca este necesara schimbarea nodului
		if((temp2->timestamp - temp1->timestamp) >= 100 && (temp2->timestamp - temp1->timestamp) <=1000)
		{
			//reinitializez valorile cu ce trebuie
			temp2->value = (temp1->value + temp2->value)/2;
			temp2->timestamp = (temp1->timestamp + temp2->timestamp)/2;
		}
		//necesar pentru a nu primi segfault
		if(i < (n-2))
		temp1 = temp2, temp2 = temp2->next;
	}
	
	return list;
}