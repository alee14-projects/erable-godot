using System;
using System.Collections.Generic;
using System.Text;
using Gst;

namespace AleeAudioPlayer.ViewModels
{
    public class MainWindowViewModel : ViewModelBase
    {
        public string Greeting => "Welcome to Alee Audio Player!";

        public void PlayFunction(string[] args)
        {
            Application.Init(ref args);
            // Build the pipeline
            var pipeline = Parse.Launch("playbin uri=file:///home/andrew/Music/4616-werq-by-kevin-macleod.mp3");

            // Start playing
            pipeline.SetState(State.Playing);

            // Wait until error or EOS
            var bus = pipeline.Bus;
            var msg = bus.TimedPopFiltered (Constants.CLOCK_TIME_NONE, MessageType.Eos | MessageType.Error);

            // Free resources
            //pipeline.SetState (State.Null);
        }
    }
}
