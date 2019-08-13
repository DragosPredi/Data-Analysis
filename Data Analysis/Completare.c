#include "header.h"

double C(List list, int scalare) //Calcularea C-ului
{	
	return ((double)scalare) / (list->next->timestamp - list->timestamp);
}

double W(int i) //Calcularea W(i)-ului
{
	double S=0;
	double j;
	j=0;
	while(j<3)
	{
		S+=((j/2)*(j/2)*0.9)+0.1;
		j++;
	}

	j=i;

	return (((j/2)*(j/2)*0.9)+0.1)/S;

}

double F(List left, List right, double c)//Calcularea valorii ce trebuie adaugate
{	
	double Sleft = 0, Sright = 0;
	
	int i;
	for(i = 2; i >= 0; i--)
	{
		Sleft += left->value * W(i); //Calcularea sumei elem din stanga
		Sright += right->value * W(i); //calcularea sumei elem din dreapta
		left = left->prev; 
		right = right->next;
	}

	return (((1-c)*Sleft) + (c*Sright));
}

List Completare(List list, int *n)
{
	
	List temp = list->next->next;
	List left, right;
	left = temp;
	right = temp->next;

	int scalare;
	
	while(right->next->next != NULL){
		if((right->timestamp - left->timestamp) > 1000) //verificare daca trebuie adaugate elem
		{
			scalare = left->timestamp;
			while(right->timestamp - scalare > 200)//se adauga toate elem necesare
			{	
				scalare += 200;
				list = addItem(list, (scalare - 200), F(left, right, ((double)scalare - left->timestamp) / (right->timestamp - left->timestamp)), scalare);
				(*n)++;
			}
		}

		
		right = right->next;
		left = right->prev;
	
	}
	return list;
}