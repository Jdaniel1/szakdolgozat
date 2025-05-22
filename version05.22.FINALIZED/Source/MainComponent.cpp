#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : clearButton(juce::CharPointer_UTF8 ("\xf0\x9f\x9e\xab")),
                                allButton(juce::CharPointer_UTF8("\xe2\x96\xb6/\xe2\x96\xa0")),
								playButton1(juce::CharPointer_UTF8("\xe2\x96\xb6")),
                                playButton2(juce::CharPointer_UTF8 ("\xe2\x96\xb6")),
                                playButton3(juce::CharPointer_UTF8 ("\xe2\x96\xb6")),
                                stopButton1(juce::CharPointer_UTF8 ("\xe2\x96\xa0")),
                                stopButton2(juce::CharPointer_UTF8("\xe2\x96\xa0")),
                                stopButton3(juce::CharPointer_UTF8("\xe2\x96\xa0")),
								clearButton1(juce::CharPointer_UTF8("1\xf0\x9f\x9e\xab")),
								clearButton2(juce::CharPointer_UTF8("2\xf0\x9f\x9e\xab")),
								clearButton3(juce::CharPointer_UTF8("3\xf0\x9f\x9e\xab"))
{

	// hangerõszabályzó
	dialVol.setColour(juce::Slider::textBoxOutlineColourId, juce::Colour(48, 48, 48));
	dialVol.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	dialVol.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
	dialVol.setRange(-48.0f, 15.0f, 0.1f);
    addAndMakeVisible(dialVol);
	dialVol.setLookAndFeel (&otherLookAndFeel);
	dialVol.setValue(7.5f); // alapértelmezett hangerõszint

	// clear gomb
	clearButton.setLookAndFeel(&fontLookAndFeel);
	clearButton.onClick = [this] { clearButtonClicked(); };
	clearButton.setEnabled(false);
    clearButton.setColour(juce::TextButton::buttonColourId, juce::Colour(251, 255, 117));
	clearButton.setColour(juce::TextButton::textColourOffId, juce::Colour(115, 109, 0));
	addAndMakeVisible(&clearButton);

	// dedikált clear gombok
	clearButton1.setLookAndFeel(&fontLookAndFeel);
	clearButton1.onClick = [this] { clearButton1Clicked(); };
	clearButton1.setEnabled(false);
	clearButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(251, 255, 117));
	clearButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(115, 109, 0));
	addAndMakeVisible(&clearButton1);
	clearButton2.setLookAndFeel(&fontLookAndFeel);
	clearButton2.onClick = [this] { clearButton2Clicked(); };
	clearButton2.setEnabled(false);
	clearButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(251, 255, 117));
	clearButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(115, 109, 0));
	addAndMakeVisible(&clearButton2);
	clearButton3.setLookAndFeel(&fontLookAndFeel);
	clearButton3.onClick = [this] { clearButton3Clicked(); };
	clearButton3.setEnabled(false);
	clearButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(251, 255, 117));
	clearButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(115, 109, 0));
	addAndMakeVisible(&clearButton3);

	// all start/stop gomb
	allButton.setLookAndFeel(&fontLookAndFeel);
	allButton.onClick = [this] { allButtonClicked(); };
	allButton.setEnabled(false);
	allButton.setColour(juce::TextButton::buttonColourId, juce::Colour(153, 240, 255));
	allButton.setColour(juce::TextButton::textColourOffId, juce::Colour(63, 72, 204));
	allButton.setColour(juce::TextButton::textColourOnId, juce::Colour(63, 72, 204));
	addAndMakeVisible(&allButton);

	// play gombok
	playButton1.setLookAndFeel(&fontLookAndFeel);
	playButton1.onClick = [this] { playButton1Clicked(); };
	playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));  //button
	playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43)); //ikon
	addAndMakeVisible(&playButton1);
	playButton2.setLookAndFeel(&fontLookAndFeel);
	playButton2.onClick = [this] { playButton2Clicked(); };
	playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));
	playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43));
	addAndMakeVisible(&playButton2);
	playButton3.setLookAndFeel(&fontLookAndFeel);
	playButton3.onClick = [this] { playButton3Clicked(); };
	playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));
	playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43));
	addAndMakeVisible(&playButton3);

	// stop gombok
	stopButton1.setLookAndFeel(&fontLookAndFeel);
	stopButton1.onClick = [this] { stopButton1Clicked(); };
	stopButton1.setEnabled(false);
	stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
	stopButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(237, 28, 36));
	stopButton1.setColour(juce::TextButton::textColourOnId, juce::Colour(237, 28, 36));
	addAndMakeVisible(&stopButton1);
	stopButton2.setLookAndFeel(&fontLookAndFeel);
	stopButton2.onClick = [this] { stopButton2Clicked(); };
	stopButton2.setEnabled(false);
	stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
	stopButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(237, 28, 36));
	stopButton2.setColour(juce::TextButton::textColourOnId, juce::Colour(237, 28, 36));
	addAndMakeVisible(&stopButton2);
	stopButton3.setLookAndFeel(&fontLookAndFeel);
	stopButton3.onClick = [this] { stopButton3Clicked(); };
	stopButton3.setEnabled(false);
	stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
	stopButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(237, 28, 36));
	stopButton3.setColour(juce::TextButton::textColourOnId, juce::Colour(237, 28, 36));
	addAndMakeVisible(&stopButton3);

	// feliratok
	addAndMakeVisible(&slotLabel1);
	addAndMakeVisible(&slotLabel2);
	addAndMakeVisible(&slotLabel3);
	addAndMakeVisible(&volumeLabel);
	addAndMakeVisible(&allLabel);
	addAndMakeVisible(&clearLabel);
	addAndMakeVisible(&lsLabel);
	addAndMakeVisible(&nameLabel);
	slotLabel1.setText("Channel 1", juce::dontSendNotification);
	slotLabel2.setText("Channel 2", juce::dontSendNotification);
	slotLabel3.setText("Channel 3", juce::dontSendNotification);
	volumeLabel.setText("Volume", juce::dontSendNotification);
	allLabel.setText("All start/stop", juce::dontSendNotification);
	clearLabel.setText("Clear all", juce::dontSendNotification);
	lsLabel.setText("LoopStation", juce::dontSendNotification);
	nameLabel.setText(juce::CharPointer_UTF8("Jobb\xc3\xa1gy D\xc3\xa1niel"), juce::dontSendNotification);
	slotLabel1.setFont(juce::Font(20.0f, juce::Font::bold));
	slotLabel2.setFont(juce::Font(20.0f, juce::Font::bold));
	slotLabel3.setFont(juce::Font(20.0f, juce::Font::bold));
	volumeLabel.setFont(juce::Font(20.0f, juce::Font::bold));
	allLabel.setFont(juce::Font(20.0f, juce::Font::bold));
	clearLabel.setFont(juce::Font(20.0f, juce::Font::bold));
	lsLabel.setFont(juce::Font(40.0f, juce::Font::bold));
	nameLabel.setFont(juce::Font(20.0f, juce::Font::italic));


	formatManager.registerBasicFormats();  // formátumok regisztrálása

	
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        setAudioChannels (2, 2);
    }
}

