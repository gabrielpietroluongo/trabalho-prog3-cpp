src/exceptions/classinconsistencyexception.o: src/exceptions/ClassInconsistencyException.cpp src/exceptions/ClassInconsistencyException.h
	$(CPPC) -o src/exceptions/classinconsistencyexception.o -c src/exceptions/ClassInconsistencyException.cpp

src/exceptions/invalidcodeexception.o: src/exceptions/InvalidCodeException.cpp src/exceptions/InvalidCodeException.h
	$(CPPC) -o src/exceptions/invalidcodeexception.o -c src/exceptions/InvalidCodeException.cpp

src/exceptions/invaliddateexception.o: src/exceptions/InvalidDateException.cpp src/exceptions/InvalidDateException.h
	$(CPPC) -o src/exceptions/invaliddateexception.o -c src/exceptions/InvalidDateException.cpp

src/exceptions/repeatedcodeexception.o: src/exceptions/RepeatedCodeException.cpp src/exceptions/RepeatedCodeException.h
	$(CPPC) -o src/exceptions/repeatedcodeexception.o -c src/exceptions/RepeatedCodeException.cpp