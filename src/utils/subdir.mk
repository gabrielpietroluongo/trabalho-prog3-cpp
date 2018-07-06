# Utils

argparse: src/utils/ArgParse.cpp src/utils/ArgParse.h
	$(CPPC) -o build/utils/argparse.o -c src/utils/ArgParse.cpp

icstream: src/utils/icstream.cpp src/utils/icstream.h
	$(CPPC) -o build/utils/icstream.o -c src/utils/icstream.cpp

ocstream: src/utils/ocstream.cpp src/utils/ocstream.h
	$(CPPC) -o build/utils/ocstream.o -c src/utils/ocstream.cpp


# CPP Utils

cpp_utils/dateutils: src/utils/cpp_utils/DateUtils.cpp src/utils/cpp_utils/DateUtils.h
	$(CPPC) -o build/utils/dateutils.o -c src/utils/cpp_utils/DateUtils.cpp

cpp_utils/numberutils: src/utils/cpp_utils/NumberUtils.cpp src/utils/cpp_utils/NumberUtils.h
	$(CPPC) -o build/utils/numberutils.o -c src/utils/cpp_utils/NumberUtils.cpp

cpp_utils/numpunctptbr: src/utils/cpp_utils/NumPunctPTBR.cpp src/utils/cpp_utils/NumPunctPTBR.h
	$(CPPC) -o build/utils/numpunctptbr.o -c src/utils/cpp_utils/NumPunctPTBR.cpp

cpp_utils/stringutils: src/utils/cpp_utils/StringUtils.cpp src/utils/cpp_utils/StringUtils.h
	$(CPPC) -o build/utils/stringutils.o -c src/utils/cpp_utils/StringUtils.cpp

cpp_utils/tokenizer: src/utils/cpp_utils/Tokenizer.cpp src/utils/cpp_utils/Tokenizer.h
	$(CPPC) -o build/utils/tokenizer.o -c src/utils/cpp_utils/Tokenizer.cpp

clean:
	@rm -f build bin