using System.IO.Compression;


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
              
                using (StreamWriter writer = new StreamWriter(infoFilePath))
                {
                    writer.WriteLine("All files: ");
                    

                    foreach (var file in dirInfo.GetFiles())
                    {
                        writer.WriteLine(file.Name);
                        
                    }
                    writer.WriteLine("All subfolders: ");
                   
                    foreach (var sub in dirInfo.GetDirectories())
                    {
                        writer.WriteLine(sub.Name);
                      
                    }
                    writer.Close();
                }
                FIALog.WriteLog("List of files and directories was written down to a file","fiaDirInfo.txt",infoFilePath);
                Console.WriteLine("All files and subdirectories were written down to a file");

                string copyFilePath = Path.Combine(inspectDirectory.FullName, "fiaDirinfoCopy.txt");
                File.Copy(infoFilePath, copyFilePath, true);
                File.Delete(infoFilePath);
                Console.WriteLine($"{infoFilePath} was copied to {copyFilePath}");
                FIALog.WriteLog("File was copied to another folder and deleted", copyFilePath.Split('\\').Last(), copyFilePath);
            }
            else
            {
                throw new ArgumentException("There's no such directory");
            }
        }

        public static void CopyByRequiredExtenction(string ext, string dirPath)
        {
            if (Directory.Exists(dirPath))
            {
                DirectoryInfo srcDirInfo = new DirectoryInfo(dirPath);
                DirectoryInfo inspectInfo = new DirectoryInfo("FIAinspect");
                DirectoryInfo destDirInfo = inspectInfo.CreateSubdirectory("FIAFiles");
                FIALog.WriteLog("Subdirectory created",destDirInfo.Name,destDirInfo.FullName);
                Console.WriteLine("<---------->");
                foreach(string file in Directory.GetFiles(srcDirInfo.FullName, ext))
                {
                   
                    string destFilePath = Path.Combine(destDirInfo.FullName, file.Split('\\').Last());
                    File.Copy(file, destFilePath,true);
                    FIALog.WriteLog($"Files with {ext} extension were copied",destDirInfo.Name,destDirInfo.FullName);  
                }
                Console.WriteLine($"All files were copied from {dirPath} to {destDirInfo.Name}");
                Console.WriteLine($"{destDirInfo.Name} was moved to FIAinspect");

                ArchiveDirectory(destDirInfo.FullName);
                Console.WriteLine("<---------->");
            }

            else
            {
                throw new ArgumentException("This directory does not exist");
            }
        }

        public static void ArchiveDirectory(string dirPath)
        {
            if (Directory.Exists(dirPath))
            {
                DirectoryInfo directoryInfo = new DirectoryInfo(dirPath);
                string zipFileName = Path.Combine(Path.GetDirectoryName(directoryInfo.FullName), "Archive");
                //Console.Write(zipFileName);
                int archIterator = 0;
                ZipFile.CreateFromDirectory(directoryInfo.FullName,$"{zipFileName}_{archIterator}");
                Console.WriteLine($"Directory {dirPath.Split('\\').Last()} was sucsessfully archived to {zipFileName.Split('\\').Last()}_{archIterator} file");
                string targetFolder = Path.Combine(Path.GetDirectoryName(directoryInfo.FullName), $"Unarchived_{archIterator}");
                ZipFile.ExtractToDirectory($"{zipFileName}_{archIterator}", targetFolder);
                Console.WriteLine($"{zipFileName.Split('\\').Last()}_{archIterator} was sucsessfully extracted to {targetFolder.Split('\\').Last()}_{archIterator} folder");
            }
            else
            {
                throw new ArgumentException("This directory does not exist");
            }
        }
      
    }
}
