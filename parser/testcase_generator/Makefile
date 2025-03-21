NUM_TESTCASES=100
MAX_RECURSION_DEPTH=25

.PHONY: all clean generate_testcases

all: generate_testcases

install:
	pip install grammarinator

UebersetzerbauGenerator.py: Uebersetzerbau.g4
	@grammarinator-process Uebersetzerbau.g4 -o . > /dev/null 2> /dev/null

generate_testcases: UebersetzerbauGenerator.py
	@grammarinator-generate \
		-r program \
		-n $(NUM_TESTCASES) \
		-d $(MAX_RECURSION_DEPTH) \
		-o ../generated_test_%d.0 \
		-s grammarinator.runtime.serializer.simple_space_serializer \
		--sys-path . \
		UebersetzerbauGenerator.UebersetzerbauGenerator

	@echo "Generated $(NUM_TESTCASES) testcases"

clean:
	rm -rf UebersetzerbauGenerator.py ../generated_test_*.0
