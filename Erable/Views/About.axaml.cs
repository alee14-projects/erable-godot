using System;
using Avalonia;
using Avalonia.Controls;
using Avalonia.Input;
using Avalonia.Markup.Xaml;

namespace Erable.Views
{
    public class About : Window
    {

        public About()
        {
            InitializeComponent();
#if DEBUG
            this.AttachDevTools();
#endif
        }

        private void InitializeComponent()
        {
            AvaloniaXamlLoader.Load(this);
        }

        private void InputElement_OnPointerPressed(object? sender, PointerPressedEventArgs e)
        {
            Environment.Exit(0);
        }
    }
}