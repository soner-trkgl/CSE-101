////////////////////////////////////////////////////
//  Gebze Technical University                    //
//  Computer Engineering                          //
//  CSE101 Project                                //
//                                                //  
//  Soner Türkoğlu 161044013                      //
//                                                //  
//                                                //
////////////////////////////////////////////////////




#include<stdio.h>		
#include<termios.h>				// for termios structure
#include<string.h>
#include<unistd.h>				// unix library
#include<errno.h>
#include<fcntl.h>				// file handling
#include <stdlib.h>
#include <signal.h>			
#include <stdbool.h>
#include "myfunction.h"			// my own library has some function int-char conversion

volatile sig_atomic_t stop = true;		
											
void sig_handler(int signum){			// signal handler
	if(signum == SIGINT)
		stop = false;
}



int main(){

	int get_value,square , counter , index=0;		
	long square_result;
	char sent_value;
	char get_buffer[256];

	int serial_port = open("/dev/ttyUSB0", O_RDWR);			

	struct termios tty;

	if(serial_port<0){
		printf("error occur (error no : %d , error information : %s)\n", errno , strerror(errno));

	}

	if(tcgetattr(serial_port,&tty) != 0){
		printf("error occur (error no : %d , error information : %s ) \n" , errno, strerror(errno));
	}

	tty.c_cflag |= CREAD | CLOCAL ;					// some configuration for serial port communication 
	tty.c_cflag &= ~PARENB;
	tty.c_cflag &= ~CSTOPB;
	tty.c_cflag &= CSIZE;
	tty.c_cflag |= CS8;
	tty.c_cflag &= CRTSCTS;
	tty.c_lflag &= ~ICANON;
	tty.c_cc[VTIME] = 10;
	tty.c_cc[VMIN] = 0;
	cfsetispeed(&tty,B9600);
	cfsetospeed(&tty,B9600);


	printf( "## WELCOME TO GTU ARDUINO LAB        ##\n"
			"## STUDENT NAME: SONER TÜRKOĞLU      ##\n"
			"## PLEASE SELECT FROM THE FOLLOWING  ##\n"
			"## MENU:							  ##\n"
			" (1) TURN ON LED ON ARDUINO \n"
			" (2) TURN OFF LED ON ARDUINO \n"
			" (3) FLASH ARDUINO LED 3 TIMES \n"
			" (4) SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO \n"
			" (5) BUTTON PRESS COUNTER \n"
			" (0) EXIT\n"
			
		);

	get_value = 1;	
	while(get_value != 0){
		printf("PLEASE SELECT:\n");
		scanf("%d",&get_value);
		switch(get_value){

			case 1:
				sent_value = '1';
				write(serial_port,&sent_value,1);
				break;
			case 2:
				sent_value = '2';
				write(serial_port,&sent_value,1);
				break;
			case 3:
				sent_value = '3';
				write(serial_port,&sent_value,1);
				break;
			case 4:
				get_buffer[0] = '\0';
				sent_value = '4';
				write(serial_port,&sent_value,1);
				printf("Enter number to calculate square by arduino : ");
				scanf("%d",&square);
				char* temp = int_to_char(square);
				write(serial_port,temp,sizeof(temp));
				memset(get_buffer,'\0',sizeof(get_buffer));
				while( read(serial_port,get_buffer,sizeof(get_buffer)) < 1){}
				square_result = char_to_long(get_buffer);
				printf("Square of %d is %ld\n" , square , square_result);
				break;
			case 5:
				signal(SIGINT,&sig_handler);
				sent_value = '5';
				get_buffer[0] = '\0';
				write(serial_port,&sent_value,1);
				printf("Press ctrl+c combination to stop the counter and return menu\n");
				stop=true;
				while( stop ){
					if(read(serial_port,&get_buffer,sizeof(get_buffer)) > 0){
						printf("%s\n",get_buffer );
						counter = atoi(get_buffer);
						printf("Counter : %d\n", counter);
						memset(get_buffer,'\0',sizeof(get_buffer));
					}
				}
				sent_value = '\0';
				write(serial_port,&sent_value,1);	
				break;
			case 0:
				break;
			default:
				printf("Please enter correct option or you can enter 0 to quit\n");
				break;
		}

	}


	close(serial_port);
	return 0;
}


