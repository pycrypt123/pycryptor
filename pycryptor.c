// encrypt python source code

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "pycrypt.h"

static char *usage = "\
pycryptor: encrypt a python file\n\
Version: 1.03\n\
\n\
pycryptor is not a public program. You cannot use this program unless you are authorized.\n\
\n\
Usage:\n\
pycryptor <hello.py> <hello_enc.py>\n\
\n\
hello.py: the python file to encrypt\n\
hello_enc.py: the encrypted python file\n\
\n\
The suffix of the encrypted python file MUST be .py. Do not use other suffix.\n\
";

int main(int argc, char **argv)
{
	const char *key = _my_pycryptor_key;

	if (argc != 3) {
		fprintf(stderr, "%s", usage);
		return 0;
	}

	char *filename = argv[1];
	FILE *fp = NULL;
	if ((fp = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "__error__: cannot open input file\n");
		return 0;
	}

	char *outfile = argv[2];
	FILE *out = NULL;
	if ((out = fopen(outfile, "wb")) == NULL) {
		fprintf(stderr, "__error__: cannot open output file\n");
		return 0;
	}

	int fsize = get_file_size(filename);
	if (fsize > 0) { // input is not empty
		byte *enc = (byte *)malloc(fsize + 32);
		encrypt_py_rc4(fp, fsize, key, enc);
		fwrite(enc, 1, fsize + 32, out);
		free(enc);
	}

	fclose(fp);
	fclose(out);

	fprintf(stderr, "LOG: %s is encrypted.\n", argv[1]);
	return 1;
}

