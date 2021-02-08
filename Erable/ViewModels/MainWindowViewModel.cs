using System.Threading;
using Avalonia.Controls;
using Erable.Views;
using Gst;

namespace Erable.ViewModels
{
    public class MainWindowViewModel : ViewModelBase
    {
        public string Greeting => "Welcome to Erable Audio Player!";

        public void PlayFunction()
        {
            Thread t = new (AudioPlay);
            t.Start();
        }
        
        static void AudioPlay()
        {
            Application.Init();
            // Build the pipeline
            var pipeline = Parse.Launch("playbin uri=file:///home/andrew/Music/4616-werq-by-kevin-macleod.mp3");

            // Start playing
            pipeline.SetState(State.Playing);

            // Wait until error or EOS
            var bus = pipeline.Bus;
            var msg = bus.TimedPopFiltered (Constants.CLOCK_TIME_NONE, MessageType.Eos | MessageType.Error);

            // Free resources
            pipeline.SetState (State.Null);
            
        }
        

        public async void BrowseFunction()
        {
            var dialog = new OpenFileDialog();
          //  dialog.Title
            dialog.Filters.Add(new FileDialogFilter() {Name = "Audio Files", Extensions = {"mp3", "wav", "flac"}});
            dialog.Title = "Select Audio FIle";
            /*
            var files = await dialog.ShowAsync(this);
            
            if(files != null && files.Length > 0)
            {
                var file = files[0];
                if (System.Runtime.InteropServices.RuntimeInformation.IsOSPlatform(System.Runtime.InteropServices.OSPlatform.Windows))
                {
                    PlayFunction($"file:/{file.Replace('\\', '/')}");
                }
                else
                {
                    PlayFunction($"file://{file}");
                }
            }*/
        }

        public void MsgBoxTest()
        {
            MessageBox.Show(new MainWindow(), "Hello world", "Test Title", MessageBox.MessageBoxButtons.Ok);
        }
        
    }
}
