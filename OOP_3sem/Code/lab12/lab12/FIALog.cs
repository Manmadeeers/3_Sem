
using System.Security.Cryptography.X509Certificates;

namespace lab12
{
    public static class FIALog
    {
        public static void StartLogging()
        {
            File.Create("FIALog.txt");
        }
       // public delegate void FIALogDelegate(string chenges, string fileName,string FilePath);
        public static void WriteLog(string action, string filaName,string FilePath)
        {
            FileInfo log = new FileInfo("FIALog.txt");
            if (log.Exists)
            {
                using(StreamWriter writer = new StreamWriter("FIALog.txt"))
                {
                    writer.WriteLine("<---------->");
                    writer.WriteLine($"{DateTime.Today}*{DateTime.Now}|{action} was performed|File changed: {filaName}|File path: {FilePath}");
                }
            }
            else
            {
                throw new ArgumentException("log file not found");
            }
        }
    }
}