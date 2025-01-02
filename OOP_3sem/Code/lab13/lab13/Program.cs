using System.Xml;
using System.Xml.Linq;

namespace lab13
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Sofa sofa1 = new Sofa("Sofa", "200$");

            BinSerializer<Sofa> binSerializer = new BinSerializer<Sofa>();
            binSerializer.FormatSerialize("sofa.dat", sofa1);
            binSerializer.FormatDeserialize("sofa.dat");
            SoapSerializer<Sofa> soapSerializer = new SoapSerializer<Sofa>();
            soapSerializer.FormatSerialize("SoapSofa.dat", sofa1);
            soapSerializer.FormatDeserialize("SoapSofa.dat");

            XMLSerializer<Sofa> xMLSerializer = new XMLSerializer<Sofa>();
            xMLSerializer.FormatSerialize("Sofa.xml", sofa1);
            xMLSerializer.FormatDeserialize("Sofa.xml");

            JSONSerializer<Sofa>JSSerializer = new JSONSerializer<Sofa>();
            JSSerializer.FormatSerialize("Sofa.json", sofa1);
            JSSerializer.FormatDeserialize("Sofa.json");


            Sofa sofa2 = new Sofa("Sofa", "300$");
            Sofa sofa3 = new Sofa("Sofa", "400$");

            List<Sofa> collection1 = new List<Sofa>() { sofa1, sofa2, sofa3};
            CollectionSerializer<Sofa> collectionSerializer = new CollectionSerializer<Sofa>();
            collectionSerializer.Serialize("collection.json", collection1);
            collectionSerializer.Deserialize("collection.json");


            XmlDocument xmldoc = new XmlDocument();
            xmldoc.Load("Sofa.xml");
            XmlElement? xroot = xmldoc.DocumentElement;

            XmlNodeList? nodes = xroot?.SelectNodes("*");
            foreach (XmlNode node in nodes)
            {
                Console.WriteLine(node.OuterXml);
            }
            XmlNodeList? nodes1 = xroot?.SelectNodes("Amount");

            foreach (XmlNode node in nodes1)
            {
                Console.WriteLine(node.OuterXml);
            }

            XDocument xdoc2 = new XDocument();
            XElement doc = new XElement("SMTH");
            XElement fElem = new XElement("SomeElement");
            fElem.Value = "first";

            doc.Add(fElem);


            XElement decname = new XElement("SomeElement");
            decname.Value = "Second";

            doc.Add(decname);

            xdoc2.Add(doc);


            xdoc2.Save("Docs.xml");
        }
    }
}