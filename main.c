
//NOT YET COMPLETE (PARSER FUNCTION AND TOTAL DISTANCE CALCULATION ONLY)



#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main() {
            double totaldistance=0;
            double distance=0;
            double longitude2=0;
            double latitude2=0;
            char* ID ;
            char* Time;
            char* Longitude1;
            char* direction;
            char* Latitude1;
            char NMEA[100];
     while(totaldistance<100){

    //parsingfun(); returns latitude1 , longitude1

            char* ID ;
            char* Time;
            char* Longitude1;
            char* direction;
            char* Latitude1;
            char NMEA[100];
            int c=1;
	//parsing function by:(Ahmed Haggag)(not yet tested)
     while(c){

            /*we are going to implement a for loop that passes the ascii character in the data register to a string whenever it is not empty ,,
	    if the string doesn,t contain GPGGA , another loop is made with the following sentence , once the
            GPGGA line is found , long and lat are extracted and the loop breaks*/
            int i;
            for(i =0 ; i<100 , i++){
            while((UART1_FR_R&0X10)!=0){}
            NMEA[i]=UART7_DATA_R;} //finishes when line break is found

        if(NMEA[4]=='G' && NMEA[5]=='A'){   //check for GPGGA
            c=0;
            ID = strtok(NMEA,",");
            Time = strtok(NULL,",");
            Latitude1 = strtok(NULL,",");
            direction = strtok(NULL,",");
            Longitude1 = strtok(NULL,",");

            }
        else{c=1;}
        }
        double longitude1=atof(Longitude1);
        double latitude1=atof(Latitude1);

	//to calculate total distance (by: Sandy Ibrahim)

     if (longitude2!=0&&latitude2!=0) //don't calculate distance at first point
    {

        distance= Calc_distance( latitude1,  longitude1, latitude2, longitude2);
    }
        latitude2=latitude1;
        longitude2=longitude1;
	totaldistance+=distance ;


}}
