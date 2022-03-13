/****************************************************************************
  FileName     [ pca9956.h ]
  PackageName  [ clientApp ]
  Synopsis     [  ]
  Author       [ Ken Chung ]
  Copyright    [ Copyleft(c) , NTUEE, Taiwan ]
****************************************************************************/

//----------------------------------------------------------------------
//    Global
//----------------------------------------------------------------------

#ifndef PCA9956_H
#define PCA9956_H

#include "pca995X.h"
#include "pcaDefinition.h"

class PCA9956 : public PCA995X {
   public:
    PCA9956(){};
    ~PCA9956(){};
    PCA9956(int Address) : PCA995X(Address){};

    bool CheckChannelLegal(int channel);
    int GetLedChannelNum();
    int GetIREF0Reg();
    int GetPWM0Reg();
};

#endif /* PCA9956_H */
