#include "header.h"

ValStat calculare(List l, int k)   //Calcularea mediei + deviatiei
{


	ValStat valStat;
	int i ;
	double sum = 0;
	List temp = l;
	
	for(i = 0; i < k; i++)
	{
		sum += temp->value;
		temp = temp->next;
	}

	valStat.media = sum/k; //media

	sum = 0;
	
	for(i = 0; i < k; i++)
	{
		sum += (l->value - valStat.media)*(l->value - valStat.media);
		l = l->next;
	}

	valStat.deviatia = sqrt(sum/k); //deviatia

	//functia v-a returna media si deviatia unei variabile struct de tip valStat
	return valStat;

}
List MetodeStatistice(List list, int *n){
	
	int nrNoduri = *n;
	List temp = list;
	List cont = list;
	List noduriDeSters = NULL;

	int i;

	for(i = 2; i < (nrNoduri-2); i++)  //parcurg lista
	{
		ValStat valStat = calculare(temp, 5);
		cont = temp->next->next;

	  	if(!(cont->value >= (valStat.media - valStat.deviatia) && cont->value <= (valStat.media + valStat.deviatia))) 
	  		noduriDeSters = addLast(noduriDeSters, cont->value, cont->timestamp); // marchez nodurile care trebuie sterse

	  	
		 temp = temp->next;
	}
	temp = list;
	cont = noduriDeSters;

	while (noduriDeSters != NULL) 
	{
		//parcurg lista nodurilor marcate si le sterg din lista originala

		list = deleteItem(list, noduriDeSters->value);
		noduriDeSters = noduriDeSters->next;
		nrNoduri--;
	}

	//dealocarea memoriei listei de noduri marcate
	cont = deleteList(cont);

	*n = nrNoduri;
	return list;	
}
