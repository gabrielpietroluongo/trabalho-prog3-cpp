classinconsistencyexception: src/exceptions/ClassInconsistencyException.cpp src/exceptions/ClassInconsistencyException.h
	$(CPPC) -o build/exceptions/classinconsistencyexception.o -c src/exceptions/ClassInconsistencyException.cpp

invalidcodeexception: src/exceptions/InvalidCodeException.cpp src/exceptions/InvalidCodeException.h
	$(CPPC) -o build/exceptions/invalidcodeexception.o -c src/exceptions/InvalidCodeException.cpp

invaliddateexception: src/exceptions/InvalidDateException.cpp src/exceptions/InvalidDateException.h
	$(CPPC) -o build/exceptions/invaliddateexception.o -c src/exceptions/InvalidDateException.cpp

repeatedcodeexception: src/exceptions/RepeatedCodeException.cpp src/exceptions/RepeatedCodeException.h
	$(CPPC) -o build/exceptions/repeatedcodeexception.o -c src/exceptions/RepeatedCodeException.cpp