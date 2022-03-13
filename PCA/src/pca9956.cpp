#include "../include/pca9956.h"


// Derived PCA9956
bool PCA9956::CheckChannelLegal(int channel) {
    return channel < 0 ? false : channel > PCA9956_OUTPUTS ? false
                                                            : true;
};
int PCA9956::GetLedChannelNum() {
    return NUM_CHANNEL_FROM_PCA9956;
};
int PCA9956::GetIREF0Reg() {
    return PCA9956_IREF0_ADDR;
};
int PCA9956::GetPWM0Reg() {
    return PCA9956_PWM0_ADDR;
};