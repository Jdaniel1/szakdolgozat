#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : openButton("OPEN"),
                                clearButton(juce::CharPointer_UTF8 ("\xf0\x9f\x9e\xab")),
                                allButton(juce::CharPointer_UTF8("\xe2\x96\xb6/\xe2\x96\xa0")),
								playButton1(juce::CharPointer_UTF8("\xe2\x96\xb6")),
                                playButton2(juce::CharPointer_UTF8 ("\xe2\x96\xb6")),
                                playButton3(juce::CharPointer_UTF8 ("\xe2\x96\xb6")),
                                stopButton1(juce::CharPointer_UTF8 ("\xe2\x96\xa0")),
                                stopButton2(juce::CharPointer_UTF8("\xe2\x96\xa0")),
                                stopButton3(juce::CharPointer_UTF8("\xe2\x96\xa0"))
{
    // Make sure you set the size of the component after
    // you add any child components.
    //setSize (800, 600);


	// hangerõszabályzó
	dialVol.setColour(juce::Slider::textBoxOutlineColourId, juce::Colour(48, 48, 48));
	dialVol.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	dialVol.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
	dialVol.setRange(0.0f, 10.0f, 0.1f);
    addAndMakeVisible(dialVol);
	dialVol.setLookAndFeel (&otherLookAndFeel);

	// open gomb
	openButton.setLookAndFeel(&fontLookAndFeel);
    openButton.onClick = [this] { openButtonClicked(); };
	addAndMakeVisible(&openButton);

	//clear gomb
	clearButton.setLookAndFeel(&fontLookAndFeel);
	clearButton.onClick = [this] { clearButtonClicked(); };
	clearButton.setEnabled(false);  // alapértelmezett állapotban letiltva
    clearButton.setColour(juce::TextButton::buttonColourId, juce::Colour(251, 255, 117));
	clearButton.setColour(juce::TextButton::textColourOffId, juce::Colour(115, 109, 0));
	addAndMakeVisible(&clearButton);

	// all gomb
	allButton.setLookAndFeel(&fontLookAndFeel);
	allButton.onClick = [this] { allButtonClicked(); };
	allButton.setEnabled(false);  // alapértelmezett állapotban letiltva
	allButton.setColour(juce::TextButton::buttonColourId, juce::Colour(153, 240, 255));
	allButton.setColour(juce::TextButton::textColourOffId, juce::Colour(63, 72, 204));
	allButton.setColour(juce::TextButton::textColourOnId, juce::Colour(63, 72, 204));
	addAndMakeVisible(&allButton);

	// play gombok
	playButton1.setLookAndFeel(&fontLookAndFeel);
	playButton1.onClick = [this] { playButton1Clicked(); };
	playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));  //button
	playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43)); //ikon
	//playButton1.setColour(juce::TextButton::textColourOnId, juce::Colour(19, 99, 43));
	addAndMakeVisible(&playButton1);
	playButton2.setLookAndFeel(&fontLookAndFeel);
	playButton2.onClick = [this] { playButton2Clicked(); };
	playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));
	playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43));
	//playButton2.setColour(juce::TextButton::textColourOnId, juce::Colour(19, 99, 43));
	addAndMakeVisible(&playButton2);
	playButton3.setLookAndFeel(&fontLookAndFeel);
	playButton3.onClick = [this] { playButton3Clicked(); };
	playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));
	playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43));
	//playButton3.setColour(juce::TextButton::textColourOnId, juce::Colour(19, 99, 43));
	addAndMakeVisible(&playButton3);

	// stop gombok
	stopButton1.setLookAndFeel(&fontLookAndFeel);
	stopButton1.onClick = [this] { stopButton1Clicked(); };
	stopButton1.setEnabled(false);  // alapértelmezett állapotban letiltva
	stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
	stopButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(237, 28, 36));
	stopButton1.setColour(juce::TextButton::textColourOnId, juce::Colour(237, 28, 36));
	addAndMakeVisible(&stopButton1);
	stopButton2.setLookAndFeel(&fontLookAndFeel);
	stopButton2.onClick = [this] { stopButton2Clicked(); };
	stopButton2.setEnabled(false);  // alapértelmezett állapotban letiltva
	stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
	stopButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(237, 28, 36));
	stopButton2.setColour(juce::TextButton::textColourOnId, juce::Colour(237, 28, 36));
	addAndMakeVisible(&stopButton2);
	stopButton3.setLookAndFeel(&fontLookAndFeel);
	stopButton3.onClick = [this] { stopButton3Clicked(); };
	stopButton3.setEnabled(false);  // alapértelmezett állapotban letiltva
	stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
	stopButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(237, 28, 36));
	stopButton3.setColour(juce::TextButton::textColourOnId, juce::Colour(237, 28, 36));
	addAndMakeVisible(&stopButton3);


	addAndMakeVisible(&slotLabel1);
	addAndMakeVisible(&slotLabel2);
	addAndMakeVisible(&slotLabel3);
	addAndMakeVisible(&volumeLabel);
	addAndMakeVisible(&allLabel);
	addAndMakeVisible(&clearLabel);
	slotLabel1.setText("Channel 1", juce::dontSendNotification);
	slotLabel2.setText("Channel 2", juce::dontSendNotification);
	slotLabel3.setText("Channel 3", juce::dontSendNotification);
	volumeLabel.setText("Volume", juce::dontSendNotification);
	allLabel.setText("All start/stop", juce::dontSendNotification);
	clearLabel.setText("Clear all", juce::dontSendNotification);
	slotLabel1.setFont(juce::Font(20.0f, juce::Font::bold));
	slotLabel2.setFont(juce::Font(20.0f, juce::Font::bold));
	slotLabel3.setFont(juce::Font(20.0f, juce::Font::bold));
	volumeLabel.setFont(juce::Font(20.0f, juce::Font::bold));
	allLabel.setFont(juce::Font(20.0f, juce::Font::bold));
	clearLabel.setFont(juce::Font(20.0f, juce::Font::bold));


	formatManager.registerBasicFormats();  // formátumok regisztrálása


    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
	dialVol.setLookAndFeel(nullptr);
	openButton.setLookAndFeel(nullptr);
	clearButton.setLookAndFeel(nullptr);
	allButton.setLookAndFeel(nullptr);
	playButton1.setLookAndFeel(nullptr);
	playButton2.setLookAndFeel(nullptr);
	playButton3.setLookAndFeel(nullptr);
	stopButton1.setLookAndFeel(nullptr);
	stopButton2.setLookAndFeel(nullptr);
	stopButton3.setLookAndFeel(nullptr);
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()

	transport1.prepareToPlay(samplesPerBlockExpected, sampleRate);
	transport2.prepareToPlay(samplesPerBlockExpected, sampleRate);
	transport3.prepareToPlay(samplesPerBlockExpected, sampleRate);

}

