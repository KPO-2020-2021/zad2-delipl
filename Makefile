TRGDIR=.
OBJ=./obj
SRC=./src
INC=./inc
TESTS=./tests
TBIN=./tests/bin
FLAGS= -Wall -pedantic -std=c++14 -g -iquote inc

${TRGDIR}/test_arytm_zesp: ${OBJ} ${OBJ}/main.o ${OBJ}/Complex.o\
                     ${OBJ}/Expression.o  ${OBJ}/QuizDataBase.o ${OBJ}/Statistics.o
	g++ -o ${TRGDIR}/test_arytm_zesp ${OBJ}/main.o ${OBJ}/Complex.o\
                     ${OBJ}/Expression.o ${OBJ}/QuizDataBase.o ${OBJ}/Statistics.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: ${SRC}/main.cpp ${INC}/Complex.hpp ${INC}/Expression.hpp ${INC}/QuizDataBase.hpp
	g++ -c ${FLAGS} -o ${OBJ}/main.o ${SRC}/main.cpp

${OBJ}/Complex.o: ${SRC}/Complex.cpp inc/Complex.hpp
	g++ -c ${FLAGS} -o ${OBJ}/Complex.o ${SRC}/Complex.cpp

${OBJ}/Expression.o: ${SRC}/Expression.cpp ${INC}/Expression.hpp\
                       inc/Complex.hpp
	g++ -c ${FLAGS} -o ${OBJ}/Expression.o ${SRC}/Expression.cpp

${OBJ}/QuizDataBase.o: ${SRC}/QuizDataBase.cpp ${INC}/QuizDataBase.hpp ${INC}/Expression.hpp\
                       inc/Complex.hpp
	g++ -c ${FLAGS} -o ${OBJ}/QuizDataBase.o ${SRC}/QuizDataBase.cpp 

${OBJ}/Statistics.o: ${SRC}/Statistics.cpp inc/Statistics.hpp
	g++ -c ${FLAGS} -o ${OBJ}/Statistics.o ${SRC}/Statistics.cpp

${TBIN}/test_0.o: ${TBIN} 
	g++ -o ${TESTS}/bin/test_1.o ${FLAGS} -I${TESTS}/doctest ${TESTS}/test0.cpp 

${TBIN}/test_1.o: ${TBIN} ${OBJ}/Complex.o 
	g++ -o ${TESTS}/bin/test_1.o ${FLAGS} -I${TESTS}/doctest ${TESTS}/test1.cpp ${OBJ}/Complex.o

${TBIN}/test_2.o: ${TBIN} ${OBJ}/Complex.o ${OBJ}/Expression.o 
	g++ -o ${TESTS}/bin/test_2.o ${FLAGS} -I${TESTS}/doctest ${TESTS}/test2.cpp ${OBJ}/Complex.o ${OBJ}/Expression.o 

${TBIN}/test_3.o: ${TBIN} ${OBJ}/QuizDataBase.o ${OBJ}/Complex.o ${OBJ}/Expression.o 
	g++ -o ${TESTS}/bin/test_3.o ${FLAGS} -I${TESTS}/doctest ${TESTS}/test3.cpp ${OBJ}/Complex.o ${OBJ}/Expression.o ${OBJ}/QuizDataBase.o 



${TBIN}:
	mkdir ${TBIN}

test: ${TBIN}/test_0.o  ${TBIN}/test_1.o ${TBIN}/test_2.o  ${TBIN}/test_3.o
	${TBIN}/test_0.o 
	${TBIN}/test_1.o 
	${TBIN}/test_2.o
	${TBIN}/test_3.o 

testRound:	${TBIN}/test_0.o 
	${TBIN}/test_0.o 

testComplex:  ${TBIN}/test_1.o 
	${TBIN}/test_1.o 

testExpression: ${TBIN}/test_2.o
	${TBIN}/test_2.o

testQuiz: ${TBIN}/test_3.o
	${TBIN}/test_3.o


run:
	${TRGDIR}/test_arytm_zesp latwy
runTrudny:
	${TRGDIR}/test_arytm_zesp trudny

clean:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/* ${TBIN}/*

complex: ${SRC}/Complex.cpp inc/Complex.hpp
	g++ -c ${FLAGS} -o ${OBJ}/Complex.o ${SRC}/Complex.cpp

expression: ${SRC}/Expression.cpp inc/Expression.hpp inc/Complex.hpp
	g++ -c ${FLAGS} -o ${OBJ}/Expression.o ${SRC}/Expression.cpp

quiz: ${SRC}/QuizDataBase.cpp inc/QuizDataBase.hpp inc/Expression.hpp inc/Complex.hpp 
	g++ -c ${FLAGS} -o ${OBJ}/QuizDataBase.o ${SRC}/QuizDataBase.cpp