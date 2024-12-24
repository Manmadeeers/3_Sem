using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab12
{
    public static class FIADirInfo
    {
        public static void GetDirInfo(string dirPath)
        {
            if (Directory.Exists(dirPath))
            {
                DirectoryInfo dirInfo = new DirectoryInfo(dirPath);
                Console.WriteLine("<---------->");
                
                string[] files = Directory.GetFiles(dirPath);
                Console.WriteLine($"Amount of files: {files.Length}");
                Console.WriteLine($"Creation time: {dirInfo.CreationTime}");
                string[]subDirs = Directory.GetDirectories(dirPath);
                Console.WriteLine($"Amount of subdirectories: {subDirs.Length}");
                Console.WriteLine($"Root directory: {dirInfo.Root}");
                Console.WriteLine("<---------->");

            }
            else
            {
                throw new ArgumentException("This directory does not exsist");
            }
        }
    }
}
