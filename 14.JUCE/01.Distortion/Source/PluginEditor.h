/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MyAwesomeVSTPluginAudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Slider::Listener
{
public:
    MyAwesomeVSTPluginAudioProcessorEditor (MyAwesomeVSTPluginAudioProcessor&);
    ~MyAwesomeVSTPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //The slider listener callback function
    void sliderValueChanged (juce::Slider* slider) override;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MyAwesomeVSTPluginAudioProcessor& audioProcessor;
    juce::Slider gain;
    juce::Slider level;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyAwesomeVSTPluginAudioProcessorEditor)
};
