/*
  ==============================================================================

    MixerPlugin PluginProcessor.cpp
    © Rob Salino 2020

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MixerPluginSalinoAudioProcessor::MixerPluginSalinoAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    
    dBGain = -10;
    panL = 0;
    panR = 0;
    muteL = false;
    muteR = false;
}

MixerPluginSalinoAudioProcessor::~MixerPluginSalinoAudioProcessor()
{
}

//==============================================================================
const String MixerPluginSalinoAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MixerPluginSalinoAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MixerPluginSalinoAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MixerPluginSalinoAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MixerPluginSalinoAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MixerPluginSalinoAudioProcessor::getNumPrograms()
{
    return 1;
}

int MixerPluginSalinoAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MixerPluginSalinoAudioProcessor::setCurrentProgram (int index)
{
}

const String MixerPluginSalinoAudioProcessor::getProgramName (int index)
{
    return {};
}

void MixerPluginSalinoAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MixerPluginSalinoAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
}

void MixerPluginSalinoAudioProcessor::releaseResources()
{
    
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MixerPluginSalinoAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void MixerPluginSalinoAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
    }
}

//==============================================================================
bool MixerPluginSalinoAudioProcessor::hasEditor() const
{
    return true;
}

AudioProcessorEditor* MixerPluginSalinoAudioProcessor::createEditor()
{
    return new MixerPluginSalinoAudioProcessorEditor (*this);
}

//==============================================================================
void MixerPluginSalinoAudioProcessor::getStateInformation (MemoryBlock& destData)
{

}

void MixerPluginSalinoAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{

}

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MixerPluginSalinoAudioProcessor();
}
