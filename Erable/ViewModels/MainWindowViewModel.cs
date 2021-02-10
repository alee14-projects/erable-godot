/**********************************************************************
 *
 *    Erable: Audio Player
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
