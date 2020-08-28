/*
  ==============================================================================

    MixerPlugin PluginEditor.h
    © Rob Salino 2020

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MixerPluginSalinoAudioProcessorEditor  : public AudioProcessorEditor, private Slider::Listener, private Button::Listener
{
public:
    MixerPluginSalinoAudioProcessorEditor (MixerPluginSalinoAudioProcessor&);
    ~MixerPluginSalinoAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:

    LookAndFeel_V4 otherLookAndFeel;
    
    MixerPluginSalinoAudioProcessor& processor;
    Slider gainSlider;
    Slider panKnobL;
    Slider panKnobR;
    ToggleButton muteToggleL;
    ToggleButton muteToggleR;
    Label gainLabel;
    Label panLabelL;
    Label panLabelR;
    
    void sliderValueChanged (Slider* slider) override;
    void buttonClicked (Button*) override;
    void buttonStateChanged (Button *) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerPluginSalinoAudioProcessorEditor)
};
