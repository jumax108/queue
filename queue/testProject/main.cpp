#include <stdio.h>

#include "../headers/queue.h"

#include "dump/headers/dump.h"
#pragma comment(lib, "lib/dump/dump")

class CTest{

public:
	CTest(){
		printf("Constructor\n");
	}

	CTest(const CTest& ptr){
		printf("copy\n");
	}

	~CTest(){
		printf("Destructor\n");
	}

};

CDump dump;

int main(){

	CQueue<CTest> queue(5, 5);

	while(1){
		queue.push(CTest());
		queue.pop();
		system("PAUSE>NUL");
	}

	return 0;
}