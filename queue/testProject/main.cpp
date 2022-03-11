#include <stdio.h>

#include "../headers/queue.h"

#include "dump/headers/dump.h"
#pragma comment(lib, "lib/dump/dump")

CDump dump;

int main(){

	CQueue<int> queue(5, 5);

	for(;;){
		
		bool result;
		
		result = queue.push(1);
		if(result == false){
			CDump::crash();
		}
		result = queue.push(2);
		if(result == false){
			CDump::crash();
		}
		result = queue.push(3);
		if(result == false){
			CDump::crash();
		}
		result = queue.push(4);
		if(result == false){
			CDump::crash();
		}
		result = queue.push(5);
		if(result == false){
			CDump::crash();
		}

		
		result = queue.pop();
		if(result == false){
			CDump::crash();
		}
		result = queue.pop();
		if(result == false){
			CDump::crash();
		}
		result = queue.pop();
		if(result == false){
			CDump::crash();
		}
		result = queue.pop();
		if(result == false){
			CDump::crash();
		}
		result = queue.pop();
		if(result == false){
			CDump::crash();
		}

		printf("LOOP\n");

	}

	return 0;
}