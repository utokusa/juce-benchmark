#pragma once

#include <JuceHeader.h>

class FancyFx
{
public:
    FancyFx() = default;
    void render (juce::AudioBuffer<float>& out_buffer)
    {
        
        for (int channel = 0; channel < out_buffer.getNumChannels(); ++channel)
        {
            auto* channelData = out_buffer.getWritePointer (channel);
            for (int i = 0; i < out_buffer.getNumSamples(); i++)
            {
                channelData[i] = channelData[i] * gain;
            }
        }
    }
private:
    const float gain = 0.3f;

};