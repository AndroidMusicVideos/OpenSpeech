using System;
using SpVoice = SpeechLib.SpVoice;

class Program
{
    static void Main(string[] args)
    {
        // Initialize a new instance of the SpVoice class
        SpVoice voice = new SpVoice();

        // Set the voice to use for the synthesis
        voice.Voice = voice.GetVoices().Item(0);

        // Speak the text
        voice.Speak("Hello, welcome to North Point Studios!", SpeechVoiceSpeakFlags.SVSFDefault);

        // Wait for the synthesis to complete before exiting the program
        while (voice.Status.RunningState == SpeechRunState.SRSEIsSpeaking)
        {
            System.Threading.Thread.Sleep(100);
        }
    }
}
