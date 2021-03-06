#include <iostream> 
#include <time.h> 
#include "../lib/LED_strip.h"
#define fps 30
using namespace std;

// the number of leds of every strip
// maximum 16 numbers in the vector ( maximum 16 led strips )
// declaration
vector<uint16_t> nLeds;
// rgb data of every single led
vector< vector<char> > buf; 

// initialization
LED_Strip strips;

int main() {
    // resize buf to a (number of strips)*(number of leds of the strip)*3 vector
    nLeds={60, 60, 60, 60, 60,60};//change the numbers of lights here
    strips.initialize(nLeds);
    
	buf.resize(nLeds.size());
	for(int i = 0; i < nLeds.size(); ++i){
		buf[i].resize(nLeds[i] * 3, (char)0);
	}
    clock_t init=clock();
    // set the colors of every leds
    // this example set every leds to green
    // the while loop is for 
    while(true) {
        while( (1000 * (clock() - init)) / CLOCKS_PER_SEC < 1000/fps);
        init = clock();
        for (int i = 0; i < nLeds.size(); ++i) {
            for (int j = 0; j < nLeds[i]; ++j) {
                buf[i][3*j  ] = 0; // g
                buf[i][3*j+1] = 0; // r
                buf[i][3*j+2] = 100; // b     
            }
        }
        // send data to stm32s
        strips.sendToStrip(buf);
        // wait for stm to deal with the data
    }
}