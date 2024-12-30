

namespace lab12
{
    internal class Program
    {
        public static void Main(string[] args)
        {
           
            FIADiskInfo.GetDriveInfo();
            FIAFileInfo.GetFileInfo("file.txt");
            FIADirInfo.GetDirInfo("info");
            FIAFileManager.GetDirsAndFiles("Dir1");
            FIAFileManager.CopyByRequiredExtenction("*.txt", "Dir2");
            FIALog.CountLogs();
            FIALog.GetLogsByDay(31);
            FIALog.GetLogsBySpan(30, 31);
            FIALog.GetLogsByKeyWord("Get");
            //FIAFileManager.ArchiveDirectory("Dir2");
        }
    }
}