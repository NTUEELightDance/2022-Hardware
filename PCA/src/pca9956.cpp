#include "../include/pca9956.h"


// Derived PCA9956
bool PCA9956::CheckChannelLegal(int channel) {
    return channel < 0 ? false : channel > PCA9956_OUTPUTS ? false
                                                            : true;
};
int PCA9956::GetLedChannelNum() {
    return NUM_CHANNEL_FROM_PCA9956;
};