void MainComponent::openButtonClicked()
{
	DBG("Open button clicked");

	juce::FileChooser chooser("Select a file to open...",
		juce::File::getSpecialLocation(juce::File::userDesktopDirectory),
		"*.wav", "*.aiff");

    if (chooser.browseForFileToOpen())
    {
        juce::File myFile = chooser.getResult();

		juce::AudioFormatReader* reader = formatManager.createReaderFor(myFile);

		std::unique_ptr<juce::AudioFormatReaderSource> tempSource (new juce::AudioFormatReaderSource (reader, true));

		playSource.reset(tempSource.release());

        DBG(reader->getFormatName());
    }
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

	allButton.setEnabled(false);  // alapértelmezett állapotban letiltva
	clearButton.setEnabled(false);  // alapértelmezett állapotban letiltva

	playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));
	playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43)); //ikon
	// playButton1.setColour(juce::TextButton::textColourOnId, juce::Colour(19, 99, 43));
	stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
	stopButton1.setEnabled(false);  // alapértelmezett állapotban letiltva

	playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));
	playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43)); //ikon
	// playButton2.setColour(juce::TextButton::textColourOnId, juce::Colour(19, 99, 43));
	stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
	stopButton2.setEnabled(false);  // alapértelmezett állapotban letiltva

	playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(24, 43, 23));
	playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(19, 99, 43)); //ikon
	// playButton3.setColour(juce::TextButton::textColourOnId, juce::Colour(19, 99, 43));
	stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
	stopButton3.setEnabled(false);  // alapértelmezett állapotban letiltva

	// TÖRÖL
}

