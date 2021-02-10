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
