using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Runtime.Serialization.Formatters.Soap;

namespace lab13
{
     interface ISerialize<T>
    {
        void FormatSerialize(string filename, T obj);
        void FormatDeserialize(string filename);

    }

    public  class BinSerializer<T> : ISerialize<T>
    {

        public  void FormatSerialize(string filename, T obj)
        {
            BinaryFormatter bf = new BinaryFormatter();

            using (Stream sw = new FileStream(filename, FileMode.Create))
            {
               bf.Serialize(sw, obj);
                Console.WriteLine("binserialize");
            }

        }
        public  void FormatDeserialize(string filename)
        {
            BinaryFormatter bf = new BinaryFormatter();
            using (Stream sw = new FileStream(filename, FileMode.Open))
            {
                var deserializedobj = (object)bf.Deserialize(sw);
                Console.WriteLine($"Bin deserialized: {deserializedobj.ToString()}");
            }
        }
    }
    public  class SoapSerializer<T>:ISerialize<T>
    {
        public  void FormatSerialize(string filename, T obj)
        {
            SoapFormatter sf = new SoapFormatter();
            using (Stream stream = new FileStream(filename, FileMode.Create))
            {
                sf.Serialize(stream, obj);
                Console.WriteLine("Soap serialized");
            }
        }

        public  void FormatDeserialize(string filename)
        {
            SoapFormatter sf = new SoapFormatter();
            using(Stream stream = new FileStream(filename, FileMode.Open))
            {
                var obj = (object)sf.Deserialize(stream);
                Console.WriteLine($"Soap deserialized: {obj.ToString()}");
                //Console.WriteLine("Soap deserialized");
            }
        }
    }

    public class XMLSerializer<T>:ISerialize<T> where T : Furniture
    {
        public void FormatSerialize(string filename,T obj)
        {
            Type type = obj.GetType();

            XmlSerializer xmlSerializer = new XmlSerializer(type);
            using (Stream sw = new FileStream(filename, FileMode.Create))
            {
                xmlSerializer.Serialize(sw, obj);
                Console.WriteLine("Xml serialized");
            }
        }
        public void FormatDeserialize(string filename)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(T));
            //Console.WriteLine(typeof(T));
            using (FileStream sw = new FileStream(filename, FileMode.Open))
            {
                T? obj = xmlSerializer.Deserialize(sw) as T;
                Console.WriteLine($"Xml deserialized: {obj.ToString()}");
            }
        }
    }

    public class JSONSerializer<T> : ISerialize<T>
    {
        public void FormatSerialize(string filename,T obj)
        {
            using (Stream sw = new FileStream(filename, FileMode.Create))
            {
                JsonSerializer.Serialize(sw, obj);
                Console.WriteLine("JSON serialized");
            }
        }
        public void FormatDeserialize(string filename)
        {
            using (Stream sw = new FileStream(filename, FileMode.Open))
            {
                var obj = JsonSerializer.Deserialize<object>(sw);
                Console.WriteLine($"JSON deserialized: {obj.ToString()}");
            }
        }
    }

    public class CollectionSerializer<T>
    {
        public void Serialize(string filename, List<T> items)
        {
            string serializer = JsonSerializer.Serialize(items);
            using(StreamWriter sw = new StreamWriter(filename))
            {
                sw.Write(serializer);
            }
            Console.WriteLine("Collection serialized");
        }
        public void Deserialize(string filename)
        {
            List<T> items = new List<T>();
            using (Stream sw = new FileStream(filename, FileMode.Open))
            {
                items = JsonSerializer.Deserialize<List<T>>(sw);
            }
            
          
            Console.WriteLine("Collection deserialized");
            foreach (var item in items)
            {
                Console.WriteLine(item.ToString());
            }
            Console.WriteLine("<---------->");
        }
    }
}
