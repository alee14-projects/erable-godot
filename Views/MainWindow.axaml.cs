using Avalonia;
using Avalonia.Controls;
using Avalonia.Markup.Xaml;

namespace Alee_Audio_Player.Views
{
    public class MainWindow : Window
    {
        public MainWindow()
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
    }
}