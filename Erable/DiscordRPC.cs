using System;
using DiscordRPC;
using DiscordRPC.Logging;

namespace Erable
{
    public class DiscordRpc
    {
        
//Called when your application first starts.
//For example, just before your main loop, on OnEnable for unity.
        public static void Initialize() 
        {
            /*
            Create a Discord client
            NOTE: 	If you are using Unity3D, you must use the full constructor and define
                     the pipe connection.
            */
            var client = new DiscordRpcClient("808844258038644747")
            {
                Logger = new ConsoleLogger() {Level = LogLevel.Warning}
            };

            //Set the logger

            //Subscribe to events
            client.OnReady += (sender, e) =>
            {
                Console.WriteLine("Connected to Discord...");
                Console.WriteLine("Received Ready from user {0}", e.User.Username);
            };
            #if DEBUG
            client.OnPresenceUpdate += (sender, e) =>
            {
                Console.WriteLine("Received Update! {0}", e.Presence);
            };
            #endif
	
            //Connect to the RPC
            client.Initialize();

            //Set the rich presence
            //Call this as many times as you want and anywhere in your code.
            client.SetPresence(new RichPresence()
            {
                Details = "Playing Nothing",
                State = "RPC is being implemented!",
                Assets = new Assets()
                {
                    LargeImageKey = "erable_logo",
                    LargeImageText = "Erable Audio Player"
                }
            });	
        }
    }
}