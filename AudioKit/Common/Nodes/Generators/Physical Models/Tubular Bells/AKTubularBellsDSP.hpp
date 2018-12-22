//
//  AKTubularBellsDSP.hpp
//  AudioKit For iOS
//
//  Created by Aurelius Prochazka on 12/22/18.
//  Copyright © 2018 AudioKit. All rights reserved.
//

#pragma once

#import <AVFoundation/AVFoundation.h>

typedef NS_ENUM(AUParameterAddress, AKTubularBellsParameter) {
    AKTubularBellsParameterFrequency,
    AKTubularBellsParameterAmplitude,
    AKTubularBellsParameterRampDuration
};

#import "AKLinearParameterRamp.hpp"  // have to put this here to get it included in umbrella header

#ifndef __cplusplus

AKDSPRef createTubularBellsDSP(int nChannels, double sampleRate);

#else

class AKTubularBellsDSP : public AKDSPBase {
private:
    struct _Internal;
    std::unique_ptr<_Internal> _private;

public:

    AKTubularBellsDSP();

    ~AKTubularBellsDSP();

    /** Uses the ParameterAddress as a key */
    void setParameter(AUParameterAddress address, float value, bool immediate) override;

    /** Uses the ParameterAddress as a key */
    float getParameter(AUParameterAddress address) override;

    void init(int _channels, double _sampleRate) override;

    void trigger() override;

    void triggerFrequencyAmplitude(AUValue freq, AUValue amp) override;

    void destroy();

    void process(AUAudioFrameCount frameCount, AUAudioFrameCount bufferOffset) override;
};

#endif


