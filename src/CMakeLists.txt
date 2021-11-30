# Plugin formats
set(JUCE_FORMATS AU VST3 Standalone)

juce_add_plugin(JuceBenchmark
    COMPANY_NAME "Example Company Name"
    COPY_PLUGIN_AFTER_BUILD TRUE # Should the plugin be installed to a default location after building?
    PLUGIN_MANUFACTURER_CODE gMei # A four-character manufacturer id with at least one upper-case character
    PLUGIN_CODE exAs # A unique four-character plugin id with at least one upper-case character
    FORMATS ${JUCE_FORMATS}
    VST3_CATEGORIES "Fx"
    AU_MAIN_TYPE "kAudioUnitType_Effect"
    MICROPHONE_PERMISSION_ENABLED TRUE
    MICROPHONE_PERMISSION_TEXT "This application requires a permission to use an audio input device of your computer. By Default, Built-In microphone will be used."

    PRODUCT_NAME "JuceBenchmark") # The name of the final

target_compile_definitions(JuceBenchmark
    PUBLIC
    # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
    JUCE_WEB_BROWSER=0 # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
    JUCE_USE_CURL=0) # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call.0olp;m8uj/'4rcf5v}TV

target_sources(JuceBenchmark PRIVATE
    PluginProcessor.cpp
    PluginEditor.cpp)

target_link_libraries(JuceBenchmark PUBLIC
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
    juce::juce_gui_extra)

juce_generate_juce_header(JuceBenchmark)
