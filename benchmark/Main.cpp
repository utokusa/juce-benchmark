#include <JuceHeader.h>
#include <benchmark/benchmark.h>
#include <cmath>
#include "../src/FancyFx.h"

//==============================================================================
// Constants

constexpr double SAMPLE_RATE = 44100.0;
constexpr double MAX_TIME_SEC = 2.0;
constexpr double PI = 3.14159265359;
constexpr double FREQ_A = 440.0;
constexpr int NUM_SAMPLE = static_cast<int> (SAMPLE_RATE) * static_cast<int> (MAX_TIME_SEC);
constexpr int NUM_CHANNEL = 2;

//==============================================================================

class FancyFxFixture : public benchmark::Fixture
{
public:
    FancyFxFixture() : buffer(NUM_CHANNEL, NUM_SAMPLE), fancy_fx() {}
    void SetUp (::benchmark::State& state) override
    {
        // Setup if input audio buffer
        for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
        {
            auto* channelData = buffer.getWritePointer (channel);
            for (int i = 0; i < buffer.getNumSamples(); i++)
            {
                // 440 Hz sin wave
                channelData[i] = channelData[i] * std::sin(2.0 * PI * FREQ_A * i / SAMPLE_RATE);
            }
        }
    }

    void TearDown (::benchmark::State& state) override
    {
        // TearDown if necessary
    }

    void render()
    {
        fancy_fx.render (buffer);
    }

    //==============================================================================
private:
    juce::AudioBuffer<float> buffer;
    FancyFx fancy_fx;
    
};

BENCHMARK_F (FancyFxFixture, render)
(benchmark::State& state)
{
    for (auto _ : state)
    {
        render();
    }
}

BENCHMARK_MAIN();
