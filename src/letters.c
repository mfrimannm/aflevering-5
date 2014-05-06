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

/* man skal hukse at argc fortæller hvor mange pladser som argv har
 * det vil sige at hvis man har 4 ord vil argc være 5 da plads 0 er navnet på filen
 * og plads 1,2,3,4 vil være de 4 ord.
 *
 * man skal derfor også bruge et for loop da hver ord har sin plads i arrayet som
 * består af char arrays.
 *
 * så den tager værdien len som sættes til 0 i starten og lægger så længden
 * af hver af stringene som ligger på plads i I argv.
 */
