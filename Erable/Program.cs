using System;
using Avalonia;
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

            AppDomain.CurrentDomain.UnhandledException += ErrorHandler;

            #if DEBUG
            Console.WriteLine("Running on .NET " + Environment.Version + ", and " + Environment.OSVersion);
            Console.WriteLine("Opening window...");
            #endif
            
            DiscordRpc.Initialize();
            
            BuildAvaloniaApp().StartWithClassicDesktopLifetime(args);

        }

        static void ErrorHandler(object sender, UnhandledExceptionEventArgs e)
        {
            Console.WriteLine("Oh no! An error has occurred!");
            Console.WriteLine("OS Version: " + Environment.OSVersion);
            Console.WriteLine(".NET Version: " + Environment.Version);
            Console.WriteLine("Report this to the developers...");
            Console.WriteLine("Did this crashed? " + e.IsTerminating);
        }
        
        // Avalonia configuration, don't remove; also used by visual designer.
        static AppBuilder BuildAvaloniaApp()
            => AppBuilder.Configure<App>()
                .UsePlatformDetect()
                .LogToTrace()
                .UseReactiveUI();
    }
}
