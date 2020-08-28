/*
  ==============================================================================

    MixerPlugin PluginEditor.cpp
    © Rob Salino 2020

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MixerPluginSalinoAudioProcessorEditor::MixerPluginSalinoAudioProcessorEditor (MixerPluginSalinoAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{

    setResizable(true, true); //make window resizable
    setResizeLimits(400, 300, 1200, 1500); //size limits
    getConstrainer()->setFixedAspectRatio(1.333333); //size ratio
    auto width = 400;
    auto height = 300;
    setSize(width, height); //default size
    otherLookAndFeel.setColour(Slider::thumbColourId, Colours::green);
    
    //gain slider settings:
    gainSlider.setLookAndFeel(&otherLookAndFeel);
    gainSlider.setSliderStyle(Slider::LinearHorizontal);
    gainSlider.setTextBoxStyle (Slider::TextBoxRight, true, width * 0.2, height * 0.05);
    gainSlider.setTextBoxIsEditable(true);
    gainSlider.setTextValueSuffix(" dB");
    gainSlider.setRange(-70, 10, 1);
    gainSlider.setValue(processor.dBGain);
    addAndMakeVisible(gainSlider);
    
    //pan knob L settings:
    panKnobL.setSliderStyle (Slider::Rotary);
    panKnobL.setTextBoxStyle (Slider::TextBoxBelow, true, width * 0.2, height * 0.05);
    panKnobL.setTextBoxIsEditable(true);
    panKnobL.setRange(-1, 1, 0.01);
    panKnobL.setValue(processor.panL);
    addAndMakeVisible (panKnobL);
    // pan Label L
    panLabelL.setText("Pan", dontSendNotification);
    panLabelL.setJustificationType(Justification::horizontallyCentred);
    panLabelL.setFont(Font(24.0f, Font::bold));
    panLabelL.setColour(Label::backgroundColourId, Colours::green);
    panLabelL.setColour(Label::textColourId, Colours::tomato);
    addAndMakeVisible(panLabelL);
    
    //pan knob R settings:
    panKnobR.setSliderStyle (Slider::Rotary);
    panKnobR.setTextBoxStyle (Slider::TextBoxBelow, true, width * 0.2, height * 0.05);
    panKnobR.setTextBoxIsEditable(true);
    panKnobR.setRange(-1, 1, 0.01);
    panKnobR.setValue(processor.panR);
    addAndMakeVisible (panKnobL);
    // pan Label R
    panLabelR.setText("Pan", dontSendNotification);
    panLabelR.setJustificationType(Justification::horizontallyCentred);
    panLabelR.setFont(Font(24.0f, Font::bold));
    panLabelR.setColour(Label::backgroundColourId, Colours::green);
    panLabelR.setColour(Label::textColourId, Colours::tomato);
    addAndMakeVisible(panLabelR);
    
    //muteL:
    muteToggleL.setButtonText("Mute");  // text size cannot be changed?  Use a label instead
    muteToggleL.setToggleState(processor.muteL, NotificationType::dontSendNotification);
    muteToggleL.setColour(ToggleButton::textColourId , Colours::yellow);
    muteToggleL.setColour(ToggleButton::tickColourId, Colours::greenyellow);
    addAndMakeVisible(muteToggleL);
    
    //muteR:
    muteToggleR.setButtonText("Mute");  // text size cannot be changed?  Use a label instead
    muteToggleR.setToggleState(processor.muteR, NotificationType::dontSendNotification);
    muteToggleR.setColour(ToggleButton::textColourId , Colours::yellow);
    muteToggleR.setColour(ToggleButton::tickColourId, Colours::greenyellow);
    addAndMakeVisible(muteToggleR);
    
    gainSlider.addListener(this);
    panKnobL.addListener(this);
    panKnobR.addListener(this);
    muteToggleL.addListener(this);
    muteToggleR.addListener(this);
}

MixerPluginSalinoAudioProcessorEditor::~MixerPluginSalinoAudioProcessorEditor()
{
}

//==============================================================================
void MixerPluginSalinoAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.fillAll(Colours::turquoise);
    auto border = 1;
    auto area = getLocalBounds().reduced(border * 4);
    auto areaWidth = area.getWidth();
    auto areaHeight = area.getHeight();
    auto ratioW = 0.4;
    auto ratioH = 0.3;
    auto upperArea = area.removeFromTop(ratioH* areaHeight);

}

void MixerPluginSalinoAudioProcessorEditor::resized()
{

}

void MixerPluginSalinoAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    if(slider == &gainSlider)
    {
        processor.dBGain =gainSlider.getValue();
    }
    else if(slider == &panKnobL)
    {
        processor.panL = panKnobL.getValue();
    }
    else if(slider == &panKnobR)
    {
        processor.panR = panKnobR.getValue();
    }
}
void MixerPluginSalinoAudioProcessorEditor::buttonClicked(Button* button)
{
    if(button == &muteToggleL) // mute ToggleButton
    {
        if(muteToggleL.getToggleState() == true)
        {
            processor.muteL = true;
            DBG("mute");
        }
        else
            processor.muteL = false;
    }
    if(button == &muteToggleR) // mute ToggleButton
    {
        if(muteToggleR.getToggleState() == true){
            processor.muteR = true;
            DBG("mute");
        }
        else
            processor.muteR = false;
    }
}
