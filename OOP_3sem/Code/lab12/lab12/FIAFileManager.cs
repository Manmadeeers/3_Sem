using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
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
                
                DirectoryInfo inspectDirectory = Directory.CreateDirectory("FIAInspect");
                string infoFilePath = Path.Combine(inspectDirectory.FullName, "fiaDirInfo.txt");
                //Console.WriteLine("<---------->");
                using (StreamWriter writer = new StreamWriter(infoFilePath))
                {
                    writer.WriteLine("All files: ");
                    //Console.WriteLine("All files:");

                    foreach(var file in dirInfo.GetFiles())
                    {
                        writer.WriteLine(file.Name);
                        //Console.WriteLine(file.Name);
                    }
                    writer.WriteLine("All subfolders: ");
                    //Console.WriteLine("All subdirectories: ");
                    foreach(var sub in dirInfo.GetDirectories())
                    {
                        writer.WriteLine(sub.Name);
                        //Console.WriteLine(sub.Name);
                    }
                }
                //Console.WriteLine("<---------->");
                Console.WriteLine("All files and subdirectories were written down to a file");

                string copyFilePath = Path.Combine(inspectDirectory.FullName, "fiaDirinfoCopy.txt");
                File.Copy(infoFilePath, copyFilePath,true);
                File.Delete(infoFilePath);
                Console.WriteLine($"{infoFilePath} was copied to {copyFilePath}");
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
                DirectoryInfo dirInfo = Directory.CreateDirectory("FIAFiles");
                DirectoryInfo srcDirInfo = new DirectoryInfo(dirPath);
                foreach(var file in Directory.GetFiles(dirPath,ext))
                {
                    string fileName = Path.GetFileName(file);
                    string CopyTo = Path.Combine(dirInfo.FullName, fileName);
                    File.Copy(file,CopyTo, true);
                    
                }
                Console.WriteLine($"All files with required extention {ext} were copied to {dirPath}");
            }
            else
            {
                throw new ArgumentException("This directory does not exist");
            }
        }
    }
}
