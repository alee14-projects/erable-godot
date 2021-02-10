using System;
using System.Threading;
using Avalonia.Controls;
using Erable.Views;
using Sirop.Backend;

namespace Erable.ViewModels
{
    public class MainWindowViewModel : ViewModelBase
    {

        public void PlayFunction()
        {
            try
            {
                Thread t = new(Playback.PlayAudio);
                t.Start();
            }
            catch(Exception ex)
            {
                MessageBox.Show(new MainWindow(), ex.ToString(), "Error", MessageBox.MessageBoxButtons.Ok);
            }
        }

        public void StopFunction()
        {
            
        }
        
        public void BrowseFunction()
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

        public void ExceptionButton()
        {
            throw new Exception();
        }
    }
}
