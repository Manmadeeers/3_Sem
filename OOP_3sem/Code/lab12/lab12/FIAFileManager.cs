using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab12
{
    public static class FIAFileManager
    {
        public static void GetDirsAndFiles(string dirPath)
        {
            if (Directory.Exists(dirPath))
            {
                DirectoryInfo dirInfo = new DirectoryInfo(dirPath);

                string[] dirs = Directory.GetDirectories(dirPath);
                string[] files = Directory.GetFiles(dirPath);
                string inspectDirName = "FIAinspect";
                Directory.CreateDirectory(inspectDirName);
                string infoFileName = "fiadirinfo.txt";
                File.Create($"{inspectDirName}/fiadirinfo.txt");
                File.AppendAllLines(infoFileName, dirs);
                File.AppendAllLines(infoFileName, files);
                File.Copy($"{inspectDirName}/fiadirinfo.txt", "fiadirinfoNEW.txt", true);
                File.Delete($"{inspectDirName}/fiadirinfo.txt");
                
            }
            else
            {
                throw new ArgumentException("There's no such directory");
            }
        }

        public static void CopyByRequiredExtenction(string ext,string dirPath)
        {
            if (Directory.Exists(dirPath))
            {
                string filedirName = "FIAfiles";
                Directory.CreateDirectory(filedirName);

            }
            else
            {
                throw new ArgumentException("This directory does not exist");
            }
        }
    }
}
