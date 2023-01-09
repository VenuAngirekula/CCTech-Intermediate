.PHONY: all
all: Test 

.PHONY: Test
Test: Testingcode
	./Testingcode

Testingcode: CurrencyConvertor.o 

.PHONY: Implement
Implement:Implementation
	./Implementation

Implementation: CurrencyConvertor.o 

.PHONY: clean
clean::
	$(RM) *[adios] *.ii Testingcode Implementation CurrencyConvertor
