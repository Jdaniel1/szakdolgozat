#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/


class OtherLookAndFeel : public juce::LookAndFeel_V4
{
public:
    void drawRotarySlider(juce::Graphics &g, int x, int y, int width, int height, float sliderPos,
        float rotaryStartAngle, float rotaryEndAngle, juce::Slider &slider) override
    {
		float diameter = juce::jmin(width, (height - 20));
		float radius = diameter / 2;
		float centreX = x + width / 2;
		float centreY = y + height / 2;
		float rx = centreX - radius;
		float ry = centreY - radius;
		float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

		std::cout << rotaryStartAngle << " " << rotaryEndAngle << std::endl;

		juce::Rectangle<float> r(rx, ry, diameter, diameter);

		g.setColour(juce::Colours::silver);
		g.fillEllipse(r);

		g.setColour(juce::Colours::darkgrey);
		for (int i = 0; i < radius; i += 2)
		{
			g.drawEllipse(rx + i, ry + i, diameter - (2 * i), diameter - (2 * i), 1.0f);
		}

		g.setColour(juce::Colours::white);
		g.drawEllipse(rx, ry, diameter, diameter, 2.5f);

		g.setColour(juce::Colours::black);
        juce::Path dialTick;
		dialTick.addRectangle(0, -radius, 10.0f, radius * 0.4);

        g.fillPath(dialTick, juce::AffineTransform::rotation(angle). translated(centreX, centreY));
    }
};

class FontLookAndFeel : public juce::LookAndFeel_V4 {
public:
	void drawButtonText(juce::Graphics& g, juce::TextButton& button,
		bool /*shouldDrawButtonAsHighlighted*/, bool /*shouldDrawButtonAsDown*/)
	{
		juce::Font font(button.getHeight() * 0.6f);
		g.setFont(font);
		g.setColour(button.findColour(button.getToggleState() ?
			juce::TextButton::textColourOnId : juce::TextButton::textColourOffId)
			.withMultipliedAlpha(button.isEnabled() ? 1.0f : 0.5f));

		const int yIndent = button.proportionOfHeight(0.1f);
		const int cornerSize = juce::jmin(button.getHeight(), button.getWidth()) / 2;

		const int leftIndent = cornerSize / (button.isConnectedOnLeft() ?
			yIndent * 2 : yIndent);
		const int rightIndent = cornerSize / (button.isConnectedOnRight() ?
			yIndent * 2 : yIndent);
		const int textWidth = button.getWidth() - leftIndent - rightIndent;

		if (textWidth > 0)
			g.drawFittedText(button.getButtonText(),
				leftIndent, yIndent, textWidth, button.getHeight() - yIndent * 2,
				juce::Justification::centred, 2, 0.5f);
	}
};


class MainComponent  : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...

   void clearButtonClicked();
   void allButtonClicked();

   void clearButton1Clicked();
   void clearButton2Clicked();
   void clearButton3Clicked();

   void playButton1Clicked();
   void playButton2Clicked();
   void playButton3Clicked();
   void stopButton1Clicked();
   void stopButton2Clicked();
   void stopButton3Clicked();



   juce::Slider dialVol;

   juce::TextButton clearButton;
   juce::TextButton allButton;

   juce::TextButton playButton1;
   juce::TextButton playButton2;
   juce::TextButton playButton3;

   juce::TextButton stopButton1;
   juce::TextButton stopButton2;
   juce::TextButton stopButton3;

   juce::TextButton clearButton1;
   juce::TextButton clearButton2;
   juce::TextButton clearButton3;

   juce::AudioFormatManager formatManager;  // formátumkezelõ
   std::unique_ptr<juce::AudioFormatReaderSource> playSource; // audio source
   juce::AudioTransportSource transport1, transport2, transport3;

   juce::Label slotLabel1, slotLabel2, slotLabel3, volumeLabel, allLabel, clearLabel, lsLabel, nameLabel;

   bool empty1 = true, empty2 = true, empty3 = true;
   bool recording1 = false, recording2 = false, recording3 = false;
   bool playing1 = false, playing2 = false, playing3 = false;

   OtherLookAndFeel otherLookAndFeel;
   FontLookAndFeel fontLookAndFeel;

   juce::AudioSampleBuffer channelBuffers[3], existingBuffers[3];
   int writePositions[3] = { 0, 0, 0 };
   int readPositions[3] = { 0, 0, 0 };
   bool hasData[3] = { false, false, false };
   int maxBufferSize = 44100 * 60; // max 60 sec mono buffer per channel
   double currentSampleRate = 44100.0;

   bool loopLengthLocked = false;
   int loopLengthInSamples = 0;
   int globalSamplePosition = 0;

   const int latencyOffset = 512;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};