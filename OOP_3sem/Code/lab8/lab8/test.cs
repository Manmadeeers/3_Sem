using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace lab8
{
    public class Master
    {
        public Master() { }
        public delegate void MovementDelegate(int offset, char axis);
        public event MovementDelegate? Moved;


        public void MoveSlave(int offset, char axis)
        {
            Console.WriteLine($"Slave was moved on {offset} along {axis} axis");
        }


    }

    public class Slave
    {
        private string _name;
        private int _offsetX = 0;
        private int _offsetY = 0;

        public Slave(string name)
        {
            _name = name;
        }

        public void HandleMovement(int offset, char axis)
        {
            if (axis == 'X')
            {
                _offsetX += offset;
            }
            else
            {
                _offsetY += offset;
            }

            Console.WriteLine($"Slave {_name} was moved by {offset} along {axis} axis");
        }
        public override string ToString()
        {
            return $"Name: {_name}, PositionX:{_offsetX}, PositionY:{_offsetY}";
        }
    }
}
