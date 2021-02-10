/**********************************************************************
 *
 *   Erable: Audio Player
 *   Copyright (C) 2021 Alee Productions
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
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
using System.Threading.Tasks;
using Avalonia.Controls;
using Avalonia.Markup.Xaml;

namespace Erable.Views
{
    public class MessageBox : Window
    {
        public enum MessageBoxButtons
        {
            Ok,
            OkCancel,
            YesNo,
            YesNoCancel
        }

        public enum MessageBoxResult
        {
            Ok,
            Cancel,
            Yes,
            No
        }

        
        public MessageBox()
        {
            AvaloniaXamlLoader.Load(this);
        }

        public static Task<MessageBoxResult> Show(Window parent, string text, string title, MessageBoxButtons buttons)
        {
            var msgbox = new MessageBox()
            {
                Title = title
            };
            msgbox.FindControl<TextBlock>("Text").Text = text;
            var buttonPanel = msgbox.FindControl<StackPanel>("Buttons");

            var res = MessageBoxResult.Ok;

            void AddButton(string caption, MessageBoxResult r, bool def = false)
            {
                var btn = new Button {Content = caption};
                btn.Click += (_, __) => { 
                    res = r;
                    msgbox.Close();
                };
                buttonPanel.Children.Add(btn);
                if (def)
                    res = r;
            }

            if (buttons == MessageBoxButtons.Ok || buttons == MessageBoxButtons.OkCancel)
                AddButton("OK", MessageBoxResult.Ok, true);
            if (buttons == MessageBoxButtons.YesNo || buttons == MessageBoxButtons.YesNoCancel)
            {
                AddButton("Yes", MessageBoxResult.Yes);
                AddButton("No", MessageBoxResult.No, true);
            }

            if (buttons == MessageBoxButtons.OkCancel || buttons == MessageBoxButtons.YesNoCancel)
                AddButton("Cancel", MessageBoxResult.Cancel, true);


            var tcs = new TaskCompletionSource<MessageBoxResult>();
            msgbox.Closed += delegate { tcs.TrySetResult(res); };
            if (parent != null)
                msgbox.ShowDialog(parent);
            else msgbox.Show();
            return tcs.Task;
        }
    }
}