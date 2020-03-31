// deencrypt python source code

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "pycrypt.h"

static char *usage = "\
pydecrypt: decrypt a encrypted python file\n\
Version: 1.03\n\
\n\
pydecrypt is not a public program. You cannot use this program unless you are authorized.\n\
\n\
Usage:\n\
pydecrypt <enc.py> \n\
";

int main(int argc, char **argv)
{
	const char *key = _my_pycryptor_key;

	if (argc != 2) {
		fprintf(stderr, "%s", usage);
		return 0;
	}

	FILE *fp = fopen(argv[1], "rb");

	if (fp == NULL) {
		fprintf(stderr, "__error__: cannot open %s\n", argv[1]);
		fprintf(stderr, "%s", usage);
		return 0;
	}

	char *out = load_pye(fp, key);
	if (out != NULL) {
		printf("%s", out);
	}

	fclose(fp);
	free(out);
	return 1;
}