MainComponent::~MainComponent()
{
	dialVol.setLookAndFeel(nullptr);
	clearButton.setLookAndFeel(nullptr);
	allButton.setLookAndFeel(nullptr);
	clearButton1.setLookAndFeel(nullptr);
	clearButton2.setLookAndFeel(nullptr);
	clearButton3.setLookAndFeel(nullptr);
	playButton1.setLookAndFeel(nullptr);
	playButton2.setLookAndFeel(nullptr);
	playButton3.setLookAndFeel(nullptr);
	stopButton1.setLookAndFeel(nullptr);
	stopButton2.setLookAndFeel(nullptr);
	stopButton3.setLookAndFeel(nullptr);
    shutdownAudio();
}

void MainComponent::clearButtonClicked()
{
	DBG("Clear button clicked");

	empty1 = true;
	empty2 = true;
	empty3 = true;

	recording1 = false;
	recording2 = false;
	recording3 = false;

	playing1 = false;
	playing2 = false;
	playing3 = false;

	allButton.setEnabled(false);
	clearButton.setEnabled(false);
	clearButton1.setEnabled(false);
	clearButton2.setEnabled(false);
	clearButton3.setEnabled(false);

	playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));
	playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43)); //ikon színe
	stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
	stopButton1.setEnabled(false);

	playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));
	playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43)); //ikon színe
	stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
	stopButton2.setEnabled(false);

	playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));
	playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43)); //ikon színe
	stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
	stopButton3.setEnabled(false);

	for (int i = 0; i < 3; ++i)
	{
		channelBuffers[i].clear();
		writePositions[i] = 0;
		readPositions[i] = 0;
		hasData[i] = false;
	}

	loopLengthLocked = false;
	loopLengthInSamples = 0;
	globalSamplePosition = 0;
	maxBufferSize = 44100 * 60; // max 60mp buffer méret


}

