
using System.Security.Cryptography.X509Certificates;

namespace lab12
{
    public static class FIALog
    {

        public delegate void FIALogDelegate(string chenges, string fileName,string FilePath);
        public static void WriteLog(string action, string filaName,string FilePath)
        {
            
        }
    }
}