#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <unistd.h>
#include <vector>
using namespace std;

int main(){
  int fd = serialOpen("/dev/serial0",38400);    	
  wiringPiSetup();
  fflush(stdout);
  if(fd<0) printf("can not open serialport\n");    
  else       printf("serialport opened\n");
  char cnt = 0;
	
	vector<char> buf;
  while(1){
		int v = serialGetchar(fd);
		if(v < 0) continue;
		if(v < 0 || v == '\n' ){
			buf.push_back(0);
			printf("%s\n", &buf[0]);
			buf.clear();
		}else{
			buf.push_back((char)v);
		}
    usleep(1000);
  }
  return 0;
}