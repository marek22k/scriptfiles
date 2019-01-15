using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.NetworkInformation;

namespace ping5test
{
    class Program
    {
        public static void Main(string[] args)
        {
            /* ping5test code */

            Console.Title
                = "ping5test";

            Console.InputEncoding = Encoding.UTF8;
            Console.OutputEncoding = Encoding.UTF8;

            try
            {
                string host = args[0];
                int timeout = int.Parse(args[1]);
                int size = int.Parse(args[2]);
                int count = int.Parse(args[3]);

                byte[] str = new byte[size];
                for (int i = 0; i <= (size - 1); i++)
                {
                    str[i] = 2;
                }


                for (int i = 0; i <= (count - 1); i++)
                {
                    try
                    {
                        Ping sen = new Ping();

                        PingReply res = sen.Send(host, timeout, str);
                        string status = res.Status.ToString();
                        string address = res.Address.ToString();
                        string time = res.RoundtripTime.ToString();
                        string ttl = res.Options.Ttl.ToString();

                        Console.WriteLine("{0}: Status={1} Time={2} TTL={3} BufferSize={4}", address, status, time, ttl, size);
                    }
                    catch (NullReferenceException e)  // Except timeout
                    {
                        Console.WriteLine("Timeout error: {0}", e.Message.ToString());
                    }
                    catch (Exception e)  // Except e
                    {
                        Console.WriteLine("Error: {0}", e.ToString());
                    }
                }
            }
            catch (IndexOutOfRangeException e)
            {
                Console.WriteLine("ping5test host timeout buffersize count\nError: {0}", e.ToString());
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
            Console.WriteLine("\n\nFree download from http://test.mk16.de/scriptFiles/ping5test.exe");
            Console.Read();
            Environment.Exit(Environment.ExitCode);
        }
    }
}