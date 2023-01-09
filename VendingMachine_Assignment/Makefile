.PHONY: all
all: Test 

.PHONY: Test
Test: Testing
	./Testing

Testing: VendingMachine.o 

.PHONY: Prod
Prod:Production
	./Production

Production: VendingMachine.o 

.PHONY: clean
clean::
	$(RM) *.ii VendingMachine.o Testing Production 
