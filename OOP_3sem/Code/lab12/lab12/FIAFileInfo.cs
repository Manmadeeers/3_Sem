using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab12
{
    public static class FIAFileInfo
    {
       public static void GetFileInfo(string filePath)
        {
            FileInfo fileInfo = new FileInfo(filePath);
            if(fileInfo.Exists )
            {
                Console.WriteLine("<----------->");
                Console.WriteLine($"Info about file by {filePath}");
                Console.WriteLine($"Full file path: {fileInfo.DirectoryName}");
                Console.WriteLine($"File size: {fileInfo.Length}");
                Console.WriteLine($"File extenction: {fileInfo.Extension}");
                Console.WriteLine($"File name: {fileInfo.Name}");
                Console.WriteLine($"Creation date: {fileInfo.CreationTime}");
                Console.WriteLine($"Last changes: {fileInfo.LastWriteTime}");
                Console.WriteLine("<---------->");
            }
            else
            {
                throw new ArgumentException("Invalid file path transmitted");
            }
        }

    }
}
