/**********************************************************************
 *
 *    Sirop Backend: Erable Audio Player's Backend
 *    Copyright (C) 2021 Alee Productions
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * 
 ************************************************************************/
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