void MainComponent::clearButton1Clicked()
{
	DBG("Clear button 1 clicked");

	if (empty2 && empty3)
		clearButtonClicked();
	else
	{
		empty1 = true;
		recording1 = false;
		playing1 = false;
		clearButton1.setEnabled(false);
		playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));
		playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43)); //ikon színe
		stopButton1.setEnabled(false);

		channelBuffers[0].clear();
		writePositions[0] = 0;
		readPositions[0] = 0;
		hasData[0] = false;
	}
}

void MainComponent::clearButton2Clicked()
{
	DBG("Clear button 2 clicked");

	if (empty1 && empty3)
		clearButtonClicked();
	else
	{
		empty2 = true;
		recording2 = false;
		playing2 = false;
		clearButton2.setEnabled(false);
		playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));
		playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43)); //ikon színe
		stopButton2.setEnabled(false);

		channelBuffers[1].clear();
		writePositions[1] = 0;
		readPositions[1] = 0;
		hasData[1] = false;
	}
}

void MainComponent::clearButton3Clicked()
{
	DBG("Clear button 3 clicked");

	if (empty1 && empty2)
		clearButtonClicked();
	else
	{
		empty3 = true;
		recording3 = false;
		playing3 = false;
		clearButton3.setEnabled(false);
		playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));
		playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43)); //ikon színe
		stopButton3.setEnabled(false);

		channelBuffers[2].clear();
		writePositions[2] = 0;
		readPositions[2] = 0;
		hasData[2] = false;
	}
}


void MainComponent::allButtonClicked()
{
	DBG("All button clicked");
	globalSamplePosition = 0;

	if ((playing1 == true || playing2 == true || playing3 == true ) || (recording1 == true || recording2 == true || recording3 == true))
	{
		if (playing1 == true || recording1 == true)
		{
			stopButton1Clicked();
		}
		if (playing2 == true || recording2 == true)
		{
			stopButton2Clicked();
		}
		if (playing3 == true || recording3 == true)
		{
			stopButton3Clicked();
		}
	}
	else if (playing1 == false || playing2 == false || playing3 == false)
	{
		if (empty1 == false)
		{
			playButton1Clicked();
		}
		if (empty2 == false)
		{
			playButton2Clicked();
		}
		if (empty3 == false)
		{
			playButton3Clicked();
		}
	}
}

