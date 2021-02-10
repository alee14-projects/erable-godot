using System;
using Gst;

namespace Sirop.Backend
{
    public static class Playback
    {
        public static void PlayAudio()
        {
            Application.Init();
            // Build the pipeline
            var pipeline = Parse.Launch("playbin uri=file:///home/andrew/Music/4616-werq-by-kevin-macleod.mp3");
            // Start playing
            pipeline.SetState(State.Playing);

            // Wait until error or EOS
            var bus = pipeline.Bus;
            var msg = bus.TimedPopFiltered(Constants.CLOCK_TIME_NONE, MessageType.Eos | MessageType.Error);

            // Free resources
            pipeline.SetState(State.Null);
            

    }

        public static void StopAudio()
        {
            
        }
    }
}