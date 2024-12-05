using Microsoft.VisualBasic;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace lab8
{
    public class User
    {

        private int _positionX = 0;
        private int _positionY = 0;
        private string _name;
        private double _compression_rate;
        public string Name
        {
            get { return _name; }
        }
        public User() { }
        public User(string Nname)
        {
            _name = Nname;
        }

        public delegate void MovementDelegate(int offset, char axis);
        public event MovementDelegate? Moved;
        public delegate void CompressionDelegate(double comprassion_rate);
        public event CompressionDelegate? Compressed;

        public void HandleMovement(int offset, char axis)
        {
            if(offset < 0)
            {
                throw new ArgumentException("Offset coud not be negative");
            }
            else if (offset == 0)
            {
                Console.WriteLine($"User {Name} wasn't moved");
                Moved?.Invoke(offset, axis);
            }
            else
            {
                if (axis == 'X' || axis == 'x')
                {
                    _positionX += offset;
                    Console.WriteLine($"User {Name} was moved on {offset} by {axis} axis");
                    Moved?.Invoke(offset,axis);
                }
                else if(axis == 'Y' || axis == 'y')
                {
                    _positionY += offset;
                    Console.WriteLine($"User {Name} was moved on {offset} by {axis} axis");
                    Moved?.Invoke(offset,axis);

                }
                else
                {
                    throw new ArgumentException("Invalid axis name");
                }
            }
        }

        public void HandleCompression(double Ncomprassion_rate)
        {
            if(Ncomprassion_rate < 0)
            {
                throw new ArgumentException("Compression rate could not be negative");
            }
            else if(Ncomprassion_rate==0)
            {
               
                Console.WriteLine($"User {Name} was not compressed");
                Compressed?.Invoke(Ncomprassion_rate);
            }
            else
            {
                _compression_rate = Ncomprassion_rate;
                Console.WriteLine($"User {Name} was compressed by {Ncomprassion_rate} rate");
                Compressed?.Invoke(Ncomprassion_rate);
            }
        }

        public override string ToString()
        {
            return $"Name: {Name}, PositionX:{_positionX}, PositionY:{_positionY}, CompressionRate: {_compression_rate}";
        }

    }

}
