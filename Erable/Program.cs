using System;
using Avalonia;
using Avalonia.Controls.ApplicationLifetimes;
using Avalonia.ReactiveUI;

namespace Erable
{
    class Program
    {
        // Initialization code. Don't use any Avalonia, third-party APIs or any
        // SynchronizationContext-reliant code before AppMain is called: things aren't initialized
        // yet and stuff might break.
        public static void Main(string[] args)
        {
            Console.WriteLine("Erable: Audio Player by Alee Productions");
            Console.WriteLine("Running on .NET " + Environment.Version + ", and " + Environment.OSVersion);
            #if DEBUG
            Console.WriteLine("Opening MainWindow...");
            #endif
            try { BuildAvaloniaApp().StartWithClassicDesktopLifetime(args); }catch (Exception ex) { Console.WriteLine(ex); }
        } 

        // Avalonia configuration, don't remove; also used by visual designer.
        static AppBuilder BuildAvaloniaApp()
            => AppBuilder.Configure<App>()
                .UsePlatformDetect()
                .LogToTrace()
                .UseReactiveUI();
    }
}