void MainComponent::playButton1Clicked()
{
	DBG("Play button 1 clicked");

	if (empty1 == true && recording1 == false && playing1 == false)  // felvétel
	{
		if (recording2 == true)
		{
			playing2 = true;
			playButton2Clicked();
		}
		if (recording3 == true)
		{
			playing3 = true;
			playButton3Clicked();
		}
		if (empty2 && empty3)
		{
			globalSamplePosition = 0;
			readPositions[0] = 0;
		}

		stopButton1.setEnabled(true);
		allButton.setEnabled(true);
		clearButton.setEnabled(true);
		clearButton1.setEnabled(true);

		playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(255, 127, 39));  //gomb - narancs citrom
		playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty1 = false;
		recording1 = true;
		playing1 = false;

		DBG("1felvetel");

	}
	else if (empty1 == false && recording1 == true && playing1 == false && empty2 && empty3)  // köztes szakasz
	{
		playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty1 = false;
		recording1 = true;
		playing1 = true;
		maxBufferSize = writePositions[0];
		DBG("1köztes");
		if (!loopLengthLocked && writePositions[0] > 0)
		{
			loopLengthInSamples = writePositions[0];
			loopLengthLocked = true;
		}
		writePositions[0] = 0;

	}
	else if (empty1 == false && recording1 == true && playing1 == true)	 // köztesből lejátszás
	{
		playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty1 = false;
		recording1 = false;
		playing1 = true;
		DBG("1koztesbol lejatszas");
	}
	else if (empty1 == false && recording1 == true && playing1 == false)	 // felvételből lejátszás
	{
		playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty1 = false;
		recording1 = false;
		playing1 = true;
		DBG("1lejatszas");
	}
	else if (empty1 == false && recording1 == false && playing1 == false)  // elindítás
	{
		if (playing1 == false && playing2 == false && playing3 == false)
		{
			globalSamplePosition = 0;
			readPositions[0] = 0;
		}

		playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty1 = false;
		recording1 = false;
		playing1 = true;
		DBG("1elinditas");
	}
	else if (empty1 == false && recording1 == false && playing1 == true)  // rávétel
	{
		if (recording2 == true)
		{
			playing2 = true;
			playButton2Clicked();
		}
		if (recording3 == true)
		{
			playing3 = true;
			playButton3Clicked();
		}

		writePositions[0] = 0;
		playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty1 = false;
		recording1 = true;
		playing1 = true;
		DBG("1ravetel");
	}
}

void MainComponent::playButton2Clicked()
{
	DBG("Play button 2 clicked");

	if (empty2 == true && recording2 == false && playing2 == false)  // felvétel
	{
		if (recording1 == true)
		{
			playing1 = true;
			playButton1Clicked();
		}
		if (recording3 == true)
		{
			playing3 = true;
			playButton3Clicked();
		}
		if (empty1 && empty3)
		{
			globalSamplePosition = 0;
			readPositions[1] = 0;
		}

		stopButton2.setEnabled(true);
		allButton.setEnabled(true);
		clearButton.setEnabled(true);
		clearButton2.setEnabled(true);

		playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(255, 127, 39));  //gomb - narancs citrom
		playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty2 = false;
		recording2 = true;
		playing2 = false;

		DBG("2felvetel");
	}
	else if (empty2 == false && recording2 == true && playing2 == false && empty1 && empty3)  // köztes szakasz
	{
		playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty2 = false;
		recording2 = true;
		playing2 = true;
		DBG("2köztes");
		maxBufferSize = writePositions[1];
		if (!loopLengthLocked && writePositions[1] > 0)
		{
			loopLengthInSamples = writePositions[1];
			loopLengthLocked = true;
		}
		writePositions[1] = 0; // Reset write position

	}
	else if (empty2 == false && recording2 == true && playing2 == true)	 // köztesből lejátszás
	{
		playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty2 = false;
		recording2 = false;
		playing2 = true;
		DBG("2koztesbol lejatszas");
	}
	else if (empty2 == false && recording2 == true && playing2 == false)	 // lejátszás
	{
		playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty2 = false;
		recording2 = false;
		playing2 = true;
		DBG("2lejatszas");
	}
	else if (empty2 == false && recording2 == false && playing2 == false)  // elindítás
	{
		if (playing1 == false && playing2 == false && playing3 == false)
		{
			globalSamplePosition = 0;
			readPositions[0] = 0;
		}

		playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty2 = false;
		recording2 = false;
		playing2 = true;
		DBG("2elinditas");
	}
	else if (empty2 == false && recording2 == false && playing2 == true)  // rávétel
	{
		if (recording1 == true)
		{
			playing1 = true;
			playButton1Clicked();
		}
		if (recording3 == true)
		{
			playing3 = true;
			playButton3Clicked();
		}


		writePositions[1] = 0;
		playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty2 = false;
		recording2 = true;
		playing2 = true;
		DBG("2ravetel");
	}
}

