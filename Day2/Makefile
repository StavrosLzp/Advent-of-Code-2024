.phony: all clean
 
all: safe_reports

CPP = g++
CPPFLAGS = -Wall -Wextra -std=c++17 -O3

safe_reports: safe_reports.cpp
	$(CPP) safe_reports.cpp -o safe_reports $(CPPFLAGS)



clean:
	rm -f *.o safe_reports 