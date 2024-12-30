
using System.Security.Cryptography.X509Certificates;

namespace lab12
{
    public static class FIALog
    {
        private static string _logPath = "fialog.txt";
        public static void StartLogging()
        {
            File.Create("FIALog.txt");
        }
       // public delegate void FIALogDelegate(string chenges, string fileName,string FilePath);
        public static void WriteLog(string action, string filaName,string FilePath)
        {
            string logPath = _logPath;
            //File.Create(logPath);
            //FileInfo logInfo = new FileInfo(logPath);
            string logText = $"{DateTime.Now.TimeOfDay}|{DateTime.Now.Date}|{action}|{filaName}|{FilePath}\n";
            File.AppendAllText(logPath, logText);
        }

        public static void CountLogs()
        {
            int allLogs = File.ReadAllLines(_logPath).Count();
            Console.WriteLine($"There are {allLogs} logs in {_logPath} file");
        }

        public static void GetLogsByDay(int inDay)
        {
            string day = Convert.ToString(inDay);
            Console.WriteLine($"<-----Log at {day}----->");
            foreach(string line in File.ReadAllLines(_logPath))
            {
                string[] currentLineInhalt = line.Split('|');
                if (currentLineInhalt.Length > 1) {
                    string assumedDate = currentLineInhalt[1];
                    assumedDate = assumedDate.Substring(0, assumedDate.IndexOf(' '));
                    if (assumedDate.Contains(day))
                    {
                        Console.WriteLine($"Suitable log: {line}");
                    }
                }
               
            }
            Console.WriteLine($"<-----End of logs----->");
        }

        public static void GetLogsBySpan(int start, int end)
        {
            string startDay = Convert.ToString(start);
            string endDay = Convert.ToString(end);
            Console.WriteLine($"<-----Logs at time span from {startDay} to {endDay}----->");
            foreach(string line in File.ReadLines(_logPath))
            {
                string[]currentLineContent = line.Split('|');
                if(currentLineContent.Length > 1)
                {
                    string assumeDate = currentLineContent[1];
                    assumeDate = assumeDate.Substring(0, assumeDate.IndexOf(' '));
                    //Console.WriteLine(assumeDate.Split('.').First());
                    assumeDate = assumeDate.Split('.').First();
                    if (Int32.Parse(assumeDate) >= start && Int32.Parse(assumeDate) <= end)
                    {
                        Console.WriteLine($"Suitable log: {line.Split('|').First()}");
                    }
                }
                else if (currentLineContent.Length > 7)
                {
                    throw new ArgumentException("Invalid log format");
                }
            }
            Console.WriteLine($"<-----End of logs----->");
        }

        public static void GetLogsByKeyWord(string word)
        {
            Console.WriteLine($"<-----Logs by {word}----->");

            foreach(string line in File.ReadLines(_logPath))
            {
                if (line.Contains(word))
                {
                    Console.WriteLine($"Suitable log by key word: {line.Split('|').First()}");
                }
            }

            Console.WriteLine($"<-----End of logs----->");
        }
    }
}