using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using lab3;
using lab_4;

namespace lab7
{
    [XmlInclude(typeof(Product))]
    public static class FileProcessor
    {
        public static void SaveToFile<T>(string filePath, CollectionType<T>collection) where T : class
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<T>));
            using (FileStream stream = new FileStream(filePath, FileMode.Create))
            {
                serializer.Serialize(stream, collection._collection);
            }
        }
        public static void LoadFromFile<T>(string filePath, CollectionType<T> collection) where T : class
        {
            if (File.Exists(filePath))
            {
                XmlSerializer serializer = new XmlSerializer(typeof(List<T>));
                using (FileStream stream = new FileStream(filePath, FileMode.Open))
                {
                    var tmp_collection = (List<T>)serializer.Deserialize(stream);
                    collection._collection.Clear();
                    collection._collection.AddRange(tmp_collection);
                }
                Console.WriteLine($"Collection extracted from {filePath} file: ");
                foreach(var item in collection._collection)
                {
                    Console.WriteLine(item.ToString());
                }
            }
            else
            {
                throw new UnexistingFileException();
            }
        }
    }
}