void MainComponent::playButton3Clicked()
{
	DBG("Play button 3 clicked");

	if (empty3 == true && recording3 == false && playing3 == false)  // felvétel
	{
		if (recording1 == true)
		{
			playing1 = true;
			playButton1Clicked();
		}
		if (recording2 == true)
		{
			playing2 = true;
			playButton2Clicked();
		}
		if (empty1 && empty2)
		{
			globalSamplePosition = 0;
			readPositions[2] = 0;
		}

		stopButton3.setEnabled(true);
		allButton.setEnabled(true);
		clearButton.setEnabled(true);
		clearButton3.setEnabled(true);

		playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(255, 127, 39));  //gomb - narancs citrom
		playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty3 = false;
		recording3 = true;
		playing3 = false;

		DBG("3felvetel");
	}
	else if (empty3 == false && recording3 == true && playing3 == false && empty1 && empty2)  // köztes szakasz
	{
		playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty3 = false;
		recording3 = true;
		playing3 = true;
		DBG("3köztes");
		maxBufferSize = writePositions[2];
		if (!loopLengthLocked && writePositions[2] > 0)
		{
			loopLengthInSamples = writePositions[2];
			loopLengthLocked = true;
		}
		writePositions[2] = 0;

	}
	else if (empty3 == false && recording3 == true && playing3 == true)	 // köztesből lejátszás
	{
		playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty3 = false;
		recording3 = false;
		playing3 = true;
		DBG("3koztesbol lejatszas");
	}
	else if (empty3 == false && recording3 == true && playing3 == false)	 // lejátszás
	{
		playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty3 = false;
		recording3 = false;
		playing3 = true;
		DBG("3lejatszas");
	}
	else if (empty3 == false && recording3 == false && playing3 == false)  // elindítás
	{
		if (playing1 == false && playing2 == false && playing3 == false)
		{
			globalSamplePosition = 0;
			readPositions[0] = 0;
		}

		playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty3 = false;
		recording3 = false;
		playing3 = true;
		DBG("3elinditas");
	}
	else if (empty3 == false && recording3 == false && playing3 == true)  // rávétel
	{
		if (recording1 == true)
		{
			playing1 = true;
			playButton1Clicked();
		}
		if (recording2 == true)
		{
			playing2 = true;
			playButton2Clicked();
		}


		writePositions[2] = 0;
		playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty3 = false;
		recording3 = true;
		playing3 = true;
		DBG("3ravetel");
	}
}

void MainComponent::stopButton1Clicked()
{
	DBG("Stop button 1 clicked");

	if (empty1 == false)
	{
		playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(37, 66, 35));
		playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
		empty1 = false;
		recording1 = false;
		playing1 = false;
		maxBufferSize = writePositions[0];
		if (!loopLengthLocked && writePositions[0] > 0)
		{
			loopLengthInSamples = writePositions[0];
			loopLengthLocked = true;
		}
		writePositions[0] = 0;
	}
}

void MainComponent::stopButton2Clicked()
{
	DBG("Stop button 2 clicked");

	if (empty2 == false)
	{
		playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(37, 66, 35));
		playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
		empty2 = false;
		recording2 = false;
		playing2 = false;
		maxBufferSize = writePositions[1];
		if (!loopLengthLocked && writePositions[1] > 0)
		{
			loopLengthInSamples = writePositions[1];
			loopLengthLocked = true;
		}
		writePositions[1] = 0;
	}
}

