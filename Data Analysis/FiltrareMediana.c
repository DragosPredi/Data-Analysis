#include "header.h"

double mediaAritm(List list)//media aritm a unei liste de 5 elem
{
	double media = 0;
	while(list != NULL)
	{
		media += list->value;
		list = list->next;
	}
	return media / 5;

}

List FiltrareMediana(List list, int n)
{
	int  i, j;
	
	
	List temp2 = list;
	List temp = temp2;
	List sortedWindow = NULL;
	List WindowPoint = NULL;
	List secondBetterList = NULL;

	sortedWindow = initList(temp->value, temp->timestamp);

	WindowPoint = sortedWindow;
	temp = temp -> next;

	for(i = 0 ; i < 4 ; i++) //creez prima fereastra
		{
			sortedWindow = addLast(sortedWindow, temp->value, temp->timestamp);
			temp = temp->next;
		}

	sortList(sortedWindow); //o sortez
	// adaug elem care trebuie in lista noua
	secondBetterList = addLast(secondBetterList, sortedWindow->next->next->value,sortedWindow->next->next->timestamp);
	temp2 = temp2->next;
	temp = temp2;
	

	for(i = 0 ; i < (n-5) ; i++)
	{		
		sortedWindow = WindowPoint;
		for(j = 0 ; j < 5 ; j++) // reinitializare fereastra
		{
			sortedWindow->value = temp->value;
			sortedWindow->timestamp = temp->timestamp;
			if(j < 4)
				sortedWindow = sortedWindow->next , temp = temp->next;
		}
		sortedWindow = WindowPoint;


		sortList(sortedWindow); // o sortez
		// adaug elem care trebuie in lista noua
		secondBetterList = addLast(secondBetterList, sortedWindow->next->next->value, sortedWindow->next->next->timestamp); 
		temp2 = temp2->next;
		temp = temp2;
	}

	list = deleteList(list);
	sortedWindow = deleteList(sortedWindow);
	
	return secondBetterList;
	
}


List FiltrareMedianaMedieAritm(List list, int n)
{
	int i, j;
	
	List temp2 = list;
	List temp = temp2;
	List sortedWindow = NULL;
	List WindowPoint = NULL;
	List secondBetterList = NULL;

	sortedWindow = initList(temp->value, temp->timestamp);
	WindowPoint = sortedWindow;
	temp = temp -> next;

	for(i = 0 ; i < 4 ; i++) //creez fereastra
		{
			sortedWindow = addLast(sortedWindow, temp->value, temp->timestamp);
			temp = temp->next;
		}
	
	//adaug elem cu valoarea rezultatului functiei mediaArit()
	secondBetterList = addLast(secondBetterList , mediaAritm(sortedWindow) , sortedWindow->next->next->timestamp);
	temp2 = temp2->next;
	temp = temp2;
	

	for(i = 0 ; i < (n-5) ; i++)
	{	

		sortedWindow = WindowPoint;
		for(j = 0 ; j < 5 ; j++) //reinitializez fereastra
		{
			sortedWindow->value = temp->value;
			sortedWindow->timestamp = temp->timestamp;
			if(j < 4)
				sortedWindow = sortedWindow->next , temp = temp->next;
		}
		sortedWindow = WindowPoint;
		//adaug elem cu valoarea rezultatului functiei mediaArit()
		secondBetterList = addLast(secondBetterList, mediaAritm(sortedWindow), sortedWindow->next->next->timestamp);
		temp2 = temp2->next;
		temp = temp2;
	}
	//dealocarea memoriei
	list = deleteList(list);
	sortedWindow = deleteList(sortedWindow);
	return secondBetterList;
}