void MainComponent::allButtonClicked()		// NEM JÓ EGYELŐRE (HA FELVÉTEL MEGY, NEM JÓ)
{
	DBG("All button clicked");

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

		stopButton1.setEnabled(true);
		allButton.setEnabled(true);  // alapértelmezett állapotban letiltva
		clearButton.setEnabled(true);  // alapértelmezett állapotban letiltva

		playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(255, 127, 39));  //gomb - narancs citrom
		// playButton1.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
		playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty1 = false;
		recording1 = true;

		if (empty2 == false || empty3 == false)
		{
			playing1 = true;
		}
		else
		{
			playing1 = false;
		}
		DBG("1felvetel");
	}
	else if (empty1 == false && recording1 == true && playing1 == false)  // köztes szakasz
	{
		playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		//playButton1.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
		playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty1 = false;
		recording1 = true;
		playing1 = true;
		DBG("1köztes");
	}
	else if (empty1 == false && recording1 == true && playing1 == true)	 // lejátszás
	{
		playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		//playButton1.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
		playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty1 = false;
		recording1 = false;
		playing1 = true;
		DBG("1lejatszas");
	}
	else if (empty1 == false && recording1 == false && playing1 == false)  // elindítás
	{
		playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		//playButton1.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
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


		playButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		//playButton1.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
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

		stopButton2.setEnabled(true);
		allButton.setEnabled(true);  // alapértelmezett állapotban letiltva
		clearButton.setEnabled(true);  // alapértelmezett állapotban letiltva

		playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(255, 127, 39));  //gomb - narancs citrom
		// playButton2.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
		playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty2 = false;
		recording2 = true;

		if (empty1 == false || empty3 == false)
		{
			playing2 = true;
		}
		else
		{
			playing2 = false;
		}
		DBG("2felvetel");
	}
	else if (empty2 == false && recording2 == true && playing2 == false)  // köztes szakasz
	{
		playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		//playButton2.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
		playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty2 = false;
		recording2 = true;
		playing2 = true;
		DBG("2köztes");
	}
	else if (empty2 == false && recording2 == true && playing2 == true)	 // lejátszás
	{
		playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		//playButton2.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
		playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty2 = false;
		recording2 = false;
		playing2 = true;
		DBG("2lejatszas");
	}
	else if (empty2 == false && recording2 == false && playing2 == false)  // elindítás
	{
		playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		//playButton2.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
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


		playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		//playButton2.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
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

		stopButton3.setEnabled(true);
		allButton.setEnabled(true);  // alapértelmezett állapotban letiltva
		clearButton.setEnabled(true);  // alapértelmezett állapotban letiltva

		playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(255, 127, 39));  //gomb - narancs citrom
		// playButton3.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
		playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty3 = false;
		recording3 = true;

		if (empty1 == false || empty2 == false)
		{
			playing3 = true;
		}
		else
		{
			playing3 = false;
		}
		DBG("3felvetel");
	}
	else if (empty3 == false && recording3 == true && playing3 == false)  // köztes szakasz
	{
		playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		//playButton3.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
		playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(255, 60, 0));	  //ikon - erős narancs
		stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty3 = false;
		recording3 = true;
		playing3 = true;
		DBG("3köztes");
	}
	else if (empty3 == false && recording3 == true && playing3 == true)	 // lejátszás
	{
		playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		//playButton3.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
		playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(237, 28, 36));
		empty3 = false;
		recording3 = false;
		playing3 = true;
		DBG("3lejatszas");
	}
	else if (empty3 == false && recording3 == false && playing3 == false)  // elindítás
	{
		playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		//playButton3.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
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


		playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(34, 177, 76));  //gomb - zöld
		//playButton3.setColour(juce::TextButton::textColourOnId, juce::Colour(225, 0, 4));
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
		//playButton1.setColour(juce::TextButton::textColourOnId, juce::Colour(19, 99, 43));
		playButton1.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton1.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
		empty1 = false;
		recording1 = false;
		playing1 = false;
	}
}

void MainComponent::stopButton2Clicked()
{
	DBG("Stop button 2 clicked");

	if (empty2 == false)
	{
		playButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(37, 66, 35));
		//playButton2.setColour(juce::TextButton::textColourOnId, juce::Colour(19, 99, 43));
		playButton2.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton2.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
		empty2 = false;
		recording2 = false;
		playing2 = false;
	}
}

void MainComponent::stopButton3Clicked()
{
	DBG("Stop button 3 clicked");

	if (empty3 == false)
	{
		playButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(37, 66, 35));
		//playButton3.setColour(juce::TextButton::textColourOnId, juce::Colour(19, 99, 43));
		playButton3.setColour(juce::TextButton::textColourOffId, juce::Colour(48, 250, 107));  //ikon - világos zöld
		stopButton3.setColour(juce::TextButton::buttonColourId, juce::Colour(136, 0, 21));
		empty3 = false;
		recording3 = false;
		playing3 = false;
	}
}

//==============================================================================

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{

    g.fillAll (juce::Colour(48, 48, 48));

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
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.

    juce::Rectangle<int> area = getLocalBounds();
	juce::Rectangle<int> bottom = area.removeFromBottom(area.getHeight() / 2);
    juce::Rectangle<int> botLeft = bottom.removeFromLeft(bottom.getWidth() / 3);
	juce::Rectangle<int> botRight = bottom.removeFromRight(bottom.getWidth() / 2);


	juce::Rectangle<int> dialVolArea = area.removeFromLeft(area.getWidth() / 4);
	juce::Rectangle<int> allStartArea = area.removeFromRight(area.getWidth() / 3);
	juce::Rectangle<int> clearArea = area.removeFromRight(area.getWidth() / 2);

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
	openButton.setBounds(area.reduced(50));
	playButton1.setBounds(play1.reduced(20));
	playButton2.setBounds(play2.reduced(20));
	playButton3.setBounds(play3.reduced(20));
	clearButton.setBounds(clearArea.reduced(80));
	allButton.setBounds(allStartArea.reduced(80));
	stopButton1.setBounds(botLeft.reduced(20));
	stopButton2.setBounds(bottom.reduced(20));
	stopButton3.setBounds(botRight.reduced(20));

	volumeLabel.setBounds(dialVol.getX(), dialVol.getY() - 20, dialVol.getWidth(), 20);
	allLabel.setBounds(allButton.getX(), allButton.getY() - 20, allButton.getWidth(), 20);
	clearLabel.setBounds(clearButton.getX(), clearButton.getY() - 20, clearButton.getWidth(), 20);

	volumeLabel.setJustificationType(juce::Justification::centredBottom);
	allLabel.setJustificationType(juce::Justification::centredBottom);
	clearLabel.setJustificationType(juce::Justification::centredBottom);
}