void MainComponent::stopButton3Clicked()
{
	DBG("Stop button 3 clicked");

	if (empty3 == false)
	{
		playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(37, 66, 35));
		playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
		empty3 = false;
		recording3 = false;
		playing3 = false;
		maxBufferSize = writePositions[2];
		if (!loopLengthLocked && writePositions[2] > 0)
		{
			loopLengthInSamples = writePositions[2];
			loopLengthLocked = true;
		}
		writePositions[2] = 0;
	}
}

//==============================================================================
void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
	currentSampleRate = sampleRate;
	for (int i = 0; i < 3; ++i)
	{
		channelBuffers[i].setSize(1, maxBufferSize); // mono jel
		channelBuffers[i].clear();
		writePositions[i] = 0;
		readPositions[i] = 0;
		hasData[i] = false;
	}
}

//==============================================================================

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
	auto* input = bufferToFill.buffer->getReadPointer(0);
	auto* left = bufferToFill.buffer->getWritePointer(0);
	auto* right = bufferToFill.buffer->getWritePointer(1);


	for (int sample = 0; sample < bufferToFill.numSamples; ++sample)
	{
		float mixedSample = 0.0f;

		for (int ch = 0; ch < 3; ++ch)
		{
			bool isRec = (ch == 0 && recording1) || (ch == 1 && recording2) || (ch == 2 && recording3);
			bool isPlay = (ch == 0 && playing1) || (ch == 1 && playing2) || (ch == 2 && playing3);

			// felvétel
			if (isRec && writePositions[ch] < maxBufferSize)
			{
				int writePos = 0;
				if (loopLengthLocked)
				{
					// overdub
					writePos = (globalSamplePosition - (latencyOffset) + loopLengthInSamples) % loopLengthInSamples;

					float existing = channelBuffers[ch].getSample(0, writePos);
					float combined = existing + input[sample];
					combined = juce::jlimit(-1.0f, 1.0f, combined);
					channelBuffers[ch].setSample(0, writePos, combined);
				}
				else
				{
					writePos = writePositions[ch];
					channelBuffers[ch].setSample(0, writePos, input[sample]);
					writePositions[ch]++;
				}

				hasData[ch] = true;
			}

			// lejátszás
			if (isPlay && hasData[ch] && loopLengthInSamples > 0)
			{
				int pos = (globalSamplePosition + (latencyOffset*20) + loopLengthInSamples) % loopLengthInSamples;
				mixedSample += channelBuffers[ch].getSample(0, pos);
			}
		}

		// decibel képlete
		mixedSample *= pow (10, dialVol.getValue() / 10.0f);

		left[sample] = mixedSample;
		right[sample] = mixedSample;

		globalSamplePosition++;
		
		if (globalSamplePosition >= loopLengthInSamples)
		{
			globalSamplePosition = 0;
		}
	}

}

void MainComponent::releaseResources()
{

}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
	// háttér
    g.fillAll (juce::Colour(48, 48, 48));

	// elkülönítő vonalak
	g.setColour(juce::Colours::darkgrey);
	juce::Rectangle<float> line1(495, 360, 10, 260);
	juce::Rectangle<float> line2(995, 360, 10, 260);
	juce::Rectangle<float> line3(400, 350, 200, 10);
	juce::Rectangle<float> line4(900, 350, 200, 10);
	juce::Rectangle<float> line5(0, 350, 100, 10);
	juce::Rectangle<float> line6(1400, 350, 100, 10);
	juce::Rectangle<float> line7(0, 350, 5, 260);
	juce::Rectangle<float> line8(1495, 350, 5, 260);
	g.drawRect(line1);
	g.drawRect(line2);
	g.drawRect(line3);
	g.drawRect(line4);
	g.drawRect(line5);
	g.drawRect(line6);
	g.drawRect(line7);
	g.drawRect(line8);
	g.fillRect(line1);
	g.fillRect(line2);
	g.fillRect(line3);
	g.fillRect(line4);
	g.fillRect(line5);
	g.fillRect(line6);
	g.fillRect(line7);
	g.fillRect(line8);

}

