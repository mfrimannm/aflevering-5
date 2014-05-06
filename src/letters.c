// letters.c

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {
	int len = 0;
	int i = 1;

	for(i = 1; i < argc; i++) {
		len = len + strlen(argv[i]);
	}
	printf("%d", len);
	return 0;
}

/* man skal hukse at argc fort�ller hvor mange pladser som argv har
 * det vil sige at hvis man har 4 ord vil argc v�re 5 da plads 0 er navnet p� filen
 * og plads 1,2,3,4 vil v�re de 4 ord.
 *
 * man skal derfor ogs� bruge et for loop da hver ord har sin plads i arrayet som
 * best�r af char arrays.
 *
 * s� den tager v�rdien len som s�ttes til 0 i starten og l�gger s� l�ngden
 * af hver af stringene som ligger p� plads i I argv.
 */
