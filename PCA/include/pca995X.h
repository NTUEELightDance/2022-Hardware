/****************************************************************************
  FileName     [ pca995X.h ]
  PackageName  [ clientApp ]
  Synopsis     [  ]
  Author       [ Ken Chung ]
  Copyright    [ Copyleft(c) , NTUEE, Taiwan ]
****************************************************************************/

//----------------------------------------------------------------------
//    Global
//----------------------------------------------------------------------

#ifndef PCA995X_H
#define PCA995X_H

#include <cstdint>

#define PCA995X_I2C_ADDRESS_DEFAULT 0x00
#define PCA995X_IREF_DEFAULT 255
#define PCA995X_PWM_DEFAULT 0

#define ADDRESS(x) (static_cast<int>(x))
#define VALUE(x) (static_cast<int>(x))
#define CHANNEL(x) (static_cast<int>(x))

#define IREF_MAX 255
#define IREF_MIN 0
#define PWM_MAX 255
#define PWM_MIN 0


// Base class for PCA9955 & PCA9956
class PCA995X {
   public:
    PCA995X() {}
    ~PCA995X() {}
    PCA995X(int Address);

    int SetPWMAI(int channel, int *PWM, int size);
    int SetIREFAI(int channel, int *IREF, int size);
    int SetPWMIREFAI(int *data);

    int SetRGB(int led_address, int Rduty, int Gduty, int Bduty, int Riref, int Giref, int Biref);

    void GetAll();

    int Getfd() { return fd; };

    virtual bool CheckChannelLegal(int channel){ return true; };
    virtual int GetLedChannelNum(){ return 0; };
    virtual int GetIREF0Reg(){ return 0; };
    virtual int GetPWM0Reg(){ return 0; };

   protected:
    int SetPWM(int channel, int PWM);
    int GetPWM(int channel);

    int SetIREF(int channel, int IREF);
    int GetIREF(int channel);

    int I2CWriteReg(int reg, int value);
    int I2CReadReg(int reg);

    int PCA995X_Address;
    int fd;
};

#endif /* PCA995X_H */
