#include "header.h"

int main(int argc, char **argv)
{

	int n , i;
	List list = NULL;
	list = citire(list, &n);

	int ok = 0; // necesar pentru cazul in care testul este de tip --st<delta>
	for(i = 1 ; i < argc ; i++) //loop prin toate comenzile date in linia de comanda
	{
		if(strcmp(argv[i], "--e1") == 0)
			list = MetodeStatistice(list, &n);
		else if(strcmp(argv[i], "--e2") == 0)
			list = FiltrareMediana(list, n), n = n - 4;
		else if(strcmp(argv[i], "--e3") == 0)
			list = FiltrareMedianaMedieAritm(list, n) , n = n - 4;
		else if(strcmp(argv[i], "--u") == 0)
			list = uniformizare(list, n);
		else if(strcmp(argv[i], "--c") == 0)
			list = Completare(list, &n);
		else 
			list = bonus(list, atoi(argv[1]+4)) , ok = 1;

	}
	if(ok == 0)//daca a fost --st nu se mai face afisarea
	{
		//afisare lista finala
		printf("%d\n", n);
		printList(list);
	}
	//dealocarea memoriei
	list = deleteList(list);





	

	return 0;

}