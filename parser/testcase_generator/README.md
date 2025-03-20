# Testcase Generator

**NOTE: I cannot guarantee that the translation of the grammar to the ANTLR format is correct. The generated testcases are only as good as the grammar itself. I tried my best, but there might be errors. If you find some, please fix them.**

This is a small scipt to automatically generate testcases for the parser.

## Requirements

Python and the `grammarinator` package are required to run the script. To install this package, run `make install` or `pip install grammarinator`.

## Usage

To generate the testcases, maybe change the values for the number of testcases and the maximum recursion depth in the `Makefile`. 

Then run `make` to generate the testcases.

Every time `make` is run, new testcases are generated and the old are overwritten. To remove the generated testcases, run `make clean`.