void MainComponent::resized()
{
	// elrendezések
    juce::Rectangle<int> area = getLocalBounds();
	juce::Rectangle<int> bottom = area.removeFromBottom(area.getHeight() / 2);
    juce::Rectangle<int> botLeft = bottom.removeFromLeft(bottom.getWidth() / 3);
	juce::Rectangle<int> botRight = bottom.removeFromRight(bottom.getWidth() / 2);

	juce::Rectangle<int> dialVolArea = area.removeFromLeft(area.getWidth() / 4);
	juce::Rectangle<int> allStartArea = area.removeFromRight(area.getWidth() / 3);
	juce::Rectangle<int> clearArea = area.removeFromRight(area.getWidth() / 2);
	juce::Rectangle<int> upperArea = area.removeFromTop(area.getHeight() / 2);
	juce::Rectangle<int> bottArea = area.removeFromBottom(area.getHeight() / 2);
	juce::Rectangle<int> bottAreaLeft = bottArea.removeFromLeft(bottArea.getWidth() / 3);
	juce::Rectangle<int> bottAreaRight = bottArea.removeFromRight(bottArea.getWidth() / 2);

	slotLabel1.setBounds(botLeft.getX(), botLeft.getY() - 5, botLeft.getWidth(), 20);
	slotLabel2.setBounds(bottom.getX(), bottom.getY() - 5, bottom.getWidth(), 20);
	slotLabel3.setBounds(botRight.getX(), botRight.getY() - 5, botRight.getWidth(), 20);

	slotLabel1.setJustificationType(juce::Justification::centredBottom);
	slotLabel2.setJustificationType(juce::Justification::centredBottom);
	slotLabel3.setJustificationType(juce::Justification::centredBottom);

	juce::Rectangle<int> play1 = botLeft.removeFromLeft(botLeft.getWidth() / 2);
	juce::Rectangle<int> play2 = bottom.removeFromLeft(bottom.getWidth() / 2);
	juce::Rectangle<int> play3 = botRight.removeFromLeft(botRight.getWidth() / 2);

	dialVol.setBounds(dialVolArea.reduced(20));
	playButton1.setBounds(play1.reduced(20));
	playButton2.setBounds(play2.reduced(20));
	playButton3.setBounds(play3.reduced(20));
	clearButton.setBounds(clearArea.reduced(80));
	clearButton1.setBounds(bottAreaLeft.reduced(20));
	clearButton2.setBounds(bottArea.reduced(20));
	clearButton3.setBounds(bottAreaRight.reduced(20));
	allButton.setBounds(allStartArea.reduced(80));
	stopButton1.setBounds(botLeft.reduced(20));
	stopButton2.setBounds(bottom.reduced(20));
	stopButton3.setBounds(botRight.reduced(20));
	lsLabel.setBounds(upperArea);
	nameLabel.setBounds(area);

	volumeLabel.setBounds(dialVol.getX(), dialVol.getY() - 20, dialVol.getWidth(), 20);
	allLabel.setBounds(allButton.getX(), allButton.getY() - 20, allButton.getWidth(), 20);
	clearLabel.setBounds(clearButton.getX(), clearButton.getY() - 20, clearButton.getWidth(), 20);

	volumeLabel.setJustificationType(juce::Justification::centredBottom);
	allLabel.setJustificationType(juce::Justification::centredBottom);
	clearLabel.setJustificationType(juce::Justification::centredBottom);
	lsLabel.setJustificationType(juce::Justification::centredBottom);
	nameLabel.setJustificationType(juce::Justification::centredTop);
}