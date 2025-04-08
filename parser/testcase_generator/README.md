# Testcase Generator

**NOTE: I cannot guarantee that the translation of the grammar to the ANTLR format is correct. The generated testcases are only as good as the grammar itself. I tried my best, but there might be errors. If you find some, please fix them.**

This is a small scipt to automatically generate testcases for the parser.

## Requirements

Python and the `grammarinator` package are required to run the script. To install this package, run `make install` or `pip install grammarinator`.

## Usage

To generate the testcases, maybe change the values for the number of testcases and the maximum recursion depth in the `Makefile`. 

Then run `make` to generate the testcases.

Every time `make` is run, new testcases are generated and the old are overwritten. To remove the generated testcases, run `make clean`.

### If it doesn't work

If the makefile does not work (e.g. Error 127), make sure the `~/.local/bin` directory is in your PATH. You can do this by running the following command:

```bash
export PATH=$PATH:~/.local/bin
```

If it still does not work, try running the commands directly in the `parser/testcase_generator` directory:

```bash
grammarinator-process Uebersetzerbau.g4 -o . > /dev/null 2> /dev/null
grammarinator-generate \
		-r program \
		-n 100 \
		-d 25 \
		-o ../generated_test_%d.0 \
		-s grammarinator.runtime.serializer.simple_space_serializer \
		--sys-path . \
		UebersetzerbauGenerator.UebersetzerbauGenerator
```

**NOTE: For some reason, the PATH gets modified after the `.bashrc` is loaded, so you can sadly not add it in there.**
