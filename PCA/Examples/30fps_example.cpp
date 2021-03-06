#include <time.h>

#include <iostream>
#include <vector>

#include "pca.h"
#include "pcaDefinition.h"
using namespace std;

vector<vector<char> > OFs;
vector<char> OF;

 #define EX_WRITE_ALL
// #define EX_WRITE_CHANNEL

int main(int argc, char* argv[]) {
    PCA pca;  // PCA init
    clock_t init, clk;
    int level = 80, decay = 1;
    init = clock();
    int status = 0;
    while (1) {
        clk = clock();
        if ((clk - init) % (1000 / 15) == 0) {
#ifdef EX_WRITE_CHANNEL
            OF.resize(NUM_AN_OF_NEED_DATA);  // NUM_AN_OF_NEED_DATA = 6 in pcaDefinition.h
            OF[0] = level;
            OF[1] = 200-level;
            OF[2] = level;
            OF[3] = 100;
            OF[4] = 80;
            OF[5] = 90;
            pca.WriteChannel(OF, 9);  // PCA Write One Channel
                                      // pass data(type : vector<char>) and selected channel(type : int) orderly
#endif                                /* EX_WRITE_CHANNEL */
#ifdef EX_WRITE_ALL
            OFs.resize(NUM_OF);  // NUM_OF = 26 in pcaDefinition.h
            for (int i = 0; i < NUM_OF; i++) {
                OFs[i].resize(NUM_AN_OF_NEED_DATA);  // NUM_AN_OF_NEED_DATA = 6 in pcaDefinition.h
                OFs[i][0] = level;//b
                OFs[i][1] = level;//g
                OFs[i][2] = level;//r
                OFs[i][3] = (status%3 == 0)*100;//80;//b
                OFs[i][4] = (status%3 == 1)*100;//80;//g
                OFs[i][5] = (status%3 == 2)*100;//80;//r
            }
            pca.WriteAll(OFs);  // PCA Write All Channel
                                // pass data(type : vector<vector<char>>)
#endif                          /* EX_WRITE_ALL */

            if (level <= 0 || level >= 255) {
                decay -= (decay + decay);
		++status;
            }
            level -= decay;
        }
    }
}
