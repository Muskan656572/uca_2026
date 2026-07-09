#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char *argv[]){
	if(argc!=3){
		printf("Usage: ./copy <file1> <file2> \n ");
		exit(-1);
	}
	return 0;
}
