/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyAwesomeVSTPluginAudioProcessorEditor::MyAwesomeVSTPluginAudioProcessorEditor (MyAwesomeVSTPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    //Set the parameters of the gain slider
    gain.setSliderStyle(juce::Slider::LinearVertical);
    gain.setRange(0.0, 1000.0, 1.0);
    gain.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    gain.setPopupDisplayEnabled(true, false, this);
    gain.setTextValueSuffix(" Gain");
    gain.setValue(100.0);
    
    //Add the listener to the slider
    gain.addListener(this);
    
    //Add the slider to the editor
    addAndMakeVisible(&gain);
    
    //Set the parameters of the volume slider
    level.setSliderStyle(juce::Slider::LinearVertical);
    level.setRange(0.0, 1.0, 0.01);
    level.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    level.setPopupDisplayEnabled(true, false, this);
    level.setTextValueSuffix(" Level");
    level.setValue(0.5);
    
    //Add the listener to the slider
    level.addListener(this);
    
    //Add the slider to the editor
    addAndMakeVisible(&level);
    
}

MyAwesomeVSTPluginAudioProcessorEditor::~MyAwesomeVSTPluginAudioProcessorEditor()
{
}

//==============================================================================
void MyAwesomeVSTPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void MyAwesomeVSTPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gain.setBounds(40, 30, 20, getHeight() - 60);
    level.setBounds(80, 30, 20, getHeight() - 60);
}

void MyAwesomeVSTPluginAudioProcessorEditor::sliderValueChanged(juce::Slider *slider){
        audioProcessor.gain = gain.getValue();
        audioProcessor.level = level.getValue();
}
