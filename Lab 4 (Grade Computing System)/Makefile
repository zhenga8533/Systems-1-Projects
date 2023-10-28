FUNCTIONS = functions/calcFinals.c functions/deleteNode.c functions/freeMemory.c functions/insertNode.c functions/populateNode.c functions/printHeader.c functions/printScores.c functions/recalcID.c functions/recalcScores.c functions/requestID.c functions/requestName.c functions/scoreID.c functions/writeData.c functions/calcCumulative.c functions/printLine.c functions/addStudent.c functions/findID.c functions/calcFinal.c functions/recalcScore.c

all: lab4.zip lab4

lab4.zip: Makefile lab4main.c lab4.h ${FUNCTIONS}
	zip lab4 Makefile lab4main.c lab4.h ${FUNCTIONS}
	
lab4: lab4main.c lab4.h ${FUNCTIONS}
	gcc -std=c99 -pedantic -g -o lab4 lab4main.c lab4.h ${FUNCTIONS}

clean:
	rm -rf lab4 lab4.zip
