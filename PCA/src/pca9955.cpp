#include "../include/pca9955.h"

// Derived PCA9955
bool PCA9955::CheckChannelLegal(int channel) {
    return channel < 0 ? false : channel > PCA9955B_OUTPUTS ? false
                                                            : true;
};
int PCA9955::GetLedChannelNum() {
    return NUM_CHANNEL_FROM_PCA9955B;
};
int PCA9955::GetIREF0Reg() {
    return PCA9955B_IREF0_ADDR;
};
int PCA9955::GetPWM0Reg() {
    return PCA9955B_PWM0_ADDR;
};