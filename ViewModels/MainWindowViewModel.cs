using System;
using System.Collections.Generic;
using System.Text;
using Avalonia.Controls;
using Gst;

namespace Erable.ViewModels
{
    public class MainWindowViewModel : ViewModelBase
    {
        public string Greeting => "Welcome to Erable Audio Player!";

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

        public void BrowseFunction()
        {
            //OpenFileDialog dialog = new OpenFileDialog();
            //dialog.Filters.Add(new FileDialogFilter() {Name = "Audio Files", Extensions = {"mp3"}});
        }
    }
}
