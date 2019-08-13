#include "header.h"

List bonus(List list, int delta)
{
	int cap;
	sortList(list);
	double maxim = max(list); // gasirea elem maxim, necesar pentru conditia de oprire
	List temp = list;

	//gasirea primului cap de interval
	if(list->value < 0)
		cap = (int)(list->value - 1);
	else
		cap = abs(list->value);

	int nrElem;
	//parcurgerea listei
	while(cap < maxim)
	{
		nrElem = 0;

		while(temp->value < cap + delta) // caut elem pe fiecare interval
		{
			nrElem++;
			if(temp->next == NULL) break;
			temp = temp->next;
		}
		
		if(nrElem != 0) //afisez daca gasesc elem pe acel interval
			printf("[%d, %d] %d\n", cap, cap +delta, nrElem);

		cap = cap + delta;
	}

	return list;
}