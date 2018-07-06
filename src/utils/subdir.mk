# Utils

src/utils/argparse.o: src/utils/ArgParse.cpp src/utils/ArgParse.h
	$(CPPC) -o src/utils/argparse.o -c src/utils/ArgParse.cpp

src/utils/icstream.o: src/utils/icstream.cpp src/utils/icstream.h
	$(CPPC) -o src/utils/icstream.o -c src/utils/icstream.cpp

src/utils/ocstream.o: src/utils/ocstream.cpp src/utils/ocstream.h
	$(CPPC) -o src/utils/ocstream.o -c src/utils/ocstream.cpp


# CPP Utils

src/utils/cpp_utils/dateutils.o: src/utils/cpp_utils/DateUtils.cpp src/utils/cpp_utils/DateUtils.h
	$(CPPC) -o src/utils/cpp_utils/dateutils.o -c src/utils/cpp_utils/DateUtils.cpp

src/utils/cpp_utils/numberutils.o: src/utils/cpp_utils/NumberUtils.cpp src/utils/cpp_utils/NumberUtils.h
	$(CPPC) -o src/utils/cpp_utils/numberutils.o -c src/utils/cpp_utils/NumberUtils.cpp

src/utils/cpp_utils/numpunctptbr.o: src/utils/cpp_utils/NumPunctPTBR.cpp src/utils/cpp_utils/NumPunctPTBR.h
	$(CPPC) -o src/utils/cpp_utils/numpunctptbr.o -c src/utils/cpp_utils/NumPunctPTBR.cpp

src/utils/cpp_utils/stringutils.o: src/utils/cpp_utils/StringUtils.cpp src/utils/cpp_utils/StringUtils.h
	$(CPPC) -o src/utils/cpp_utils/stringutils.o -c src/utils/cpp_utils/StringUtils.cpp

src/utils/cpp_utils/tokenizer.o: src/utils/cpp_utils/Tokenizer.cpp src/utils/cpp_utils/Tokenizer.h
	$(CPPC) -o src/utils/cpp_utils/tokenizer.o -c src/utils/cpp_utils/Tokenizer.cpp

