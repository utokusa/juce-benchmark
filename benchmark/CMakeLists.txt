juce_add_console_app(JuceBenchmark_Benchmark)

# Add Google Benchmark
target_link_libraries(JuceBenchmark_Benchmark PUBLIC
     benchmark)

target_compile_definitions(JuceBenchmark_Benchmark
    PUBLIC
    # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
    JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
    JUCE_USE_CURL=0)    # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call

target_sources(JuceBenchmark_Benchmark PRIVATE
        Main.cpp) # If your target code includes .cpp files, add them here

target_link_libraries(JuceBenchmark_Benchmark PUBLIC
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_plugin_client
        juce::juce_audio_processors
        juce::juce_audio_utils
        juce::juce_core
        juce::juce_data_structures
        juce::juce_dsp
        juce::juce_events
        juce::juce_graphics
        juce::juce_gui_basics
        juce::juce_gui_extra
        )

juce_generate_juce_header(JuceBenchmark_Benchmark)

