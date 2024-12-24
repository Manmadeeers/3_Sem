
namespace lab12
{
    public static class FIADiskInfo
    {
        public static void GetDriveInfo()
        {
            var allDrives = DriveInfo.GetDrives();
            foreach (var drive in allDrives)
            {
                Console.WriteLine("<---------->");
                Console.WriteLine($"Dirve: {drive.Name}");
                Console.WriteLine($"Filesystem: {drive.DriveFormat}");
                Console.WriteLine($"Total size: {drive.TotalSize}");
                Console.WriteLine($"Free size: {drive.TotalFreeSpace}");
                Console.WriteLine($"Label: {drive.VolumeLabel}");
                Console.WriteLine("<---------->");
            }
        }
    }
}
