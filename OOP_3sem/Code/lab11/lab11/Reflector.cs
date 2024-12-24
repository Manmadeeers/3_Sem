using System.Reflection;
using System.Xml;

namespace lab11
{
    public static class Reflector
    {
      
       public static void CollectInfo(string className, string parametrTypeName)
        {
            Type? currentType = Type.GetType("lab11." + className);
            string? currentAssemblyName = currentType.Assembly.FullName;

            using (XmlWriter writer = XmlWriter.Create("data.xml"))
            {
                writer.WriteStartDocument();
                writer.WriteStartElement("Data");
                writer.WriteElementString("Assembly", currentAssemblyName);
                Console.WriteLine("Assembly name done");
                GetPublicConstructors(writer,currentType);
                IEnumerable<string> publicMethods = GetPublicMethods(currentType);
                writer.WriteStartElement("PublicMethods");
                int methCount = 1;
                foreach (string method in publicMethods)
                {
                    writer.WriteElementString($"PublicMethod{methCount}", method);
                    methCount++;
                }
                writer.WriteFullEndElement();
                Console.WriteLine("Public Methods done");

                
                IEnumerable<string>fieldsAndProperties = GetFieldsAndProperties(currentType);
                int FandPcount = 1;
                writer.WriteStartElement("FieldsAndProperties");
                foreach (string field in fieldsAndProperties)
                {
                    writer.WriteElementString($"FieldOrProp{FandPcount}", field);
                    FandPcount++;
                }
                Console.WriteLine("Fields and properties done");
                writer.WriteFullEndElement();


                IEnumerable<string>realizedInterfaces = GetRealizedInterfaces(currentType);
                int interCount = 1;
                writer.WriteStartElement("RealizedInterfaces");
                foreach(string inter in realizedInterfaces)
                {
                    writer.WriteElementString($"RealizedInterface{interCount}", inter);
                    interCount++;
                }
                Console.WriteLine("Interfaces done");
                writer.WriteFullEndElement();


                IEnumerable<string> MethodsByParametres = GetMethodsByParams(currentType,parametrTypeName);
                int paramsIter = 1;
                writer.WriteStartElement("ByParams");
                foreach(string method in MethodsByParametres)
                {
                    writer.WriteElementString($"ByParam{paramsIter}", method);
                    paramsIter++;
                }
                Console.WriteLine("Methods by parametres done");
                writer.WriteFullEndElement();




                writer.WriteEndDocument();
            }
        }

        public static void GetPublicConstructors(XmlWriter writer,Type type)
        {

            bool hasPublicConstructors = type.GetConstructors(BindingFlags.Instance | BindingFlags.Public).Any();
            writer.WriteElementString("HasPublicConstructors", hasPublicConstructors.ToString());
            Console.WriteLine("Public constructors done");
        }

        public static IEnumerable<string> GetPublicMethods(Type type)
        {
            return type.GetMethods(BindingFlags.Public | BindingFlags.Instance).Select(method => method.Name);
        }

        public static IEnumerable<string>GetFieldsAndProperties(Type type)
        {
            return type.GetMembers(BindingFlags.Public|BindingFlags.Instance|BindingFlags.NonPublic).Where(member=>member.MemberType==MemberTypes.Field||member.MemberType==MemberTypes.Property).Select(member=>member.Name);
        }

        public static IEnumerable<string>GetRealizedInterfaces(Type type) 
        {
            return type.GetInterfaces().Select(inter => inter.Name);
        }

        public static IEnumerable<string> GetMethodsByParams(Type type, string parametrTypeName)
        {
            Type ? paramType = Type.GetType(parametrTypeName);

            return type.GetMethods().Where(m => m.GetParameters().Any(param => param.ParameterType == paramType)).Select(m => m.Name);

        }

        public static void InvokeFromFile(object invokedClass,string methodName, object[]paramets)
        {
          if (invokedClass == null)
            {
                throw new ArgumentNullException("Invoked class was null");
            }

            Type type = invokedClass.GetType();
            var method = type.GetMethod(methodName);
            if(method == null)
            {
                throw new ArgumentException("There's no such method");
            }

            var lines = File.ReadAllLines("Params.txt");
            ParameterInfo[] parametersInf = method.GetParameters();
            object[]parametres = new object[parametersInf.Length];
            for(int i = 0; i< parametersInf.Length; i++)
            {
                if(i<lines.Length)
                {
                    parametres[i] = Convert.ChangeType(lines[i], parametersInf[i].ParameterType);
                }
                else
                {
                    parametres[i] = GenerateParmValue(parametersInf[i].ParameterType);
                }
            }
            object  classInstane = Activator.CreateInstance(type);
            object InvokeMeth = method.Invoke(classInstane, parametres);

        }
        public static object GenerateParmValue(Type type)
        {
            if (type.IsValueType)
            {
                return Activator.CreateInstance(type);
            }
            return null;
        }
        
        public static T Create<T>() where T: class 
        {
            var constructor = typeof(T).GetConstructors().FirstOrDefault();

            if (constructor == null)
            {
                Console.WriteLine($"Не найден ни один конструктор для типа {typeof(T).Name}");
                return null;
            }

            var parameters = constructor.GetParameters()
                                        .Select(p => Activator.CreateInstance(p.ParameterType))
                                        .ToArray();

            return constructor.Invoke(parameters) as T;
        }
    }
}
